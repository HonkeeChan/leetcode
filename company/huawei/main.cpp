//算法复杂度O(n)

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int main() {

        int n;
        cin >> n;
        vector<string> vs;
        while(n--){
            string s;
            cin >> s;
            sort(s.begin(), s.end());
            vs.push_back(s);
        }
        sort(vs.begin(), vs.end());
        vector<string>::iterator pre = vs.begin();
        vector<string>::iterator it = pre + 1;
        int cnt = 1;
        for(; it != vs.end(); ++it){
            if(*pre != *it){
                cnt++;
                pre = it;
            }
        }
        cout << cnt << endl;
        return 0;


}

//
//
//void postExpression(){
//    string input;
//    cin >> input;
//    stack<int> s;
//    //int i = 0;
//    for(string::iterator iter = input.begin(); iter != input.end(); ++iter){
//        if(*iter >= '0' && *iter <= '9'){
//            s.push(*iter - '0');
//        }else if(*iter >= 'A' && *iter <= 'F'){
//            s.push(*iter - 'A' + 10);
//        }else if(*iter == '/'){
//            int a = s.top();
//            s.pop();
//            int b  = s.top();
//            s.pop();
//            int c = b / a;
//            s.push(c);
//        }else if(*iter == '*'){
//            int a = s.top();
//            s.pop();
//            int b  = s.top();
//            s.pop();
//            int c = b * a;
//            s.push(c);
//        }else if(*iter == '+'){
//            int a = s.top();
//            s.pop();
//            int b  = s.top();
//            s.pop();
//            int c = b + a;
//            s.push(c);
//        }else if(*iter == '-'){
//            int a = s.top();
//            s.pop();
//            int b  = s.top();
//            s.pop();
//            int c = b - a;
//            s.push(c);
//        }
//    }
//    cout << s.top();
//}


//void fun1(){
//    int offset, n, l1, l2;
//    while(cin >> offset >> n >> l1 >> l2){
//        int start1 = 0;
//        int end1 = 0;
//        int start2 = 0;
//        int end2 = 0;
//        int lilunStart;
//        int lilunEnd;
//        if(l1 <  offset){
//            start1 = l1;
//            end1 = l1;
//            int left = offset - l1;
//            start2 = left > l2 ? l2 : left;
//            lilunEnd = start2 + n;
//            end2 = lilunEnd > l2 ? l2 : lilunEnd;
//
//        }else if(l1 > offset + n){
//            start2 = 0;
//            end2 = 0;
//            start1 = offset;
//            end1 = offset + n;
//        }else{
//            start1 = offset;
//            end1 = l1;
//            start2 = 0;
//            lilunEnd = n - l1 + offset;
//            end2 = lilunEnd > l2 ? l2: lilunEnd;
//        }
//        cout << start1 << " " << end1 << " "  << start2 << " "  << end2 << endl;
//    }
//}

//void fun2(){
//    stack<int> si;
//    vector<int> li;
//    string input;
//    cin >> input;
//    size_t pos = 0;
//    size_t prePos = 0;
//    while((pos = input.find(",", prePos)) != string::npos){
//        string sub = input.substr(prePos, pos - prePos);
//        int i = atoi(sub.c_str());
//        li.push_back(i);
//        prePos = pos + 1;
//    }
//    string sub = input.substr(prePos);
//    int i = atoi(sub.c_str());
//    li.push_back(i);
//
//    vector<int>::iterator faster = li.begin();
//    vector<int>::iterator slower = li.begin();
//    vector<int>::iterator fasetr1 = faster;
//    if(++fasetr1 == li.end()){
//        cout << 1 << endl;
//        return 0;
//    }
//    bool isOdd = false;
//    si.push(*slower);
//    while(faster != li.end()){
//        if(++faster == li.end()){
//            isOdd = true;
//            break;
//        }
//        if(++faster == li.end()){
//            isOdd = false;
//            break;
//        }
//
//        slower++;
//        si.push(*slower);
//
//    }
//    if(isOdd){
//        si.pop();
//    }
//    while(++slower != li.end()){
//        if( si.size() == 0 || *slower != si.top()){
//            cout << 0 << endl;
//            return 0;
//        }
//        si.pop();
//    }
//    cout << 1 << endl;
//    return 0;
//}