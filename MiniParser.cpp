/**
 * 385. Mini Parser
 */

#include "inc/common.h"

NestedInteger deserialize(string s, int &index) {
    NestedInteger res;
    if(s[index] == '[') {
        index++;
        while(s[index] != ']') {
            res.add(deserialize(s, index));
            if(s[index] == ',')
                index++;
        }
        index++;
        return res;
    }
    if(s[index] >= '0' && s[index] <= '9' || s[index] == '-') {
        int sum = 0;
        bool positive = true;
        if(s[index] == '-') {
            positive = false;
            index++;
        }
        while(s[index] >= '0' && s[index] <= '9') {
            sum = 10*sum+s[index]-'0';
            index++;
        }
        if(!positive)
            sum = -sum;
        res.setInteger(sum);
        return res;
    }
    return res;
}

NestedInteger deserialize(string s) {
    int index = 0;
    NestedInteger root = deserialize(s, index);
    return root;
}