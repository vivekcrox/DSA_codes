#include<iostream>
using namespace std;


int divideNumber(int dividend, int divisor){
    int s = 0;
    int e = abs(dividend);
    int ans = -1;

    while(s <= e){
        int mid = s+(e-s)/2;

        if(abs(mid*divisor) == abs(dividend)){
            return mid;
        }
        else if(abs(mid*divisor) < abs(dividend)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}

int main(){
    int dividend;
    int divisor;
    cout<<"dividend & divisor: "<<endl;
    cin>>dividend>>divisor;
    
    //Precision calc using Brute force
    int ans = divideNumber(dividend, divisor);

    double finalAns = ans;
    double step = 0.1;
    int precision = 3;

    for(int i=0; i<precision; i++){
        for(double j=finalAns; j*abs(divisor) <= abs(dividend); j+=step){
            finalAns = j;
        }
        step /= 10;
    }
    
    if((divisor > 0 && dividend > 0) || (divisor < 0 && dividend < 0)){
        cout<< finalAns <<endl;
    }
    else{
        cout<< -finalAns <<endl;
    }
    
    return 0;
}