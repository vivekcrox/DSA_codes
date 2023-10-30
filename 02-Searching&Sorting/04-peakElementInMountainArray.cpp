int peakElementInMountainArray(int* arr, int n){
    int s = 0; 
    int e = n-1;

    while(s < e){            // s<=e result into infinite loop when s & e pointing to same element which the peak
        int mid = s+(e-s)/2;
        if(mid+1 < n && arr[mid] < arr[mid+1]){
            s = mid+1;
        }
        else{
            e = mid;
        }
    }
    return s;   // or may return e;
}