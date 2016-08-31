/**
 * 391. Perfect Rectangle
 */

#include "inc/common.h"

int findPos(vector<pair<int, int> > arr, int x) {
    for(int i = 0;i < arr.size();i++) {
        if(arr[i].first > x)
            return i;
    }
    return arr.size();
}

bool isRectangleCover(vector<vector<int> >& rectangles) {
    unordered_map<int, vector<pair<int, int> > > map;
    for(int i = 0;i < rectangles.size();i++) {
        vector<int> rect = rectangles[i];
        int x1 = rect[0], x2 = rect[2]-1;
        int y1 = rect[1], y2 = rect[3]-1;
        for(int j = y1;j <= y2;j++) {
            if(map[j].size() == 0)
                map[j].push_back(pair<int,int>(x1,x2));
            else {
                int k = findPos(map[j], x1);
                map[j].insert(map[j].begin()+k, pair<int,int>(x1,x2));
            }   
        }
    }
    for(auto it = map.begin();it != map.end();it++) {
        vector<pair<int, int> > temp = it->second;
        vector<pair<int, int> > result;
        pair<int, int> prev = temp[0];
        int index = 1;
        pair<int, int> cur = temp[index];
        while (index < temp.size()) {
            if (cur.first > prev.second+1) {
                result.push_back(prev);
                prev = cur;
                cur = temp[++index];
            }
            else if(cur.first == prev.second+1) {
                prev.second = cur.second;
                cur = temp[++index];
            }
            else {
                return false;
            }
        }
        result.push_back(prev);
        map[it->first] = result;
    }
    pair<int,int> stand = map.begin()->second[0];
    for(auto it = map.begin();it != map.end();it++) {
        vector<pair<int, int> > temp = it->second;
        if(temp.size() != 1) return false;
        if(temp[0] != stand) return false;
    }
    return true;
}

int main() {
    int a[][4] = {{1,1,2,3},
                  {1,3,2,4},
                  {3,1,4,2},
                  {3,2,4,4}};
    vector<vector<int> > rectangles;
    for(int i = 0;i < 4;i++) {
        vector<int> t = arrayToVector(a[i]);
        rectangles.push_back(t);
    }
    cout<<isRectangleCover(rectangles)<<endl;
    return 0;
}