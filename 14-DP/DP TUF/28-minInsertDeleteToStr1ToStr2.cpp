int lcsSO(string& s1, string& s2, int n, int m){
    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);
    
    for(int j=0; j<=m; j++){
        prev[j] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1])
                curr[j] = 1 + prev[j-1];
            else
                curr[j] = max(prev[j], curr[j-1]);
        }
        prev = curr;
    }
    return prev[m];
}

int minInsertDeleteToConvertS1ToS2(string &s1, string &s2){
    int n = s1.length();
    int m = s2.length();
    return n + m - 2*lcsSO(s1, s2, n, m);
}