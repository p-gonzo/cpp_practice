FILE_NAME=$1
g++ -std=c++17 -o ../builds/$FILE_NAME $FILE_NAME.cpp || exit 1;
valgrind ../builds/$FILE_NAME