int minCoinCount(vector<int> arr, int target){
    if(target == 0){
        return 0;
    }
    if(target < 0){
        return INT_MAX;
    }


    int mini = INT_MAX;
    for(int i=0; i<arr.size(); i++){
        int ans = minCoinCount(arr, target-arr[i]);
        
        if(ans != INT_MAX){
            mini = min(mini, 1+ans);
        }
    }
    return mini;
}