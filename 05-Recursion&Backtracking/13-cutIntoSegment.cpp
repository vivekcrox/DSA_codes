#include<iostream>
using namespace std;

//max no. of segments
int maxSegment(int n, int x, int y, int z){
    if(n==0){
        return 0;
    }
    if(n < 0){
        return INT_MIN;
    }

    int ans1 = maxSegment(n-x, x, y, z) + 1;
    int ans2 = maxSegment(n-y, x, y, z) + 1;
    int ans3 = maxSegment(n-z, x, y, z) + 1;

    int ans = max(ans1, max(ans2, ans3));
    return ans;
}

int main(){
    int n;
    int x, y, z;
    cin>>n>>x>>y>>z;

    int ans = maxSegment(n,x,y,z);

    if(ans < 0){   //not possible to cut 'n' length rod into segments of x,y,z
        cout<< 0 <<endl;
    }
    else {
        cout<< ans <<endl;
    }

    return 0;
}