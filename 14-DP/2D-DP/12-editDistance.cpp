class Solution {
public:
    int solveRec(string& word1, string& word2, int i, int j){
        if(i >= word1.length())
            return word2.length() - j;
        if(j >= word2.length())
            return word1.length() - i;
        
        int ans = 0;
        if(word1[i] == word2[j])
            ans = 0 + solveRec(word1, word2, i+1, j+1);
        else{
            int insert = 1 + solveRec(word1, word2, i, j+1);
            int deleted = 1 + solveRec(word1, word2, i+1, j);
            int replace = 1 + solveRec(word1, word2, i+1, j+1);

            ans = min(insert, min(deleted, replace));
        }
        return ans;
    }

    int solveMem(string& word1, string& word2, int i, int j, vector<vector<int>>& dp){
        if(i >= word1.length())
            return word2.length() - j;
        if(j >= word2.length())
            return word1.length() - i;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        if(word1[i] == word2[j])
            ans = 0 + solveMem(word1, word2, i+1, j+1, dp);
        else{
            int insert = 1 + solveMem(word1, word2, i, j+1, dp);
            int deleted = 1 + solveMem(word1, word2, i+1, j, dp);
            int replace = 1 + solveMem(word1, word2, i+1, j+1, dp);

            ans = min(insert, min(deleted, replace));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveTab(string& word1, string& word2){
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));

        for(int j=0; j<=word2.length(); j++){
            dp[word1.length()][j] = word2.length() - j;
        }
        for(int i=0; i<=word1.length(); i++){
            dp[i][word2.length()] = word1.length() - i;
        }

        for(int i=word1.length()-1; i>=0; i--){
            for(int j=word2.length()-1; j>=0; j--){
                int ans = 0;
                if(word1[i] == word2[j])
                    ans = 0 + dp[i+1][j+1];
                else{
                    int insert = 1 + dp[i][j+1];
                    int deleted = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];

                    ans = min(insert, min(deleted, replace));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveSO(string& word1, string& word2){
        vector<int> curr(word2.length()+1, 0);
        vector<int> next(word2.length()+1, 0);

        for(int j=0; j<=word2.length(); j++){
            next[j] = word2.length() - j;
        }
        

        for(int i=word1.length()-1; i>=0; i--){
            //every row starts here. //yaha galti karunga
            curr[word2.length()] = word1.length()-i;

            for(int j=word2.length()-1; j>=0; j--){
                int ans = 0;
                if(word1[i] == word2[j])
                    ans = 0 + next[j+1];
                else{
                    int insert = 1 + curr[j+1];
                    int deleted = 1 + next[j];
                    int replace = 1 + next[j+1];

                    ans = min(insert, min(deleted, replace));
                }
                curr[j] = ans;
            }
            //shifting
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        // return solveRec(word1, word2, 0, 0);

        // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        // return solveMem(word1, word2, 0, 0, dp);

        // return solveTab(word1, word2);
        return solveSO(word1, word2);
    }
};