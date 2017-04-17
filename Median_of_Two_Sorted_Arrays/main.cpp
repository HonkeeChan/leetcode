#include <iostream>
#include <vector>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.empty() && nums2.empty()){
        return 0;
    }
    int v1beg = 0, v1end = nums1.size() - 1;
    int  v2beg = 0, v2end = nums2.size() - 1;
    int midLeft = 0;
    int midRight = 0;
    while(v1beg <= v1end && v2beg <= v2end){
        if(nums1[v1beg] < nums2[v2beg] && v1beg <= v1end){
            midLeft = nums1[v1beg];
            v1beg++;
        }else{
            midLeft = nums2[v2beg];
            v2beg++;
        }
        if(nums2[v2end] > nums1[v1end] && v2end >= v2beg){
            midRight = nums2[v2end];
            v2end--;
        }
        else if(v1beg <= v1end){
            midRight = nums1[v1end];
            v1end--;

        }
    }
    while(v2beg <= v2end){
        midLeft = nums2[v2beg];
        midRight = nums2[v2end];
        v2beg++;
        v2end--;
    }
    while(v1beg <= v1end){
        midLeft = nums1[v1beg];
        midRight = nums1[v1end];
        v1beg++;
        v1end--;
    }

    if((nums1.size() + nums2.size()) % 2 == 1){
        return midLeft;
    }else{
        return (midLeft + midRight)/2.0;
    }
}

int main() {
    vector<int> v1 = {1,2};
    vector<int> v2 = {3, 4};
    findMedianSortedArrays(v1, v2);
    return 0;
}