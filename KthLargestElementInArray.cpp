/**
 * 215. Kth Largest Element in an Array
 */
#include "inc/common.h"

class Heap {
private:
    vector<int> data;
    int size;
public:
    Heap(int k) {
        data = vector<int>(k);
        size = 0;
    }
    void insert(int val) {
        if(data.size() == size) {
            if(val > data[0]) {
                data[0] = val;
                shiftDown(0);
            }
        }
        else {
            data[size] = val;
            shiftUp(size);
            size++;
        }
    }
    void shiftUp(int k) {
        if(k == 0)
            return;
        int parent = (k-1)/2;
        if(data[parent] > data[k]) {
            swap(data[parent], data[k]);
            shiftUp(parent);
        }
    }
    void shiftDown(int k) {
        int min = data[k];
        int minIndex = k;
        int left = 2*k+1;
        int right = 2*k+2;
        if(left < size && data[left] < min) {
            min = data[left];
            minIndex = left;
        }
        if(right < size && data[right] < min) {
            min = data[right];
            minIndex = right;
        }
        if(minIndex != k) {
            swap(data[k], data[minIndex]);
            shiftDown(minIndex);
        }
    }
    int getMin() {
        return data[0];
    }
};

int findKthLargest(vector<int>& nums, int k) {
    Heap h = Heap(k);
    for(int i = 0;i < nums.size();i++) {
        h.insert(nums[i]);
    }
    return h.getMin();
}

int main() {
    int a[] = {5,2,4,1,3,6,0};
    vector<int> b = arrayToVector(a, 7);
    cout<<findKthLargest(b, 4)<<endl;
    return 0;
}
