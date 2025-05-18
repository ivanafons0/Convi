# File: /file-converter/file-converter/README.md

# File Converter

This project is a file converter that currently supports converting PDF documents to DOC format and vice versa. The goal is to extend the functionality in the future to support additional file types.

## Features

- Convert PDF to DOC
- Convert DOC to PDF
- Easy to extend for additional file formats

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)
- Make utility

## Libraries Used

This project relies on the following libraries for file conversion:

### PDF Handling
- **Poppler-GLib**: Used for reading and extracting text from PDF files.
  - Website: [https://poppler.freedesktop.org/](https://poppler.freedesktop.org/)
  - Installation: 
  
  *ArchLinux

  ´´´
  sudo pacman -S poppler-glib
  ´´´  

### DOC Handling
- **LibreOffice CLI**: Used for converting DOC files to PDF and vice versa.
  - Website: [https://www.libreoffice.org/](https://www.libreoffice.org/)
  - Installation: 
  
  *ArchLinux

  ´´´
  sudo pacman -S libreoffice-fresh
  ´´´  

### General Utilities
- **GLib**: Provides utility functions for handling strings, memory, and file paths.
  - Website: [https://developer.gnome.org/glib/](https://developer.gnome.org/glib/)
  - Installation: 
  
  *ArchLinux

  ´´´
  sudo pacman -S glib2
  ´´´ 

### Build Tools
- **pkg-config**: Used to manage compiler and linker flags for the libraries.
  - Installation: 

  *ArchLinux
  
  ´´´
  sudo pacman -S pkgconf
  ´´´ 

Make sure these libraries are installed on your system before building the project.

### Building the Project

To build the project, navigate to the project directory and run:

```
make
```

### Running the Converter

After building the project, you can run the file converter seleccting which option you want:

1. Convert PDF to DOC
2. Convert DOC to PDF
Choose an option (1 or 2): 

(Working on making a better interface)

And then putting your file path and how do you want to name your new converter file


### Running Tests

To run the tests for the conversion functionality, use the following command:
(just a first time test, actually have to improve them)

```
make test
```

## Future Enhancements

- Support for additional file formats (e.g., TXT, HTML, etc.)
- Improved error handling and user feedback
- GUI for easier file conversion

## License

This project is licensed under the Apache License 2.0 - see the LICENSE file for details.