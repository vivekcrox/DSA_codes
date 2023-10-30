#include <iostream>
#include<vector>
using namespace std;

bool isSafe(int i, int j, int row, int col, int arr[][4],
 vector<vector<bool> > &visited) {
  if( ((i>=0 && i < row) && (j >= 0 && j< col)) &&
      (arr[i][j] == 1 ) &&
      (visited[i][j]==false)) {
    return true;
  }
  else {
    return false;
  }
}

void solveMaze(int arr[][4], int row,int col, int i, int j,
vector<vector<bool> > &visited, vector<string>& path, string output  ) {

  //base case
  if(i == row-1 && j == col-1) {
    //answer found
    path.push_back(output);
    return;
  } 

  //Down -> i+1, j
  if(isSafe(i+1, j, row, col, arr, visited)) {
    visited[i+1][j] = true;
    solveMaze(arr, row, col, i+1, j, visited, path, output + 'D');
    //backtrack 
    visited[i+1][j] = false;
  }

  //Left -> i, j-1
  if(isSafe(i, j-1, row, col, arr, visited)) {
    visited[i][j-1] = true;
    solveMaze(arr, row, col, i, j-1, visited, path, output + 'L');
    //backtrack 
    visited[i][j-1] = false;
  }

  //Right -> i, j+1
  if(isSafe(i, j+1, row, col, arr, visited)) {
    visited[i][j+1] = true;
    solveMaze(arr, row, col, i, j+1, visited, path, output + 'R');
    //backtrack 
    visited[i][j+1] = false;
  }

  //Up-> i-1, j
if(isSafe(i-1, j, row, col, arr, visited)) {
    visited[i-1][j] = true;
    solveMaze(arr, row, col, i-1, j, visited, path, output + 'U');
    //backtrack 
    visited[i-1][j] = false;
  }


}

int main() {
  int maze[4][4] = { {1,0,0,0}, 
                 {1,1,0, 1},
                 {1,1,0,0},
                 {0,1,1,1}};

  if(maze[0][0] == 0) {
    cout << "No Path Exists " << endl;
    return 0;
  }

  int row = 4;
  int col = 4;

  vector<vector<bool> > visited(row, vector<bool>(col,false));
  //src ki value k true mark kredete h 
  visited[0][0] = true;

  vector<string> path;
  string output = "";

  solveMaze(maze,row,col, 0,0, visited, path, output);

  cout << "printing the results " << endl;
  for(auto i: path) {
    cout << i << " ";
  }
  cout << endl;
  if(path.size() == 0 ){
    cout << "No Path Exists " << endl;
  }

  
  return 0;
}



/***********************  GFG pe kiya solution  ************************************/
class Solution{
    public:
    
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,-1,1,0};
    char direction[4] = {'D','L','R','U'};
    
    bool isSafe(int x, int y,int row, int col, vector<vector<bool>> &visited, vector<vector<int>> &m){
        if(((x>=0 && x<row) && (y>=0 && y<col)) && (m[x][y]==1) && (visited[x][y]==0)){
            return true;
        }
        else{
            return false;
        }
    }
    
    void ratMaze(vector<vector<int>> &m, int row, int col,int x, int y, vector<vector<bool>> &visited, string output, vector<string>& path){
        if(x==row-1 && y==col-1){
            path.push_back(output);
            return;
        }
        
        for(int k=0; k<4; k++){
            int newx = x + dx[k];
            int newy = y + dy[k];
            char dir = direction[k];
            
            if(isSafe(newx,newy,row,col,visited,m)){
                visited[newx][newy] = 1;
                ratMaze(m,row,col,newx,newy,visited,output+dir,path);
                //backtracking
                visited[newx][newy] = 0;
            }
        }
        
        
        //Method1: above for loop is used to reduce the code size only remaining part will be same
        // //down
        // if(isSafe(x+1,y,row,col,visited,m)){
        //     visited[x+1][y] = 1;
        //     ratMaze(m,row,col,x+1,y,visited,output+'D',path);
        //     //backtrack
        //     visited[x+1][y] = 0;
        // }
        // //left
        // if(isSafe(x,y-1,row,col,visited,m)){
        //     visited[x][y-1] = 1;
        //     ratMaze(m,row,col,x,y-1,visited,output+'L',path);
        //     //backtrack
        //     visited[x][y-1] = 0;
        // }
        // //right
        // if(isSafe(x,y+1,row,col,visited,m)){
        //     visited[x][y+1] = 1;
        //     ratMaze(m,row,col,x,y+1,visited,output+'R',path);
        //     //backtrack
        //     visited[x][y+1] = 0;
        // }
        // //up
        // if(isSafe(x-1,y,row,col,visited,m)){
        //     visited[x-1][y] = 1;
        //     ratMaze(m,row,col,x-1,y,visited,output+'U',path);
        //     //backtrack
        //     visited[x-1][y] = 0;
        // }
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> path;
        
        int row = n;
        int col = n;
        
        vector<vector<bool> > visited(row, vector<bool>(col,false));
        visited[0][0] = 1;
        
        
        string output = "";
        if(m[0][0]==0){
            return path;
        }
        
        ratMaze(m,row,col,0,0,visited,output,path);
        
        return path;
    }