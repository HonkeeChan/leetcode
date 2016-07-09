#include <iostream>
#include <string>
#include <sstream>
using namespace std;


string int2string(int i);
bool isOverflow(string s);
int reverse(int x);

int main() {
    //cout << int2string(-111) << endl;
    //cout << int2string(1) << endl;
    cout << "sizeof int: " << sizeof(int) <<endl;
    cout << "sizeof long: " << sizeof(long) <<endl;
    cout << "sizeof long int: " << sizeof(long int) <<endl;
    cout << "sizeof long long int: " << sizeof(long long int) <<endl;
    cout << "sizeof long long : " << sizeof(long long) <<endl;
    cout << "-102% 10: " << -102 % 10 << "  -102 / 10: " << -102 / 10 << endl;
    return 0;
}



string int2string(int i){
    stringstream ss;
    ss << i;
    string s;
    ss >> s;
    return s;
}

int reverse(int x){
    string s = int2string(x);
    stringstream ss;
    bool bZero = true;

    string::reverse_iterator sritEnd = s.rend();
    if(x < 0){
        sritEnd--;
        ss.clear();
        ss << '-';
    }
    for(string::reverse_iterator srit = s.rbegin(); srit != sritEnd; ++srit){

        if(bZero && *srit == '0'){

        }else{
            if( *srit != '0'){
                bZero = false;
            }
            ss << *srit;
        }
    }

    string result;
    ss >> result;
    int iret;
    if(isOverflow(result)){
        iret = 0;
    }else{
        ss.clear();
        ss << result;
        ss >> iret;
    }
    return iret;
}

bool isOverflow(string s){
    // -2,147,483,648 ~ 2,147,483,647
//    string lowerbound = "-102";
//    string upperbound = "101";
    string lowerbound = "-2147483648";
    string upperbound = "2147483647";
    if(s[0] == '-'){
        if(s.length() > lowerbound.length())
            return true;
        if(s.length() < lowerbound.length())
            return false;
        if(s > lowerbound)
            return true;
        else
            return false;
    }else{
        if(s.length() > upperbound.length())
            return true;
        if(s.length() < upperbound.length())
            return false;
        if(s > upperbound)
            return true;
        else
            return false;
    }
}
