//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    
    vector<int> maxToLeft(int arr[], int n){
        vector<int> ret;
        ret.push_back(arr[0]);
        for(int i=1;i<n;i++){
            ret.push_back(max(ret.back(), arr[i]));
        }
        return ret;
    }
    
    vector<int> maxToRight(int arr[], int n){
        vector<int> ret;
        ret.push_back(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            ret.push_back(max(ret.back(), arr[i]));
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    long long trappingWater(int arr[], int n){
        // code herea
        vector<int> maxL, maxR;
        maxL = maxToLeft(arr,n);
        maxR = maxToRight(arr,n);
        
        long long vol = 0;
        
        for(int i=0;i<n;i++){
            long long ht = min(maxL[i], maxR[i]);
            vol += (ht-arr[i]);    
        }
        
        return vol;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
