class Solution {
public:
    int scoreOfString(string& s, int i=1) {
        return (i==s.size())?0:abs(s[i]-s[i-1])+scoreOfString(s, i+1);
    }
};
