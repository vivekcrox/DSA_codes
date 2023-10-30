// Assuming pivot as the max number in the array
// ex: 3,4,5,6,7,1,2  -> 7 is the pivot or 1 can be take as pivot

int findPivot(int* arr, int n){
    int s = 0, e = n-1;
    while(s <= e){
        //single element
        if(s==e){
            return s;
        }
        if(mid+1 < n && arr[mid] > arr[mid+1]){
            return mid;
        }
        if(mid-1 >= 0 && arr[mid-1] > arr[mid]){
            return mid-1;
        }

        if(arr[s] > arr[mid]){   // 2nd line m condition
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}