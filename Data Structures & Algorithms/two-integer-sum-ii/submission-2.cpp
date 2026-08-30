
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        auto left_index = 0;
        auto right_index = numbers.size()-1;

        do{
            
            const auto sum = numbers[left_index] + numbers[right_index];
            
            if(sum>target) {
                right_index--;
                continue;
            }else if (sum<target){
                left_index++;
                continue;
            }else{
                std::vector<int> result(2);
                result[0] = left_index+1;
                result[1] = right_index+1;
                return result;
            }

        } while(left_index<right_index);
        
        
    }
};
