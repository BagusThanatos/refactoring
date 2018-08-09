mkdir -p build/linux/
clang src/original.cpp $(< flags_linux.txt) -o build/linux/original
clang src/rename1.cpp $(< flags_linux.txt)  -o build/linux/rename1
clang src/refactor1.cpp $(< flags_linux.txt) -o build/linux/refactor1