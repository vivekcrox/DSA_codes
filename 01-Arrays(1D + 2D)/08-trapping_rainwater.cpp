class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        //1. store leftMax height and rightMax height
        vector<int> leftMax(n, 0);
        leftMax[0] = height[0];
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        vector<int> rightMax(n, 0);
        rightMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        //2. iterate over height array and calc water (*ignoring 0th and last height)
        int water = 0;
        for(int i=1; i<n-1; i++){
            water += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return water;
    }
};
