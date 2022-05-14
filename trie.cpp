#include <utility>

#include "trie.h"

TrieNode::TrieNode(char key) {
    this->key = key;
    this->end = false;
    this->children = std::unordered_map<char, TrieNode*>();
}

TrieNode::~TrieNode() {
    for(auto& child : children) {
        delete child.second;
    }
}

Trie::Trie() {
    this->root = new TrieNode(0);
}

Trie::~Trie() {
    delete root;
}

void Trie::put(const std::string& string) {
    auto node = root;
    // Iterate over each character c in the string
    for(auto& c : string) {
        // If there is no child for c, construct the child
        if(!node->children.count(c)) {
            node->children[c] = new TrieNode(c);
        }
        // Traverse the trie
        node = node->children[c];
    }
    // Mark the node as the end of a string
    node->end = true;
}
    
std::set<std::string> Trie::get(const std::string& prefix) {
    auto node = root;
    // Iterate over each character c in the prefix
    for(auto c : prefix) {
        // If there is no child for c, return the empty set
        if(!node->children.count(c)) {
            return std::set<std::string>();
        }
        // Traverse the trie
        node = node->children[c];
    }
    // Get all strings in the subtrie with the prefix
    this->strings.clear();
    dfs(node, prefix);
    // Return the set of strings
    return this->strings;
}

void Trie::dfs(TrieNode* node, const std::string& prefix) {
    // If the end of a string, add it to the set of strings
    if(node->end) {
        this->strings.insert(prefix);
    }
    // Traverse the subtrie */
    for(auto child : node->children) {
        dfs(child.second, prefix + child.second->key);
    }
}