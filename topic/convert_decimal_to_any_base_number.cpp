/* this topic is about convert a decimal number to any base number, up to hex(16) */


/* convert non-negative number from decimal to any base number */
string to_base(int num, int base)
{
    if(num == 0)
        return "0";
    string bases = "0123456789ABCDEF";
    string ret;
    while(num)
    {
        ret = bases[num%base] + ret;
        num /= base;
    }
    return ret;
}



/*

result:
to_base(10,2) ==> 1010
to_base(5,2) ==> 101
to_base(10,16) ==> A
to_base(10,8) ==> 12
to_base(32,2) ==> 100000

*/
