class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> emailSet;
        string localName;
        for(auto email: emails)
        {
            string temp;
            int pos = 0;
            if(email.find('@') != string::npos)
                pos = email.find('@');
            localName = email.substr(0, pos);
            for(int i = 0; i < localName.size(); ++i)
            {
                if(localName[i] == '.')
                    continue;
                else if(localName[i] == '+')
                    break;
                else
                    temp = temp + localName[i];
            }
            string domain = email.substr(pos+1);
            emailSet.insert(temp+domain);
        }
        
        return emailSet.size();
    }
};

/*
Conclusion:
an easy algorithm issue, using hashset and string manipulation to solve the issue.
*/
