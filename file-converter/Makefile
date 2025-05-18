CC = gcc
CFLAGS = -Iinclude -I./src/utils -Wall -Wextra $(shell pkg-config --cflags glib-2.0 poppler-glib)
LDFLAGS = $(shell pkg-config --libs glib-2.0 poppler-glib)
SRC = src/converter.c src/pdf_handler.c src/doc_handler.c src/utils/file_utils.c
OBJ = $(SRC:.c=.o)
TARGET = file_converter

TEST_SRC = tests/test_convi.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_TARGET = run_tests

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ) $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_OBJ) $(TEST_TARGET) src/main.o

.PHONY: all clean test