#include <iostream>
#include <string>
using namespace std;


string speakString(string s){
    size_t idx = 0;
    size_t next_char_idx;
    char cur = s[0];
    string ret = "";
    while ((next_char_idx = s.find_first_not_of(cur, idx)) != -1){

        ret += '0' + next_char_idx - idx;
        ret += cur;
        cur = s[next_char_idx];
        idx = next_char_idx;
    }
    ret += '0' + s.size() - idx;
    ret += cur;
    return ret;
}
string countAndSay(int n) {
    if(n <= 0)
        return "";
    if(n < 2)
        return "1";
    string ret = "1";
    for(int i = 1; i < n; ++i){
        ret = speakString(ret);
    }
    return ret;
}
int main() {
    cout<< countAndSay(2) << endl;
    cout<< countAndSay(3) << endl;
    cout<< countAndSay(4) << endl;
    cout<< countAndSay(10) << endl;


    return 0;
}