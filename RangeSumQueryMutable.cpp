/**
 * 307. Range Sum Query - Mutable
 */
#include "inc/common.h"

struct SegTreeNode {
    SegTreeNode *left;
    SegTreeNode *right;
    int lidx;
    int ridx;
    int sum;
    SegTreeNode(vector<int> &nums, int l, int r):lidx(l), ridx(r) {
        if(l == r) {
            sum = nums[l];
            left = NULL;
            right = NULL;
        }
        else {
            int mid = (l+r)/2;
            left = new SegTreeNode(nums, l, mid);
            right = new SegTreeNode(nums, mid+1, r);
            sum = left->sum+right->sum;
        }
    }
};

class NumArray {
private:
    SegTreeNode *root;
    void update(int i, int val, SegTreeNode *f) {
        if(f->lidx == f->ridx) {
            f->sum = val;
        }
        else {
            int mid = (f->lidx+f->ridx)/2;
            if(i <= mid) {
                f->sum -= f->left->sum;
                update(i, val, f->left);
                f->sum += f->left->sum;
            }
            else {
                f->sum -= f->right->sum;
                update(i, val, f->right);
                f->sum += f->right->sum;
            }
        }
    }
    int sumRange(int i, int j, SegTreeNode *f) {
        if(f->lidx == i && f->ridx == j)
            return f->sum;
        int s = 0;
        int mid = (f->lidx+f->ridx)/2;
        if(i >= f->lidx && i <= mid) {
            if(j <= mid) {
                return sumRange(i, j, f->left);
            }
            else {
                s += sumRange(i, mid, f->left);
                s += sumRange(mid+1, j, f->right);
                return s;
            }
        }
        if(i > mid) {
            return sumRange(i, j, f->right);
        }
        return s;
    }
public:
    NumArray(vector<int> &nums) {
        if(nums.size() == 0)
            root = NULL;
        else
            root = new SegTreeNode(nums, 0, nums.size()-1);
    }

    void update(int i, int val) {
        if(root == NULL)
            return;
        update(i, val, root);
    }

    int sumRange(int i, int j) {
        if(root == NULL)
            return 0;
        return sumRange(i, j, root);
    }
};

int main() {
    int a[] = {1,3,5};
    vector<int> nums = arrayToVector(a);
    NumArray numArray(nums);
    cout<<numArray.sumRange(0, 1)<<endl;
    numArray.update(1, 10);
    cout<<numArray.sumRange(1, 2)<<endl;
    return 0;
}