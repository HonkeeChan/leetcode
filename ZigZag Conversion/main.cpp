#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string convert(string text, int nRows);
void getNextIndex(int& r, int& c, bool& b, int maxRows);
int main() {
    //cout << convert(string("PAYPALISHIRING"), 3); //should return "PAHNAPLSIIGYIR"
    //cout << convert(string("ABCDEF"), 1);
    cout << convert(string("A"), 2);
//    string s = string("string");
//    for(int i = 0; i < 3; ++i){
//        cout << s[i];
//    }
    return 0;
}

string convert(string text, int nRows){

    size_t textLen = text.length();
    char *pIndex = new char[textLen * nRows];
    memset(pIndex, 0, (int)textLen * nRows * sizeof(char));

    bool bUp = false;
    int r = 0, c = 0;
    int colMax = 0;
    for(int i = 0; i < (int)textLen; ++i){

        pIndex[textLen * r + c] = text[i];
        printf("index r: %d, c: %d is char: %c\n", r, c, text[i]);
        if (colMax < c)
            colMax = c;
        getNextIndex(r, c, bUp, nRows);
    }
    //int colMax = c;
    stringstream ss;
    printf("read\n");
    for(int r = 0; r < nRows; ++r){
        for(int c = 0; c <= colMax; ++c){
            if(pIndex[textLen * r + c] != 0){
                printf("index r: %d, c: %d is char: %c\n", r, c, pIndex[textLen * r + c]);
                ss << pIndex[textLen * r + c];
            }
        }
    }

    string ret;
    ss >> ret;
    return ret;

}

void getNextIndex(int& r, int& c, bool& bUp, int maxRows){
    if(maxRows == 1){
        c += 1;
    }
    else if(bUp){
        r -= 1;
        c += 1;
        if(r == 0)
            bUp = false;
    }else{
        r += 1;
        if(r == maxRows - 1)
            bUp = true;
    }
}