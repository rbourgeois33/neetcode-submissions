

void twoSum(vector<int>& nums, const int target, const int anchor, vector<vector<int>>& result) {

        int left_index = anchor+1;
        int right_index = nums.size()-1;

        std::cout<<"[twoSum] trying to hit "<<target<<" excluding "<<-target<<std::endl;

        while(left_index<right_index){
            
            const int sum = nums[left_index] + nums[right_index];
            
            if(sum>target) {
                right_index--;
                continue;
            }else if (sum<target){
                left_index++;
                continue;
            }else{
                std::cout<<"found!\n";
                result.emplace_back();
                result[result.size()-1] = {nums[left_index], nums[right_index], nums[anchor]};
                left_index++; right_index--;
                while (left_index < right_index && nums[left_index] == nums[left_index-1]) left_index++;
                while (left_index < right_index && nums[right_index] == nums[right_index+1]) right_index--;
            }

        }    
}



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int index=0; index<nums.size(); index++){
            if (index > 0 && nums[index] == nums[index-1]) continue;//avoid duplicate entries
            twoSum(nums, -nums[index], index, result);
        }

        return result;
    };
};
