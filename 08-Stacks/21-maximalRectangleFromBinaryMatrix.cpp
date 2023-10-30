class Solution {
public:
    vector<int> prevSmallerIndex(vector<int>& input){
        stack<int> s;
        s.push(-1);
        vector<int> ans(input.size());

        //left to right -> prev smaller
        for(int i=0; i<input.size(); i++){
            int curr = input[i];

            //apka answer stack me
            while(s.top() != -1 && input[s.top()] >= curr){
                s.pop();
            }

            //chotte element mil chuka h -> ans store
            ans[i] = s.top();

            //push krdo curr element ko
            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerIndex(vector<int> &input){
        stack<int> s;
        s.push(-1);

        vector<int> ans(input.size());
        
        for(int i=input.size()-1; i>=0; i--){
            int curr = input[i];

            //apka ans stack me
            while(s.top() != -1 && input[s.top()] >= curr){
                s.pop();
            }

            //chotte element mil chuka h -> ans store
            ans[i] = s.top();

            //push krdo curr element ko
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        //step1: prevSmaller output
        vector<int> prev = prevSmallerIndex(heights);
        //step2: nextSmaller output
        vector<int> next = nextSmallerIndex(heights);

        int maxArea = INT_MIN;
        int size = heights.size();

        for(int i=0; i<heights.size(); i++){
            int length = heights[i];

            if(next[i] == -1){
                next[i] = size;
            }
            int width = next[i] - prev[i] - 1;

            int area = length*width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
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

        //compute area for 1st row
        int area = largestRectangleArea(matrix[0]);
        
        //for remaining rows
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                //row update: by adding prev row's value
                if(matrix[i][j] != 0)
                    matrix[i][j] += matrix[i-1][j];
                else
                    matrix[i][j] = 0;
            }
            //entire row is updated now
            int newArea = largestRectangleArea(matrix[i]);
            area = max(area, newArea);
        }
        return area;
    }
};