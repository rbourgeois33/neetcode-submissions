#include <ranges>
#include <algorithm>

//Same but with counting iterator
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = static_cast<int>(nums.size());
        auto indices = std::views::iota(0, n);   // lazy: no vector, no iota fill

        std::unordered_map<int,int> map;
        map.reserve(n);
        std::ranges::for_each(indices, [&](const int i){
            map.insert({nums[i], i});            // keeps the first index
        });

        std::vector<int> result{-1,-1};
        std::ranges::find_if(indices, [&](const int i){
            const auto found = map.find(target - nums[i]);
            if (found == map.end()) return false;
            const int j = found->second;
            if (i == j) return false;
            result = { std::min(i,j), std::max(i,j) };
            return true;
        });
        return result;
    }
};