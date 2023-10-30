bool SearchIn2dMatrix(vector<vector<int>> v, int target){
    int row = v.size();
    int col = v[0].size();

    int s = 0;
    int e = row*col-1;

    while(s <= e){
        int mid = s + (e-s)/2;

        int rowIndex = mid/col;
        int colIndex = mid%col;

        int element = v[rowIndex][colIndex];
        if(element == target){
            return true;
        }
        else if(element > target){
            e = mid-1;
        }
        else {
            s = mid+1;
        }
    }
    return false;

}