#include <iostream>

using namespace std;
int lengthOfLastWord(string s) {
    if(s == "")
        return 0;
    size_t word_end_idx = s.find_last_not_of(' ');
    if( word_end_idx == -1)
        return 0;
    size_t word_beg_idx = s.find_last_of(' ', word_end_idx);
    return int(word_end_idx - word_beg_idx);
}
int main() {
    cout << lengthOfLastWord("hello world") << endl;
    return 0;
}