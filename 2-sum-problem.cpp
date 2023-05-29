class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i]) != hash.end()){
                if(target / 2 == nums[i]){
                    return {i,hash[target/2]};
                }
            }
            hash[nums[i]] = i;
        }

        for(int i=0;i<nums.size();i++){
            if(hash.find(target-nums[i]) != hash.end() && hash[target-nums[i]] != i){
                return {i,hash[target-nums[i]]};
            }
        }
        return {};

        return ans;
    }
};
