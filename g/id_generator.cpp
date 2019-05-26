class IdGenerator
{
public:
    IdGenerator(int size = 5)
    {
        this->idx = 0;
        this->arr = vector<bool>(size, false);
    }
    
    int generateId(int obj)
    {
        if(m.count(obj))
            return m[obj];
        while(idx < arr.size() && arr[idx] == true)
            ++idx;
        if(idx == arr.size())
            return -1;
        m[obj] = idx;
        arr[idx] = true;
        int ret = idx;
        ++idx;
        return ret;
    }
    
    void freeId(int obj)
    {
        if(!m.count(obj))
            return;
        int id = m[obj];
        m.erase(obj);
        arr[id] = false;
        if(id < idx)
            idx = id;
        return;
    }
    
private:
    int idx;
    vector<bool> arr;
    unordered_map<int, int> m;
};
