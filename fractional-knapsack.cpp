//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        priority_queue<pair<double,Item>> pq;
        
        for(int i=0;i<n;i++){
            double perUnit = (double)(arr[i].value/arr[i].weight);
            
            pq.push({perUnit,arr[i]});
        }
        
        int left = W;
        double ans = 0;
        
        while(left >0 && !pq.empty()){
            pair<double,Item> topPair = pq.top();
            pq.pop();
            
            if(topPair.second.weight >= left){
                ans += topPair.first * left;
                left = 0;
            }else{
                ans += topPair.second.value;
                left -= topPair.second.weight;
            }
        }
        
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
