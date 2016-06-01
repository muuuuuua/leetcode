/**
 * 327. Count of Range Sum
 */
#include "inc/common.h"

struct SegTreeNode {
    long long L, R;
    int count;
    SegTreeNode *left, *right;
    SegTreeNode(long long l, long long r):L(l),R(r),count(0),left(NULL),right(NULL) {}
};

class SegTree {
private:
    SegTreeNode *root;
    SegTreeNode *buildTree(vector<long long> nums, int l, int r) {
        if(l > r) return NULL;
        SegTreeNode *root = new SegTreeNode(nums[l], nums[r]);
        if(l == r) return root;
        int mid = (l+r)/2;
        root->left = buildTree(nums, l, mid);
        root->right = buildTree(nums, mid+1, r);
        return root;
    }
    int sum(SegTreeNode *root, long long l, long long r) {
        if(!root || r < root->L || l > root->R) return 0;
        if(l <= root->L && r >= root->R) return root->count;
        return sum(root->left, l, r) + sum(root->right, l, r);
    }
    void update(SegTreeNode *root, long long val) {
        if(root && val >= root->L && val <= root->R) {
            root->count++;
            update(root->left, val);
            update(root->right, val);
        }
    }
public:
    SegTree(vector<long long> nums, int l, int r) {
        root = buildTree(nums, l, r);
    }
    int sum(long long l, long long r) {
        return sum(root, l, r);
    }
    void update(long long val) {
        update(root, val);
    }
};

int countRangeSum(vector<int>& nums, int lower, int upper) {
    if(nums.size() == 0) return 0;
    vector<long long> sums(nums.size(), 0);
    sums[0] = nums[0];
    for(int i = 1;i < nums.size();i++) 
        sums[i] = nums[i] + sums[i-1];
    long long temp = sums[nums.size()-1];
    sort(sums.begin(), sums.end());
    vector<long long>::iterator t = unique(sums.begin(), sums.end());
    SegTree tree(sums, 0, t-sums.begin()-1);
    int res = 0;
    for(int i = nums.size()-1;i >= 0;i--) {
        tree.update(temp);
        temp -= nums[i];
        res += tree.sum(lower+temp, upper+temp);
    }
    return res;
}

int main() {
    int a[] = {-1,0,1,-2,2,0,5,-1,2,3,2,0,-1,1};
    vector<int> b = arrayToVector(a);
    cout<<countRangeSum(b, -2, 2)<<endl;
    return 0;
}
