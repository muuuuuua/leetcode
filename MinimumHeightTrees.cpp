/**
 * 310. Minimum Height Trees
 */
#include "inc/common.h"

struct Node {
    int val;
    vector<Node *> adj;
    Node(int x): val(x) {}
};

vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
    vector<int> res;
    vector<int> degree(n, 0);
    if(n <= 2) {
        for(int i = 0;i < n;i++)
            res.push_back(i);
        return res;
    }
    unordered_map<int, Node *> map;
    for(int i = 0;i < edges.size();i++) {
        if(map.find(edges[i].first) == map.end()) {
            Node *node = new Node(edges[i].first);
            map[edges[i].first] = node;
        }
        if(map.find(edges[i].second) == map.end()) {
            Node *node = new Node(edges[i].second);
            map[edges[i].second] = node;
        }
        map[edges[i].first]->adj.push_back(map[edges[i].second]);
        map[edges[i].second]->adj.push_back(map[edges[i].first]);
    }
    for(int i = 0;i < n;i++) {
        degree[i] = map[i]->adj.size();
    }
    int count = n;
    while(count > 2) {
        vector<int> del;
        for(int i = 0;i < n;i++) {
            if(degree[i] == 1) {
                del.push_back(i);
                degree[i] = -1;
                count--;
            }
        }
        for(int i = 0;i < del.size();i++) {
            Node *node = map[del[i]];
            for(int j = 0;j < node->adj.size();j++) {
                degree[node->adj[j]->val]--;
            }
        }
    }
    for(int i = 0;i < n;i++) {
        if(degree[i] == 0 || degree[i] == 1)
            res.push_back(i);
    }
    return res;
}

int main() {
    pair<int, int> a[] = {pair<int,int>(0,1), pair<int,int>(1,2), pair<int,int>(1,3)};
    vector<pair<int, int> > b = arrayToVector(a);
    vector<int> r = findMinHeightTrees(4, b);
    printVector(r);
    return 0;
}
