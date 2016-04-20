/**
 * 228. Summary Ranges
 */
#include "inc/common.h"

vector<string> summaryRanges(vector<int> &nums) {
    vector<string> res;
    if(nums.size() == 0)
        return res;
    int start = nums[0];
    int end = start;
    for(int i = 1;i < nums.size();i++) {
        if(nums[i] == nums[i-1]+1) {
            end = nums[i];
        }
        else {
            if(start == end) {
                string temp;
                stringstream ss;
                ss<<start;
                ss>>temp;
                res.push_back(temp);
            }
            else {
                string s, e;
                stringstream ss1, ss2;
                ss1<<start;
                ss1>>s;
                ss2<<end;
                ss2>>e;
                string temp = s+"->"+e;
                res.push_back(temp);
            }
            start = nums[i];
            end = nums[i];
        }
    }
    if(start == end) {
        string temp;
        stringstream ss;
        ss<<start;
        ss>>temp;
        res.push_back(temp);
    }
    else {
        string s, e;
        stringstream ss1, ss2;
        ss1<<start;
        ss1>>s;
        ss2<<end;
        ss2>>e;
        string temp = s+"->"+e;
        res.push_back(temp);
    }
    return res;
}

int main() {
    int a[] = {0,1,2,4,5,7};
    vector<int> b = arrayToVector(a, 6);
    vector<string> r = summaryRanges(b);
    printVector(r);
    return 0;
}
