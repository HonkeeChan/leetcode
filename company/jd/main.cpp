#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

double calcRightNProb(int);
void combine(vector<int>& data, int n, int m, vector<int>& temp, const int M, vector<vector<int>> & res);

vector<int> data;
vector<int> p;
int n;
int main(){

    cin >> n;
    p = vector<int>(n,0);
    for(int i = 0; i < n; ++i){
        int input;
        cin >> input;
        p[i] = input;
    }

    int rightNum = ceil(n * 0.6);
    data = vector<int>(n, 0);
    for(int i = 0; i < n; ++i){
        data[i] = i;
    }
    double resProb = 0.0;
    for(int i = rightNum; i <= n; ++i){
        resProb += calcRightNProb(i);
    }
    cout << fixed << setprecision(5)  << resProb << endl;

    return 0;
}

double calcRightNProb(int rightNum){
    double prob = 0.0;
    vector<int> temp(rightNum, 0);
    vector<vector<int>> res;
    combine(data, n, rightNum, temp, rightNum, res);

    for(int i = 0; i < res.size(); ++i){
        vector<int> right(n, 0);
        for(int j = 0; j < res[i].size(); ++j){
            right[res[i][j]] = 1;
        }
        double onetimep = 1.0;
        for(int k = 0; k < n; ++k){
            if(right[k] == 1)
                onetimep *= p[k] / 100.0;
            else
                onetimep *= (1 - p[k] / 100.0);
        }
        prob += onetimep;

    }
    return prob;
}

void combine(vector<int>& data, int n, int m, vector<int>& temp, const int M, vector<vector<int>> & res){
    for(int i = n; i >=m; --i){
        temp[m - 1] = i - 1;
        if(m > 1)
            combine(data, i - 1, m - 1, temp, M, res);
        else{
            vector<int> vi;
            for(int j = M - 1; j >=0; --j){
                vi.push_back(data[temp[j]]);
            }
            res.push_back(vi);
        }
    }
}


//void fun1(){
//
//    int n;
//    string str1, str2;
//    cin >> n >> str1 >> str2;
//    string res;
//    for(int i = 0; i < n; ++i){
//        res += ((str1[i] - '0') ^ (str2[i] - '0')) + '0';
//    }
//    long resInt = 0;
//    int base = 1;
//    for(int i = n - 1; i >= 0; --i){
//        resInt += base * (res[i] - '0');
//        base = base * 2;
//    }
//    cout << resInt << endl;
//
//    return 0;
//}