set -e

mkdir -p build
g++ chapter3/ex3_6.c -o build/theory -g -std=c++11
./build/theory