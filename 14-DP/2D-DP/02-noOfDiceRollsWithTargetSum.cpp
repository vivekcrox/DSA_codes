#define MOD 1000000007
class Solution {
public:
    int solveRec(int n, int k, int target){
        //base
        if(target < 0) return 0;
        if(n==0 && target==0) return 1;
        if(n==0 && target!=0) return 0;
        if(n!=0 && target==0) return 0;

        int ans = 0;
        for(int i=1; i<=k; i++){
            ans = (ans + numRollsToTarget(n-1, k, target-i))%MOD;
        }   
        return ans;
    }

    int solveMem(int n, int k, int target, vector<vector<int>>& dp){
        //base
        if(target < 0) return 0;
        if(n==0 && target==0) return 1;
        if(n==0 && target!=0) return 0;
        if(n!=0 && target==0) return 0;

        if(dp[n][target] != -1)
            return dp[n][target];

        int ans = 0;
        for(int i=1; i<=k; i++){
            ans = (ans + solveMem(n-1, k, target-i, dp))%MOD;
        }   
        dp[n][target] = ans;
        return dp[n][target];
    }

    int solveTab(int n, int k, int target){
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    
        dp[0][0] = 1;

        for(int dice=1; dice<=n; dice++){ //n
            for(int t=1; t<=target; t++){  // target
                int ans = 0;
                for(int i=1; i<=k; i++){
                    if(t-i >= 0)
                        ans = (ans + dp[dice-1][t-i])%MOD;
                }   
                dp[dice][t] = ans;
            }
        }
        return dp[n][target];
    }

    int solveSO(int n, int k, int target){
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);
    
        prev[0] = 1;  // initially prev array points to 0th row

        for(int dice=1; dice<=n; dice++){ //n
            for(int t=1; t<=target; t++){  // target
                int ans = 0;
                for(int i=1; i<=k; i++){
                    if(t-i >= 0)
                        ans = (ans + prev[t-i])%MOD;
                }   
                curr[t] = ans;
            }
            //shifting
            prev = curr;
        }
        return curr[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // return solveRec(n,k,target);

        // vector<vector<int> > dp(n+1, vector<int>(target+1, -1));
        // return solveMem(n, k, target, dp);

        // return solveTab(n, k, target);

        return solveSO(n,k,target);
    }
};