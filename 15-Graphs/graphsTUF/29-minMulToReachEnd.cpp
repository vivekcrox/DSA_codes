class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // edge case
        if(start == end)
            return 0;
            
        queue<pair<int,int>> q;
        q.push({0,start});
        vector<int> dist(100000, INT_MAX);
        dist[start] = 0;
        while(!q.empty()){
            int step = q.front().first;
            int node = q.front().second;
            q.pop();
            
            for(int i=0; i<arr.size(); i++){
                int mul = (arr[i]*node)%100000;
                if(step + 1 < dist[mul]){
                    if(mul == end){
                        return step + 1;
                    }
                    dist[mul] = step + 1;
                    q.push({step+1, mul});
                }
            }
        }
        return -1;
    }
};