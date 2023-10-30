// Apply LCS function on : original string and its reversed string.
class Solution {
public:
    int solveSO(string& text1, string& text2){
        vector<int> curr(text2.length()+1, 0);
        vector<int> next(text2.length()+1, 0);

        for(int i=text1.length()-1; i>=0; i--){
            for(int j=text2.length()-1; j>=0; j--){
                int ans = 0;
                if(text1[i] == text2[j])   
                    ans = 1 + next[j+1];
                else{
                    ans = 0 + max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            //shifting
            next = curr;
        }
        return next[0];
    }

    int longestPalindromeSubseq(string s) {
        string first = s;
        reverse(s.begin(), s.end());
        string second = s;

        return solveSO(first, second);
    }
};