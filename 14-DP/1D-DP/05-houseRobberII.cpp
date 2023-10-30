class Solution {
public:

    int solve(vector<int>& item){
        int n = item. size();
        int prev2 = 0;
        int prev1 = item[0];

        for(int i=1; i<item.size(); i++){
            int include = item[i] + prev2;
            int exclude = 0 + prev1;

            int ans = max(include, exclude);
            //shifting
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;   //yha glti merese glti hoti h....
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        vector<int> first, second;
        for(int i=0; i<n; i++){
            if(i != n-1)    // max sum after excluding last element
                first.push_back(nums[i]);
            if(i != 0)     // max sum after excluding first element
                second.push_back(nums[i]);
        }

        return max(solve(first), solve(second));
    }
};