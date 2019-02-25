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


int main()
{
     vector<string> input = {
        "1,28,310.6,SF",
        "4,5,204.1,SF",
        "20,7,203.2,Oakland",
        "6,8,202.2,SF",
        "6,10,199.1,SF",
        "1,16,190.4,SF",
        "6,29,185.2,SF",
        "7,20,180.1,SF",
        "6,21,162.1,SF",
        "2,18,161.2,SF",
        "2,30,149.1,SF",
        "3,76,146.2,SF",
        "2,14,141.1,San Jose"
    };
    
    vector<string> pages = displayPages(input, 4);
    
    for(int i = 0; i < pages.size(); ++i)
    {
        if(pages[i] != " ")
            cout<<pages[i]<<endl;
        else
            cout<<endl;
    }
    cout<<endl;
    return 0;
}
