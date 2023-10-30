// Length of a char array
int getLength(char ch[]){
    int length = 0;
    int i = 0;
    while(ch[i] != '\0'){
        length++;
        i++;
    }
    return length;
}

// Reverse a char array
void revCharArray(char ch[]){
    int s = 0;
    int e = strlen(ch)-1;
    while(s <= e){
        swap(ch[s], ch[e]);
        s++;
        e--;
    }
}

// Replace all spaces by '@'
void replaceWith(char ch[]){
    int i = 0;
    int n = strlen(ch);

    while(i < n){
        if(ch[i]==' '){
            ch[i] = '@';
        }
        i++;
    }
}

// Palindrome
bool chkPalindrome(char ch[]){
    int s = 0;
    int e = strlen(ch)-1;

    while(s <= e){
        if(ch[s]!=ch[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}


// Convert into uppercase or lowercase
void toUp(char ch[]){
    for(int i=0; i<strlen(ch); i++){
        if(ch[i]>='a' && ch[i]<='z'){
            ch[i] = ch[i]-'a'+'A';         //convert lower to upper
        }
    }
}
