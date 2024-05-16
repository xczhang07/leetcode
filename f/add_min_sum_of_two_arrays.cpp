// Question: https://www.1point3acres.com/bbs/thread-1066945-1-1.html

vector<pair<int,int>> getMinTwo(vector<int>& arr1) {
    int minNum1 = INT_MAX;
    int minNum2 = INT_MAX;
    pair<int,int> p1;
    pair<int,int> p2;
    p1.first = minNum1;
    p1.second = -1;
    p2.first = minNum2;
    p2.second = -1;
    for(int i = 0; i < arr1.size(); ++i) {
        if(arr1[i] < p1.first) {
            p1.first = arr1[i];
            p1.second = i;
        }
        if(arr1[i] > p1.first && arr1[i] < p2.first) {
            p2.first = arr1[i];
            p2.second = i;
        }
    }
    return {p1,p2};
}

// Meta
int getMinSum(vector<int>& arr1, vector<int>& arr2) {
    vector<pair<int,int>> v1 = getMinTwo(arr1);
    vector<pair<int,int>> v2 = getMinTwo(arr2);
    if(v1[0].second != v2[0].second) {
        return v1[0].first + v2[0].first;
    } else {
        return min(v1[0].first + v2[1].first, v1[1].first+v2[0].first);
    }
}
