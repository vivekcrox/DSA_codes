int exponentialSearch(int* arr, int n, int target){
    if(arr[0]==target){
        return 0;
    }
    int i=1;
    while(i<n && arr[i] <= target){
        i = i*2;   // i = i<<1;
    }
    return binarySearch(arr,i/2,min(i,n-1), target);
}


//In unbounded arr there is infinite elements
int unboundedSearch(int* arr, int target){
    int i=0, j=1;
    while(arr[j] <= target){
        i=j;
        j=j*2;
    }
    return binarySearch(arr,i,j, target);
}