# AJ Stein, CS3610, Project 3

all: build archive

#build
build: main.o min_heap.o huffman_tree.o
	g++ main.o min_heap.o huffman_tree.o -o run

main.o: main.cpp
	g++ -c main.cpp

min_heap.o: min_heap.cpp
	g++ -c min_heap.cpp

huffman_tree.o: huffman_tree.cpp
	g++ -c huffman_tree.cpp

# deletes
clean:
	-rm -f *.o run