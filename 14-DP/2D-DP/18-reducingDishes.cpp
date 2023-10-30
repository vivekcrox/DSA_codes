class Solution {
public:
    int solveRec(vector<int>& satisfaction, int index, int time){
        if(index >= satisfaction.size())
            return 0;
        
        int include = satisfaction[index]*(time+1) + solveRec(satisfaction, index+1, time+1);
        int exclude = 0 + solveRec(satisfaction, index+1, time);

        return max(include, exclude);
    }

    int solveMem(vector<int>& satisfaction, int index, int time, vector<vector<int>>& dp){
        if(index >= satisfaction.size())
            return 0;
        if(dp[index][time] != -1)
            return dp[index][time];

        int include = satisfaction[index]*(time+1) + solveMem(satisfaction, index+1, time+1, dp);
        int exclude = 0 + solveMem(satisfaction, index+1, time, dp);

        return dp[index][time] = max(include, exclude);
    }

    int solveTab(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int index = n-1; index>=0; index--){
            for(int time = index; time>=0; time--){
                int include = satisfaction[index]*(time+1) + dp[index+1][time+1];
                int exclude = 0 + dp[index+1][time];

                dp[index][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int solveSO(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int index = n-1; index>=0; index--){
            for(int time = index; time>=0; time--){
                int include = satisfaction[index]*(time+1) + next[time+1];
                int exclude = 0 + next[time];

                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }
    /* Greedy approach */
    int maxSatisfaction1(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int ans=0;
        for(int i=0;i<satisfaction.size();i++){
            int sum=0;
            int count=1;
            for(int j=i;j<satisfaction.size();j++){
              sum+=satisfaction[j]*count;
              count++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());   // to get max sum
        // return solveRec(satisfaction, 0, 0);

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveMem(satisfaction, 0, 0, dp);

        // return solveTab(satisfaction);
        // return solveSO(satisfaction);

        return maxSatisfaction1(satisfaction);
    }
};