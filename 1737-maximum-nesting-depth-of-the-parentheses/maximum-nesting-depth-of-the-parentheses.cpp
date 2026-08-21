class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int Depth = 0;
        for (char ch : s) {
            if (ch == '(') {
                depth++;
                Depth = max(Depth, depth);
            }
            else if (ch == ')') {
                depth--;
            }
        }
        return Depth;
    }
};