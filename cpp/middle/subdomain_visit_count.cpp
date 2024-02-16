class Solution {
public:
    int getVisitTimes(string& domain) {
        int num = 0;
        int i = 0;
        while(isdigit(domain[i])) {
            num = num * 10 + (domain[i]-'0');
            ++i;
        }
        return num;
    }

    string getDomain(string& domain) {
        int i = 0;
        while(isdigit(domain[i])) {
            ++i;
        }
        ++i;
        return domain.substr(i);
    }

    vector<string> splitStr(string domain) {
        vector<string> sub_domains;
        while(!domain.empty()) {
            int pos = domain.find('.');
            if(pos == string::npos) {
                sub_domains.push_back(domain);
                break;
            }
            sub_domains.push_back(domain.substr(0,pos));
            domain = domain.substr(pos+1);
        }
        return sub_domains;
    }

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> count;
        for(string& domain: cpdomains) {
            int visit_times = getVisitTimes(domain);
            string rdomain = getDomain(domain);
            vector<string> sub_domains = splitStr(rdomain);
            if(sub_domains.size() == 3) {
                count[sub_domains[2]] += visit_times;
                count[sub_domains[1]+"."+sub_domains[2]] += visit_times;
                count[sub_domains[0]+"."+sub_domains[1]+"."+sub_domains[2]] += visit_times;
            } else {
                count[sub_domains[1]] += visit_times;
                count[sub_domains[0]+"."+sub_domains[1]] += visit_times;
            }
        }
        vector<string> ret;
        for(auto& iter : count) {
            ret.push_back(to_string(iter.second)+" "+iter.first);
        }
        return ret;
    }
};
