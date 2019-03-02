https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=488670&extra=&page=1

（一夫一妻制，不允许图中P又和其他人生小孩）
如何判断E和H是否related  ==> true
followup
孩子的基因是一半母亲，一半父亲。
判断E和H血缘有多少match ==> 50%
A和B血缘match ==> 100%


void getAncestor(unordered_set<char>& ancestor, unordered_map<char, pair<char, char>>& parents, char p)
{
    if(!parents.count(p))
        return;
    auto t = parents[p];
    ancestor.insert(t.first);
    ancestor.insert(t.second);
    getAncestor(ancestor, parents, t.first);
    getAncestor(ancestor, parents, t.second);
    return;
}

bool checkCommonAncestor(unordered_set<char>& ancestor, unordered_map<char, pair<char,char>>& parents, char p)
{
    if(!parents.count(p))
        return false;
    auto t = parents[p];
    char father = t.first;
    char mother = t.second;
    if(ancestor.count(father) || ancestor.count(mother))
        return true;
    bool l = checkCommonAncestor(ancestor, parents, father);
    bool r = checkCommonAncestor(ancestor, parents, mother);
    return l||r;
}

bool hasRelationShip(unordered_map<char, pair<char,char>>& parents, char p1, char p2)
{
    if(parents.size() == 0)
        return false;
    
    unordered_set<char> ancestor;
    ancestor.insert(p2);
    getAncestor(ancestor, parents, p2);
    if(ancestor.count(p1))
        return true;
   
    return checkCommonAncestor(ancestor, parents, p1);
}
