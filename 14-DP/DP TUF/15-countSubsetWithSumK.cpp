#define mod 1000000007
int solveRec(vector<int>&arr, int i, int k){
	//base
	if(i==0){
		if(k==0 && arr[i]==0)
			return 2;
		else if(k==0 || arr[i]==k) 
			return 1;
		return 0;
	}

	int notTake = solveRec(arr, i-1, k);
	int take = 0;
	if(arr[i]<=k)
		take = solveRec(arr, i-1, k-arr[i]);
	
	return (take + notTake)%mod;
}
int solveMem(vector<int>&arr, int i, int k,vector<vector<int>>&dp){
	//base
	if(i==0){
		if(k==0 && arr[i]==0)
			return 2;
		else if(k==0 || arr[i]==k) 
			return 1;
		return 0;
	}
	if(dp[i][k] != -1)
		return dp[i][k];

	int notTake = solveMem(arr, i-1, k, dp);
	int take = 0;
	if(arr[i]<=k)
		take = solveMem(arr, i-1, k-arr[i], dp);
	
	return dp[i][k] = (take + notTake)%mod;
}
int solveTab(vector<int>&arr, int n, int k){
	vector<vector<int>> dp(n, vector<int>(k+1, 0));
	if(arr[0] == 0) 
        dp[0][0] = 2;
    else  				
        dp[0][0] = 1;  //exclude 0th element (as target already 0)
    if(arr[0]!=0 && arr[0]<=k)
        dp[0][arr[0]] = 1;      //include 0th element (as target == nums[0])

	for(int i=1; i<n; i++){
		for(int t=0; t<=k; t++){
		int notTake = dp[i-1][t];
		int take = 0;
		if(arr[i]<=t)
			take = dp[i-1][t-arr[i]];
		
		dp[i][t] = (take + notTake)%mod;

		}
	}
	return dp[n-1][k];
}
int solveSO(vector<int>&arr, int n, int k){
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
		int notTake = prev[t];
		int take = 0;
		if(arr[i]<=t)
			take = prev[t-arr[i]];
		
		curr[t] = (take + notTake)%mod;

		}
		prev = curr;
	}
	return prev[k];
}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	// return solveRec(arr, n-1, k);

	// vector<vector<int>> dp(n, vector<int>(k+1,-1));
	// return solveMem(arr, n-1, k, dp);
	
	// return solveTab(arr, n, k);
	return solveSO(arr, n, k);
}