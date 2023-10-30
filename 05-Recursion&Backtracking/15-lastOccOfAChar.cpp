// method 1: from left to right movement
void lastOccOfChar(string& str, int i, int& ans, char& key){
    if(i==str.size()){
        return;
    }

    if(str[i]==key){
        ans = i;
    }
    lastOccOfChar(str,i+1,ans,key);
}

//method 2: from right to left movement
void lastOccOfChar(string& str, char& key, int i, int& ans){
    if(i < 0){
        return;
    }
    if(str[i]==key){
        ans = i;
        return;
    }
    lastOccOfChar(str,key,i-1,ans);
}