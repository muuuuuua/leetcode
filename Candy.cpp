/**
 * 135. Candy
 */
#include "inc/common.h"

int max(int a, int b) {
    return a>b?a:b;
}

int candy(vector<int>& ratings) {
    int n = ratings.size();
    if(n == 0) return 0;
    vector<int> res(n, 1);
    for(int i = 1;i < n;i++) {
        if(ratings[i] > ratings[i-1])
            res[i] = res[i-1]+1;
    }
    for(int i = n-2;i >= 0;i--) {
        if(ratings[i] > ratings[i+1])
            res[i] = max(res[i], res[i+1]+1);
    }
    int sum = 0;
    for(int i = 0;i < n;i++) {
        sum += res[i];
    }
    return sum;
}

int main() {
    int a[] = {0};
    vector<int> b = arrayToVector(a);
    cout<<candy(b)<<endl;
    return 0;
}
