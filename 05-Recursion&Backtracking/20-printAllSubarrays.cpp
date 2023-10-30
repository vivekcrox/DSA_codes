void subArrayUtils(vector<int>& arr, int s, int e){
    if(e == arr.size()){
        return;
    }

    for(int i=s; i<=e; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    subArrayUtils(arr,s,e+1);
}

void printSubarray(vector<int>& arr){
    for(int s=0; s<arr.size(); s++){
        int e = s;
        subArrayUtils(arr, s, e);
    }
}