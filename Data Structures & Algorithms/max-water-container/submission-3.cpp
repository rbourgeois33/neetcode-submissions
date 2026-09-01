
int amount(vector<int>& heights, const int hi, const int low){

    const int width = hi-low;
    const int height = min(heights[hi], heights[low]);

    return width*height;
}

class Solution {
public:
    int maxArea(vector<int>& heights) {
        

        int hi = heights.size()-1;
        int low = 0;

        int max = -100;
        while (hi>low){
            int cur = amount(heights,hi,low);
            
            if (cur>max){max=cur;}

            if (heights[low]>heights[hi]){
                hi--;
            }else{
                low++;
            }     
        }

        return max;
    }
};
