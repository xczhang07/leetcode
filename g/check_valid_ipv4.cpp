write a program to check whether or not an ipv4 is valid.

bool isValidateIpv4(string ip)
{
	if (ip.find(".") == string::npos)
		return false;
	ip.push_back('.');
	int cnt = 0;
	int start = 0;
	while (ip.size() > 0)
	{
		int idx = ip.find_first_of(".");
		string num = ip.substr(start, idx - start);
		ip = ip.substr(idx+1);
		cnt++;
		if (cnt > 4)
			return false;
		if (num.size() > 3 || (num.size() > 1 && num[0] == '0'))
			return false;
		int n = stoi(num);
		if (n > 255)
			return false;
		for (int i = 0; i < num.size(); ++i)
		{
			if (num[i] < '0' || num[i] > '9')
				return false;
		}
	}
	if(cnt == 4)
		return true;
	return false;
}
