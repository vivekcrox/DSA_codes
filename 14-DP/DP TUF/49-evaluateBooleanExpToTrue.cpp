#include <bits/stdc++.h> 
#define mod 1000000007

long long solveRec(string& exp, long long i, long long j, long long isTrue){
    if(i > j)
        return 0;
    if(i == j){
        if(isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }

    long long ways = 0;
    for(long long k=i+1; k<j; k+=2){
        long long lT = solveRec(exp,i,k-1,1);
        long long lF = solveRec(exp,i,k-1,0);
        long long rT = solveRec(exp,k+1,j,1);
        long long rF = solveRec(exp,k+1,j,0);

        if(exp[k] == '&'){
            if(isTrue)
                ways += (lT*rT)%mod;
            else
                ways += (lT*rF)%mod + (lF*rT)%mod + (lF*rF)%mod;
        }
        else if(exp[k] == '|'){
            if(isTrue)
                ways += (lT*rF)%mod + (lF*rT)%mod + (lT*rT)%mod;
            else
                ways += (lF*rF)%mod;
        }
        else{
            if(isTrue)
                ways += (lT*rF)%mod + (lF*rT)%mod;
            else
                ways += (lT*rT)%mod + (lF*rF)%mod;
        }
    }
    return ways;
}
long long solveMem(string& exp, long long i, long long j, long long isTrue, vector<vector<vector<long long>>>&dp){
    if(i > j)
        return 0;
    if(i == j){
        if(isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }
    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    long long ways = 0;
    for(long long k=i+1; k<j; k+=2){
        long long lT = solveRec(exp,i,k-1,1);
        long long lF = solveRec(exp,i,k-1,0);
        long long rT = solveRec(exp,k+1,j,1);
        long long rF = solveRec(exp,k+1,j,0);

        if(exp[k] == '&'){
            if(isTrue)
                ways = (ways + (lT*rT)%mod)%mod;
            else
                ways = (ways + (lT*rF)%mod + (lF*rT)%mod + (lF*rF)%mod)%mod;
        }
        else if(exp[k] == '|'){
            if(isTrue)
                ways = (ways + (lT*rF)%mod + (lF*rT)%mod + (lT*rT)%mod)%mod;
            else
                ways = (ways + (lF*rF)%mod)%mod;
        }
        else{
            if(isTrue)
                ways = (ways + (lT*rF)%mod + (lF*rT)%mod)%mod;
            else
                ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
        }
    }
    return dp[i][j][isTrue] = ways%mod;
}

int evaluateExp(string & exp) {
    long long n = exp.size();
    long long isTrue = 1;
    // return solveRec(exp, 0, n-1, isTrue);

    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return (int) solveMem(exp, 0, n-1, isTrue, dp);
}