class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        //store piles s.t. top points to max pile size.
        priority_queue<int> maxHeap;

        for(int i=0; i<piles.size(); i++){
            maxHeap.push(piles[i]);
        }
        
        // perform operation of subtracting --> 'k' times
        while(k--){
            int maxElement = maxHeap.top();
            maxHeap.pop();
            maxElement = maxElement - floor(maxElement/2);
            maxHeap.push(maxElement);
        }
        int sum =  0;
        while(!maxHeap.empty()){
            sum += maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};