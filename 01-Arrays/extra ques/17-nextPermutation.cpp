class Solution{
public:
    // // STL 
    // next_permutation(arr.begin(), arr.end());

    vector<int> nextPermutation(int n, vector<int> arr){
        int i=0;
        for(i=n-2; i>=0; i--){
            if(arr[i] < arr[i+1])
                break;
        }
        if(i < 0)
            reverse(arr.begin(), arr.end());
        else{
            int j = 0;
            for(j = n-1; j>=0; j--){
                if(arr[j] > arr[i])
                    break;
            }
            swap(arr[j], arr[i]);
            reverse(arr.begin()+i+1, arr.end());
        }
        return arr;
    }
};