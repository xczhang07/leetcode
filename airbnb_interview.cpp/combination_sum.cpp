void backTracking(vector<vector<double>>& ret, vector<double>& path, vector<double>& prices, vector<int>& r_prices, int sum, int& r_target, int idx)
{
    if(sum > r_target)
        return;
    else if(sum == r_target)
    {
        ret.push_back(path);
        return;
    }
    
    for(int i = idx; i < prices.size(); ++i)
    {
        path.push_back(prices[i]);
        sum += r_prices[i];
        backTracking(ret, path, prices, r_prices, sum, r_target, i);
        sum -= r_prices[i];
        path.pop_back();
    }
    return;
}

vector<vector<double>> getCombination(vector<double> prices, double target)
{
    vector<vector<double>> ret;
    if(prices.size() == 0)
        return ret;
    int r_target = round(target*100);
    vector<double> path;
    int sum = 0;
    vector<int> r_prices;
    for(int i = 0; i < prices.size(); ++i)
        r_prices.push_back(round(prices[i]*100));
    backTracking(ret, path, prices, r_prices, sum, r_target, 0);
    return ret;
}

/* test case */
int main()
{
    double x = 1.236;
    cout<<round(x*100)<<endl;
    
    vector<double> prices = {1.23, 2.30, 5.46, 1.69, 6.00, 1.68, 6.01};
    double target = 7.69;
    vector<vector<double>> comb = getCombination(prices, target);
    
    for(int i = 0; i < comb.size(); ++i)
    {
        for(int j = 0; j < comb[i].size(); ++j)
            cout<<comb[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
