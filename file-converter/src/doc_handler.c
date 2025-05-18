#include "doc_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

int write_pdf_from_doc(const char *doc_file, const char *pdf_file) {
    // Use LibreOffice CLI to convert the DOC to PDF
    char command[512];
    snprintf(command, sizeof(command),
             "libreoffice --headless --convert-to pdf --outdir %s %s",
             dirname(strdup(pdf_file)), doc_file);

    int result = system(command);
    if (result != 0) {
        fprintf(stderr, "LibreOffice conversion failed\n");
        return -1;
    }

    // Move the converted file to the desired location
    char converted_file[512];
    snprintf(converted_file, sizeof(converted_file), "%s/%s.pdf",
             dirname(strdup(doc_file)), basename(strdup(doc_file)));

    rename(converted_file, pdf_file);

    return 0; // Éxito
}