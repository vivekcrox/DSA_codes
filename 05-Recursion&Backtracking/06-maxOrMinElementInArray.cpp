int maxElement(int* arr, int n, int i, int& maxi){ //maxi passed by reference to update the single maxi var created in main() 
    if(i == n){
        return;
    }
    if(arr[i] > maxi){
        maxi = arr[i];
    }
    maxElement(arr,n,i+1,maxi);
}