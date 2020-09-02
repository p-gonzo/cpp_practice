OBJS = Vec2.cpp Ball.cpp pong_clone.cpp
CC = g++
# -w suppresses all warnings
COMPILER_FLAGS = -w -g -std=c++17
LINKER_FLAGS = -lSDL2
#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = pong_clone
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)