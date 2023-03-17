#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isterminal;

    TrieNode(char data){
        this->data = data;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isterminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertintrie(TrieNode* root, string word){
        if(word.length() == 0){
            root->isterminal = true;
            return;
        }

        int index = word[0]-'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertintrie(child, word.substr(1));
    }

    void insert(string word){
        insertintrie(root, word);
        return;
    }

    // -----search

    bool searchintrie(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isterminal;
        }

        int index = word[0]-'a';
        TrieNode* child;

        if(root->children[index]!=NULL)
            child = root->children[index];
        else
            return false;
        
        return searchintrie(child,word.substr(1));
    }

    bool search(string word){
        return searchintrie(root,word);
    }

    // ----------delete

    void deleteintrie(TrieNode* root, string word){
        if(word.length() == 0 ){
            root->isterminal = false;
            cout << "word delete"<<endl;
            return;
        }

        int index = word[0]-'a';
        TrieNode* child;

        if(root->children[index] != NULL)
            child = root->children[index];
        else{
            cout << "Word is not present\n";
            return;
        }
        deleteintrie(child, word.substr(1));
    }
    
    void deleted(string word){
        deleteintrie(root, word);
    }

};


int main(){

    Trie* node = new Trie();
    
    node->insert("dev");
    node->insert("deve");
    node->insert("asdf");
    cout << "success";
    cout << "node is present : " << node->search("de") << endl;
    node->deleted("deve");

    return 0;
}

//making trie by iteration
class Trie {
private:
    class Node{
     public:
        Node* node[26]={};
        bool isword= false;
    };
    
public:
    Node* ROOT;
    Trie() {
        ROOT= new Node();
    }
    //Fixed memory Leak but it will take twice the time.
    ~Trie(){
        // clear(ROOT);
    }
    
    void insert(string word) {
        Node* root = ROOT;
        for(char x: word){
            x-='a';
            if(root->node[x]==NULL){
                root->node[x]= new Node();
            }
            root = root->node[x];
        }
        root->isword= true;
    }
    
    bool search(string word) {
        Node* root = ROOT;
        for(auto i: word){
            char x = i-'a';
            if(root->node[x]!=NULL){
                root = root->node[x];
            }else return false;
        }
        return root->isword;
    }
    
    bool startsWith(string prefix) {
        Node* root = ROOT;
        for(auto i: prefix){
            char x = i-'a';
            if(root->node[x]!=NULL){
                root = root->node[x];
            }else return false;
        }
        return root!=NULL;
    }
    
    void clear(Node* root){
        for(int i=0; i<26; i++){
            if(root->node[i]!= nullptr){
                clear(root->node[i]);
            }
        }
        cout<<root<<" ";
        delete root;
    }
};