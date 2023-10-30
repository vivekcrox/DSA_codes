//print n to 1 
void printCount(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    printCount(n-1);
}

//print 1 to n 
void printCount(int n){
    if(n==0){
        return;
    }
    printCount(n-1);
    cout<<n<<" ";
}