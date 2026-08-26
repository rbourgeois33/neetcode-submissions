
//std::find_if Returns an iterator to the first element in the source range [first, last) that satisfies specific criteria (or last if there is no such iterator).
//std::map is a sorted associative container that contains key-value pairs with unique keys. 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //0,1,....
        std::vector<int> indices(nums.size());
        std::iota(indices.begin(), indices.end(),0);
        
        std::unordered_map<int,int> map;
        std::for_each(indices.begin(),
                      indices.end(),
                      [&](const int i){
                       // map[nums[i]]=i; We want first index that would overwrite !!!!
                       map.insert({nums[i], i});  //Pair {nums[10],10} for instance
                      });
        
        std::vector<int> result({-1,-1});

        std::find_if(indices.begin(),
                     indices.end(),
                     [&](const int i){
                        const int lookfor=target-nums[i]; //for each value in nums, we compute target

                        const auto found = map.find(lookfor);
                    
                        if (found==map.end()) return false; // if not found, no op
                        const int j = found->second;//index of second value
                        if( i==j ) return false; // if i==j found, no op

                        result = { std::min(i,j), std::max(i,j) };
                        return true;
                     });

    
    return result;

    }

    
};
