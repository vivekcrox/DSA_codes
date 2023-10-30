#include <iostream>
#include <vector>

using namespace std;

int findMissingElement(const vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    // If the first element is missing, return it
    if (nums[left] != left) {
        return left;
    }

    // Binary search to find the missing element
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // If the element at mid is equal to mid, the missing element is on the right side
        if (nums[mid] == mid) {
            left = mid + 1;
        } else {
            // Otherwise, the missing element is on the left side
            right = mid;
        }
    }

    // Once the loop ends, left and right will be pointing to the missing element
    return left;
}

int main() {
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8,10};
    int missingElement = findMissingElement(nums);

    cout << "Missing element: " << missingElement << endl;

    return 0;
}
