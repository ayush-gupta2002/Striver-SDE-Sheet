class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int breakPoint = -1;

        for(int i=0;i<n-1;i++){
            if(nums[i] < nums[i+1]){
                breakPoint = i;
            }
        }

        if(breakPoint == -1){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i=n-1;i>breakPoint;i--){
                if(nums[i] > nums[breakPoint]){
                    swap(nums[breakPoint],nums[i]);
                    break;
                }
            }
            reverse(nums.begin()+breakPoint+1,nums.end());
        }




    }
};
