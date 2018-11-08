Solution 1
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for(int i = 0; i < vec2d.size(); ++i)
        {
            for(int j = 0; j < vec2d[i].size(); ++j)
                nums.push_back(vec2d[i][j]);
        }
        this->idx = 0;
        this->size = nums.size();
    }

    int next() {
        return nums[idx++];
    }

    bool hasNext() {
        return idx < size;
    }
    
private:
    vector<int> nums;
    int idx;
    int size;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
 
 Solution 2: maintain two integers x and y.
 
 class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        this->nums = vec2d;
        this->x = 0;
        this->y = 0;
    }

    int next() {
        return nums[x][y++];
    }

    bool hasNext() {
        while(x < nums.size() && y == nums[x].size())
        {
            x++;
            y = 0;
        }
        return x < nums.size();
    }
    
private:
    vector<vector<int>> nums;
    int x;
    int y;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
 
 Solution 3: maintain c++ iterator, meets follow up
 
 class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        this->start = vec2d.begin();
        this->end = vec2d.end();
        this->y = 0;
    }

    int next() {
        return (*start)[y++];
    }

    bool hasNext() {
       while(start != end && y == (*start).size())
       {
           ++start;
           y = 0;
       }
        return start != end;
    }
    
private:
    vector<vector<int>>::iterator start;
    vector<vector<int>>::iterator end;
    int y;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
