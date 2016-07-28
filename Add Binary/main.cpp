#include <iostream>
#include <string>
using namespace std;
typedef string::reverse_iterator SRI;
string addBinary(string a, string b) {

    if(b.length() == 0)
        return a;
    if(a.length() == 0)
        return b;

    string longStr, shortStr;
    if(a.length() > b.length()){
        longStr = a;
        shortStr = b;
    }else{
        longStr = b;
        shortStr = a;
    }
    SRI lri = longStr.rbegin();
    SRI sri = shortStr.rbegin();
    SRI sriEnd = shortStr.rend();
    SRI lriEnd = longStr.rend();
    int carry = 0;
    while(sri != sriEnd){
        if(*lri -'0' + *sri - '0' + carry >= 2){
            *lri =  char((*lri + *sri - '0' - '0' + carry) % 2 + '0');
            carry = 1;
        }else{
            *lri += *sri - '0' + carry;
            carry = 0;
        }
        lri++;
        sri++;
    }
    while(carry && lri != lriEnd){
        if(*lri + carry - '0' >= 2){
            *lri = char((*lri - '0' + carry) % 2 + '0') ;
            cout << *lri << endl;
            carry = 1;
        }else{
            *lri += carry;
            carry = 0;
        }
        ++lri;
    }
    if(lri == lriEnd && carry){
        longStr.insert(longStr.begin(), '1');
    }
    return longStr;
}
int main() {
    cout << addBinary("101111","10") << endl;
    return 0;
}