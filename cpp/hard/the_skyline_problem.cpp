class Solution {
public:
   vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
       vector<pair<int,int>> ret;
       if(buildings.size() == 0)
           return ret;
       vector<pair<int,int>> height;
       for(int i = 0; i < buildings.size(); ++i)
       {
           height.push_back({buildings[i][0], -buildings[i][2]});
           height.push_back({buildings[i][1], buildings[i][2]});
       }
       
       sort(height.begin(), height.end());
       multiset<int> ms;
       ms.insert(0);
       int pre = 0;
       for(auto h : height)
       {
           if(h.second < 0)
               ms.insert(-h.second);
           else
           {
               ms.erase(ms.find(h.second));
           }
           int curr = *ms.rbegin();
           if(curr != pre)
           {
               ret.push_back({h.first, curr});
               pre = curr;
           }
       }
       
       return ret;
    }
};
