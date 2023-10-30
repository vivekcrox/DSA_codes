int binSearch(vector<int> arr, int s, int e, int k){
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid]==k){
                return mid;
            }
            else if(arr[mid]>k){
                e = mid - 1;
            }
            else 
                s = mid + 1;
            
            mid = s + (e-s)/2;
        }
        return -1;
    }
    
    int getPivot(vector<int> nums){   //assume pivot is minimum number
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e-s)/2;
        while(s<e){
            if(nums[mid] >= nums[0]){
                s = mid+1;
            }
            else
                e = mid;
            mid = s + (e-s)/2;
            
        }
        return s;
    }
    
    int getPivotMax(vector<int> nums){
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e-s)/2;
        while(s<e){
            if(mid+1 < nums.size() && nums[mid] > nums[mid+1]){
                return mid;
            }
            if(mid-1 >= 0 && nums[mid-1] > nums[mid]){
                return mid-1; 
            }

            if(nums[s] >= nums[mid]){
                e = mid-1;
            }
            else{
                s = mid;
            }
            mid = s + (e-s)/2;
        }
        return s;
    }

    int search(vector<int>& nums, int target) {
        // int pivot = getPivot(nums);
        
        // if(target >= nums[pivot] && target <= nums[nums.size()-1]){
        //     return binSearch(nums, pivot, nums.size()-1, target);
        // }
        // else{
        //     return binSearch(nums, 0, pivot-1, target);
        // }

        // pivot as maximum number
        int pivot = getPivotMax(nums);
        
        if(target >= nums[0] && target <= nums[pivot]){
            return binSearch(nums, 0, pivot, target);
        }
        else if(pivot+1 < nums.size() && target >= nums[pivot+1] && target <= nums[nums.size()-1]){
            return binSearch(nums, pivot+1, nums.size()-1, target);
        }
        return -1;
    }