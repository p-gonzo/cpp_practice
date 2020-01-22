FILE_NAME=$1
g++ -std=c++17 -o $FILE_NAME $FILE_NAME.cpp
valgrind ./$FILE_NAME