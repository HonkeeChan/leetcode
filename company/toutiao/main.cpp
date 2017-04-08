#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cstdio>

using namespace std;
void getword(const string& para, vector<string>& );
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> paragrah;
    vector<string> query;
    vector<unordered_set<string>> vset;
    for(int i = 0; i < n; ++i){

        char buf[100];
        gets(buf);
        string s(buf);
        //getline(cin, s);
        vector<string> wordsVector;
        wordsVector.reserve(32);
        getword(s, wordsVector);

        unordered_set<string> stringSet;
        for(int j = 0; j < wordsVector.size(); ++j){
            stringSet.insert(wordsVector[j]);
        }
        vset.push_back(stringSet);
        paragrah.push_back(s);
    }
    for(int i = 0; i < m; ++i){
        string s;
        getline(cin, s);

        vector<string> wordsVector;
        wordsVector.reserve(32);
        getword(s, wordsVector);

        unordered_set<string> stringSet;
        for(int j = 0; j < wordsVector.size(); ++j){
            stringSet.insert(wordsVector[j]);
        }
        vector<int> repeatWordCnt(paragrah.size(), 0);
        for(int parIdx = 0; parIdx < paragrah.size(); ++parIdx){
            for(auto iter = stringSet.begin(); iter != stringSet.end(); ++iter){
                if(vset[parIdx].find(*iter) != vset[parIdx].end()){
                    repeatWordCnt[parIdx] ++;
                }
            }
        }
        int max = 0;
        int maxidx = -1;
        for(int j = 0; j < repeatWordCnt.size(); ++j){
            if(max < repeatWordCnt[j]){
                maxidx = j;
                max = repeatWordCnt[j];
            }
        }
        cout << paragrah[maxidx] << endl;

        //query.push_back(s);
    }




    return 0;
}

void getword(const string& para, vector<string>& vs){
    if(para.length() > 0){
        size_t  prePos = 0;
        size_t curPos = 0;
        while((curPos = para.find(" ", prePos)) != string::npos){
            string s = para.substr(prePos, curPos - prePos);
            vs.push_back(s);
            prePos = curPos + 1;
        }
        string s = para.substr(prePos);
        vs.push_back(s);
    }
}

//void fun1(){
//    int n;
//    cin >> n;
//    vector<int> vi;
//    vi.reserve(n);
//    int* pI = new int[n + 1];
//    int* pI2 = new int[n + 1];
//    pI2[0] = 0;
//    int *pEverUp = pI2 + 1;
//    pI[0] = 0;
//    int * pTimes = pI + 1;
//    int k = n;
//    while(k--){
//        int i;
//        cin >> i;
//        vi.push_back(i);
//    }
//    if(n < 3){
//        cout << -1 << " " << -1 << endl;
//        return 0;
//    }
//
//    bool isUp = false;
//    bool isEverUp = false;
//    for(int i = 0; i < vi.size(); ++i) {
//        if (vi[i + 1] > vi[i] && isUp == false) {
//            isUp = true;
//            if(i == 0)
//                pEverUp[-1] = 1;
//            pTimes[i] = 1;
//            pEverUp[i] = 1;
//        } else if (vi[i + 1] < vi[i] && isUp == true) {
//            pTimes[i] = pTimes[i - 1] + 1;
//            isUp = false;
//            pEverUp[i] = pEverUp[i - 1];
//        } else if (vi[i + 1] < vi[i] && isUp == false) {
//            pTimes[i] = pTimes[i - 1] + 1;
//            pEverUp[i] = pEverUp[i - 1];
//        }else if (vi[i + 1] > vi[i] && isUp == true) {
//            pTimes[i] = pTimes[i - 1] + 1;
//            pEverUp[i] = pEverUp[i - 1];
//        }
//    }
//    //vector<int> v(pTimes, pTimes + n);
//    for(int i = 0; i < n; ++i){
//        if(pTimes[i] == 1 && pTimes[i - 1] > 1 && vi[i] < vi[i - 1]){
//            pTimes[i] = -(pTimes[i - 1] + 1);
//        }
//    }
//    if(vi[n - 1] < vi[n - 2]){
//        pTimes[n - 1] = - pTimes[n - 1];
//    }
//    vector<int> v1(pEverUp, pEverUp + n);
//    vector<int> v(pTimes, pTimes + n);
//    int max = 0;
//    int maxIdx = -1;
//    for(int i = 0; i < n+1; ++i){
//        if(pTimes[i] < 0 && pEverUp[i - 1] == 1 && max < abs(pTimes[i]) ){
//            max = abs(pTimes[i]);
//            maxIdx = i;
//        }
//    }
//    int minIdx = maxIdx;
//    //pTimes[maxIdx] = - pTimes[maxIdx];
//    for(; minIdx > 0; --minIdx){
//        if(abs(pTimes[minIdx]) < abs(pTimes[minIdx - 1])){
//            if(minIdx != 0){
//                minIdx--;
//            }
//            break;
//        }
//    }
//
//    if(max == 0){
//        cout << -1 << " " << -1 << endl;
//    }else{
//        cout << minIdx << " " << maxIdx << endl;
//    }
//}