//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        pair<int,pair<int, int>> d;
        int arrPos, valPos;
        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> minh;
        for(int i=0;i<K;i++){
            d.first = arr[i][0];
            d.second.first = i;
            d.second.second = 0;
            minh.push(d);
        }
        while(!minh.empty()){
            d = minh.top();
            minh.pop();
            ans.push_back(d.first);
            arrPos = d.second.first;
            valPos = d.second.second;
            if(valPos+1 < arr[arrPos].size()){
                d.first = arr[arrPos][valPos+1];
                d.second.first = arrPos;
                d.second.second = valPos+1;
                minh.push(d);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}
