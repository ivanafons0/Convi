#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "converter.h"

int main() {
    char input_file[256];
    char output_file[256];
    int choice;

    printf("File Converter\n");
    printf("1. Convert PDF to DOC\n");
    printf("2. Convert DOC to PDF\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // Consume newline character

    switch (choice) {
        case 1:
            printf("Enter the path of the PDF file: ");
            fgets(input_file, sizeof(input_file), stdin);
            input_file[strcspn(input_file, "\n")] = 0; // Remove newline character
            printf("Enter the path for the output DOC file: ");
            fgets(output_file, sizeof(output_file), stdin);
            output_file[strcspn(output_file, "\n")] = 0; // Remove newline character
            if (convert_pdf_to_doc(input_file, output_file) == 0) {
                printf("Conversion successful: %s -> %s\n", input_file, output_file);
            } else {
                printf("Conversion failed.\n");
            }
            break;
        case 2:
            printf("Enter the path of the DOC file: ");
            fgets(input_file, sizeof(input_file), stdin);
            input_file[strcspn(input_file, "\n")] = 0; // Remove newline character
            printf("Enter the path for the output PDF file: ");
            fgets(output_file, sizeof(output_file), stdin);
            output_file[strcspn(output_file, "\n")] = 0; // Remove newline character
            if (convert_doc_to_pdf(input_file, output_file) == 0) {
                printf("Conversion successful: %s -> %s\n", input_file, output_file);
            } else {
                printf("Conversion failed.\n");
            }
            break;
        default:
            printf("Invalid option.\n");
            break;
    }

    return 0;
}