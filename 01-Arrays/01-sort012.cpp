void sortColors(vector<int>& nums) {
        //I) sort()
        // sort(nums.begin(), nums.end());

        //II) counting approach
        // int zeros = 0, ones = 0, twos = 0;
        // int i = 0;
        // while(i < nums.size()){
        //     if(nums[i]==0)
        //         zeros++;
        //     else if(nums[i]==1)
        //         ones++;
        //     else
        //         twos++;
        //     i++;
        // }

        // i=0;
        // while(zeros--){
        //     nums[i++] = 0;
        // }
        // while(ones--){
        //     nums[i++] = 1;
        // }
        // while(twos--){
        //     nums[i++] = 2;
        // }

        //III) 3 ptr
        int l=0, m=0, h=nums.size()-1;
        while(m <= h){
            if(nums[m]==0){
                swap(nums[l++], nums[m++]);
            }
            else if(nums[m]==1){
                m++;
            }
            else{
                swap(nums[m], nums[h--]);
            }
        }
    }