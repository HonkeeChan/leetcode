#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    typedef vector<int>::iterator VIT;
    typedef vector<int>::reverse_iterator VIRT;
    int n;
    cin >> n;
    vector<int> vi;
    vi.reserve(50);
    while(n--){
        int length;
        cin >> length;
        vi.push_back(length);
    }

    sort(vi.begin(), vi.end());
    long sum = 0;
    for(VIT it = vi.begin(); it !=vi.end(); ++it){
        sum += *it;
    }
    long half = sum /2;
    long min = half;
    do{
        long cur = 0;
        for(VIT it = vi.begin(); it != vi.end() && cur <= half; ++it){
            cur += *it;
            if(half - cur < min && half > cur){
                min = half - cur;
            }
        }
    }while(next_permutation(vi.begin(),vi.end()));
    cout << (half + min) << endl;


    return 0;
}
//
//void fun2(){
//    unordered_set<float> fset;
//    int w,x,y,z;
//    vector<int> p;
//    p.reserve(100);
//    vector<int> q;
//    q.reserve(100);
//    cin >> w >> x >> y >> z;
//    for(int i = w; i <= x; ++i){
//        p.push_back(i);
//    }
//    for(int i = y; i <= z; ++i){
//        q.push_back(i);
//    }
//    typedef vector<int>::iterator VIT;
//    int cnt = 0;
//    for(VIT itp = p.begin(); itp!= p.end(); ++itp){
//        for(VIT itq = q.begin(); itq != q.end(); ++itq){
//            float f = (float)*itp / *itq;
//            if(fset.find(f) == fset.end()){
//                fset.insert(f);
//                cnt ++;
//            }
//        }
//    }
//    cout << cnt << endl;
//}

//void fun1(){
//    string str;
//    stack<int> si;
//    cin >> str;
//    string::iterator it = str.begin();
//    int sum = *it - '0';
//    ++it;
//    for(; it != str.end(); ++it){
//        if(*it == '+'){
//            sum += *(++it) - '0';
//        }else if(*it == '-'){
//            sum -= *(++it) - '0';
//        }else if(*it == '*'){
//            sum *= *(++it) - '0';
//        }else{
//
//        }
//    }
//    cout << sum << endl;
//}

//
//void fun1(){
//    int n;
//    cin >> n;
//    for(int i = 0; i <  n; ++i){
//        string add1;
//        string add2;
//        int sum;
//        cin >> add1 >> add2 >> sum;
////        vector<int> vi1;
////        vector<int> vi2;
//        set<int> si1;
//        set<int> si2;
//        strToIntArr(add1, si1);
//        strToIntArr(add2, si2);
//        int cnt = 0;
//
//        for(set<int>::iterator iter1 =  si1.begin(); iter1 != si1.end(); ++iter1){
//            for(set<int>::iterator iter2 = si2.begin(); iter2 != si2.end(); ++ iter2){
//                if(*iter1 + *iter2 == sum){
//                    cnt++;
//                }
//            }
//        }
//        cout << cnt << endl;
//        //copy(si1.begin(), si1.end(), ostream_iterator<int>(cout," "));
//
//    }
//}
//
//void strToIntArr(string str, set<int>& vi){
//    int bai = 0;
//    int shi = 0;
//    int num = 0;
//    if(str.length() ==  3){
//
//        for(int i = 1; i <= 9; ++i){
//            if(str[0] == 'X'){
//                bai = i * 100;
//            }else{
//                bai = (str[0] - '0') * 100;
//            }
//
//            for(int j = 1; j <= 9; ++j){
//                if(str[1] == 'X'){
//                    shi = j * 10;
//                }else{
//                    shi = (str[1] - '0') * 10;
//                }
//                for(int k = 1; k <= 9; ++k){
//                    if(str[2] == 'X'){
//                        num = bai + shi + k;
//                    }else{
//                        num = bai + shi + (str[2] - '0');
//                    }
//                    vi.insert(num);
//                }
//            }
//        }
//    }else if(str.length() == 2){
//        for(int j = 1; j <= 9; ++j){
//            if(str[0] == 'X'){
//                shi = j * 10;
//            }else{
//                shi = (str[0] - '0') * 10;
//            }
//            for(int k = 1; k <= 9; ++k){
//                if(str[1] == 'X'){
//                    num = shi + k;
//                }else{
//                    num = shi + (str[1] - '0');
//                }
//                vi.insert(num);
//            }
//        }
//    }else if(str.length() == 1){
//        for(int k = 1; k <= 9; ++k){
//            if(str[0] == 'X'){
//                num = k;
//            }else{
//                num = (str[0] - '0');
//            }
//            vi.insert(num);
//        }
//    }
//
//
//}

