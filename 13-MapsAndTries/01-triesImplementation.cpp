#include <iostream>
using namespace std;


class TrieNode{
        public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char d) {
                this->data = d;
                for(int i=0; i<26 ; i++) {
                        children[i] = NULL;
                }
                this->isTerminal = false;
        }
};

void insertWord(TrieNode* root, string word) {
        //cout << "Inserting " << word << endl;
   //base case
        if(word.length() == 0) {   // string khtm hogya h. ab upar wapas chalo or last char ke terminal true mark & return
                root->isTerminal = true;
                return;
        }
        
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        //present
        if(root->children[index] != NULL) {     // already wo char present h
                child = root->children[index];
        }
        else {
                //not present
                child = new TrieNode(ch);
                root->children[index] = child;
        }

        //recursion sambhal lega
        insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
                return root->isTerminal;   // last char ka terminal true hoga wo return ho jayega
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else{
                return false;      // child not present searching for that's why false immediately.
        }
        //rec call
        return searchWord(child, word.substr(1));

}
void deleteWord(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
                root->isTerminal = false;    //last char ke terminal ko false mark kr diya then return;
                return;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else{  
            cout<<"Not present"<<endl;   // searching word not present in trie
                return ;
        }
        //rec call
        deleteWord(child, word.substr(1));

}

int main() {
  TrieNode* root = new TrieNode('-');

  //root->insertWord("coding");
  insertWord(root, "coding");
  insertWord(root, "code");
  insertWord(root, "coder");
  insertWord(root, "codehelp");
  insertWord(root, "baba");
  insertWord(root, "baby");
  insertWord(root, "babu");
  insertWord(root, "shona");
  cout << "Searching " << endl;
  if(searchWord(root,"code")) {
          cout << "present" << endl;
  }
  else {
          cout << "absent" << endl;
  }

  cout<<"Deleting "<<endl;
  deleteWord(root, "codehelp");
  if(searchWord(root,"codehelp")) {
          cout << "present" << endl;
  }
  else {
          cout << "absent" << endl;
  }

  

  return 0;
}