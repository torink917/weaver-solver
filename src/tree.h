#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>


struct Node{
    std::string word; 
    std::vector<Node*> children;
    Node* parent;
    Node(std::string word);};

class Tree{
    Node*target_node;
    std::string target;
    Node* root;
    std::unordered_set<std::string> used_words;
    public:
    Tree(std::string word);
    void word_used(std::string word);
    Node* new_child(Node*parent,std::string word);
    void set_target(std::string last);
    void create_tree(std::unordered_set<std::string> &words);

    std::vector<Node*> create_children(Node*parent, std::unordered_set<std::string> &words);
    std::vector<std::string> find_path();
};
