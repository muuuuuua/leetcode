/**
 * 309. Best Time to Buy and Sell Stock with Cooldown
 */
#include "inc/common.h"

int max(int a, int b) {
    return a>b?a:b;
}

int maxProfit(vector<int>& prices) {
    if(prices.size() <= 1)
        return 0;
    int n = prices.size();
    vector<int> sell(n, 0);
    vector<int> cooldown(n, 0);
    sell[1] = max(0, prices[1]-prices[0]);
    for(int i = 2;i < n;i++) {
        cooldown[i] = max(cooldown[i-1], sell[i-1]);
        sell[i] = max(cooldown[i-1], sell[i-1]+prices[i]-prices[i-1]);
    }

    return max(sell[n-1], cooldown[n-1]);
}

int main() {
    int a[] = {1,4,2};
    vector<int> b = arrayToVector(a);
    cout<<maxProfit(b)<<endl;
    return 0;
}
