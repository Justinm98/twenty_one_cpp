CC = g++

CFLAGS = -g -Wall -Werror

TARGET = twenty_one

FILES = deck.cc deck.hh list.cc list.hh

CLANG = clang++ -fsanitize=address -g

CTARGET = twenty-one-clang

CLANGFILES = deck.cc list.cc

all: $(TARGET)

$(TARGET): $(TARGET).cc
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cc $(FILES)

clean:
	$(RM) $(TARGET)

clang:
	$(CLANG) -fsanitize=address -g -Wall $(TARGET).cc $(FILES) 