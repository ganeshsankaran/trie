#ifndef _TRIE_H_
#define _TRIE_H_

#include <set>
#include <string>
#include <unordered_map>

struct TrieNode {
    TrieNode(char key); // Constructor
    ~TrieNode(); // Destructor

    char key;
    bool end;
    std::unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    Trie(); // Constructor 
    ~Trie(); // Destructor

    // Put a string into a trie
    void put(const std::string& string);
    // Get all strings in the trie with a given prefix
    std::set<std::string> get(const std::string& prefix);
private:
    // Get all strings in a subtrie with a given prefix
    void dfs(TrieNode* node, const std::string& prefix);

    TrieNode* root;
    std::set<std::string> strings;
};

#endif