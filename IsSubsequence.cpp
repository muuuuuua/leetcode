/**
 * 392. Is Subsequence
 */
#include "inc/common.h"

int binary_find(vector<int> a, int target) {
    int low = 0, high = a.size()-1;
    while(low < high) {
        int mid = (low+high)/2;
        if(a[mid] >= target)
            high = mid;
        else 
            low = mid + 1;
    }
    if(a[low] >= target)
        return a[low];
    else
        return -1;
}

bool isSubsequence(string s, string t) {
    vector<vector<int> > record(26);
    for(int i = 0;i < t.size();i++) {
        record[t[i]-'a'].push_back(i);
    }
    int index = 0;
    for(int i = 0;i < s.size();i++) {
        if(record[s[i]-'a'].empty()) return false;
        int temp = binary_find(record[s[i]-'a'], index);
        if(temp == -1) return false;
        index = temp+1;
    }
    return true;
}

int main() {
    cout<<isSubsequence("abc", "aabbcc")<<endl;
    return 0;
}
