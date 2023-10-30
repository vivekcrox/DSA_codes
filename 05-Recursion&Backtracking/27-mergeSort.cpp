#include<iostream>
using namespace std;

class Solution {
public:
    //Merge sort: merge inplace i.e auxiliary S.C = O(1);
    void mergeInPlace(vector<int>& nums, int start, int mid, int end){
        int totalSize = end - start + 1;
        int gap = (totalSize/2) + (totalSize%2);  //ceil
        while(gap > 0){
            int i = start, j = start + gap;
            while(j <= end){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
                ++i, ++j;
            }
            gap = (gap<=1) ? 0:(gap/2)+(gap%2);
        }
    }

    void mergeSort(vector<int>& nums, int start, int end){
        if(start >= end){
            return;
        }

        int mid = start+(end-start)/2;

        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        mergeInPlace(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
//**********************************************************

    //Merge sort: not inplace i.e S.C = O(n);
    // Method 1: not inplace
    // void merge(vector<int>& nums, vector<int>& temp, int start, int mid, int end){
    //     int i=start, j = mid+1, k = start;

    //     while(i <= mid && j <= end){
    //         if(nums[i] < nums[j]){
    //             temp[k++] = nums[i++];
    //         }
    //         else{
    //             temp[k++] = nums[j++];
    //         }
    //     }
    //     while(i <= mid){
    //         temp[k++] = nums[i++];
    //     }
    //     while(j <= end){
    //         temp[k++] = nums[j++];
    //     }

        
    //     while(start <= end){
    //         nums[start] = temp[start];
    //         start++;
    //     }
    // }

    // void mergeSort(vector<int>& nums, vector<int>& temp, int start, int end){
    //     if(start >= end){
    //         return;
    //     }

    //     int mid = start+(end-start)/2;

    //     mergeSort(nums,temp, start, mid);
    //     mergeSort(nums,temp, mid+1, end);
    //     merge(nums, temp, start, mid, end);
    // }

    // vector<int> sortArray(vector<int>& nums) {
    //     vector<int> temp(nums.size(), 0);
    //     mergeSort(nums, temp, 0, nums.size()-1);
    //     return nums;
    // }
};

// // merge Sort : not inplace s.c = O(n)
// // method 2: not inplace
// void merge(int* arr, int s, int e){
//     int mid = s+(e-s)/2;

//     int len1 = mid-s+1;
//     int len2 = e-mid;

//     //create two array for both parts
//     int* left = new int[len1];
//     int* right = new int[len2];

//     //copy
//     int k = s;
//     for(int i=0; i<len1; i++){
//         left[i] = arr[k++];
//     }

//     k = mid+1;
//     for(int i=0; i<len2; i++){
//         right[i] = arr[k++];
//     }

//     //sort both parts
//     int leftIndex = 0;
//     int rightIndex = 0;
//     int mainIndex = s;
//     while(leftIndex < len1 && rightIndex < len2){
//         if(left[leftIndex] < right[rightIndex]){
//             arr[mainIndex++] = left[leftIndex++];
//         }
//         else{
//             arr[mainIndex++] = right[rightIndex++];
//         }
//     }
//     //copy remaining elements
//     while(leftIndex < len1){
//         arr[mainIndex++] = left[leftIndex++];
//     }
//     while(rightIndex < len2){
//         arr[mainIndex++] = right[rightIndex++];
//     }

//     //delete the created arrays dynamically
//     delete[] left;
//     delete[] right;
// }

// void mergeSort(int* arr, int s, int e){
//     //if s==e  -> single element is sorted
//     //if s>e   -> invalid index
//     if(s >= e){
//         return ;
//     }

//     int mid = s + (e-s)/2;
    
//     //left part recursion bhaiya solve krke do
//     mergeSort(arr, s, mid);
//     //right part recursion bhaiya solve krke do
//     mergeSort(arr, mid+1, e);

//     //merge both sorted parts
//     merge(arr, s, e);
// }

// int main(){
//     int arr[] = {23,13,44,2,5,32,13};
//     int n = 7;

//     mergeSort(arr,0,n-1);

//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;

//     return 0;
// }