typedef void (*callback) (void);

void helloWorldBJ()
{
    cout<<" Hello World From BJ "<<endl;
}

void helloWorldSF()
{
    cout<<" Hello World From SF "<<endl;
}

class FileSystem
{
public:
    bool create(string path, int val)
    {
        if(pathMap.count(path))
            return false;
        int idx = path.find_last_of('/');
        string dir = path.substr(0,idx);
        if(idx != 0 && !pathMap.count(dir)) /* used to check whether or not the upper level exist in the path map */
            return false;
        pathMap[path] = {val, NULL};
        return true;
    }
    
    bool set(string path, int val)
    {
        if(!pathMap.count(path))
            return false;
        pathMap[path].first = val;
        
        /* triger the callback function */
        string curr = path;
        while(curr.size() != 0)
        {
            if(pathMap.count(curr) && pathMap[curr].second != NULL)
                pathMap[curr].second();
            int last_slash = curr.find_last_of('/');
            if(last_slash != -1)
                curr = curr.substr(0,last_slash);
            else
                break;
        }
        return true;
    }
    
    int get(string path)
    {
        if(!pathMap.count(path))
            return INT_MIN;
        else
            return pathMap[path].first;
    }
    
    bool watch(string path, callback cb)
    {
        if(!pathMap.count(path))
            return false;
        pathMap[path].second = cb;
        return true;
    }
    
private:
    unordered_map<string, pair<int, callback>> pathMap;
};


/* test case */

int main()
{
    FileSystem fs;
    string file = "/a";
    bool ret = fs.create(file, 1);
    if(ret)
        cout<<"create file: "<<file<<" success"<<endl;
    else
        cout<<"create file: "<<file<<" failed"<<endl;
    
    int val = fs.get(file);
    if(val != INT_MIN)
        cout<<file<<"'s value is: "<<val<<endl;
    else
        cout<<"error happens"<<endl;
    
    file = "/a/b";
    ret = fs.create(file, 2);
    if(ret)
        cout<<"create file: "<<file<<" success"<<endl;
    else
        cout<<"create file: "<<file<<" failed"<<endl;
        
    val = fs.get(file);
    if(val != INT_MIN)
        cout<<file<<"'s value is: "<<val<<endl;
    else
        cout<<"error happens"<<endl;
    
    file = "/c/d";
    ret = fs.create(file, 2);
    if(ret)
        cout<<"create file: "<<file<<" success"<<endl;
    else
        cout<<"create file: "<<file<<" failed"<<endl;
    
    val = fs.get(file);
    if(val != INT_MIN)
        cout<<file<<"'s value is: "<<val<<endl;
    else
        cout<<"error happens"<<endl;
    cout<<endl;
    
    fs.watch("/a", helloWorldBJ);
    fs.watch("/a/b", helloWorldSF);
    fs.set("/a", 4);
    fs.set("/a/b", 6);
    
    return 0;
}
