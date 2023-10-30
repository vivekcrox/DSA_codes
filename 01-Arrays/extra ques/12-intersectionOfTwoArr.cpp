class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // set<int> ans;
        // for(int i=0; i<nums1.size(); i++){
        //     for(int j=0; j<nums2.size(); j++){
        //         if(nums1[i]==nums2[j]){
        //             ans.insert(nums1[i]);
        //             nums2[j] = -1;
        //             break;
        //         }
        //     }
        // }
        // vector<int> res;
        // for(auto i:ans)
        //     res.push_back(i);
        // return res;

        // 2. two pointer
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        set<int> st;
        int i=0, j=0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i]==nums2[j]){
                st.insert(nums1[i]);
                i++; j++;
            }
            else if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        // store unique ans
        vector<int> ans;
        for(auto i:st)
            ans.push_back(i);
        return ans;
    }
};