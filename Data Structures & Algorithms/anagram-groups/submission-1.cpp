//Solution: building a hash map mapping key_t
using _key_t = std::array<int,26>; // 26 character histogram
//To positions in the result. Because if histo ==, it's anagram
using bucket_t = vector<string>;

//dont deep copy. n complexity
_key_t compute_frequencies(const string& s) {
        _key_t freq{};
        //O(n) at worst, c-a is for offset
        std::for_each(s.begin(), s.end(), [&](const char c) {freq[c-'a']+=1;} );
        return freq;
}





class Solution {
public:
    vector<bucket_t> groupAnagrams(vector<string>& strs) {
         
        //result: size number of anagrams
        vector<bucket_t> result;

        const size_t m = strs.size();

        //We hash all the strings, m*n complexity
        vector<_key_t> hashs(m);
        std::transform(strs.cbegin(), strs.cend(), hashs.begin(), compute_frequencies);
        

        //maps key to locations in result. Keys are hashs
        std::map<_key_t, size_t> hash_map; 

        for(size_t i=0; i<m; i++){

            auto hash = hashs[i];
            //try_emplace: if hash is in map:
            //success = false, add (hash, result.size()) to the map, it->second = map.size()+1
            //else, success=true, it->second = the index.
            auto [it,success] = hash_map.try_emplace(hash,result.size());

            auto bucket_idx = it->second; //So it's where we put the string 

            if (success) result.emplace_back();// build empty bucket if success ??

            //Add the string to the correct bucket
            result[bucket_idx].push_back(strs[i]);

        };
        
        return result;
    }
};
