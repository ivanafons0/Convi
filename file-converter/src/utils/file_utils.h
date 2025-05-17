#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdbool.h>

// Function to check if a file exists
bool file_exists(const char *filename);

// Function to get the file extension
const char* get_file_extension(const char *filename);

#endif // FILE_UTILS_H