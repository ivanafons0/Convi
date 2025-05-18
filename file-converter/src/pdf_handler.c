#include <stdio.h>
#include <stdlib.h>
#include <poppler/glib/poppler.h>
#include "pdf_handler.h"
#include <glib.h>
#include <glib/gstring.h>


int read_pdf(const char *filename, char **content) {
    GError *error = NULL;

    //Convert the file path to a URI
    char *uri = g_filename_to_uri(filename, NULL, &error);
    if (!uri) {
        fprintf(stderr, "Error converting file path to URI: %s\n", error->message);
        g_error_free(error);
        return -1;
    }

    // Open the PDF file using Poppler
    PopplerDocument *document = poppler_document_new_from_file(uri, NULL, &error);
    g_free(uri); // Free the URI string

    if (!document) {
        fprintf(stderr, "Error opening PDF file: %s\n", error->message);
        g_error_free(error);
        return -1;
    }

    int n_pages = poppler_document_get_n_pages(document);
    GString *text = g_string_new("");

    for (int i = 0; i < n_pages; i++) {
        PopplerPage *page = poppler_document_get_page(document, i);
        if (page) {
            gchar *page_text = poppler_page_get_text(page);
            g_string_append(text, page_text);
            g_free(page_text);
            g_object_unref(page);
        }
    }

    *content = strdup(text->str);
    g_string_free(text, TRUE);
    g_object_unref(document);

    return 0; // Success
}

int write_doc_from_pdf(const char *filename, const char *content) {
    // Write the content to a temporary text file
    const char *temp_txt = "/tmp/temp_text.txt";
    FILE *temp_file = fopen(temp_txt, "w");
    if (!temp_file) {
        perror("Failed to create temporary text file");
        return -1;
    }
    fprintf(temp_file, "%s", content);
    fclose(temp_file);

    // Use LibreOffice CLI to convert the text file to DOC
    char command[512];
    snprintf(command, sizeof(command), "libreoffice --headless --convert-to doc --outdir %s %s",
             g_dirname(strdup(filename)), temp_txt);

    int result = system(command);
    if (result != 0) {
        fprintf(stderr, "LibreOffice conversion failed\n");
        return -1;
    }

    // Move the converted file to the desired location
    char converted_file[512];
    snprintf(converted_file, sizeof(converted_file), "%s/temp_text.doc", g_dirname(strdup(filename)));
    rename(converted_file, filename);

    return 0; // Success
}