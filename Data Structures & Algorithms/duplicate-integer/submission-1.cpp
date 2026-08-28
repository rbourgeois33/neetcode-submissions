#include <numeric>
#include <unordered_set>
#include <iostream>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        //Unordered set: unique set of keys
        //ctor removes duplicate
        unordered_set<int> set(nums.cbegin(), nums.cend());

        //wow
        return set.size() != nums.size(); 
    }
};

