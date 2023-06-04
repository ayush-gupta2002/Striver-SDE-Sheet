//OPTIMAL

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate_1 = -1;
        int candidate_2 = -1;
        int votes_1 = 0;
        int votes_2 = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == candidate_1){
                votes_1++;
            }
            else if(nums[i] == candidate_2){
                votes_2++;
            }
            else if(votes_1 == 0){
                candidate_1 = nums[i];
                votes_1 = 1;
            }
            else if(votes_2 == 0){
                candidate_2 = nums[i];
                votes_2 = 1;
            }
            else{
                votes_1--;
                votes_2--;
            }
        }
        vector<int> ans;

        int cnt1 = 0;
        int cnt2 = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == candidate_1){
                cnt1++;
            }else if(nums[i] == candidate_2){
                cnt2++;
            }
        }
        if(cnt1 > floor(nums.size()/3)){
            ans.push_back(candidate_1);
        }
        if(cnt2 > floor(nums.size()/3)){
            ans.push_back(candidate_2);
        }
        return ans;
    }
};
