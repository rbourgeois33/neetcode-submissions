
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left_index = 0;
        int right_index = numbers.size()-1;

        do{
            
            const int sum = numbers[left_index] + numbers[right_index];
            
            if(sum>target) {
                right_index--;
                continue;
            }else if (sum<target){
                left_index++;
                continue;
            }else{
                return {left_index+1, right_index+1};
            }

        } while(left_index<right_index);
        
        
    }
};
