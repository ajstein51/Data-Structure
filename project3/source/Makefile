# AJ Stein, CS3610, Project 3

all: build clean

#build
build: main.o huffman_tree.o
	g++ -std=c++11 main.o huffman_tree.o -o run

main.o: min_heap.h main.cpp huffman_tree.h
	g++ -c -std=c++11 main.cpp 

#min_heap.o: min_heap.h huffman_tree.cpp huffman_tree.h
#	g++ -c min_heap.cpp

huffman_tree.o: min_heap.h huffman_tree.cpp huffman_tree.h
	g++ -c -std=c++11 huffman_tree.cpp

# deletes
clean:
	-rm -f *.o run