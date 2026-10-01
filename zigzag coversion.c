class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        vector<string> v(numRows);
        int r = 0, d = 1;
        for (char c : s) {
            v[r] += c;
            if (r == 0) d = 1;
            else if (r == numRows - 1) d = -1;
            r += d;
        }
        string res;
        for (auto& row : v) res += row;
        return res;
    }
};
