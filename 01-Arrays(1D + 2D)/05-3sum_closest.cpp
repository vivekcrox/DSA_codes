class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int closestSum = 1e9;
        for(int k=0; k<n; k++){
            int i = k+1;
            int j = n-1;

            while(i < j){
                int sum = nums[k] + nums[i] + nums[j];

                if(abs(target - sum) < abs(target - closestSum)){
                    closestSum = sum;
                }  

                if(sum > target)    // try to reach closest to target
                    j--;
                else
                    i++;
            }
        }
        return closestSum;
    }
};
