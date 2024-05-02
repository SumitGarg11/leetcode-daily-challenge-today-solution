Intuition

2 methods.

    Sorting nums + 2 pointer
    1 pass using seen array (a unsigned char array is enough)

Approach

The 1st method needs sorting O(n log n) time which is a very standard method; then use 2-pointer to find the answer.

The 2nd method use a uint8_t array instead of the slow C++ unordered_map or unordered_set.
The bit manipulation trick is so: if negative x is seen set seen[-x]|=2, if positive x is seen set seen[x]|=1. seen[x]==3   ⟺  \iff⟺ both x, -x are seen.
Complexity

    Time complexity:

O(nlog⁡n)O(n\log n)O(nlogn) vs O(n)O(n)O(n)

    Space complexity:

O(1)O(1)O(1) vs O(n)O(n)O(n)
C++ sort+ 2 pointer||11 ms Beats 94.04%

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size(), l=0, r=n-1;
        sort(nums.begin(), nums.end());
        while(l<r && nums[l]!=-nums[r]){
            if (-nums[l]>nums[r]) l++;
            else r--;

        }
        return (l<r) ?nums[r]:-1;
          
    }
};

Code using seen array||8ms Beats 97.34%

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        uint8_t seen[1001]={0};
        int k=-1;
        for(int x:nums){
            if (x<0) {
                x=-x;
                seen[x]|=2;
            }
            else seen[x]|=1;
            if (seen[x]==3 && x>k) k=x;
        }
        return k;
    }
};
