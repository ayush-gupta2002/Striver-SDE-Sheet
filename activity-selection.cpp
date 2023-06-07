//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>> meetings;
        for(int i=0;i<n;i++){
            meetings.push_back({start[i],end[i]});
        }
        
        sort(meetings.begin(),meetings.end(),[](vector<int>& a,vector<int>& b){return a[1] < b[1];});
        
        if(n == 0){
            return 0;
        }
        
        int cnt = 1;
        vector<int> curr = meetings[0];
        
        for(int i = 1 ; i< n;i++){
            if(meetings[i][0] > curr[1]){
                cnt++;
                curr = meetings[i];
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
