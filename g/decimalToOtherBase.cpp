/*
 int n: the input n is the number which needs to convert to another type
 int t: the t is the number for based, like 8 based, 2 based, 16 based
 */
string decimalConvert(int n, int t)
{
    string ret;
    while(n)
    {
        int rest = n%t;
        n = n/t;
        if(t == 16)
        {
            if(rest == 10)
                ret = "A"+ret;
            else if(rest == 11)
                ret = "B"+ret;
            else if(rest == 12)
                ret = "C"+ret;
            else if(rest == 13)
                ret = "D"+ret;
            else if(rest == 14)
                ret = "E"+ret;
            else if(rest == 15)
                ret = "F"+ret;
        }
        if(t < 16 || rest < 10)
            ret = to_string(rest) + ret;
    }
    return ret;
}
