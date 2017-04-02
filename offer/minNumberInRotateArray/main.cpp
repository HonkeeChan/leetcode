#include <iostream>
#include <vector>
using namespace std;

int  minNumberInRotateArray(vector<int> rotateArray);
int main() {
    vector<int> rotateArray = {3,4,5,1,2};
    cout << minNumberInRotateArray(rotateArray) << endl;
    rotateArray = {1,1,1,1,0,1};
    cout << minNumberInRotateArray(rotateArray) << endl;
    rotateArray = {1,0,1,1,1,1,1};
    cout << minNumberInRotateArray(rotateArray) << endl;
    rotateArray = {0,1,1,1,1,1};
    cout << minNumberInRotateArray(rotateArray) << endl;
    rotateArray = {1,1,1,1,0};
    cout << minNumberInRotateArray(rotateArray) << endl;
    rotateArray = {6501,6828,6963,7036,7422,7674,8146,8468,8704,8717,9170,9359,9719,9895,9896,9913,9962,154,293,334,492,1323,1479,1539,1727,1870,1943,2383,2392,2996,3282,3812,3903,4465,4605,4665,4772,4828,5142,5437,5448,5668,5706,5725,6300,6335};
    cout << minNumberInRotateArray(rotateArray) << endl;


return 0;
}


int minNumberInRotateArray(vector<int> rotateArray) {
    vector<int>& nums = rotateArray;
    int left, right, middle;
    left = 0;
    right = nums.size() - 1;
    while(left < right) {

        middle = (left + right) / 2;
        cout << nums[left] << " "  << nums[middle] << " " << nums[right] << endl;
        if(right - left < 3)
            break;
        if(nums[middle] == nums[left] && nums[middle] == nums[right]){
            int minVal = nums[left];
            for (; left <= right; ++left) {
                if (minVal > nums[left]) {
                    return nums[left];
                }
            }
        }
        // split point is at right

        if (nums[middle] >= nums[left]) {
            left = middle ;
        }
        // // split point is at left
        else if (nums[middle] <= nums[left] ) {
            right = middle ;
        }

    }
    int minVal = nums[left];
    for (; left <= right; ++left) {
        if (minVal > nums[left]) {
            return nums[left];
        }
    }
    return minVal;
}