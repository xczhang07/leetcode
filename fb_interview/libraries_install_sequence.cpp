给一些 library 的名字以及相互之间的 requirement 关系，比如 "A"->("B", "C") 表示 install A 的时候需要先 install B and C
然后给定任意的 library name ，返回个数组表示安装顺序，上面的例子("B", "C", "A") 和 ("C", "B", "A")
中间问了异常情况怎么处理，后来直接 raise 异常就行

similar with course schedule algorithm issue.


bool dfs(unordered_map<char, vector<char>>& g, char lib, unordered_map<char, bool>& call_stack, string& path)
{
    if(call_stack.count(lib))
        return true;
    call_stack[lib] = true;
    path.push_back(lib);
    for(int i = 0; i < g[lib].size(); ++i)
    {
        bool has_cycle = dfs(g, g[lib][i], call_stack, path);
        if(has_cycle)
            return true;
    }
    call_stack[lib] = false;
    return false;
}

string installSequence(vector<pair<char, char>> libraries, char lib)
{
    if(libraries.size() == 0)
        return "";
    /* construct the graph */
    unordered_map<char, vector<char>> g;
    for(auto l : libraries)
        g[l.first].push_back(l.second);
    unordered_map<char, bool> call_stack;
    string path = "";
    bool success = dfs(g, lib, call_stack, path);
    if(success)
    {
        cout<<"there is a cycle in the lib, dead lock"<<endl;
        return "";
    }
    reverse(path.begin(), path.end());
    return path;
}


/* test code */
int main(int argc, const char * argv[]) {
    vector<pair<char,char>> libriaries = {{'A', 'B'}, {'A','C'}, {'B','D'}, {'C','T'}, {'D','F'}, {'D','M'}};
    string seq = installSequence(libriaries, 'A');
    cout<<"install sequenece is: "<<seq<<endl;
    return 0;
}

output is: TCMFDBA
