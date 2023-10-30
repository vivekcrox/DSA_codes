
int solveRec(int n, int x, int y, int z){
	if(n==0)
		return 0;
	if(n < 0)
		return INT_MIN;
	
	int ans1 = 1 + solveRec(n-x, x, y, z);
	int ans2 = 1 + solveRec(n-y, x, y, z);
	int ans3 = 1 + solveRec(n-z, x, y, z);

	int ans = max(ans1, max(ans2, ans3));
	return ans;
}

int solveMem(int n, int x, int y, int z, vector<int>& dp){
	if(n==0)
		return 0;
	if(n < 0)
		return INT_MIN;
	
	if(dp[n] != -1)
		return dp[n];
	
	int ans1 = 1 + solveMem(n-x, x, y, z, dp);
	int ans2 = 1 + solveMem(n-y, x, y, z, dp);
	int ans3 = 1 + solveMem(n-z, x, y, z, dp);

	dp[n] = max(ans1, max(ans2, ans3));
	return dp[n];
}

int solveTab(int n, int x, int y, int z){
	vector<int> dp(n+1, INT_MIN);
	
	dp[0] = 0;

	for(int i=1; i<=n; i++){
		if(i-x >= 0)
			dp[i] = max(dp[i], dp[i-x]+1);
		if(i-y >= 0)
			dp[i] = max(dp[i], dp[i-y]+1);
		if(i-z >= 0)
			dp[i] = max(dp[i], dp[i-z]+1);
	}
	return dp[n];
	
}

int cutSegments(int n, int x, int y, int z) {
	// int ans = solveRec(n,x,y,z);
	// if(ans < 0)
	// 	return 0;
	// else	
	// 	return ans;

	// vector<int> dp(n+1, -1);
	// int ans = solveMem(n, x, y, z, dp);
	// if(ans < 0)
	// 	return 0;
	// else	
	// 	return ans;

	int ans = solveTab(n, x, y, z);
	if(ans < 0)
		return 0;
	else	
		return ans;
}