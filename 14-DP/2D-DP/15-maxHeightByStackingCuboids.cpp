class Solution {
public:
    bool check(vector<int>& base, vector<int>& newBox){
        if(base[0] >= newBox[0] && base[1] >= newBox[1] && base[2] >= newBox[2])
            return true;
        else
            return false;
    }
    //Using LIS logic
    int solveSO(vector<vector<int>>& nums){
        vector<int> currRow(nums.size()+1, 0);
        vector<int> next(nums.size()+1, 0);

        for(int curr=nums.size()-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || check(nums[curr], nums[prev])){    // check acc to ques.
                    include = nums[curr][2] + next[curr+1];      // add height of cuboid
                }
                int exclude = next[prev+1];

                currRow[prev+1] = max(include, exclude);
            }
            next = currRow;
        }
        return next[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // sort all dimensions for every cuboid
        for(auto &a: cuboids){
            sort(a.begin(), a.end());
        }

        //sort all cuboids basis on width or length
        sort(cuboids.begin(), cuboids.end());

        return solveSO(cuboids);
    }
};

