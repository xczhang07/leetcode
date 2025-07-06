# VO Coding：任务有deadline和rewards，求最大rewards的任务执行列表
# https://www.1point3acres.com/bbs/thread-1135537-1-1.html

bool compareVec(tuple<char, int, int>& t1, tuple<char, int, int>& t2) {
    return get<1>(t1) < get<1>(t2);
}

struct compareQueue {
    bool operator() (pair<char, int>& p1, pair<char,int>& p2) {
        return p1.second > p2.second;
    }
};

int getMaxProfit(vector<tuple<char, int, int>>& taskInfo) {
    if(taskInfo.size() == 0) {
        return -1;
    }
    sort(taskInfo.begin(), taskInfo.end(), compareVec);
    priority_queue<pair<char, int>, vector<pair<char, int>>, compareQueue> pq;
    pq.push({get<0>(taskInfo[0]), get<2>(taskInfo[0])});
    int maxProfit = 0;
    int deadline = get<1>(taskInfo[0]);
    for(int i = 1; i < taskInfo.size(); ++i) {
        if(deadline == get<1>(taskInfo[i])) {
            if(deadline > pq.size()) {
                pq.push({get<0>(taskInfo[i]), get<2>(taskInfo[i])});
            } else if(pq.top().second < get<2>(taskInfo[i])) {
                pq.pop();
                pq.push({get<0>(taskInfo[i]), get<2>(taskInfo[i])});
            }
        } else {
            deadline = get<1>(taskInfo[i]);
            pq.push({get<0>(taskInfo[i]), get<2>(taskInfo[i])});
        }
    }
    while(!pq.empty()) {
        maxProfit += pq.top().second;
        pq.pop();
    }
    return maxProfit;
}

# Test code
// Test optimal tasks selection function
    vector<tuple<char, int, int>> taskSet1 = {{'a', 2, 8}, {'b', 1, 3}, {'c', 2, 5}, {'d', 3 , 14}, {'e', 3, 15}};
    vector<pair<char, int>> selected_tasks1 = optimalTasksSelection(taskSet1);
    cout<<"selected tasks id and its corresponding profit as following: "<<endl;
    for(auto& t: selected_tasks1) {
        cout<<t.first<<" "<<t.second<<endl;
    }
    cout<<"The max profit of the selected tasks as: "<<getMaxProfit(taskSet1)<<endl;
    vector<tuple<char, int, int>> taskSet2 = {{'a', 2, 15}, {'b', 2, 14}, {'c', 3, 5}, {'d', 3 , 6}};
    cout<<"The max profit of the selected tasks(set2) as: "<<getMaxProfit(taskSet2)<<endl;
