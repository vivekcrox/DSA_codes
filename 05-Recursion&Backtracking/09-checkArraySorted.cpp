bool isSortedArray(int* arr, int n, int i){
    if(i==n-1){  // as single element is always sorted
        return true;
    }

    if(arr[i+1] < arr[i]){
        return false;
    }
    return isSortedArray(arr, n, i+1);
}