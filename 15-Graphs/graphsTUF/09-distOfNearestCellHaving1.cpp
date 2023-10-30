class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    // Using BFS traversal is possible, not DFS.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> visited(n, vector<int>(m, 0));
	    vector<vector<int>> dist(n, vector<int>(m, 0));
	    //{{row,col},steps}
	    queue<pair<pair<int,int>, int>> q;
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                visited[i][j] = 1;
	            }
	            else{
	                visited[i][j] = 0;
	            }
	        }
	    }
	    int drow[4] = {-1,0,1,0};
	    int dcol[4] = {0,1,0,-1};
	    while(!q.empty()){
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int step = q.front().second;
	        q.pop();
	        dist[r][c] = step;
	        
	        for(int i=0; i<4; i++){
	            int nrow = r + drow[i];
	            int ncol = c + dcol[i];
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol]){
	                visited[nrow][ncol] = 1;
	                q.push({{nrow,ncol}, step+1});
	            }
	        }
	    }
	    return dist;
	    
	}
};