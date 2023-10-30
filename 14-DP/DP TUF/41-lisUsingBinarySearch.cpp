int lisUsingBinarySearch(vector<int>& arr, int n){
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=0; i<n; i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
        }
        else{  // finding first > element of arr[i] & replace it with lower_bound element.
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]);
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}