void printArray(int* arr, int n, int i){
    if(i == n){
        return;
    }
    
    cout<<arr[i]<<" ";
    printArray(arr,n, i+1);
}