class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1)
            return false;
        int sum = 1;
        for(int i = 2; i*i <= num; ++i)
        {
            if(num % i == 0)
                sum += (i + num/i);
            if(i * i == num)
                sum -= i;
            if(sum > num)
                return false;
        }
        return sum == num;
    }
};


Conclusion:
an easy algorithm issue, we iterate the number from 2 to sqrt(n). initialize sum value is 1(because 1 is always been an factor of any
integer), if input num can be divided by an element, then add the element and num/element to the sum; 
Note, if element * element == num, we need to minus one element value to avoid the duplicate value add to the sum. Then check the sum value 
whether or not equal to the num out of the for loop.

Time Complexity is: O(sqrt(n))
Space Complexity is: O(1)
