/**
 * 350. Intersection of Two Arrays II
 */
#include "inc/common.h"

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    if(nums1.size() == 0 || nums2.size() == 0)
        return res;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    while(i < nums1.size() && j < nums2.size()) {
        int candidate = nums1[i];
        while(j < nums2.size() && nums2[j] < candidate)
            j++;
        if(j == nums2.size())
            break;
        if(nums2[j] == candidate) {
            j++;
            res.push_back(candidate);
        }
        i++;
    }
    return res;
}

int main() {
    int a[] = {1,2,2,2,1};
    int b[] = {2,2,2};
    vector<int> c = arrayToVector(a);
    vector<int> d = arrayToVector(b);
    vector<int> r = intersect(c, d);
    print(r);
    return 0;
}
