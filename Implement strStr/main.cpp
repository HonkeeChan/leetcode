#include <iostream>
#include <string>
using namespace std;

/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
typedef string::iterator SIT;
int strStr(string haystack, string needle) {
    if(haystack == needle || needle.size() == 0){
        return 0;
    }
    SIT longItEnd = haystack.end();
    SIT longItBeg = haystack.begin();
    SIT shortItEnd = needle.end();
    SIT shortItBeg = needle.begin();
    SIT longIt = longItBeg;
    SIT shortIt;
    SIT longTmpIt;
    for(; longIt != longItEnd; ++longIt){
        if(*longIt == *shortItBeg){
            for(shortIt = shortItBeg, longTmpIt = longIt;
                        shortIt != shortItEnd; shortIt++, longTmpIt++){
                if(*shortIt != *longTmpIt){
                    break;
                }
            }
            if(shortIt == shortItEnd){
                return (int)(longTmpIt - longItBeg) - needle.size();
            }
        }
    }
    return -1;
}
int main()
{
    cout << strStr("hello woradfald world!", "world") << endl;
    return 0;
}
