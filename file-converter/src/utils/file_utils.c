#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_utils.h"

// Function to check if a file exists
bool file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1; // File exists
    }
    return 0; // File does not exist
}

// Function to get the file extension
const char* get_file_extension(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if (!dot || dot == filename) return ""; // No extension
    return dot + 1; // Return extension without the dot
}