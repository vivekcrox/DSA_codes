/*
    Insertion    : O(logn)
    Deletion     : O(logn)
    Heapify algo : O(logn)
    Build Heap   : O(n)
    HeapSort     : O(nlogn)
    STL(priority queue)
*/
#include<iostream>
#include<queue>
using namespace std;



class heap{
    public:
        int arr[100];
        int size;

        heap(){
            arr[0] = -1;
            size = 0;
        }

        // insertion time : O(logn)
        void insert(int val){
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1){
                int parent = index/2;

                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else{
                    return ;
                }
            }
        }

        void print(){
            for(int i=1; i<=size; i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }


        // deletion time : O(logn)
        int deleteHeap() {
            if(size == 0){
                cout<<"Nothing to delete"<<endl;
                return -1;
            }

            int ans  = arr[1];  //store root val to be deleted
            //replace root node value with last node data
            arr[1] = arr[size];
            size--;

            //place root node ka data on its correct position
            int index = 1;
            while(index < size) {
                    int left = 2*index;
                    int right = 2*index+1;
                        
                    int largest = index;

                    if(left <= size && arr[largest] < arr[left] ) {
                            largest = left;
                    }
                    if(right <= size && arr[largest] < arr[right] ) {
                            largest = right;
                    }

                    if(largest == index) {
                            //value is at correct position
                            break; 
                    }
                    else {
                            swap(arr[index], arr[largest]);
                            index = largest;
                        } 
            }
            return ans;
        }
};


// Heapify algo time: O(logn)
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    //check if largest not update
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// heapSort = build Heap + heapify => time: O(nlogn)
void heapSort(int arr[], int n){
    int size = n;

    while(size > 1){
        //step1: swap
        swap(arr[size], arr[1]);
        size--;

        //step2
        heapify(arr, size, 1);
    }
}

int main(){

    heap h;
    h.insert(53);
    h.insert(52);
    h.insert(60);
    h.insert(23);
    h.insert(56);

    h.print();

    h.deleteHeap();

    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;


    // Build heap 
    for(int i=n/2; i>0; i--){   // ignore leaf node as it always heap[(n/2)+1 se n tak leaf node hoti h CBT m]
        heapify(arr, n, i);
    }
    cout<<"printing the array now"<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    heapSort(arr,n);

    cout<<"printing the sorted array now"<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

//**********************************************
    //STL
    //Max heap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"element at top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Size is"<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"pq is empty"<<endl;
    }

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minh;   // vector<int> -> container, greater<int> -> comparator

    minh.push(4);
    minh.push(2);
    minh.push(5);
    minh.push(3);


    return 0;
}