/**
 * 352. Data Stream as Disjoint Intervals
 */
#include "inc/common.h"

class SummaryRanges {
private:
    vector<Interval> v;
    int binarySearch(int val, vector<Interval> arr, int l, int r) {
        if(l > r) return r;
        if(l == r && arr[l].start <= val) return l;
        if(l == r && arr[l].start > val) return l-1;
        int mid = (l+r)/2;
        if(arr[mid].start == val)
            return mid;
        else if(val < arr[mid].start)
            return binarySearch(val, arr, l, mid-1);
        else
            return binarySearch(val, arr, mid+1, r);
    }
public:
    SummaryRanges() {
    }
    
    void addNum(int val) {
        if(v.empty()) {
            v.push_back(Interval(val, val));
            return;
        }
        int index = binarySearch(val, v, 0, v.size()-1);
        if(index == -1) {
            if(val == v[0].start-1)
                v[0].start = val;
            else
                v.insert(v.begin(), Interval(val, val));
        }
        else if(index == v.size()-1) {
            Interval last = v.back();
            if(last.end+1 < val)
                v.push_back(Interval(val, val));
            else if(last.end+1 == val)
                v[v.size()-1].end = val;
        }
        else {
            if(val > v[index].end+1 && val < v[index+1].start-1)
                v.insert(v.begin()+index+1, Interval(val, val));
            else {
                if(val == v[index].end+1)
                    v[index].end = val;
                if(val == v[index+1].start-1)
                    v[index+1].start = val;
                if(v[index].end == v[index+1].start) {
                    v[index].end = v[index+1].end;
                    v.erase(v.begin()+index+1);
                }
            }
        }
    }
    
    vector<Interval> getIntervals() {
        return v;
    }
};

int main() {
    SummaryRanges obj;
    vector<Interval> param_2;
    int a[] = {1,3,7,2,6};
    vector<int> b = arrayToVector(a);
    for(int i = 0;i < b.size();i++) {
        obj.addNum(b[i]);
        param_2 = obj.getIntervals();
        print(param_2);
    }

    
    return 0;
}