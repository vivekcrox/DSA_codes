class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    
    int kadane(int arr[], int n){
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            maxi = max(maxi, sum);
            if(sum < 0)
                sum = 0;
        }
        return maxi;
    }
    
    int circularSubarraySum(int arr[], int num){
        if(num == 1)
            return arr[0];
        
        int nonwrapSum = kadane(arr, num);
        
        int totalSum = 0;
        for(int i=0; i<num; i++){
            totalSum += arr[i];
            arr[i] = -arr[i];         // modifying array to negative element
        }
        int wrapSum = totalSum + kadane(arr, num);
          
        if(wrapSum == 0){    //mtlb all elements of the arr is non-contributing. so pick max among them.
            int maxi = INT_MIN;
            for(int i=0; i<num; i++){
                if(arr[i] < maxi)     //as array's element become negative.(min will max)
                    maxi = arr[i];
            }
            wrapSum = maxi;   // replace wrapsum = 0 to max element of the original array
        }
        
        return max(nonwrapSum, wrapSum);
    }
};