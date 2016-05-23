/**
 * 97. Interleaving String
 */
#include "inc/common.h"

bool isInterleave(string s1, string s2, string s3) {
    if(s1.size()+s2.size() != s3.size())
        return false;
    int m = s1.size();
    int n = s2.size();
    vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
    dp[0][0] = true;
    for(int i = 1;i <= m;i++) {
        if(dp[i-1][0] && s3[i-1] == s1[i-1])
            dp[i][0] = true;
    }
    for(int i = 1;i <= n;i++) {
        if(dp[0][i-1] && s3[i-1] == s2[i-1])
            dp[0][i] = true;
    }
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            if(dp[i][j-1] && s2[j-1] == s3[i+j-1])
                dp[i][j] = true;
            else if(dp[i-1][j] && s1[i-1] == s3[i+j-1])
                dp[i][j] = true;
        }
    }
    return dp[m][n];
}

int main() {
    cout<<isInterleave("aabcc","dbbca","aadbbbaccc")<<endl;
    return 0;
}
