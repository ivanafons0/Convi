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