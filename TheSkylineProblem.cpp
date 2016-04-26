/**
 * 218. The Skyline Problem
 */
#include "inc/common.h"

vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
    vector<pair<int, int> > edges;
    int left, right, height;
    for(int i=0; i<buildings.size(); i++) {
        left=buildings[i][0];
        right=buildings[i][1];
        height=buildings[i][2];
        /*** make sure : for the same left point we use the bigger height ***/
        edges.push_back(make_pair(left, -height));
        edges.push_back(make_pair(right, height));
    }
    sort(edges.begin(), edges.end());
    vector<pair<int, int> > result;
    /*** use the multiset to store the max height util current pos ***/
    multiset<int> m;
    /*** left most height ***/
    m.insert(0);
    int pre=0, cur=0;
    for(int i=0; i<edges.size(); i++){
        pair<int, int> e=edges[i];
        if(e.second < 0)  m.insert(-e.second);
        else m.erase(m.find(e.second));
        cur=*(m.rbegin());
        if(cur!=pre){
            result.push_back(make_pair(e.first, cur));
            pre=cur;
        }
    }
    return result;
}

int main() {
    vector<vector<int> > buildings;
    int a[][3] = {{0,2,3},{2,5,3},{5,12,12},{15,20,10},{19,24,8}};
    for(int i = 0;i < 5;i++) {
        vector<int> t = arrayToVector(a[i]);
        buildings.push_back(t);
    }
    vector<pair<int, int> > r = getSkyline(buildings);
    for(int i = 0;i < r.size();i++) {
        cout<<r[i].first<<","<<r[i].second<<endl;
    }
    return 0;
}
