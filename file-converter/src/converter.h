#ifndef CONVERTER_H
#define CONVERTER_H

// Function to convert a PDF file to a DOC file
int convert_pdf_to_doc(const char *pdf_file, const char *doc_file);

// Function to convert a DOC file to a PDF file
int convert_doc_to_pdf(const char *doc_file, const char *pdf_file);

#endif // CONVERTER_H