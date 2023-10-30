class Solution {
public:
    int solveSO(vector<int>&arr, int n, int k){ //count subset with given target = k.
        vector<int> prev(k+1, 0);
        vector<int> curr(k+1, 0);

        if(arr[0] == 0) 
            prev[0] = 2;
        else 
            prev[0] = 1;
        if(arr[0]!=0 && arr[0]<=k)
            prev[arr[0]] = 1;

        for(int i=1; i<n; i++){
            for(int t=0; t<=k; t++){
                int incl = 0;
                if(t-arr[i] >= 0)
                    incl = prev[t-arr[i]];
                int excl = prev[t];
                curr[t] = incl + excl;
            }  
            prev = curr;                                  
        }

        return prev[k];
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = 0;
        for(int i=0; i<n; i++) totalSum += arr[i];

        if(totalSum - d < 0 || totalSum - d & 1)
            return 0;
        
        return solveSO(arr, n, (totalSum - d)/2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);  //using function: count subsets with given diff = target.
    }
};