// spoj platform problem
// Online C++ compiler to run C++ program online

#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, y, n;
    cin>>x>>y>>n;
    int t = n;
    // 1 base indexing grid given.
    vector<int> row;
    vector<int> col;
    //edge case
    //placing imaginary tower 
    row.push_back(0);
    col.push_back(0);
    
    while(t--){
        int a, b;
        cin>>a>>b;
        row.push_back(a);
        col.push_back(b);
    }
    //edge case
    //placing imaginary tower
    row.push_back(x+1);
    row.push_back(y+1);

    sort(row.begin(), row.end());
    sort(col.begin(), col.end());

    int maxLen = 0, maxWid = 0;
    for(int i=0; i<row.size(); i++){
        maxLen = max(maxLen, row[i]-row[i-1]-1);
    }
    for(int i=0; i<col.size(); i++){
        maxWid = max(maxWid, col[i]-col[i-1]-1);
    }
    cout<<"answer "<<maxLen*maxWid<<endl;
    
    return 0;
}