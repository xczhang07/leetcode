class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> rect;
        if(area <= 0)
            return rect;
        int r = 1;
        for(int i = 1; i*i <= area; ++i)
        {
            if(area % i == 0)
                r = i;
        }
        rect.push_back(area/r);
        rect.push_back(r);
        return rect;
    }
};

Conclustion:
easy! math algorithm issue
