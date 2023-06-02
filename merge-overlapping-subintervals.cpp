class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int> currentInterval = intervals[0];
        vector<vector<int>> ans;

        for(int i=1;i<intervals.size();i++){
            //BOTH LIMITS MERGE
            if(currentInterval[0] <= intervals[i][0] && currentInterval[1] >= intervals[i][1]){
                cout<<currentInterval[0]<<" "<<currentInterval[1]<<endl;
                continue;
            }

            //HIGHER LIMIT MERGES
            if(currentInterval[1] >= intervals[i][0] && currentInterval[1] <= intervals[i][1]){
                cout<<"higher ";
                cout<<currentInterval[0]<<" "<<currentInterval[1]<<endl;
                currentInterval[1] = intervals[i][1];
                continue;
            }

            //LOWER LIMIT MERGES
            if(currentInterval[0] >= intervals[i][0] && currentInterval[0] <= intervals[i][1]){

                currentInterval[0] = intervals[i][0];
                continue;
            }

            //NONE OF THEM MERGE
            else{
                ans.push_back(currentInterval);
                currentInterval = intervals[i];
                continue;
            }
        }
        ans.push_back(currentInterval);
        return ans;
    }
};
