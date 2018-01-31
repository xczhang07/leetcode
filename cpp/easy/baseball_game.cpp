class Solution {
public:
    int calPoints(vector<string>& ops) {
        int score = 0;
        int sum = 0;
        vector<int> points;
        if(ops.size() == 0)
            return sum;
        for(string op:ops)
        {
            if(op == "C")
            {
                sum -= points.back();
                points.pop_back();
                continue;
            }
            else if(op == "D")
            {
                score = points.back()*2;
                sum += score;
            }
            else if(op == "+")
            {
                score = points[points.size()-1] + points[points.size()-2];
                sum += score;
            }
            else
            {
                score = stoi(op);
                sum += score;
            }
            points.push_back(score);
        }
        return sum;
    }
};


Conclusion:
an easy algorithm issue, however, it takes me a while to understand the question, straight forward solution
should be fine, create a points vector to store the score, and according to different operation, we can caculate
the sum with the points vector.

Time Complexity: O(n)
Space Complexity: O(n)

