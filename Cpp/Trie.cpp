#include "header.h"

string toLowerCase(string word){
    for (int i = 0; i < word.length(); i++)
        word[i] = tolower(word[i]);
    return word;
}

class Node {
private:
    char data;
    bool isTerminal;
    int numCharacters;

public:
    Node** characters;
    Node(int n = 26) {
        data = '\0';
        numCharacters = n;
        characters = new Node*[numCharacters];
        for (int i = 0; i < numCharacters; i++)
            characters[i] = nullptr;
        isTerminal = false;
    }

    Node(char ch, int n = 26) {
        data = ch;
        numCharacters = n;
        characters = new Node*[numCharacters];
        for (int i = 0; i < numCharacters; i++)
            characters[i] = nullptr;
        isTerminal = false;
    }

    void setData(char ch) { data = ch; }
    char getData() { return data; }
    void setTerminal(bool terminal) { isTerminal = terminal; }
    bool isTerminalfn() { return isTerminal; }
    int getSize() { return numCharacters; }
};

class Trie{
    Node* head;
public:
    Trie(){
        head = new Node();
    }
    void insert(string word){ insertValue(head, word); }
    void display() { 
        displayValues(head, ""); 
        cout << endl;
    }

    void search(string word) { 
        string result = searchValue(head, word) ? " is present in trie" : " is not present in the trie";
        cout << word << result << endl;
    }

    void remove(string word) { 
        string result = searchValue(head, word, true) ? " deleted successfully from the trie" : " is not present in the trie";
        cout << word << result << endl;
    }

    void insertValue(Node* root, string word) {
        if(root == nullptr) return;

        char firstCharacter = word[0];
        int index = firstCharacter - 'a';

        Node* child;

        if(root->characters[index] != nullptr){
            child = root->characters[index];
        }
        else{
            child = new Node(firstCharacter);
            root->characters[index] = child;
        }

        if(word.length() == 1) child->setTerminal(true);
        else if(word.length() > 1) insertValue(child, word.substr(1));
    }

    bool searchValue(Node* root, string word, bool deleteWord = false){
        if(root == nullptr) return false;
        if(word.empty()) {
            if(deleteWord){
                if(root->isTerminalfn()) root->setTerminal(false);
                
                for(int i=0; i < root->getSize(); i++)
                    if(root->characters[i] != nullptr) return true;
                delete root;

                return true;
            } 
            else return root->isTerminalfn();
        }

        char firstCharacter = word[0];
        int index = firstCharacter - 'a';

        return searchValue(root->characters[index], word.substr(1), deleteWord);
    }

    void displayValues(Node* root, string word) {
        if(root == nullptr) return;

        word += root->getData();

        if(root->isTerminalfn()) cout << word << ", ";

        for (int i = 0; i < root->getSize(); i++){
            if(root->characters[i]){
                displayValues(root->characters[i], word);
            }
        }
    }
};

int main(){
    Trie t;
    int n = 0;
    string s;

    do {
        cout << "1. Insert \t2. Delete \t3. Search \t4. Display \t5. Exit" << endl;
        cout << "Enter number from following : ";
        cin >> n;
        switch (n) {
            case 1:
                cout << "Enter word to insert : ";
                cin >> s;
                t.insert(s);
                break;
            
            case 2:
                cout << "Enter word to delete : ";
                cin >> s;
                t.remove(s);
                break;
            
            case 3:
                cout << "Enter word to search : ";
                cin >> s;
                t.search(s);
                break;

            case 4:
                t.display();
                break;
            
            case 5:
                cout << "Exiting!" << endl;
                break;
            
            default:
                cout << "Enter a valid number" << endl;
                break;
        }
        cout << endl;
    } while (n!=5);

    return 0;
}