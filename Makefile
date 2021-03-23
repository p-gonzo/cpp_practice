
FILE = $(file).cpp
CC = g++
COMPILER_FLAGS = -std=c++17
LINKER_FLAGS = $(links)
OBJ_NAME = $(file)
SPLIT_PATH = $(subst /, ,$(file))
all :
	$(CC) -o ./builds/$(word 2, $(SPLIT_PATH)) $(FILE) $(COMPILER_FLAGS) $(LINKER_FLAGS)
	./builds/$(word 2, $(SPLIT_PATH))
grind :
	$(CC) -o ./builds/$(word 2, $(SPLIT_PATH)) $(FILE) $(COMPILER_FLAGS) -g $(LINKER_FLAGS)
	valgrind ./builds/$(word 2, $(SPLIT_PATH))
