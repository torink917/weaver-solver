#include "tree.h"

int main(){
    //Get start word
    std::cout<<"Enter starting word:";
    std::string start_word;
    std::cin>>start_word;
    
    //Get end word
    std::cout<<"Enter ending word:";
    std::string end_word;
    std::cin>>end_word;

    //Open file
    if(start_word.length()!=end_word.length())
        std::cout<<"Words are different length"<<std::endl;
    std::ifstream file; 
    if(start_word.length()==4)
        file.open("words4.txt");
    else if(start_word.length()==5)
        file.open("words5.txt");
    if (!file.is_open()) {
        std::cout << "Could not open the file\n";
        return 1;}
    //Create vector of all 4-letter words
    std::unordered_set<std::string> words;
    std::string line;
    while (std::getline(file, line)) {
        words.insert(line);}
    
    
    
    


    Tree tree(start_word);
    tree.set_target(end_word);
    tree.create_tree(words);
    std::vector<std::string> path=tree.find_path();
    for(auto word:path){
        std::cout<<word<<"\n";
    }


    



    
    file.close();
    return 0;}
    
    








