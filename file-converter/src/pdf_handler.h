#ifndef PDF_HANDLER_H
#define PDF_HANDLER_H

// Function to read content from a PDF file
int read_pdf(const char *filename, char **content);

// Function to write content to a PDF file
int write_doc_from_pdf(const char *filename, const char *content);

#endif // PDF_HANDLER_H