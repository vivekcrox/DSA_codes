class Solution {
public:

    bool canDistributeHelper(vector<int>& counts, vector<int>& quantity, int ithCustomer){
        //base
        if(ithCustomer == quantity.size()){
            return true;
        }

        for(int i=0; i<counts.size(); i++){
            if(counts[i] >= quantity[ithCustomer]){
                counts[i] -= quantity[ithCustomer];
                if(canDistributeHelper(counts, quantity, ithCustomer + 1)){
                    return true;
                }
                counts[i] += quantity[ithCustomer];   //backtrack
            }
        }
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> countMap;
        for(auto num: nums){
            countMap[num]++;
        }
        vector<int> counts;
        for(auto it: countMap){
            counts.push_back(it.second);
        }
        
        sort(quantity.rbegin(), quantity.rend());  // sort DESC --> so that check faster if larger quantity not satisfied then it will return faster answer (this optimisation remove TLE from the given sol)
        return canDistributeHelper(counts, quantity, 0);
    }
};