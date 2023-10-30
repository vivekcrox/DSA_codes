void wavePrint(vector<vector<int>> v){
    int row = v.size();
    int col = v[0].size();

    for(int colStart = 0; colStart < col; colStart++){
        if(colStart&1 == 0){
            //even col -> dir: top to down colwise printing
            for(int i=0; i<row; i++){
                cout<<v[i][colStart]<<" ";
            }
        }
        else{
            for(int i=row-1; i>=0; i--){
                cout<<v[i][colStart]<<" ";
            }
        }
    }
}