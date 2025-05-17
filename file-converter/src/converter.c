#include <stdio.h>
#include <stdlib.h>
#include "converter.h"
#include "pdf_handler.h"
#include "doc_handler.h"

int convert_pdf_to_doc(const char *pdf_file, const char *doc_file) {
    char *content = NULL;
    int result;

    // Read the PDF file
    result = read_pdf(pdf_file, &content);
    if (result != 0) {
        fprintf(stderr, "Error reading PDF file: %s\n", pdf_file);
        return -1;
    }

    // Convert and write to DOC file
    result = write_doc_from_pdf(doc_file, content);
    free(content); // Free allocated memory

    if (result != 0) {
        fprintf(stderr, "Error writing DOC file: %s\n", doc_file);
        return -1;
    }

    printf("Successfully converted %s to %s\n", pdf_file, doc_file);
    return 0;
}

int convert_doc_to_pdf(const char *doc_file, const char *pdf_file) {
    int result;

    // Convertir el archivo DOC a PDF
    result = write_pdf_from_doc(doc_file, pdf_file);
    if (result != 0) {
        fprintf(stderr, "Error converting DOC to PDF: %s\n", doc_file);
        return -1;
    }

    printf("Successfully converted %s to %s\n", doc_file, pdf_file);
    return 0;
}