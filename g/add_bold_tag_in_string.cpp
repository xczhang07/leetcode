Given a string s and a list of strings dict, 
you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. 
If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. 
Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.
Example 1:
Input: 
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
Example 2:
Input: 
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
Note:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].

bool compare(pair<int,int> p1, pair<int,int> p2)
{
    return p1.first < p2.first;
}

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        if(dict.size() == 0)
            return s;
        else if(s.size() == 0)
            return s;
        vector<pair<int,int>> index;
        for(int i = 0; i < dict.size(); ++i)
        {
            string tmp = dict[i];
            for(int j = 0; j < s.size(); ++j)
            {
                if(s[j] == tmp[0])
                {
                    if(tmp == s.substr(j, tmp.size()))
                        index.push_back(make_pair(j, j+tmp.size()-1));
                }
            }
        }
        
        if(index.size() == 0)
            return s;
        
        sort(index.begin(), index.end(), compare);
        
        /* merge */
        int start = index[0].first;
        int end = index[0].second;
        vector<pair<int,int>> intervals;
        for(int i = 1; i < index.size(); ++i)
        {
            if(end >= index[i].first)
            {
                start = min(start, index[i].first);
                end = max(end, index[i].second);
            }
            else if(end + 1 == index[i].first)
                end = index[i].second;
            else
            {
                intervals.push_back(make_pair(start, end));
                start = index[i].first;
                end = index[i].second;
            }
        }
        
        intervals.push_back(make_pair(start, end));
        
        int t = 0;
        string ret = "";
        for(auto e : intervals)
        {
            string m = s.substr(t, e.first-t);
            ret += m;
            ret += "<b>";
            ret += s.substr(e.first,e.second-e.first+1);
            ret += "</b>";
            t = e.second+1;
        }
        ret += s.substr(t);
        return ret;
    }
};
