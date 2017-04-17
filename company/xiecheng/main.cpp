#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <vector>
int maxNum(int k){
    std::vector<int> vi(50,0);
    int i = 0;
    for(int j = 2; j < k + 1; ++j){
        vi[i++] = j;
        k = k - j;
    }

    if(k != 0){
//        if(k == i + 1){
//            vi[i - 1]++;
//            k--;
//        }
        for(int j = 0; j < k; ++j){
            vi[i - j - 1]++;
        }
    }
    int max = 1;
    for(int j = 0; j < i; ++j){
        max = max * vi[j];
    }
    return max;
}
int main() {
    int res;
    int _k;
    scanf("%d", &_k);
    res = maxNum(_k);
    printf("%d\n", res);
    return 0;
}