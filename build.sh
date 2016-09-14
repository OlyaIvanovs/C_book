set -e

mkdir -p build
g++ chapter1/theory.c -o build/theory -g -std=c++11
./build/theory