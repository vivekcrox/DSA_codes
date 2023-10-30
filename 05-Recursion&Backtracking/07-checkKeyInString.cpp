bool checkKey(string& str, int i, char& key){
    if(i == str.length()){
        return false;
    }

    if(str[i]==key){
        return true;
    }
    return checkKey(str,i+1,key);
}