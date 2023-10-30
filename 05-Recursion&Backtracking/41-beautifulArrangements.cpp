class Solution {
public:
    void solve(vector<int>& v, int& n, int& ans, int curNum){
        if(curNum == n+1){
            ans++;
            return;
        }

        for(int i=1; i<=n; i++){
            if(v[i] == 0 && (curNum%i == 0 || i%curNum == 0)){
                v[i] = curNum;
                solve(v,n,ans,curNum+1);
                v[i] = 0; //backtrack
            }
        }
    }

    int countArrangement(int n) {
        vector<int> v(n+1);
        int ans = 0;

        solve(v, n, ans,1);
        return ans;
    }
};