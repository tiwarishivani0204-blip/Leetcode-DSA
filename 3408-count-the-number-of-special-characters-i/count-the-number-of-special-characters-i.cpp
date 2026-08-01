class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>upper(26,0),lower(26,0);
        for(int x = 0 ; x < word.size();x++){
            if(word[x] >= 'a'&& word[x] <='z'){
                lower[word[x]-'a']= 1;
            }
            if(word[x] >='A' && word[x] <='Z'){
                upper[word[x]-'A'] = 1;
            }
        }
            int count = 0;
            for(int i = 0 ; i < 26; i++){
                if(lower[i] == 1 && upper[i] == 1)
                count++;
            }
         return count;
    }
};