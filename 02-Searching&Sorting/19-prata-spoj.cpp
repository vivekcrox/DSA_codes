#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> cookRank, int p, int mid){
    int currP = 0;
    
    for(int i=0; i<cookRank.size(); i++){
        int R = cookRank[i];
        int j = 1;
        int timeTaken = 0;
        while(true){
            if(timeTaken + j*R <= mid){
                currP++;
                timeTaken += j*R;
                j++;
            }
            else{
                break;
            }
        }
        if(currP >= p){
            return true;
        }
    }
    return false;
}

int minTimeToCookOrder(vector<int> cookRank, int p){
    int start = 0;
    int highestRank = *max_element(cookRank.begin(), cookRank.end());
    int end = highestRank*(p*(p+1)/2);
    int ans = -1;

    while(start <= end){
        int mid = start + (end-start)/2;
        if(isPossible(cookRank, p, mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}



int main(){
    int T;
    cin>>T;
    while(T--){
        int p, c;    //no. of prata and no. of cooks
        cin>>p>>c;
        vector<int> cookRank;
        while(c--){
            int rank;
            cin>>rank;
            cookRank.push_back(rank);
        }
        cout<<minTimeToCookOrder(cookRank, p)<<endl;
    }

    return 0;
}
