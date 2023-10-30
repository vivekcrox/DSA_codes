class Solution
{
    public:
    int solveRec(int capacity, int wt[], int val[], int n){
        //base
        if(n==0){
            if(wt[0] <= capacity)
                return val[0];
            return 0;
        }
        
        int incl = 0;
        if(wt[n] <= capacity)
            incl = val[n] + solveRec(capacity - wt[n], wt, val, n-1);
        int excl = 0 + solveRec(capacity, wt, val, n-1);
        
        return max(incl, excl);
    }
    
    int solveMem(int capacity, int wt[], int val[], int n, vector<vector<int>>& dp){
        //base
        if(n==0){
            if(wt[0] <= capacity)
                return val[0];
            else
                return 0;
        }
        if(dp[n][capacity] != -1)
            return dp[n][capacity];
        
        int incl = 0;
        if(wt[n] <= capacity)
            incl = val[n] + solveMem(capacity - wt[n], wt, val, n-1, dp);
        int excl = 0 + solveMem(capacity, wt, val, n-1, dp);
        
        dp[n][capacity] = max(incl, excl);
        return dp[n][capacity];
    }
    
    int solveTab(int capacity, int wt[], int val[], int n){
        vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
        for(int w=wt[0]; w<=capacity; w++){
            if(wt[0] <= capacity)
                dp[0][w] = val[0];
            else
                dp[0][w] = 0;
        }
        
        for(int index=1; index<n; index++){
            for(int w=0; w<=capacity; w++){
                int incl = 0;
                if(wt[index] <= w)
                    incl = val[index] + dp[index-1][w-wt[index]];
                int excl = 0 + dp[index-1][w];
                
                dp[index][w] = max(excl, incl);
            }
        }
        return dp[n-1][capacity];
    }
    
    int solveSO(int capacity, int wt[], int val[], int n){
        vector<int> prev(capacity+1, 0);
        vector<int> curr(capacity+1, 0);
        
        for(int w=wt[0]; w<=capacity; w++){
            if(wt[0] <= capacity)
                prev[w] = val[0];
            else
                prev[w] = 0;
        }
        
        for(int index=1; index<n; index++){
            for(int w=0; w<=capacity; w++){
                int incl = 0;
                if(wt[index] <= w)
                    incl = val[index] + prev[w-wt[index]];
                int excl = 0 + prev[w];
                
                curr[w] = max(excl, incl);
            }
            //shifting
            prev = curr;
        }
        return prev[capacity];
    }
    
    int solveSO2(int capacity, int wt[], int val[], int n){
        
        vector<int> curr(capacity+1, 0);
        
        for(int w=wt[0]; w<=capacity; w++){
            if(wt[0] <= capacity)
                curr[w] = val[0];
            else
                curr[w] = 0;
        }
        
        for(int index=1; index<n; index++){
            for(int w=capacity; w>=0; w--){
                int incl = 0;
                if(wt[index] <= w)
                    incl = val[index] + curr[w-wt[index]];
                int excl = 0 + curr[w];
                
                curr[w] = max(excl, incl);
            }
        }
        return curr[capacity];
    }
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   return solveRec(W, wt, val, n-1);
    
        //  vector<vector<int>> dp(n, vector<int>(W+1, -1));
        //  return solveMem(W, wt, val, n-1, dp);
        
        // return solveTab(W, wt, val, n);   //// n-> pass krna h iss func m.
        
        // return solveSO(W, wt, val, n);
        
        return solveSO2(W, wt, val, n);
        
    }
};