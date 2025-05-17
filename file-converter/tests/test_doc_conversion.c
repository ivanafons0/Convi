#include <stdio.h>
#include <assert.h>
#include "../src/converter.h"

void test_convert_pdf_to_doc() {
    // Test case for converting a sample PDF to DOC
    const char *pdf_file = "test.pdf";
    const char *doc_file = "test.doc";
    
    // Assuming the conversion function returns 0 on success
    int result = convert_pdf_to_doc(pdf_file, doc_file);
    assert(result == 0);
}

void test_convert_doc_to_pdf() {
    // Test case for converting a sample DOC to PDF
    const char *doc_file = "test.doc";
    const char *pdf_file = "test.pdf";
    
    // Assuming the conversion function returns 0 on success
    int result = convert_doc_to_pdf(doc_file, pdf_file);
    assert(result == 0);
}

int main() {
    test_convert_pdf_to_doc();
    test_convert_doc_to_pdf();
    
    printf("All tests passed!\n");
    return 0;
}