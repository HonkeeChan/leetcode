#include <iostream>
#include <string>

using namespace std;
string longestPalindrome(string s) {
    int maxLen = 0;
    string maxLenStr = "";
    int len = s.length();
    for(int i = 0; i < len; ++i){
        if(i - 1 >= 0 &&
           i + 1 < len &&
           s[i - 1] == s[i + 1]){
            int offset = 1;
            while(i - offset >= 0 && i + offset < len){
                if(s[i - offset] == s[i + offset]){

                    if(offset * 2 + 1 > maxLen){
                        maxLen = offset * 2 + 1;
                        maxLenStr = s.substr(i - offset, offset * 2 + 1);
                    }
                    offset++;
                }else{
                    break;
                }
            }

        }
        if(i + 1 < len && s[i] == s[i+1]){
            int offset = 1;
            while(i - offset + 1 >= 0 && i + offset < len){
                if(s[i - offset + 1] == s[i + offset]){

                    if(offset * 2  > maxLen){
                        maxLen = offset * 2;
                        maxLenStr = s.substr(i - offset + 1, offset * 2);
                    }
                    offset++;
                }else{
                    break;
                }
            }

        }else{
            if(1 > maxLen){
                maxLen = 1;
                maxLenStr = s.substr(i, 1);
            }
            continue;
        }
    }
    return maxLenStr;
    }

int main() {
    string str;
    while(cin >> str){
        longestPalindrome(str);
    }
    return 0;
}