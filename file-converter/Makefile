CC = gcc
CFLAGS = -Iinclude -I./src/utils -Wall -Wextra $(shell pkg-config --cflags glib-2.0 poppler-glib)
LDFLAGS = $(shell pkg-config --libs glib-2.0 poppler-glib)
SRC = src/main.c src/converter.c src/pdf_handler.c src/doc_handler.c src/utils/file_utils.c
OBJ = $(SRC:.c=.o)
TARGET = file_converter

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)


.PHONY: all clean