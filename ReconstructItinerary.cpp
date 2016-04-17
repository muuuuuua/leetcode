/**
 * 332. Reconstruct Itinerary
 */
#include "inc/common.h"

int compare(string a, string b) {
    for(int i = 0;i < a.size();i++) {
        if(a[i] > b[i])
            return 1;
        else if(a[i] < b[i])
            return -1;
    }
    return 0;
}

vector<string> findItinerary(vector<pair<string, string> > tickets) {
    unordered_map<string, vector<string> > map;
    for(int i = 0;i < tickets.size();i++) {
        if(map.find(tickets[i].first) == map.end()) {
            vector<string> temp;
            temp.push_back(tickets[i].second);
            map[tickets[i].first] = temp;
        }
        else {
            vector<string> temp = map[tickets[i].first];
            vector<string>::iterator it;
            for(it = temp.begin();it != temp.end();it++) {
                if(compare(*it, tickets[i].second) > 0) {
                    temp.insert(it, tickets[i].second);
                    break;
                }
            }
            if(it == temp.end())
                temp.push_back(tickets[i].second);
            map[tickets[i].first] = temp;
        }
    }
    vector<string> res;
    string from = "JFK";
    res.push_back(from);
    for(int i = 0;i < tickets.size();i++) {
        vector<string> temp = map[from];
        vector<string>::iterator it = temp.begin();
        if(i != tickets.size()-1)
            while(map.find(*it) == map.end() || map[*it].size() == 0)
                it++;
        string to = *it;
        res.push_back(to);
        temp.erase(it);
        map[from] = temp;
        from = to;
    }
    return res;
}

int main() {
    vector<pair<string, string> > tickets;
    string t[][2] = {{"EZE","TIA"},{"EZE","HBA"},{"AXA","TIA"},
    {"JFK","AXA"},{"ANU","JFK"},{"ADL","ANU"},{"TIA","AUA"},
    {"ANU","AUA"},{"ADL","EZE"},{"ADL","EZE"},{"EZE","ADL"},
    {"AXA","EZE"},{"AUA","AXA"},{"JFK","AXA"},{"AXA","AUA"},
    {"AUA","ADL"},{"ANU","EZE"},{"TIA","ADL"},{"EZE","ANU"},{"AUA","ANU"}};
    for(int i = 0;i < 20;i++) {
        pair<string, string> p(t[i][0], t[i][1]);
        tickets.push_back(p);
    }
    vector<string> s = findItinerary(tickets);
    printVector(s);
    return 0;
}
