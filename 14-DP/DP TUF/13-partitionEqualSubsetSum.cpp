#include<bits/stdc++.h>
bool solveSO(vector<int>&arr, int n, int k){
    vector<bool> prev(k+1, false);
    vector<bool> curr(k+1, false);
    prev[0] = true;
    curr[0] = true;
    if(arr[0] <= k)
        prev[arr[0]] = true;
    
    
    for(int i=1; i<n; i++){
        for(int t=1; t<=k; t++){
            bool notTake = prev[t];
            bool take = false;
            if(arr[i] <= t)
                take = prev[t-arr[i]];
            
            curr[t] = notTake || take;
        }
        prev = curr;
    }
    return prev[k];
}

bool canPartition(vector<int> &arr, int n)
{
	int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if(totalSum & 1)
        return false;
	
	int target = totalSum/2;
	//using the func: chk subset equal to k.
	return solveSO(arr, n, target);
}
