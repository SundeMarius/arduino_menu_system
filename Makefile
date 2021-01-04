INCLUDE_FLAG = -Iinclude/
COMPILER = clang++

SRC_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(patsubst src/%.cpp, bin/%.o, $(SRC_FILES))

all: $(OBJ_FILES)

bin/%.o: src/%.cpp
	$(COMPILER) $(INCLUDE_FLAG) -c -o $@ $<

.PHONY: clean
clean:
	rm -rvf bin/* 
