leetcode 上有几道关于ip address的问题，都是中等难度，但都还算是比较繁琐的。
第一道题: validate_ip_addresses(https://leetcode.com/problems/validate-ip-address/description/)
这道题纯属考查的是是否熟悉 ipv4 和 ipv6的format，身为一个知名网络公司的员工，有时候也弄不清楚这些corner case，令人汗颜啊...

第二道题: restore_ip_addresses(https://leetcode.com/problems/restore-ip-addresses/description/)
这道题首先考查的是是否熟悉ipv4的format，其次是backtracking.

下面着重总结一下ipv4 的格式：
ipv4总体是分为四段，每一段的数值在[0,255]之间，如果我们用 s 代表每一段：
一些规则如下：
case1: s.size() == 0,               false
case2: s.size() > 3,                false
case3: s[0] == '0' && s.size() > 1, false
case4:
  int num = stoi(s);
  num < 0 || num > 255,             false
  
  
假设给了一个字符串 ip, 下面咱们来写一个function去验证这个ip是否是合法的ipv4:

bool is_valid_ipv4(string ip)
{
    istringstream ss(ip);
    string t = "";
    int cnt = 0;
    while(getline(ss, t, '.'))
    {
        ++cnt;
        if(cnt > 4)  /* check the input ip address has how many sections */
          return false;
        if(t.size() == 0 || t.size() > 3 || (t[0] == '0' && t.size() > 1)) /* check each part validation */
          return false;
        for(int i = 0; i < t.size(); ++i)
        {
            if(t[i] < '0' || t[i] > '9')
              return false;       /* invalidation charactors check, ipv4 string only contains 0-9 and '.' */
        }
        int num = stoi(t);
        if(num < 0 || num > 255)
          return false;
    }
    
    return (cnt == 4 && ip.back()!='.')? true:false;
}
