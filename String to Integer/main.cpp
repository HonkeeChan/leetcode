#include <iostream>
#include <sstream>
using namespace std;

typedef string::iterator SIT;
int myAtoi(string str) {
    //stringstream ss;
    if(str == ""){
        return 0;
    }
    bool neg = false;
    long ret = 0;
    size_t begIdx =  str.find_first_not_of(" ");
    if(str[begIdx] == '-'){
        neg = true;
        begIdx += 1;
        //begIdx =  str.find_first_of("0123456789",begIdx + 1);
    }else if(str[begIdx] == '+'){
        begIdx += 1;
    }else if(str[begIdx] >= '0' && str[begIdx] <= '9'){

    }else{
        return 0;
    }
    for(size_t i = begIdx; i < str.length(); ++i){
        if(str[i] >= '0' && str[i] <= '9'){
            ret = 10 * ret + str[i] - '0';
            if(ret > INT_MAX || i - begIdx > 10){
                if(neg){
                    return INT_MIN;
                } else
                    return INT_MAX;
            }
        }else {
            if (neg) {
                return (int)ret * -1;
            } else {
                return (int)ret;
            }
        }
    }
    if(neg){
        return (int)ret * -1;
    }else{
        return (int)ret;
    }
}

int main() {
    while(1){
        string s;
        cin >> s;
        cout << myAtoi(s) << endl;
    }
    return 0;
}