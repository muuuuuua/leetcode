/**
 * 399. Evaluate Division
 */
#include "inc/common.h"

vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string> > queries) {
    vector<double> res(queries.size());
    unordered_map<string, double> weight;
    unordered_set<string> nodeSet;
    vector<string> nodeList;
    for(int i = 0;i < equations.size();i++) {
        pair<string, string> eq = equations[i];
        if(nodeSet.find(eq.first) == nodeSet.end()) {
            nodeSet.insert(eq.first);
            nodeList.push_back(eq.first);
        }
        if(nodeSet.find(eq.second) == nodeSet.end()) {
            nodeSet.insert(eq.second);
            nodeList.push_back(eq.second);
        }
        weight[eq.first+"/"+eq.second] = values[i];
        weight[eq.second+"/"+eq.first] = 1.0/values[i];
        weight[eq.first+"/"+eq.first] = 1.0;
        weight[eq.second+"/"+eq.second] = 1.0;
    }
    for(int k = 0;k < nodeList.size();k++) {
        for(int i = 0;i < nodeList.size();i++) {
            for(int j = 0;j < nodeList.size();j++) {
                if(weight.find(nodeList[i]+"/"+nodeList[j]) == weight.end()) {
                    if(weight.find(nodeList[i]+"/"+nodeList[k]) != weight.end() &&
                        weight.find(nodeList[k]+"/"+nodeList[j]) != weight.end()) {
                        weight[nodeList[i]+"/"+nodeList[j]] = weight[nodeList[i]+"/"+nodeList[k]]*weight[nodeList[k]+"/"+nodeList[j]];
                    }
                }
            }
        }
    }
    for(int i = 0;i < queries.size();i++) {
        if(weight.find(queries[i].first+"/"+queries[i].second) != weight.end())
            res[i] = weight[queries[i].first+"/"+queries[i].second];
        else
            res[i] = -1.0;
    }
    return res;
}

int main() {
    vector<pair<string, string> > equations;
    vector<double> values;
    vector<pair<string, string> > queries;
    equations.push_back(pair<string, string>("a","b"));
    equations.push_back(pair<string, string>("b","c"));
    values.push_back(2.0);
    values.push_back(3.0);
    queries.push_back(pair<string, string>("a","c"));
    queries.push_back(pair<string, string>("b","a"));
    queries.push_back(pair<string, string>("a","e"));
    queries.push_back(pair<string, string>("a","a"));
    queries.push_back(pair<string, string>("x","x"));

    vector<double> r = calcEquation(equations, values, queries);
    print(r);
    return 0;
}