class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>mp;
        for(char x : s){
            mp[x]++;
        }
          int freq = mp.begin()->second;
        for(auto it : mp){
            if(it.second != freq)
            return false;
        }
        return true;
    }
};