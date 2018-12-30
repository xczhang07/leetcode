class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        /* invalidation check */
        if(logs.size() == 0)
            return {};
        vector<int> times(n,0);
        stack<int> call_stack;
        int run_time = 0;
        for(auto log: logs)
        {
            int pos1 = log.find_first_of(":");
            int pos2 = log.find_last_of(":");
            int function_id = stoi(log.substr(0,pos1));
            string status = log.substr(pos1+1, pos2-pos1-1);
            int time = stoi(log.substr(pos2+1));
            if(!call_stack.empty())
                times[call_stack.top()] += (time - run_time);
            run_time = time;
            if(status == "start")
                call_stack.push(function_id);
            else
            {
                int function = call_stack.top();
                call_stack.pop();
                times[function]++; //increase one to terminate the function.
                ++run_time; //run time increase 1 automatically, terminate function need time.
            }
        }
        return times;
    }
};


/*
Conclustion: an middle level algorithm issue, I want to mention that please read the question carefully.
then you will get what to do.
Time Complexity: O(n)
Space Complexity: O(n)
*/



struct Log
{
    int id;
    int timestamp;
    string status;
    Log(int id, int timestamp, string status)
    {
        this->id = id;
        this->timestamp = timestamp;
        this->status = status;
    }
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n,0);
        if(n == 0)
            return times;
        
        stack<Log> st;
        for(string log: logs)
        {
            stringstream ss(log);
            string id;
            string status;
            string timestamp;
            getline(ss, id, ':');
            getline(ss, status, ':');
            getline(ss, timestamp, ':');
            Log mylog(stoi(id), stoi(timestamp), status);
            if(status == "start")
                st.push(mylog);
            else
            {
                int addtime = stoi(timestamp)-st.top().timestamp+1;
                times[st.top().id] += addtime;
                st.pop();
                if(!st.empty())
                    times[st.top().id] -= addtime;
            }
        }
        return times;
    }
};
