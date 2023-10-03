class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int water = 0;
        int i = 0;
        int j = n-1;

        while(i < j){
            int width = j - i;
            int length = min(height[i], height[j]);

            water = max(water, width*length);

            if(height[i] > height[j])   // badi height will lead more water in future
                j--;
            else
                i++;
        }
        return water;
    }
};
