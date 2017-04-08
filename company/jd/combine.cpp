#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

double combine(int m, int level,const int N, const int M, int* res);
int *pProb = NULL;
bool *pPass = NULL;
int main(){
    int n;
    cin >> n;
    pProb = new int[n];
    for(int i = 0; i < n; ++i){
        int p;
        cin >> p;
        pProb[i] = p;
    }
    
    int m = ceil(n * 0.6);
    int* result;
    pPass = new bool[n];

    double res = 0.0;
    for(int i = m; i <= n; ++i){
        result = new int[i];
        //cout << n << m << endl;
        res += combine(0, 0, n, i, result);
        delete [] result;
    }
    cout << fixed << setprecision(5) << res << endl;
    
    return 0;
}
double combine(int m, int level, const int N, const int M, int* res){
    double ret = 0.0;
    for(int i = m; i <= N - M + level ; ++i){
        if(level == M - 1){
            res[level] = i;
            double d = 1.0;
            memset(pPass, 0, sizeof(bool) * N);
            for(int k = 0; k < M; ++k ){
                pPass[k] = 1;
            }
            for(int k = 0; k < N; ++k){
                if(pPass[k] == 0){
                    d *= 1 - pProb[k] / 100.0;
                }else{
                    d *= pProb[k] / 100.0;
                }
                
            }
            ret += d;
        }else if(level < M - 1){
            res[level] = i;
            ret += combine(i + 1, level + 1, N, M, res);
            //res[m] = i;
        }
    }
    //cout << ret << endl;
    return ret;
    
}