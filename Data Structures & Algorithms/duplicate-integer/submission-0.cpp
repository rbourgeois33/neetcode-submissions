#include <numeric>
#include <unordered_set>
#include <iostream>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        unordered_set<int> set(nums.cbegin(), nums.cend());

        return set.size() != nums.size();
    }
};