bool chkPalindrome(string& str, int s, int e){
    if(s >= e){
        return true;
    }

    if(str[s]!=str[e]){
        return false;
    }
    return chkPalindrome(str,s+1,e-1);
}