//Claude's most C++ idiomatic solution:

class Solution {
public:
    string encode(const vector<string>& strs) {
        size_t total = 0;
        //This could be a reduce
        for (const auto& s : strs) total += s.size() + 4;  // digits + '#'
        
        string out;
        out.reserve(total);//smarter alloc than mine (just what we need)
        //pretty sure this could be an accumulate or something (but without binary op ?)
        for (const auto& s : strs) {
            out += to_string(s.size()); //No padding, but a delimiter so technically more general than mine
            out += '#';
            out += s;
        }
        return out;
    }

    vector<string> decode(const string& s) {
        vector<string> out;
        for (size_t pos = 0; pos < s.size(); ) {
            const size_t hash = s.find('#', pos); //clean, first # after pos
            const size_t len  = stoul(s.substr(pos, hash - pos)); //get the number
            out.emplace_back(s, hash + 1, len);//like me essentially
            pos = hash + 1 + len;
        }
        return out;
    }
};