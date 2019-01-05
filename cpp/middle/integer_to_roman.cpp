class Solution {
public:
    string intToRoman(int num) {
        if(num == 0)
            return "";
        string roman_num = "IVXLCDM";
        string ret;
        int i = 0;
        while(num)
        {
            int mod = num%10;
            if(mod <= 3)
                ret = string(mod, roman_num[i]) + ret;
            else if(mod == 4)
                ret = string(1, roman_num[i]) + string(1, roman_num[i+1]) + ret;
            else if(mod == 5)
                ret = string(1, roman_num[i+1]) + ret;
            else if(mod <= 8)
                ret = string(1, roman_num[i+1]) + string(mod-5, roman_num[i]) + ret;
            else if(mod == 9)
                ret = string(1, roman_num[i]) + string(1, roman_num[i+2]) + ret;
            num /= 10;
            i += 2;
        }
        return ret;
    }
};
