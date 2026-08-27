//AI generated solution for the sake of learning
//Done after I did mine
//If I submitted it, I understand it.

using _key_t = std::array<int,26>; 
using bucket_t = vector<string>;

_key_t compute_frequencies(const string& s) {
        _key_t freq{};
        std::for_each(s.begin(), s.end(), [&](const char c) {freq[c-'a']+=1;} );
        return freq;
}


class Solution {
public:
    vector<bucket_t> groupAnagrams(vector<string>& strs) {
        
        //Map to bucket, not index !
        std::map<_key_t, bucket_t> groups;
        
        //super push back strigns in their bucket, done !
        //Map have no const [], so it creates one if new freq
        for (auto& s : strs)
            groups[compute_frequencies(s)].push_back(std::move(s));
        
        //Now it's just bookeeping for map->vector conversion

        vector<bucket_t> result;
        result.reserve(groups.size());//to avoid realloc

        //std::back_inserter: will push_back
        //kv= key, value so whole buckets
        //this is o(#buckets)
        std::transform(groups.begin(), groups.end(), std::back_inserter(result),
                    [](auto& kv) { return std::move(kv.second); });
        return result;
    }
};