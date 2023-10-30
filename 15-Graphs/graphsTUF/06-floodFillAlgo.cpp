class Solution {
public:
    void dfs(int sr, int sc, int& iniColor, int& newColor, vector<vector<int>>& ans, vector<vector<int>>& image, int delRow[], int delCol[]){
        
        ans[sr][sc] = newColor;
        int n = image.size();
        int m = image[0].size();
        
        for(int i=0; i<4; i++){
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor){
                dfs(nrow, ncol, iniColor, newColor, ans, image, delRow, delCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> ans = image;
        
        int iniColor = image[sr][sc];
        int delRow[] = {-1, 0, 1, 0}; // U R D L
        int delCol[] = {0, 1, 0, -1};
        dfs(sr, sc, iniColor, newColor, ans, image, delRow, delCol);
        return ans;
    }
};