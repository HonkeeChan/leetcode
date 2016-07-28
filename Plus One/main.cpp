#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>::reverse_iterator VIRITER;
vector<int> plusOne(vector<int>& digits) {
    VIRITER itrBeg = digits.rbegin();
    VIRITER itrEnd = digits.rend();
    VIRITER rit = itrBeg;
    int carry = 1;
    while(carry && rit != itrEnd){
        if(*rit + carry >= 10){
            *rit = (*rit + carry) % 10;
            carry = 1;
        } else{

            *rit = (*rit + carry);
            carry = 0;
        }
        ++rit;
    }
    if(rit == itrEnd && carry){
        digits.insert(digits.begin(), carry);
    }
    return digits;

}
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}