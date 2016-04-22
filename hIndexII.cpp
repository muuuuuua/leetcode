/**
 * 275. H-Index II
 */
#include "inc/common.h"

int binaryFind(vector<int>& citations, int l, int r) {
    if(l == r) {
        if(citations[l] >= citations.size()-l)
            return l;
        else
            return citations.size();
    }
    int mid = (l+r)/2;
    if(citations[mid] >= citations.size()-mid) {
        if(mid-1 >= 0 && citations[mid-1] >= citations.size()-mid+1)
            return binaryFind(citations, l, mid-1);
        else
            return mid;
    }
    else
        return binaryFind(citations, mid+1, r);
}

int hIndex(vector<int>& citations) {
    if(citations.size() == 0)
        return 0;
    return citations.size() - binaryFind(citations, 0, citations.size()-1);
}

int main() {
    int a[] = {0,1,3,5,6};
    vector<int> c = arrayToVector(a);
    cout<<hIndex(c)<<endl;
    return 0;
}
