class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boat = 0;
        int i = 0; 
        int j = people.size()-1;
        while(i <= j)
        {
            int rest = limit-people[j];
            --j;
            if(rest >= people[i])
                ++i;
            boat++;
        }
        return boat;
    }
};

/*
Conclusion:
an easy level algorithm issue, notice: there are at most 2 person in a boat.
1. we can sort the people.
2. let the heaviest people go to the boat first of all.
3. if there is enough space to save the light person, we can let the light person go to the boat.
4. return the boat result.

Time Complexity is: O(logN)
Space Complexity is: O(1)
*/
