#include <iostream>
#include <cmath>
#include <sstream>
#include <ctime>
using namespace std;

//no extra space
bool isPalindrome(int x) {
    if (x < 0){
        return false;
    }
    if(x == 0){
        return true;
    }
    long i = 1;
    int cnt = 0;
    while(x / i != 0){
        i = i * 10;
        cnt++;
    }
    int high, low;
    i = ((int)pow(10,cnt/2));
    if(cnt % 2 == 0){

        high = x / i;
        low = x % i;
    }else{
        high = x / (i*10);
        low = x % i;
    }
    i /= 10;
    int j = 10;
    for(int t = 0; t < cnt / 2; ++t){
        if(high / i != low % j){
            return false;
        }
        high %= i;
        low /= j;
        i /= 10;
        //j *= 10;
    }
    return true;

}

bool isPalidrome_string(int x){
    if(x < 0){
        return false;
    }
    if(x == 0){
        return true;
    }
    stringstream ss;
    string s;
    while(x > 0){
        ss << x % 10;
        x /= 10;
    }
    ss >> s;
    size_t len = s.length();
    for(size_t i = 0, j = len - 1; i < s.length() / 2; ++i, --j){
        if(s[i] != s[j]){
            return false;
        }
    }
    return true;
}

string int2string_ss(int i){
    stringstream ss;
    ss << i;
    string s;
    ss >> s;
    return s;
}
string int2string_math_reverse(int i){
    string s;
    while(i > 0){
        s.push_back('0' + i % 10);
        i /= 10;
    }
    return s;
}
string int2string_math_mod(int i){
    string s;
    while(i > 0){
        s.push_back('0' + i % 10);
        i /= 10;
    }
    string s_r;
    for(string::reverse_iterator riter = s.rbegin(); riter != s.rend(); ++riter){
        s_r.push_back(*riter);
    }
    return s_r;
}
string int2string_math_div(int i){
    long x = 1;
    while(i / x != 0){
        x *= 10;
    }
    x /= 10;
    string s;
    while(i > 0){
        s.push_back('0' + i / (int)x);
        i %= x;
        x /= 10;
    }
    return s;
}
int main() {

    time_t start = time(NULL);
    for(int i = 0; i < 10000000; ++i){
        int2string_math_div(i);
    }
    cout << "using div cost: "<< difftime(time(NULL), start)<< endl;
    start = time(NULL);
    for(int i = 0; i < 10000000; ++i){
        int2string_math_mod(i);
    }
    cout << "using mod cost: "<< difftime(time(NULL), start)<< endl;
    start = time(NULL);
    for(int i = 0; i < 10000000; ++i){
        int2string_ss(i);
    }
    cout << "using ss cost: "<< difftime(time(NULL), start)<< endl;
//    cout << int2string_math_mod(123) << endl;
//    cout << int2string_ss(123) << endl;
//    cout << int2string_math_div(123) << endl;
    return 0;
}