#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "trie.h"

int main() {
    std::vector<std::string> strings = {
        "was",
        "what",
        "whom",
        "where",
        "who",
        "war",
        "when",
        "went",
        "why",
        "word"
    };

    Trie trie;
    
    for(auto& string : strings)
        trie.put(string);

    for(auto& string : trie.get("wh"))
        std::cout << string << std::endl;

    return 0;
}