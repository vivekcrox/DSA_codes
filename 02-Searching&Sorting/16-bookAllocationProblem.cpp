//Book Allocation Problem = Painter's Partition Problem
bool isPossible(int* arr, int n, int m, int mid){
    int pageSum = 0;
    int c = 1;
    for(int i=0; i<n; i++){
        if(arr[i] > mid){
            return false;
        }
        if(pageSum + arr[i] > mid){
            c++;
            pageSum = arr[i];

            if(c > m){
                return false;
            }
        }
        else{
            pageSum += arr[i];
        }
    }
    return true;
}


int bookAllocate(int* arr, int n, int m){
    if(m > n){
        return -1;
    }
    int s = 0;
    int e = accumulate(arr, arr+n, 0);
    int ans = -1;

    while(s <= e){
        int mid = s+(e-s)/2;
        if(isPossible(arr,n,m,mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}