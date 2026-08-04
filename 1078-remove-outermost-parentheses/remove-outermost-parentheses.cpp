class Solution {
public:
    string removeOuterParentheses(string s) {
     string ans = "";
     int outermost = 0;
    for(char ch : s){
        if(ch == '('){
            if(outermost > 0)
                ans +=ch;
                outermost++;
        }
        else{
            outermost--;
            if(outermost > 0)
                ans +=ch;
        }
    }
    return ans;
    }
};