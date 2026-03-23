//  Created by Xiaochong Zhang on 3/23/26.
// 
// https://www.1point3acres.com/bbs/thread-1168023-1-1.html

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

vector<pair<string,int>> processEarningExperience(vector<string>& operations, vector<string>& experience, vector<int>& deltas) {
    vector<pair<string,int>> ret;
    unordered_map<string, int> profitMap;
    set<pair<int, string>> sortedProfitSet;
    for(int i = 0; i < operations.size(); ++i) {
        string op = operations[i];
        string expName = experience[i];
        if(op == "update") {
            if(!profitMap.count(expName)) {
                profitMap[expName] = deltas[i];
                sortedProfitSet.insert({deltas[i], expName});
            } else {
                auto entry = make_pair(profitMap[expName], expName);
                sortedProfitSet.erase(entry);
                profitMap[expName] += deltas[i];
                sortedProfitSet.insert({profitMap[expName], expName});
            }
        } else {
            if(sortedProfitSet.empty()) {
                continue;
            } else {
                ret.push_back({sortedProfitSet.rbegin()->second, sortedProfitSet.rbegin()->first});
            }
        }
    }
    return ret;
}
