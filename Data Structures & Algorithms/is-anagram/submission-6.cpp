

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length()!=t.length()) return false;

        //collection of key-value pairs, sorted by keys, keys are unique
        //ideal for histo
        std::map<char,int> h_s;
        std::map<char,int> h_t;

        //O(2*N)
        std::for_each(s.begin(), s.end(), [&](const char c) {h_s[c]+=1;} );
        std::for_each(t.begin(), t.end(), [&](const char c) {h_t[c]+=1;} );

        //O(26 actually)
        return h_t==h_s;
    }
};
