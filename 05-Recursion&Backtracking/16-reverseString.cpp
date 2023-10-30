void revString(string& str, int s, int e){
    if(s >= e){
        return;
    }

    swap(str[s], str[e]);
    revString(str,s+1,e-1);
}