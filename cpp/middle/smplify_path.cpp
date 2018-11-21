class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() == 0)
            return "/";
        stack<string> dirs;
        istringstream ss(path);
        string ret;
        string val;
        while(getline(ss, val, '/'))
        {
            if(val.size() == 0 || val == ".")
                continue;
            else if(val == "..")
            {
                if(!dirs.empty())
                    dirs.pop();
            }
            else
                dirs.push(val);
        }
        if(dirs.empty())
            return "/";
        while(!dirs.empty())
        {
            ret = "/"+dirs.top()+ret;
            dirs.pop();
        }
        return ret;
    }
};
