int squareRoot(int N){
    int s = 0;
    int e = N;
    while(s <= e){
        int mid = s+(e-s)/2;
        if(mid*mid == N){
            return mid;
        }
        else if(mid*mid > N){
            e = mid-1;
        }
        else{
            ans = mid;   //possible ans
            s = mid+1;
        }
    }
    return ans;
}

//Precision calculation : Brute force approach
double finalAns = squareRoot(N);   //ans in decimal part
double step = 0.1;
int precision = 3;

for(int i=0; i<precision; i++){
    for(double j=finalAns; j*j <= N; j+=step){
        finalAns = j;
    }
    step /= 10;
}
return finalAns;