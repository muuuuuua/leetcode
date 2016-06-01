/**
 * 115. Distinct Subsequences
 */
#include "inc/common.h"

int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    if(m < n) return 0;
    if(s == t) return 1;
    if(m == n) return 0;
    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
    for(int i = 0;i < m+1;i++)
        dp[i][0] = 1;
    for(int i = 1;i < m+1;i++) {
        for(int j = 1;j < n+1;j++) {
            if(j > i) break;
            if(s[i-1] == t[j-1]) 
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[m][n];
}

int main() {
    cout<<numDistinct("rabbbit", "rabbit")<<endl;
    return 0;
}
