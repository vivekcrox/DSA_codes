//I) Two pointer approach
    vector<int> kClosest(vector<int> arr, int k, int x){
        int l = 0, h = arr.size()-1;
        while(h-l >= k){
            if(x - arr[l] > arr[h] - x){
                l++;
            }else{
                h--;
            }
        }
        // vector<int> ans;
        // for(int i=l; i<=h; i++){
        //     ans.push_back(arr[i]);
        // }
        // return ans;
        //**To save using extra space
        return vector<int>(arr.begin()+l, arr.begin()+h+1);
    }

    // II) Using Binary Search

    int lowerBound(vector<int>& arr, int x){
        int s = 0, e = arr.size()-1;
        int ans = e;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(arr[mid] >= x){
                ans = mid;
                e = mid-1;
            }else if(x > arr[mid]){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
    }

    vector<int> kClosestBS(vector<int> arr, int k, int x){
        int h = lowerBound(arr,x);
        int l = h-1;
        while(k--){
            if(l < 0){
                h++;
            }else if(h >= arr.size()){
                l--;
            }else if(x-arr[l] > arr[h]-x){
                h++;
            }else{
                l--;
            }
        }
        return vector<int>(arr.begin()+l+1, arr.begin()+h);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // return kClosest(arr,k,x);
        return kClosestBS(arr,k,x);
    }