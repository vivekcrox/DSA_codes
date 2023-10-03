class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 1. transpose the matrix
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2. reverse each row
        for(auto &row: matrix){
            reverse(begin(row), end(row));
        }
    }
};
