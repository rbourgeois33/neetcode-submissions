void compute_histo(const string& s, std::map<char,int>& histo){

    for(auto c : s){
        histo[c]+=1;
    }
}

struct transform_op{
    std::map<char,int>& h_s;
    std::map<char,int>& h_t;

    bool operator()(const char& c){
        return (h_s[c] == h_t[c]);
    }
};


class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length()!=t.length()) return false;

        //collection of key-value pairs, sorted by keys, keys are unique
        //ideal for histo
        std::map<char,int> h_s;
        std::map<char,int> h_t;

        compute_histo(s, h_s);
        compute_histo(t, h_t);

        //Transform double histo into bools then reduce
        return std::transform_reduce(
                    s.begin(),
                    s.end(),
                    true,
                    std::logical_and(),
                    transform_op{h_s, h_t});
    }
};
