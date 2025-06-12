//
//  DependencyValue.h
//  AirbnbCodingChallenge
//
//  Created by Xiaochong Zhang on 6/5/25.
//
// https://www.1point3acres.com/bbs/thread-1131849-1-1.html

#ifndef DependencyValue_h
#define DependencyValue_h

#include<iostream>
#include<unordered_map>
using namespace std;

class DependencyValue {
public:
    void setValue(string key, int val) {
        // if the key doesn't exist in the map.
        if(!valMap.count(key)) {
            valMap[key] = val;
            return;
        }
        // if the key is not present in the value map.
        int originalVal = valMap[key];
        valMap[key] = val;
        int diff = val-originalVal;
        _updateDependency(diff, key);
    }
    
    void setSum(string key, vector<string> childs) {
        int sum = 0;
        for(string c: childs) {
            sum += valMap[c];
            children[key].push_back(c);
        }
        // construct the dependency map
        for(string c: childs) {
            depMap[c].push_back(key);
        }
        if(!valMap.count(key)) {
            valMap[key] = sum;
            return;
        }
        int originalVal = valMap[key];
        int diff = sum - originalVal;
        _updateDependency(diff, key);
        return;
    }
    
    int getValue(string key) {
        if(!children.count(key)) {
            return valMap[key];
        }
        int val = 0;
        for(string c: children[key]) {
            val += valMap[c];
        }
        return val;
    }
    
private:
    void _updateDependency(int& diff, string key) {
        // if the dependency map doesn't have the key value, then it means we reach to the top
        if(!depMap.count(key)) {
            valMap[key] += diff;
            return;
        }
        for(string parentKey: depMap[key]) {
            valMap[parentKey] += diff;
            _updateDependency(diff, parentKey);
        }
    }
    
    unordered_map<string, int> valMap;
    unordered_map<string, vector<string>> depMap;
    unordered_map<string, vector<string>> children;
};


#endif /* DependencyValue_h */
