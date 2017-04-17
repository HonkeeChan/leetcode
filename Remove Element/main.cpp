#include <iostream>
#include <vector>
using namespace std;


typedef vector<int>::iterator VIITER;
int removeElement(vector<int>& nums, int val) {
    VIITER itEnd = nums.end();
    VIITER itBeg = nums.begin();
    VIITER it = itBeg;
    VIITER itSlow = it;
    for(; it < itEnd; ++it){
        if(*it != val){
            *itSlow = *it;
            itSlow++;
        }
    }
    return (int)(itSlow - itBeg);
}
int main()
{
    vector<int> vi;
    vi.push_back(3);
    vi.push_back(2);
    vi.push_back(2);
    vi.push_back(3);
    cout << removeElement(vi,3) << endl;
    return 0;
}
