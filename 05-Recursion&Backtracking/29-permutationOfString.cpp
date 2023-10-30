#include<iostream>
using namespace std;

void permutation(string& s, int i){
    if(i >= s.size()){
        cout<<s<<" ";
        return;
    }

    for(int j=i; j<s.size(); j++){
        swap(s[i], s[j]);
        permutation(s,i+1);
        
        //backtracking - to create original string after recursive call  (* no need to backtracking if we pass our string "passed by value, not by reference")
        swap(s[i], s[j]);
    }
}

int main(){
    string s = "abc";
    permutation(s,0);

    return 0;
}