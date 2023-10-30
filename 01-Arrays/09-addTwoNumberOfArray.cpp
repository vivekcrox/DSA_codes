string addTwoArray(int* a, int n, int* b, int m){
    string ans;
    int carry = 0;
    int i=n-1, j=m-1;
    while(i>=0 && j>=0){
        int x = a[i] + b[j] + carry;
        int digit = x%10;
        ans.push_back(digit+'0');
        carry = x/10;
        i--;
        j--;
    }

    while(i>=0){
        int x = a[i] + carry;
        int digit = x%10;
        ans.push_back(digit+'0');
        carry = x/10;
        i--;
    }
    while(j>=0){
        int x = a[j] + carry;
        int digit = x%10;
        ans.push_back(digit+'0');
        carry = x/10;
        j--;
    }

    if(carry){
        ans.push_back(carry+'0');
    }

    while(ans[ans.size()-1]=='0'){  //removing starting zeroes ex. 210 after reversing  it will be 012 
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}