class Solution{
public:
    int solveRec(int wt[], int val[], int i, int W){
        //base
        if(i==0)
            return (int)(W/wt[0])*val[0] ;
        
        int take =  0;
        if(wt[i] <= W){
            take = val[i] + solveRec(wt, val, i, W-wt[i]);
        }
        int notTake = 0 + solveRec(wt, val, i-1, W);
        
        return max(take, notTake);
    }
    int solveMem(int wt[], int val[], int i, int W, vector<vector<int>>&dp){
        //base
        if(i==0)
            return (int)(W/wt[0])*val[0] ;
        if(dp[i][W] != -1)
            return dp[i][W];
            
        int take =  0;
        if(wt[i] <= W){
            take = val[i] + solveMem(wt, val, i, W-wt[i], dp);
        }
        int notTake = 0 + solveMem(wt, val, i-1, W, dp);
        
        return dp[i][W] = max(take, notTake);
    }
    int solveTab(int wt[], int val[], int N, int W){
        vector<vector<int>> dp(N, vector<int>(W+1, 0));
        for(int w=0; w<=W; w++){
            dp[0][w] = (int)(w/wt[0])*val[0];
        }
        
        for(int i=1; i<N; i++){
            for(int w=0; w<=W; w++){
                int take =  0;
                if(wt[i] <= w){
                    take = val[i] + dp[i][w-wt[i]];
                }
                int notTake = 0 + dp[i-1][w];
                
                dp[i][w] = max(take, notTake);
                
            }
        }
        return dp[N-1][W];
    }
    int solveSO1(int wt[], int val[], int N, int W){
        vector<int> prev(W+1, 0);
        vector<int> curr(W+1, 0);
        
        for(int w=0; w<=W; w++){
            prev[w] = (int)(w/wt[0])*val[0];
        }
        
        for(int i=1; i<N; i++){
            for(int w=0; w<=W; w++){
                int take =  0;
                if(wt[i] <= w){
                    take = val[i] + curr[w-wt[i]];
                }
                int notTake = 0 + prev[w];
                
                curr[w] = max(take, notTake);
                
            }
            prev = curr;
        }
        return prev[W];
    }
    int solveSO2(int wt[], int val[], int N, int W){
        vector<int> curr(W+1, 0);
        
        for(int w=0; w<=W; w++){
            curr[w] = (int)(w/wt[0])*val[0];
        }
        
        for(int i=1; i<N; i++){
            for(int w=0; w<=W; w++){
                int take =  0;
                if(wt[i] <= w){
                    take = val[i] + curr[w-wt[i]];
                }
                int notTake = 0 + curr[w];
                
                curr[w] = max(take, notTake);
                
            }
        }
        return curr[W];
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        // return solveRec(wt, val, N-1, W);
        
        // vector<vector<int>> dp(N, vector<int>(W+1, -1));
        // return solveMem(wt, val, N-1, W, dp);
        
        // return solveTab(wt, val, N, W);
        // return solveSO1(wt, val, N, W);
        return solveSO2(wt, val, N, W);
    }
};