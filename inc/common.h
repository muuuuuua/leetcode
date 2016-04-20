#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <utility>
#include <string>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

TreeNode *makeTree();

ListNode *makeList(int array[], int n) {
    ListNode *head = new ListNode(array[0]);
    ListNode *p = head;
    for(int i = 1;i < n;i++) {
        ListNode *t = new ListNode(array[i]);
        p->next = t;
        p = t;
    }
    return head;
}

template<class T>
void printVector(vector<T> v) {
    for(int i = 0;i < v.size();i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

template<class T>
vector<T> arrayToVector(T array[], int n) {
    vector<T> res;
    for(int i = 0;i < n;i++) {
        res.push_back(array[i]);
    }
   return res;
}

