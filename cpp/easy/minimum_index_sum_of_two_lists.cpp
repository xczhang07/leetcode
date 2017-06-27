class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> my_map;
        vector<string> ret;
        for(int i = 0; i < list2.size(); ++i)
            my_map[list2[i]] = i;
        int least_index_sum = INT_MAX;
        for(int j = 0; j < list1.size(); ++j)
        {
            int sum = 0;
            if(my_map.find(list1[j]) != my_map.end())
            {
                sum = j + my_map[list1[j]];
                if(least_index_sum == sum)
                    ret.push_back(list1[j]);
                if(least_index_sum > sum)
                {
                    least_index_sum = sum;
                    ret.clear();
                    ret.push_back(list1[j]);
                }
            }
        }
        return ret;
    }
};


Conclustion:
hash table, so easy... no extra comments.
