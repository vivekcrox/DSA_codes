int binarySearch(int* arr, int s, int e, int key){
    if(s > e){
        return -1;
    }

    int mid = s+(e-s)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(arr[mid]>key){
        return binarySearch(arr,s,mid-1,key);
    }
    else{
        return binarySearch(arr,mid+1,e,key);
    }
}