class Solution {
public:
    // 1. Rec.
    int fibRec(int n){
        //base case
        if(n==0 || n==1)
            return n;
        
        int ans = fibRec(n-1) + fibRec(n-2);
        return ans;
    }

    // 2. Rec + Memoization
    int topDownSolve(int n, vector<int>& dp){
        //base case
        if(n==0 || n==1)
            return n;
        // step 3: check if ans already exist
        if(dp[n] != -1)
            return dp[n];

        // step 2: replace ans with dp[n] 
        dp[n] = topDownSolve(n-1, dp)+ topDownSolve(n-2, dp);
        return dp[n];
    }

    // 3. Tabulation method
    int bottomUpSolve(int n){
        // step 1: create dp array
        vector<int> dp(n+1, -1);

        // step 2: observe base case
        dp[0] = 0;
        if(n==0)
            return dp[0];  // as size of dp will be -> 1 (return this single val)
        dp[1] = 1;

        // step 3: topDown approach me 'n' kaise travel krra h
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    // 4. Space Optimisation
    int spaceOptSolve(int n){
        int prev2 = 0;
        int prev1 = 1;

        if(n==0)
            return prev2;
        if(n == 1)
            return prev1;

        int curr;
        for(int i=2; i<=n; i++){
            curr = prev1 + prev2;
            // shifting
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }

    int fib(int n) {
        // return fibRec(n);

        // // step1: create dp array
        // vector<int> dp(n+1, -1);
        // int ans = topDownSolve(n, dp);
        // return ans;

        // return bottomUpSolve(n);

        return spaceOptSolve(n);
    }
};