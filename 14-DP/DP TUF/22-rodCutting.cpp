
int solveRec(vector<int>&price, int i, int k){
	//base
	if(i==0) //rod len = 1
		return k*price[0];

	int notTake = 0 + solveRec(price, i-1, k);
	int take = INT_MIN;
	int rodLen = i+1;
	if(rodLen <= k)
		take = price[i] + solveRec(price, i, k-rodLen);

	return max(take, notTake);
}
int solveMem(vector<int>&price, int i, int k, vector<vector<int>>&dp){
	//base
	if(i==0) //rod len = 1
		return k*price[0];
	if(dp[i][k] != -1)
		return dp[i][k];

	int notTake = 0 + solveMem(price, i-1, k, dp);
	int take = INT_MIN;
	int rodLen = i+1;
	if(rodLen <= k)
		take = price[i] + solveMem(price, i, k-rodLen, dp);
	return dp[i][k] = max(take, notTake);
}
int solveTab(vector<int>&price, int size, int k){
	vector<vector<int>> dp(size, vector<int>(k+1, INT_MIN));
	for(int len=0; len<=k; len++){
		dp[0][len] = len*price[0];
	}

	for(int i=1; i<size; i++){
		for(int len=0; len<=k; len++){
			int notTake = 0 + dp[i-1][len];
			int take = INT_MIN;
			int rodLen = i+1;
			if(rodLen <= len)
				take = price[i] + dp[i][len-rodLen];

			dp[i][len] = max(take, notTake);
		}
	}
	return dp[size-1][k];
}
int solveSO(vector<int>&price, int size, int k){
	vector<int> prev(k+1, INT_MIN);
	vector<int> curr(k+1, INT_MIN);
	
	for(int len=0; len<=k; len++){
		prev[len] = len*price[0];
	}

	for(int i=1; i<size; i++){
		for(int len=0; len<=k; len++){
			int notTake = 0 + prev[len];
			int take = INT_MIN;
			int rodLen = i+1;
			if(rodLen <= len)
				take = price[i] + curr[len-rodLen];

			curr[len] = max(take, notTake);
		}
		prev = curr;
	}
	return prev[k];
}

int cutRod(vector<int> &price, int n)
{
	int size = price.size();
	// return solveRec(price, size-1, n);

	// vector<vector<int>> dp(size, vector<int>(n+1, -1));
	// return solveMem(price, size-1, n, dp);

	// return solveTab(price, size, n);
	return solveSO(price, size, n);
}
