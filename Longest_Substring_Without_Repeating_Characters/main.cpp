#include <iostream>
#include <string>

using namespace std;
int lengthOfLongestSubstring(string s) {
    if(s == ""){
        return 0;
    }
    int* preIdx = new int[256];
    //memset(preIdx, , sizeof(char) * 256);
    for(int i = 0; i < 256; ++i)
        preIdx[i] = -1;
    int len = s.length();
    int* substrBeg = new int[len];
    substrBeg[0] = 0;
    preIdx[s[0]] = 0;
    for(int idx = 1; idx < len; ++idx){

        substrBeg[idx] = max(int(preIdx[s[idx]] + 1), int(substrBeg[idx - 1]));
        preIdx[s[idx]] = idx;
    }
    int maxLen = 1;
    for(int i = 0; i < len; ++i){
        if(i - substrBeg[i] + 1> maxLen){
            maxLen = i - substrBeg[i] + 1 ;
        }
    }
    return maxLen;
}

int main() {
    string str;
    while(cin >> str){
        lengthOfLongestSubstring(str);
    }
    return 0;
}