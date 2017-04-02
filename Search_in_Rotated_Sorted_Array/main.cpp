#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target);

int main() {
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    cout << search(v, 7) << endl;
    v = {4, 5, 6, 7, 0, 1, 2};
    cout << search(v, 3) << endl;
    v = {3,1};
    cout << search(v, 1) << endl;
    return 0;
}

int search(vector<int>& nums, int target){
    int left, right, middle;
    left = 0;
    right = nums.size() - 1;
    while(left <= right){
        if(right - left < 10){
            for(; left <= right; ++left){
                if(nums[left] == target){
                    return left;
                }
            }
            continue;
        }
        middle  = (left + right) / 2;
        if(nums[middle] == target){
            return middle;
        }
        // split point is at right
        if(nums[middle] > nums[left] && nums[middle] > nums[right]){
            if(nums[middle] < target){
                left = middle + 1;
            }else if(nums[left] > target){
                left = middle + 1;
            }else{
                right = middle - 1;
            }
        }
        // // split point is at left
        else if(nums[middle] < nums[left] && nums[right] > nums[middle]) {
            if(nums[right] < target){
                right = middle - 1;
            }else if(nums[middle] > target){
                right = middle - 1;
            }else{
                left = middle + 1;
            }
        }
        //increse order
        else{
            if(nums[middle] < target){
                left = middle + 1;
            }else{
                right = middle - 1;
            }
        }

    }
    return  -1;
}

