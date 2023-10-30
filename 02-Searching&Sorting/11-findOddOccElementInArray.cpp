int findOddOcc(int* arr, int n){
    int s = 0;
    int e = n-1;

    while(s <= e){
        int mid = s+(e-s)/2;

        if(s==e){   //single element
            return s;
        }

        // 2 cases
        if(mid&1==0){
            if(mid+1 < n && arr[mid]==arr[mid+1]){    //ans right side part h
                s = mid+2;
            }
            else{
                e = mid;    //possible ans
            }
        }
        else{
            if(mid-1 >= 0 && arr[mid-1]==arr[mid]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
    }
    return -1;
}