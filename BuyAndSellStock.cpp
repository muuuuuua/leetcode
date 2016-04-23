/**
 * 121. Best Time to Buy and Sell Stock
 */
#include "inc/common.h"

int maxProfit(vector<int>& prices) {
    if(prices.size() == 0)
        return 0;
    int min = prices[0];
    int profit = 0;
    for(int i = 1;i < prices.size();i++) {
        profit = profit > prices[i]-min ? profit : prices[i]-min;
        min = min < prices[i] ? min : prices[i];
    }
    return profit;
}

int main() {
    int a[] = {2,1,2,0,1};
    vector<int> b = arrayToVector(a);
    cout<<maxProfit(b)<<endl;
    return 0;
}
