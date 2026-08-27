class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        using _key_t = int;
        using _value_t = size_t;
        //std::map<_key_t, _value_t> histogram;

        //Map have no const [], so it creates one if new freq
        //O(n)-> I was wrong, operator [] is log(n) https://en.cppreference.com/cpp/container/map/operator_at
        //Because it sorts, and we dont care about sort by key so unordered & reserve to avoid rehashing

        std::unordered_map<_key_t, _value_t> histogram;
        histogram.reserve(nums.size()); //not resize!

        for (auto& num : nums)
            histogram[num]+=1;
        
        //Create a vector of pairs to sort it by value, not possible with map
        //todo, move
        using _pair_t = std::pair<_key_t, _value_t>;
        using _pair_ref_t = const _pair_t&;
        //O(#buckets <n)
        std::vector<_pair_t> histogram_v(histogram.cbegin(), histogram.cend());

        //sort by value
        //O(#buckets <n)
        std::sort(histogram_v.begin(),
                  histogram_v.end(),
                  [](_pair_ref_t a, _pair_ref_t b){
                    return a.second<b.second;
                  }
                  );

        vector<int> result(k);

        //extract the keys (number) from the sorted by value (freq) vector
        //O(k)
        std::transform(histogram_v.end()-k, 
                       histogram_v.end(),
                       result.begin(),
                       [](_pair_ref_t a){return a.first;}
        );
    return result;
    }
};
