#ifndef DOC_HANDLER_H
#define DOC_HANDLER_H

// Function to read content from a DOC file
int read_doc(const char *filename, char **content);

// Function to write content to a DOC file
int write_pdf_from_doc(const char *docfile, const char *pdf_file);

#endif // DOC_HANDLER_H