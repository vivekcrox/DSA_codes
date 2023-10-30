void moveAllNegToLeft(int* arr, int n){
    int l=0, h=arr.size()-1;
    while(l < h){
        if(arr[l] < 0){
            l++;
        }
        else if(arr[h] > 0){
            h--;
        }
        else{
            swap(arr[l], arr[h]);
        }
    }
}