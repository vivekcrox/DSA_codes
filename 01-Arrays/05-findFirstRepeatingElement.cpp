// I) Comparing Method
for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
        if(arr[i]==arr[j]){
            return i+1;   //return 1 base indexing
        }
    }
}

// II) Hashing / Store count Method

unordered_map<int,int> hash;
//store count of each element
for(int i=0; i<n; i++){  
    hash[arr[i]]++;
}

//count >1 is the first repeating element
for(int i=0; i<n; i++){
    if(hash[arr[i]] > 1){
        return i+1;
    }
}
return -1;