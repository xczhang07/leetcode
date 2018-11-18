Solution 1:
int rotatedDigits(int N) {
        int valid = 0;
        for(int i = 1; i <= N; ++i)
        {
            if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000)
                continue;
            string num = to_string(i);
            if(num.find("3") != string::npos)
                continue;
            else if(num.find("4") != string::npos)
                continue;
            else if(num.find("7") != string::npos)
                continue;
            else
            {
                for(int j = 0; j < num.size(); ++j)
                {
                    if(num[j] == '2')
                        num[j] = '5';
                    else if(num[j] == '5')
                        num[j] = '2';
                    else if(num[j] == '6')
                        num[j] = '9';
                    else if(num[j] == '9')
                        num[j] = '6';
                }
                if(stoi(num) != i)
                    ++valid;
            }
        }
        return valid;
    }
    
    
    Solution 2(much faster):
    
    int rotatedDigits(int N) {
        int valid = 0;
        bool flag = true;
        for(int i = 1; i <= N; ++i)
        {
            int num = i;
            flag = false;
            while(num)
            {
                int rest = num % 10;
                if(rest == 4 || rest == 7 || rest == 3)
                {
                    flag = false;
                    break;
                }
                else if(rest == 2 || rest == 5 || rest == 6 || rest == 9)
                    flag = true;
                num /= 10;
            }
            if(flag)
                ++valid;
        }
        return valid;
    }
