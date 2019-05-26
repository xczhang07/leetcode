美国小哥实现shell里面一种语法功能，大括号==> 对大括号中的以逗号分; 大括号外部也是以逗号分隔
如{a,b}.txt 结果会是a.txt b.txt
echo a.java,b.py,c{.java,.py}, 它应该输出的是a.java,b.py,c.java,c.py
实现这个函数，input String，output String，当时假设这个原始input会是valid的(不存在只又一个{或者只有一个},而且有且只有一对{})
follow up
多对{}
followup-followup
a{c,d{e,f},g}

vector<string> convertHelper(string& s, int& idx)
{
	if (idx >= s.size())
		return{};
	vector<string> ret;
	while (idx < s.size() && s[idx] != '}')
	{
		string tmp;
		if (idx < s.size() - 1 && (s[idx+1] == ','||s[idx+1] == '}'))
		{
			tmp.push_back(s[idx]);
			ret.push_back(tmp);
		}
		else if (idx == s.size() - 1 && isalpha(s[idx]))
		{
			tmp.push_back(s[idx]);
			ret.push_back(tmp);
		}
		else if (idx < s.size() - 1 && s[idx+1] == '{')
		{
			tmp.push_back(s[idx]);
			idx++;
			vector<string> l = convertHelper(s, idx);
			for (int i = 0; i < l.size(); ++i)
				ret.push_back(tmp + l[i]);
		}
		++idx;
	}
	return ret;
}

vector<string> convert(string s)
{
	if (s.size() == 0)
		return{};
	int idx = 0;
	vector<string> ret = convertHelper(s, idx);
	return ret;
}

Version #2

vector<string> convertHelper(string& s, int& idx)
{
    if(idx >= s.size())
        return {};
    vector<string> ret;
    string tmp;
    while(idx < s.size() && s[idx] != '}')
    {
        if(isalpha(s[idx]))
        {
            while(idx < s.size() && isalpha(s[idx]))
            {
                tmp += s[idx];
                ++idx;
            }
            if(s[idx] == ',' || s[idx] == '}')
            {
                ret.push_back(tmp);
                tmp.clear();
            }
        }
        if(s[idx] == '}')
            return ret;
        if(s[idx] == '{')
        {
            ++idx;
            vector<string> l = convertHelper(s, idx);
            for(int i = 0; i < l.size(); ++i)
                ret.push_back(tmp+l[i]);
            tmp.clear();
        }
        ++idx;
    }
    return ret;
}

vector<string> convert(string s)
{
    if (s.size() == 0)
        return{};
    int idx = 0;
    vector<string> ret = convertHelper(s, idx);
    return ret;
}


#version 3, handle parell parenthesis case: eg a{b,c,d}{m,n,t}

vector<string> convertHelper(string& s, int& idx)
{
	if (idx >= s.size())
		return{};
	vector<string> ret;
	string tmp;
	while (idx < s.size() && s[idx] != '}')
	{
		if (isalpha(s[idx]) || isdigit(s[idx]))
		{
			while (idx < s.size() && (isalpha(s[idx])||isdigit(s[idx])))
			{
				tmp += s[idx];
				++idx;
			}
			if (s[idx] == ',' || s[idx] == '}')
			{
				ret.push_back(tmp);
				tmp.clear();
			}
		}
		if (s[idx] == '}')
			return ret;
		if (s[idx] == '{')
		{
			++idx;
			vector<string> l = convertHelper(s, idx);
			if (ret.size() == 0) {
				for (int i = 0; i < l.size(); ++i)
					ret.push_back(tmp + l[i]);
				tmp.clear();
			}
			else
			{
				vector<string> t = ret;
				ret.clear();
				for (int i = 0; i < t.size(); ++i)
				{
					for (int j = 0; j < l.size(); ++j)
						ret.push_back(t[i] + l[j]);
				}
			}
		}
		++idx;
	}
	return ret;
}

vector<string> convert(string s)
{
	if (s.size() == 0)
		return{};
	int idx = 0;
	vector<string> ret = convertHelper(s, idx);
	return ret;
}

