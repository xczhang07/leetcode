class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        if(dict.size() == 0)
            return sentence;
        unordered_map<string, int> my_map;
        for(auto e: dict)
            my_map[e] = 1;
        stringstream ss(sentence);
        string successor;
        string ret;
        while(ss >> successor)
        {
            string root;
            for(int i = 1; i <= successor.size(); ++i)
            {
                root = successor.substr(0,i);
                if(my_map.find(root) != my_map.end())
                    break;
            }
            ret += root + " ";
        }
        if(ret.size() != 0)
            ret.resize(ret.size()-1);
        return ret;
    }
};


Conclusion:
一道middle level的算法题，不是很难。首先，把给的dict里面的每个元素存入一个哈希表中，这样方便与查找。
再次，通过stringstream将sentence写入，之后把每个单词读出来，针对每一个单词，看看其是否包含dict中的元素，如果包含，则将元素加入到ret中。
如果不包含，则合并整个单词。
最后，不要忘记resize一下结果，因为每次合并root的时候，在后面都加了一个空格。

Time complexity:
O(n)
Space complexity:
O(n)
