https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=290914

vector<string> displayPages(vector<string> input, int num)
{
    vector<string> pages;
    if(input.size() == 0)
        return pages;
    vector<string>::iterator iter = input.begin();
    unordered_set<int> s;
    int cnt = 0;
    while(iter != input.end())
    {
        string log = *iter;
        int idx = 0;
        int host_id = 0;
        while(idx < log.size() && isdigit(log[idx]))
        {
            host_id = host_id * 10 + (log[idx]-'0');
            ++idx;
        }
        if(cnt < num && !s.count(host_id))
        {
            pages.push_back(*iter);
            cnt++;
            s.insert(host_id);
            iter = input.erase(iter);
        }
        else if(cnt < num && s.count(host_id))
            iter++;
        
        if(cnt == num)
        {
            cnt = 0;
            s.clear();
            if(input.size() != 0)
                pages.push_back(" ");
            iter = input.begin();
        }
        
        if(iter == input.end())
        {
            iter = input.begin();
            s.clear();
        }
    }
    
    return pages;
}
