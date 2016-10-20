/**
 * 423. Reconstruct Original Digits from English
 */
#include "inc/common.h"

void process(int p, int count, unordered_map<char, int>& map, vector<int> &record) {
    string code[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i = 0;i < code[p].size();i++) {
        map[code[p][i]] -= count;
    }
    record[p] = count;
}

string originalDigits(string s) {
    unordered_map<char, int> map;
    for(int i = 0;i < s.size();i++) {
        map[s[i]]++;
    }
    vector<int> record(10, 0);
    int zero = map['z'];
    process(0, zero, map, record);
    int two = map['w'];
    process(2, two, map, record);
    int four = map['u'];
    process(4, four, map, record);
    int six = map['x'];
    process(6, six, map, record);
    int five = map['f'];
    process(5, five, map, record);
    int seven = map['v'];
    process(7, seven, map, record);
    int three = map['r'];
    process(3, three, map, record);
    int eight = map['g'];
    process(8, eight, map, record);
    int one = map['o'];
    process(1, one, map, record);
    int nine = map['e'];
    process(9, nine, map, record);
    string res = "";
    for(int i = 0;i < record.size();i++) {
        for(int j = 0;j < record[i];j++) {
            res += to_string(i);
        }
    }
    return res;
}

int main() {
    cout<<originalDigits("zeroonetwothreefourfivesixseveneightnine")<<endl;
    return 0;
}
