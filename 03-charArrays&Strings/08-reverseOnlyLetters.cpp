 string reverseOnlyLetters(string s) {
        int l = 0, h = s.length()-1;

        while(l < h){
            if(isalpha(s[l]) && isalpha(s[h])){
                swap(s[l], s[h]);
                l++;
                h--;
            }else if(!isalpha(s[l])){
                l++;
            }else{
                h--;
            }
        }
        return s;
    }