INCLUDE_FLAG = -Iinclude/
COMPILER = clang++
LIB_NAME = menu.a

SRC_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(patsubst src/%.cpp, bin/%.o, $(SRC_FILES))

all: $(LIB_NAME) examples/simple_menu

$(LIB_NAME): $(OBJ_FILES)
	#create static library
	ar -cvq $(LIB_NAME) bin/*

#Example programs
examples/simple_menu: examples/simple_menu.cpp $(LIB_NAME)
	$(COMPILER) $(INCLUDE_FLAG) -o $@ $^

.PHONY: clean
clean:
	rm -rvf bin/* $(LIB_NAME) examples/simple_menu



bin/%.o: src/%.cpp
	$(COMPILER) $(INCLUDE_FLAG) -c -o $@ $<
