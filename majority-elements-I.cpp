//BRUTE FORCE

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;

        for(int i:nums){
            hash[i]++;
        }

        for(pair<int,int> p:hash){
            if(p.second > nums.size()/2){
                return p.first;
            }
        }
        return -1;
    }
};

//OPTIMAL

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int cnt = 0;

        for(int i=0;i<nums.size();i++){
            if(cnt == 0){
                candidate = nums[i];
            }
            if(candidate == nums[i]){
                cnt++;
            }else if(candidate != nums[i]){
                cnt--;
            }
        }
        return candidate;
    }
};
