#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/converter.h"


void test_convert_pdf_to_doc() {
    const char *input_pdf = "test.pdf";
    const char *expected_doc = "test.doc";

    // Assume convert_pdf_to_doc is implemented correctly
    int result = convert_pdf_to_doc(input_pdf, expected_doc);
    assert(result == 0); // Check if conversion was successful

    // Additional checks can be added here to verify the content of the output file
}

void test_convert_doc_to_pdf() {
    const char *input_doc = "test.doc";
    const char *expected_pdf = "test.pdf";

    // Assume convert_doc_to_pdf is implemented correctly
    int result = convert_doc_to_pdf(input_doc, expected_pdf);
    assert(result == 0); // Check if conversion was successful

    // Additional checks can be added here to verify the content of the output file
}

int main() {
    test_convert_pdf_to_doc();
    test_convert_doc_to_pdf();

    printf("All tests passed!\n");
    return 0;
}