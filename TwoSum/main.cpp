#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        map<int, int > valueIndexMap;
        int numsSize = nums.size();
        map<int,int>::iterator it;

        for(int i = 0; i < numsSize; ++i){
            if( (it = valueIndexMap.find(target - nums[i])) != valueIndexMap.end()){
                ret.push_back(it->second);
                ret.push_back(i);
                return ret;
            }
            valueIndexMap.insert(pair<int,int>(nums[i], i));
        }
    }
};

int main() {
    Solution s;
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    vector<int> ret =  s.twoSum(v,6);
    for(int i = 0; i < ret.size(); ++i){
        cout << ret[i] << " ";
    }
    return 0;
}