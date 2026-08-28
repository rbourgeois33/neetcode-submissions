class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        
        const size_t n = nums.size();

        //fix4: early returns are not needed
        //fix4.5: early returns are not needed, they improve perf tho.

        if (n==0) return 0;
        if (n==1) return 1;

        //O(n), O(1) lookup we dont want to sort
        unordered_set<int> nums_set(nums.begin(), nums.end());

        //We try to build sequences with find. A candidate for the start of a sequence is a num for which num-1 is not in the sequence
        int result=0;
        //fix1: iterate over set not nums !!!
        for(auto const num:nums_set){
            int cur=0;
            
            //not found, good candidate for the start of a sequence
            //fix2: no need for is_in_set. contains exists !
            //fix3: cleaner with continue
            if (nums_set.contains(num-1)) continue;
                
            do {cur+=1;}
            while(nums_set.contains(num+cur));

            result = std::max(cur, result);
        }
        

    return result;          
    }
};
