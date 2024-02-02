class Solution {
public:

    long long caculateHours(vector<int>& piles, int& amount) {
        long long hours = 0;
        for(auto& pile : piles) {
            if(pile < amount) {
                hours += 1;
            } else if(pile % amount == 0) {
                hours += pile/amount;
            } else {
                hours += (pile/amount+1);
            }
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        int min_amount = 0;
        while(low <= high) {
            int average = low + (high-low)/2;
            if(caculateHours(piles, average) <= h) {
                min_amount = average;
                high = average - 1;
            } else {
                low = average + 1;
            }
        }
        return min_amount;
    }
};

/*
Conclusion: this is a interesting question which will be resolved with binary search. The lowest amount of bananas number koko could eat is: 1 bananas/hour
the largest number of bananas koko could eat is: the largest piles[i] in the input piles. 
get the average number between lowest number and the largest number, calculate the total hours on each piles[i], using the binary search algorithm to get the 
best solution.
*/
