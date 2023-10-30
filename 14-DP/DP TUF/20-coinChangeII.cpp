class Solution {
public:
    int solveRec(vector<int>&coins, int i, int target){
        if(i==0){
            if(target % coins[i] == 0)
                return 1;
            return 0;
        }

        int excl = solveRec(coins, i-1, target);
        int incl = 0;
        if(target-coins[i] >= 0)
            incl = solveRec(coins, i, target-coins[i]);
        return incl + excl;
    }

    int solveSO(vector<int>&coins, int n, int target){
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);

        for(int t=0; t<=target; t++){
            if(t%coins[0] == 0) prev[t] = 1;
        }

        for(int i=1; i<n; i++){
            for(int t=0; t<=target; t++){
                int excl = prev[t];
                int incl = 0;
                if(t-coins[i] >= 0)
                    incl = curr[t-coins[i]];  
                curr[t] = incl + excl;
            }
            prev = curr;
        }


        return prev[target];
    }


    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // return solveRec(coins, n-1, amount);
        return solveSO(coins, n, amount);
    }
};