class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Approach 1 : Brute force
        // int n = nums.size();
        // set<vector<int>> st;

        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         for(int k=j+1; k<n; k++){
        //             int sum = nums[i] + nums[j] + nums[k];
        //             if(sum == 0){
        //                 vector<int> temp = {nums[i], nums[j], nums[k]};
        //                 sort(begin(temp), end(temp));
        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;

        /*********/
        // Approach 2 : Using map
        // int n = nums.size();
        // sort(nums.begin(), nums.end());

        // set<vector<int>> st;

        // for(int i=0; i<n; i++){
        //     set<int> temp;
        //     for(int j=i+1; j<n; j++){
        //         int third = -(nums[i] + nums[j]);
                
        //         if(temp.find(third) != temp.end()){
        //             vector<int> temp = {nums[i], nums[j], third};
        //             st.insert(temp);
        //         }

        //         temp.insert(nums[j]);
        //     }
        // }

        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;

        /********/
        // Approach 3: using 2 ptr
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        set<vector<int>> st;
        
        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1])   // to avoid duplicate
                continue;
            
            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0){
                    st.insert({nums[i], nums[j], nums[k]});

                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]){  // to avoid duplicacy
                        j++;
                    }
                    while(j < k && nums[k] == nums[k+1]){  // to avoid duplicacy
                        k--;
                    }
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
