CC = g++

CFLAGS = -g -Wall -Werror

TARGET = twenty_one

FILES = deck.cc deck.hh list.cc list.hh

TESTTARGET = twenty_one_unit_testing

TESTFILES = test_helper.cc test_helper.hh test_twenty_one.cc test_list.cc test_deck.cc test_runner.cc

CLANG = clang++ -fsanitize=address -g -Wall

CTARGET = twenty_one_clang

CLANGFILES = deck.cc list.cc

all: $(TARGET)

$(TARGET): $(TARGET).cc
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cc $(FILES)

clean:
	$(RM) $(TARGET)

clang:
	$(CLANG) $(TARGET).cc $(FILES) 

test:
	$(CC) $(CFLAGS) -o $(TESTTARGET) $(FILES) $(TESTFILES)