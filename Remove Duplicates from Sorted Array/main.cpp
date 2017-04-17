#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>::iterator VIIT;
int removeDuplicates(vector<int>& nums) {
    if(nums.size() < 2){
        return nums.size();
    }
    VIIT itEnd = nums.end();
    VIIT itBeg = nums.begin();
    //int preVal = *itBeg;
    VIIT itSlow = itBeg;
    //itSlow++;
    for(VIIT it = itBeg + 1; it != itEnd; ++it){
        if(*itSlow != *it){
            itSlow++;
            *itSlow = *it;

        }
    }
    return (int)(itSlow - itBeg + 1);
}
int main()
{
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    vi.push_back(4);
    cout << removeDuplicates(vi) << endl;
    return 0;
}
