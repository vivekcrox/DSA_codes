void selectionSort(int* arr, int n){
    for(int round=0; round < n-1; round++){
        int minIndex = round;
        for(int j=round+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[round], arr[minIndex]);
    }
}


void bubbleSort(int* arr, int n){
    for(int round = 1; round < n; round++){
        bool swapped = false;
        for(int j = 0; j < n - round; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
}

void insertionSort(int* arr, int n){
    for(int round = 1; round < n; round++){
        //fetch val
        int val = arr[round];
        //comparison
        int j = round - 1;
        
        for(; j>=0; j--){
            if(arr[j] > val){
                //shifting
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        //copy
        arr[j+1] = val;
    }
}