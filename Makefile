CXX=g++
CXXFLAGS=-std=c++14

all: trie_test

trie_test: trie.o trie_test.o
	${CXX} ${CXXFLAGS} -o $@ $^

clean:
	rm *.o trie_test