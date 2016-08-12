#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    nums1.resize(m + n);
    int i = m - 1, j = n -1;
    int idx = m + n -1;
    while(i >= 0 && j >=0){
        if(nums1[i]> nums2[j]){
            nums1[idx--] = nums1[i--];
        }else{
            nums1[idx--] = nums2[j--];
        }
    }
    while(j >= 0){
        nums1[idx--] = nums2[j--];
    }

}
int main() {
    vector<int> a;
    a.reserve(20);
    vector<int> b;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    //a.push_back(4);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    merge(a,3,b,3);
    for(int i = 0; i < a.size(); ++i){
        cout << a[i] <<" ";
    }


    return 0;
}