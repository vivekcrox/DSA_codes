#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> trees, int m, int mid){
    int woodCollected = 0;
    for(int i=0; i<trees.size(); i++){
        if(trees[i] > mid){
            woodCollected += (trees[i]-mid);
        }
    }
    return woodCollected >= m;
}

int minHeightOfSawblade(vector<int> trees, int m){
    int start = 0;
    int end = *max_element(trees.begin(), trees.end());
    int ans = -1;

    while(start <= end){
        int mid = start + (end-start)/2;
        if(isPossible(trees,m,mid)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}


int main(){
    int n, m;
    cin>>n>>m;
    vector<int> trees;
    while(n--){
        int height;
        cin>>height;
        trees.push_back(height);
    }
    cout<<minHeightOfSawblade(trees, m)<<endl;

    return 0;
}