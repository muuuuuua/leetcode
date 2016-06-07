/**
 * 354. Russian Doll Envelopes
 */
#include "inc/common.h"

bool contain(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first && a.second > b.second;
}

int maxEnvelopes(vector<pair<int, int> >& envelopes) {
    int n = envelopes.size();
    if(n <= 1)
        return n;
    sort(envelopes.begin(), envelopes.end());
    vector<int> dp(n, 1);
    for(int i = 1;i < n;i++) {
        for(int j = 0;j < i;j++) {
            if(contain(envelopes[i], envelopes[j]))
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    int m = 0;
    for(int i = 0;i < n;i++)
        m = max(m, dp[i]);
    return m;
}

int main() {
    vector<pair<int, int> > envelopes;
    envelopes.push_back(pair<int,int>(5,4));
    envelopes.push_back(pair<int,int>(6,4));
    envelopes.push_back(pair<int,int>(6,7));
    envelopes.push_back(pair<int,int>(2,3));
    cout<<maxEnvelopes(envelopes)<<endl;
    return 0;
}
