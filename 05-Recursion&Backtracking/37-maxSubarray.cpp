class Solution {
public:

    int maxSumDnC(vector<int>& v, int start, int end){
        if(start == end)
            return v[start];
        
        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
        int mid = start + ((end-start)>>1);

        int maxLeftSum = maxSumDnC(v,start,mid);
        int maxRightSum = maxSumDnC(v,mid+1,end);

        //Max Cross Border Sum
        int leftBorderSum = 0, rightBorderSum = 0;
        for(int i=mid; i>=start; i--){
            leftBorderSum += v[i];
            if(leftBorderSum > maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
            }
        }

        for(int i=mid+1; i<=end; i++){
            rightBorderSum += v[i];
            if(rightBorderSum > maxRightBorderSum){
                maxRightBorderSum = rightBorderSum;
            }
        }

        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

        return max(crossBorderSum, max(maxLeftSum, maxRightSum));
    }

    int maxSubArray(vector<int>& nums) {

        //Brute Force O(n3)
        // int n = nums.size();
        // int maxi = INT_MIN;
        // int sum = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         sum = 0;
        //         for(int k=i; k<=j; k++){
        //             sum += nums[k];
                    
        //         }
        //         maxi = max(maxi, sum);
        //     }
        // }
        // return maxi;

        //Solution 2 O(n2)
        // int n = nums.size();
        // int maxi = INT_MIN;
        // int sum = 0;
        // for(int i=0; i<n; i++){
        //     sum = 0;
        //     for(int j=i; j<n; j++){
        //         sum += nums[j];
        //         maxi = max(maxi, sum);
        //     }
        // }
        // return maxi;

        //Kadane's algo O(n)
        // int n = nums.size();
        // int maxi = nums[0];
        // int sum = 0;

        // for(int i=0; i<n; i++){
        //     sum += nums[i];
        //     maxi = max(maxi, sum);

        //     if(sum < 0){
        //         sum = 0;
        //     }
        // }
        // return maxi;

        //Divide & Conquer approach: T.C = O(nlogn) | S.C = O(logn)
        return maxSumDnC(nums, 0, nums.size()-1);
    }
};