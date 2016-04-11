/**
 274. H-Index
 */
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& a, int l, int r) {
    if(l >= r)
        return l;
    int x = a[r];
    int j = l;
    for(int i = l;i < r;i++) {
        if(a[i] < x) {
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[r], a[j]);
    return j;
}

void qsort(vector<int>& a, int l, int r) {
    if(l >= r)
        return;
    int mid = partition(a, l, r);
    qsort(a, l, mid-1);
    qsort(a, mid+1, r);
}

int hIndex(vector<int>& citations) {
    qsort(citations, 0, citations.size()-1);
    for(int i = 0;i < citations.size();i++) {
        if(citations[i] >= citations.size()-i)
            return citations.size()-i;
    }
    return 0;
}

int main() {
    int a[] = {3,0,6,1,5};
    vector<int> c(a, a+5);
    cout<<hIndex(c)<<endl;
    return 0;
}
