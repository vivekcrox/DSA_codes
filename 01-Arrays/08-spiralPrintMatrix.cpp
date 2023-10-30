void spiralPrint(vector<vector<int>> v){
    int row = v.size();
    int col = v[0].size();
    int rowStart = 0, rowEnd = row-1;
    int colStart = 0, colEnd = col-1;
    int count = 0;
    int totalCount = row*col;

    while(count < totalCount){
        //start row printing
        for(int i=colStart; (i<=colEnd && count < totalCount); i++){
            cout<<v[rowStart][i]<<" ";
            count++;
        }
        rowStart++;

        //end col printing
        for(int i=rowStart; (i<=rowEnd && count < totalCount); i++){
            cout<<v[i][colEnd]<<" ";
            count++;
        }
        colEnd--;

        //end row printing
        for(int i=colEnd; (i>=colStart && count < totalCount); i--){
            cout<<v[rowEnd][i]<<" ";
            count++;
        }
        rowEnd--;

        //start col printing
        for(int i=rowEnd; (i>=rowStart && count < totalCount); i--){
            cout<<v[i][colStart]<<" ";
            count++;
        }
        colStart++;
    }
}