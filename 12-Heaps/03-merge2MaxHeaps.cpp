void heapify(vector<int>& arr, int n, int i){
    int largest = i;     // 0 base indexing
    int left = 2*i+1;   
    int right = 2*i+2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    //check if largest not update
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> merge2MaxHeap(vector<int>& a, vector<int>& b, int n, int m){
    //1. merging both heaps
    vector<int> ans; //store both heaps value
    for(auto i:a)
        ans.push_back(i);
    for(auto i:b)
        ans.push_back(i);
    
    //2. heapifying 
    int size = ans.size();
    for(int i=size/2 - 1; i>=0; i--){
        heapify(ans,size,i);
    }
    return ans;
}