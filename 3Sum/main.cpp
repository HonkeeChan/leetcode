#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    if(nums.size() < 3){
        return ret;
    }
    for(int i = 0; i < nums.size() - 2;){
        int a = -nums[i];
        int front = i + 1;
        int end = nums.size() - 1;
        while (front < end){
            if(nums[front] + nums[end] < a){
                front++;
            }else if(nums[front] + nums[end] > a){
                end--;
            }else{
                vector<int> v(3,0);
                v[0] = nums[i];
                v[1] = nums[front];
                v[2] = nums[end];
                ret.push_back(v);
                while(nums[--end] == v[2])
                    ;
                while(nums[++front]== v[1])
                    ;
            }

        }
        while(nums[++i] == -a)
            ;
    }
    return ret;
}
int main() {
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    threeSum(v);
    return 0;
}

//void TLE(){
//    sort(nums.begin(), nums.end());
//    set<vector<int>> ss;
//    unordered_multimap<int,int> m;
//    unordered_multimap<int,int>::iterator mi;
//    vector<vector<int>> res;
//    for(int i = 0; i < nums.size(); ++i){
//        m.insert(make_pair(nums[i], i));
//    }
//    for(int i = 0; i < nums.size(); ++i){
//        for(int j = i+1; j < nums.size(); ++j){
//            int left = 0 - nums[i] - nums[j];
//            mi = m.find(left);
//            for(int k = 0; k < m.count(left); ++k, ++mi){
//                if(mi->second > j){
//                    vector<int> v = {nums[i],nums[j], nums[mi->second]};
//                    if(ss.find(v) == ss.end()){
//                        res.push_back(v);
//                        ss.insert(v);
//                    }
//
//                }
//            }
//        }
//    }
//    return res;
//}