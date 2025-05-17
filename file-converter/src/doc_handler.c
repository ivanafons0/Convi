#include "doc_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

// Function to read DOC file content
int read_doc(const char* filename, char** content) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open DOC file");
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    *content = (char *)malloc((filesize + 1) * sizeof(char));
    if (!*content) {
        perror("Failed to allocate memory for DOC content");
        fclose(file);
        return -1;
    }

    size_t read_size = fread(*content, 1, filesize, file);
    (*content)[read_size] = '\0'; // Null-terminate the string

    fclose(file);
    return 0;
}

int write_pdf_from_doc(const char *doc_file, const char *pdf_file) {
    // Usa LibreOffice CLI para convertir el archivo DOC a PDF
    char command[512];
    snprintf(command, sizeof(command),
             "libreoffice --headless --convert-to pdf --outdir %s %s",
             dirname(strdup(pdf_file)), doc_file);

    int result = system(command);
    if (result != 0) {
        fprintf(stderr, "LibreOffice conversion failed\n");
        return -1;
    }

    // Mover el archivo convertido al destino deseado
    char converted_file[512];
    snprintf(converted_file, sizeof(converted_file), "%s/%s.pdf",
             dirname(strdup(doc_file)), basename(strdup(doc_file)));

    rename(converted_file, pdf_file);

    return 0; // Éxito
}