inline bool is_in_set(int num, unordered_set<int>& set){
    return (set.find(num)!=set.end());
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        const size_t n = nums.size();

        if (n==0) return 0;
        if (n==1) return 1;

        //O(n), O(1) lookup we dont want to sort
        unordered_set<int> set(nums.begin(), nums.end());

        //We try to build sequences with find. A candidate for the start of a sequence is a num for which num-1 is not in the sequence
        int max=0;
        for(auto num:nums){
            int cur=0;
            
            //not found, good candidate for the start of a sequence
            if(!is_in_set(num-1,set)){ 
                
                do {
                    cur+=1;
                }
                while(is_in_set(num+cur,set));                
            }

            max = std::max(cur, max);
        }

    return max;          
    }
};
