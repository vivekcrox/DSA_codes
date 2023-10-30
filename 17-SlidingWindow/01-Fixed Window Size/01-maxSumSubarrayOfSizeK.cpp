class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int i = 0;
        int j = 0;
        long sum = 0;
        long maxi = -1e9;
        while(j < N){
            sum += Arr[j];
            if(j-i+1 < K)
                j++;
            else if(j-i+1 == K){
                maxi = max(maxi, sum);
                sum = sum - Arr[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};