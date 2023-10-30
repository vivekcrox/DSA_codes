class Solution {
public:
    bool isPalindrome(string&s, int i, int j){
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++; j--;
        }
        return true;
    }

    int solveRec(string& s, int i, int n){
        if(i == n)
            return 0;
        
        int minCost = INT_MAX;
        for(int k=i; k<n; k++){
            if(isPalindrome(s, i, k)){
                int cost = 1 + solveRec(s, k+1, n);
                minCost = min(minCost, cost);
            }
        }
        return minCost;
    }
    int solveMem(string& s, int i, int n, vector<int>&dp){
        if(i == n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        
        int minCost = INT_MAX;
        for(int k=i; k<n; k++){
            if(isPalindrome(s, i, k)){
                int cost = 1 + solveMem(s, k+1, n, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }
    int solveTab(string& s, int n){
        vector<int> dp(n+1, 0);
        dp[n] = 0;

        for(int i=n-1; i>=0; i--){
            int minCost = INT_MAX;
            for(int k=i; k<n; k++){
                if(isPalindrome(s, i, k)){
                    int cost = 1 + dp[k+1];;
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0];
    }

    int minCut(string s) {  //based on : front partitioning.
        int n = s.size();
        // return solveRec(s, 0, n) - 1;   //-1 as abc| at last char c after there is a partition call.
        
        // vector<int> dp(n, -1);
        // return solveMem(s, 0, n, dp) - 1;

        return solveTab(s, n) - 1;
    }
};

/*************************************************************/

/* palindrome Partitioning - I : 
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]] */

class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        //Checks for palindrome
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void func(int index, string s, vector<string> &path, vector<vector<string>> &res){
        if(index == s.size()){
            res.push_back(path);
            return;
        }

        for(int i=index;i<s.size();i++){
            //Check if next indices forms a palindrome
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                //Check if index can be further divided into palindrome
                func(i+1,s,path,res);
                //Backtracking
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(0,s,path,res);
        return res;
    }
};