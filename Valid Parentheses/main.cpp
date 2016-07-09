#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
    string parenthesLeft = "([{";
    string parenthesRight = ")]}";
    //char a[6] = {'(',')','[',']','{','}'};
    if(s.length() % 2 != 0){
        return false;
    }
    stack<char> charSatck;
    typedef string::iterator SIT;
    SIT itEnd = s.end();
    size_t ind = -1;
    for(SIT it = s.begin(); it != itEnd; ++it){
        if( (ind = parenthesRight.find(*it)) != -1){
            if(charSatck.size() <= 0){
                return false;
            }
            if(charSatck.top() == parenthesLeft[ind]){
                charSatck.pop();
            }else{
                return false;
            }
        }else{
            charSatck.push(*it);
        }
    }
    if(charSatck.size() == 0)
        return true;
    else
        return false;
}
int main()
{
    while (1){
        string s;
        cin >> s;
        cout << isValid(s) << endl;
    }

    return 0;
}
