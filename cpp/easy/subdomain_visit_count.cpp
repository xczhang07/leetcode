class Solution {
public:
    /* map-reduce */
    int getCount(string& str)
    {
        /* get the account number and return the domain string */
        int ret = 0;
        int i = 0;
        string num;
        while(i < str.size() && ((str[i] >= '0') && (str[i] <= '9')))
        {
            num = num + str[i];
            ++i;
        }
        ret = stoi(num);
        
        /* increase 1 to skip the space */
        ++i;
        str = str.substr(i);
        return ret;
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> dict;
        vector<string> ret;
        /* the first for loop caculate the apperance number of each domain and subdomain */
        for(string ele : cpdomains)
        {
            int count = getCount(ele);
            dict[ele] += count;
            int idx = ele.find('.');
            while(idx != -1)
            {
                ele = ele.substr(idx+1);
                dict[ele] += count;
                idx = ele.find('.');
            }
        }
        /* concatonate each domain apperance number to a sentence */
        for(auto x: dict)
        {
            string query = to_string(x.second) + " ";
            query += x.first;
            ret.push_back(query);
        }
        return ret;
    }
};

Conclusion: an easy algorithm issue of leetcode, caculate the domain and subdomain apperance times; alternative, 
this question is a map-reduce issue. first, we process each string, then we gather all the data and make the union.

Time Complexity: O(n)
Space Complexity: O(n)
