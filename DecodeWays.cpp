/**
 * 91. Decode Ways
 */
#include "inc/common.h"

int numDecodings(string s) {
    int n = s.size();
    if(n == 0 || s[0] == '0') return 0;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2;i <= n;i++) {
        if(s[i-1] == '0') {
            if(s[i-2] == '1' || s[i-2] == '2')
                dp[i] = dp[i-2];
            else
                return 0;
        }
        else if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6' && s[i-1] >= '1'))
            dp[i] = dp[i-1]+dp[i-2];
        else
            dp[i] = dp[i-1];
    }
    return dp[n];
}

int main() {
    cout<<numDecodings("12")<<endl;
    return 0;
}
