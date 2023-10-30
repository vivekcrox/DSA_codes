// I) visited Method
void missingElem(int* arr, int n){
    for(int i=0; i<n; i++){
        int index = abs(arr[i]);
        if(arr[index - 1] > 0){     //marking
            arr[index - 1] *= -1;
        }
    }
    //printing all missing element which having positive element
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}

// II) sorting + swapping method
void missingElem(int* arr, int n){
    int i=0; 
    while(i<n){
        int index = arr[i] - 1;
        if(arr[i] != arr[index]){
            swap(arr[i], arr[index]);
        }
        else{
            i++;
        }
    }

    //printing missing element
    for(int i=0; i<n; i++){
        if(arr[i] != i+1){
            cout<<i+1<<" ";
        }
    }
}