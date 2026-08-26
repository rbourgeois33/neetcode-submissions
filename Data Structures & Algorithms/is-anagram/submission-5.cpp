void compute_histo(const string& s, std::map<char,int>& histo){

    for(auto c : s){
        histo[c]+=1;
    }
}

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length()!=t.length()) return false;

        //collection of key-value pairs, sorted by keys, keys are unique
        //ideal for histo
        std::map<char,int> h_s;
        std::map<char,int> h_t;

        //O(2*N)
        compute_histo(s, h_s);
        compute_histo(t, h_t);
        
        //O(26 actually)
        return h_t==h_s;
    }
};
