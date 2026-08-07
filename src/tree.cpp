#include "tree.h"

Node::Node(std::string word){
    this->word=word;
    parent=nullptr;
}






Tree::Tree(std::string first){
    root=new Node(first);
    word_used(first);}
  
void Tree::word_used(std::string word){
        used_words.insert(word);}



void Tree::set_target(std::string last){
    target=last;}

Node* Tree::new_child(Node*parent,std::string word){
    Node* child=new Node(word);
    parent->children.push_back(child);
    child->parent=parent;
    word_used(word);
    return child;}


void Tree::create_tree(std::unordered_set<std::string>& words) {
    std::queue<Node*> frontier;
    frontier.push(root);                 // root already marked used in the constructor

    while (!frontier.empty()) {
        Node* current = frontier.front();
        frontier.pop();

        std::vector<Node*> children = create_children(current, words);

        for (Node* child : children) {
            if (child->word == target){
                target_node=child;
                return;
            }
            
            frontier.push(child);
        }
    }
}

std::vector<Node*> Tree::create_children(Node*parent, std::unordered_set<std::string> &words){
    std::vector<Node*> ret;
    char alphabet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    std::string word=parent->word;
    std::string change;
    int length=word.length();
    for(int i=0;i<length;i++){
        change=word;
        for(int j=0;j<26;j++){
            change[i]=alphabet[j];
            if (change==word)continue;
            if(used_words.count(change))continue;
            if(!words.count(change))continue;
            ret.push_back(new_child(parent,change));}}
    return ret;}

std::vector<std::string> Tree::find_path() {
    std::vector<std::string> ret;

    if (target_node == nullptr)     // <-- here
        return ret;

    Node* curr = target_node;       // now safe: target_node is non-null
    while (curr != nullptr) {
        ret.push_back(curr->word);
        curr = curr->parent;
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}

