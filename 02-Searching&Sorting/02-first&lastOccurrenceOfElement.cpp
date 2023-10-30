int firstOcc(int* arr, int n, int key){

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s <= e){
        if(arr[mid] == key){
            ans = mid;     //possible ans
            e = mid-1;         // In case of last Occurrence : s = mid + 1;
        }
        else if(arr[mid] > key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}


//STL
auto ans = lower_bound(v.begin(), v.end(), key);
cout<< ans - v.begin() <<endl;

auto ans = upper_bound(v.begin(), v.end(), key);
cout<< ans - v.begin() <<endl;