int largestRectangleArea(vector<int>& histo){
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for(int i=0; i<=n; i++){
        while(!st.empty() && (i==n || histo[st.top()] >= histo[i])){
            int height = histo[st.top()];
            st.pop();
            int width;
            if(st.empty())
                width = i;
            else
                width = i-st.top()-1;
            maxA = max(maxA, width*height);
        }
        st.push(i);
    }
    return maxA;
}

int maximalRectangle(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    //convert matrix entries to int to make compatible with largestRectangleArea's heights vector
    vector<vector<int> > matrix;
    for(int i=0; i<n; i++){
        vector<int> t;
        for(int j=0; j<m; j++){
            t.push_back(grid[i][j] - '0');
        }
        matrix.push_back(t);
    }


    int maxArea = 0;
    vector<int> height(m, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 1)
                height[j]++;
            else
                height[j] = 0;
        }

        int area = largestRectangleArea(height);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}