class Solution {
public:
    int solveRec(vector<int>& obstacles, int currlane, int currpos){
        if(currpos==obstacles.size()-1)
            return 0;
        
        int ans = INT_MAX;
        if(obstacles[currpos+1] != currlane){
            ans = 0 + solveRec(obstacles, currlane, currpos+1);
        }
        else{
            for(int i=1; i<=3; i++){
                if(currlane != i && obstacles[currpos] != i){
                    ans = min(ans, 1 + solveRec(obstacles, i, currpos));
                }
            }
        }
        return ans;
    }

    int solveMem(vector<int>& obstacles, int currlane, int currpos, vector<vector<int>>& dp){
        if(currpos==obstacles.size()-1)
            return 0;
        
        if(dp[currlane][currpos] != -1)
            return dp[currlane][currpos];

        int ans = INT_MAX;
        if(obstacles[currpos+1] != currlane){
            ans = 0 + solveMem(obstacles, currlane, currpos+1, dp);
        }
        else{  // sideways jump -> there are only 3 lanes.
            for(int i=1; i<=3; i++){
                if(currlane != i && obstacles[currpos] != i){
                    ans = min(ans, 1 + solveMem(obstacles, i, currpos, dp));
                }
            }
        }
        dp[currlane][currpos] = ans;
        return dp[currlane][currpos];
    }

    int solveTab(vector<int>& obstacles){
        int n = obstacles.size()-1;
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));

        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int currpos=n-1; currpos>=0; currpos--){
            for(int currlane=1; currlane<=3; currlane++){
                int ans = 1e9;
                if(obstacles[currpos+1] != currlane){
                    ans = 0 + dp[currlane][currpos+1];
                }
                else{  // sideways jump -> there are only 3 lanes.
                    for(int i=1; i<=3; i++){
                        if(currlane != i && obstacles[currpos] != i){
                            ans = min(ans, 1 + dp[i][currpos+1]);   //catch -> currpos+1 (in case when checking lane from 1 to 3,  tries to 
                            //access that lane ans whose ans yet to be calc(now, 1e9 present), that's why access from its next one.) 
                        }
                    }
                }
                dp[currlane][currpos] = ans;
            }
        }
        return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
    }


    int solveSO(vector<int>& obstacles){
        int n = obstacles.size()-1;
        vector<int> curr(4);
        vector<int> next(4);
        // curr -> next pe dependent h isliye next m update kiya.
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int currpos=n-1; currpos>=0; currpos--){
            for(int currlane=1; currlane<=3; currlane++){
                int ans = 1e9;
                if(obstacles[currpos+1] != currlane){
                    ans = 0 + next[currlane];
                }
                else{  // sideways jump -> there are only 3 lanes.
                    for(int i=1; i<=3; i++){
                        if(currlane != i && obstacles[currpos] != i){
                            ans = min(ans, 1 + next[i]);   
                        }
                    }
                }
                curr[currlane] = ans;
            }
            next = curr;
        }
        return min(next[2], min(1+next[1], 1+next[3]));
    }

    int minSideJumps(vector<int>& obstacles) {
        // return solveRec(obstacles, 2, 0);   //initially frog at 2nd lane of 0th pos.

        // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        // return solveMem(obstacles, 2, 0, dp);

        // return solveTab(obstacles);
        return solveSO(obstacles);
    }
};