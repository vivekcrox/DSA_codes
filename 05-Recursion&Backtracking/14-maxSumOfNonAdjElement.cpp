void maxSumNonAdjElement(vector<int> arr,int i, int sum, int& maxi){
    if(i >= arr.size()){
        maxi = max(maxi, sum);
        return;
    }
    
    //include
    maxSumNonAdjElement(arr,i+2, sum+arr[i], maxi);

    //exclude
    maxSumNonAdjElement(arr,i+1,sum,maxi);
}