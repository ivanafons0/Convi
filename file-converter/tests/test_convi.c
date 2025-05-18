#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/converter.h"
#include <linux/limits.h>

void test_convert_pdf_to_doc() {
    char input_pdf[PATH_MAX];
    char expected_doc[PATH_MAX];

    // Convertir rutas relativas a absolutas
    if (!realpath("test.pdf", input_pdf)) {
        perror("Error resolving path for test.pdf");
        exit(EXIT_FAILURE);
    }
    if (!realpath("test.doc", expected_doc)) {
        perror("Error resolving path for test.doc");
        exit(EXIT_FAILURE);
    }

    int result = convert_pdf_to_doc(input_pdf, expected_doc);
    assert(result == 0); // Check if conversion was successful
}

void test_convert_doc_to_pdf() {
    char input_doc[PATH_MAX];
    char expected_pdf[PATH_MAX];

    // Convertir rutas relativas a absolutas
    if (!realpath("test.doc", input_doc)) {
        perror("Error resolving path for test.doc");
        exit(EXIT_FAILURE);
    }
    if (!realpath("test.pdf", expected_pdf)) {
        perror("Error resolving path for test.pdf");
        exit(EXIT_FAILURE);
    }

    int result = convert_doc_to_pdf(input_doc, expected_pdf);
    assert(result == 0); // Check if conversion was successful
}

int main() {
    printf("Running PDF to DOC tests...\n");
    test_convert_pdf_to_doc();

    printf("Running DOC to PDF tests...\n");
    test_convert_doc_to_pdf();

    printf("All tests passed!\n");
    return 0;
}