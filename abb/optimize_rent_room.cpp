// https://www.1point3acres.com/bbs/thread-1125781-1-1.html
代码是一个回溯题，不过题目描述套用了一些租房的概念，大意是一个group的人去旅游，要把他们放在同一个区域的房子里，
怎么做到使用最少的房间，每个房间有可容纳人数和所在区域，解法就是先遍历出目标区域的房间列表，然后回溯所有房间，
找出最优解。实际上就是一个正数数组里找最少的数凑成一个大于目标数的问题。

//
//  optimize_rent_room.h
//  AirbnbCodingChallenge
//
//  Created by Xiaochong Zhang on 5/7/25.
//

#ifndef optimize_rent_room_h
#define optimize_rent_room_h

#include <vector>
#include <iostream>
using namespace std;

// https://www.1point3acres.com/bbs/thread-1125781-1-1.html

void backTracking(int& personNum, int totalBedNum, vector<int>& rooms, vector<int>& selectedRooms, unordered_map<int, vector<int>>& m, int idx) {
    if(totalBedNum >= personNum) {
        int left = totalBedNum-personNum;
        if(!m.count(left)) {
            m[left] = selectedRooms;
            return;
        } else {
            if(selectedRooms.size() < m[left].size()) {
                m[left] = selectedRooms; // choose the min bed rooms
                return;
            }
        }
    }
    for(int i = idx; i < rooms.size(); ++i) {
        totalBedNum += rooms[i];
        selectedRooms.push_back(rooms[i]);
        backTracking(personNum, totalBedNum, rooms, selectedRooms, m, i+1);
        selectedRooms.pop_back();
        totalBedNum -= rooms[i];
    }
}

vector<int> optimizeRentRoom(vector<int>& rooms, int& personNum) {
    if(rooms.size() == 0 or personNum == 0) {
        return {};
    }
    unordered_map<int, vector<int>> m;
    int totalBedNum = 0;
    vector<int> selectedRooms;
    int idx = 0;
    backTracking(personNum, totalBedNum, rooms, selectedRooms, m, idx);
    vector<int> ret;
    int min = INT_MAX;
    for(auto& [extraBedNum, roomVec]: m) {
        if(extraBedNum < min) {
            ret = roomVec;
            min = extraBedNum;
        }
    }
    return ret;
}


#endif /* optimize_rent_room_h */
