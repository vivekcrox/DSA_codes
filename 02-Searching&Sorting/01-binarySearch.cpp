
//stl 
// //1. In case of vector<int>
// if(binary_search(v.begin(), v.end(), key)){
//     cout<<"found";
// }

// //2. In case of array arr[]
// if(binary_search(arr, arr+size, key)){
//     cout<<"found";
// }

void binarySearch(int* arr, int n, int key){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;

    while(start < end){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}