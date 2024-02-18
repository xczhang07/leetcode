tutorial(good resource): https://www.youtube.com/watch?v=oOWb_CQU5xo

class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        for(int len = 1; 3+len*2 < limit; ++len) {
            int num = pow(10, len) - 1;
            int cost = (3+len) * num;
            for(int i = 1; i <= len; ++i) {
                cost += i* (pow(10,i)-1 - (pow(10,i-1)-1));
            }
            if(limit * num - cost >= message.size()) {
                return get(message, limit, len);
            }
        }
        return {};
    }

    vector<string> get(string& message, int limit, int len) {
        vector<string> ret;
        int count = 0;
        int idx = 0;

        while(count < message.size()) {
            idx++;
            int cost = 3 + len + to_string(idx).size();
            int add = min(limit - cost, (int)message.size()-count);
            string slice_msg = message.substr(count, add) + "<" + to_string(idx) + "/";
            ret.push_back(slice_msg);
            count += add;
        }

        for(string& str : ret) {
            str += to_string(idx) + ">";
        }
        return ret;
    }
};
