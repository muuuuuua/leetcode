#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <cstdlib>
#include <utility>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>

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

template<size_t N>
ListNode *makeList(int (&array)[N]) {
    if(N == 0) return NULL;
    ListNode *head = new ListNode(array[0]);
    ListNode *p = head;
    for(int i = 1;i < N;i++) {
        ListNode *t = new ListNode(array[i]);
        p->next = t;
        p = t;
    }
    return head;
}

template<class T>
void print(unordered_set<T> v) {
    for(typename unordered_set<T>::iterator it = v.begin();it != v.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void print(ListNode *head) {
    while(head != NULL) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void print(string s) {
    cout<<s<<" ";
}

void print(int a) {
    cout<<a<<" ";
}

template<class T>
void print(vector<T> v) {
    for(int i = 0;i < v.size();i++) {
        print(v[i]);
    }
    cout<<endl;
}

template<class T>
void printVector(vector<T> v) {
    for(int i = 0;i < v.size();i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void printStackRec(stack<T> v) {
    if(v.empty())
        return;
    int t = v.top();
    v.pop();
    printStackRec(v);
    cout<<t<<" ";
}

template<class T>
void printStack(stack<T> v) {
    printStackRec(v);
    cout<<endl;
}

template<class T, size_t N>
vector<T> arrayToVector(T (&array)[N]) {
    vector<T> res;
    for(int i = 0;i < N;i++) {
        res.push_back(array[i]);
    }
    return res;
}

template<class T, size_t N>
unordered_set<T> arrayToSet(T (&array)[N]) {
    unordered_set<T> res;
    for(int i = 0;i < N;i++) {
        res.insert(array[i]);
    }
    return res;
}
