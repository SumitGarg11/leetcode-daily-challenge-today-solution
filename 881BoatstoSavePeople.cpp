Intuition

Sorting the vector and using the two pointers approach.
Approach

1- Sort the Vector.
2- We can make the lightest & heaviest person to go together.
using Two pointer appraoch i is the lightest person & j is the heaviest.
Traversing till i <= j.
3- If sum of lightest & heaviest person are under limit then both can go together , updating i & j both.
4-If sum exceeds the limit, then heaviest person will go alone, hence updating only the j pointer.
increment the count .
5- Return cnt.
Complexity

    Time complexity: O(nlogn)

    Space complexity: O(1)
  
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
         sort(people.begin() , people.end());

        int i=0 , boats=0;
        int j=people.size()-1;

        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++;
                j--;
                boats++;
            }
            else{
                boats++;
                j--;
            }
        }

        return boats;
    }
};
