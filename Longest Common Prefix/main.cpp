#include <iostream>
#include <string>
#include <vector>
using namespace std;


typedef vector<string>::iterator VSIT;
string longestCommonPrefix(vector<string>& strs) {
    VSIT itend = strs.end();
    VSIT itbeg = strs.begin();
    bool retFlag = false;
    int curIndex = 0;
    if(strs.size() <= 0){
        return string("");
    }
    char c = '\0';
    while( !retFlag ){
        for(VSIT it = strs.begin(); it != itend; ++it){
            if((*it).length() > curIndex){
                if(it == itbeg){
                    c = (*it)[curIndex];
                    continue;
                }
                if((*it)[curIndex] != c){
                    retFlag = true;
                    break;
                }

            }else{
                retFlag = true;
            }
        }
        if(!retFlag)
            curIndex++;
    }
//    if(curIndex)
//        return strs[0].substr(0,curIndex);
//    else
//        return string("");
    return strs[0].substr(0,curIndex);
}
int main() {
    string s0 = "12";
    string s1 = "1";
    vector<string> vs;
    vs.push_back(s0);
    vs.push_back(s1);
    vector<string> vs_empty;
    cout << longestCommonPrefix(vs_empty) << endl;
    cout << "end" << endl;
    return 0;
}