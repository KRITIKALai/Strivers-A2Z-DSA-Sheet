//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        pair<int, int> d;
        vector<int> ans(N,0);
    
        for(int i=0;i<N;i++){
            d.first = arr[i];
            d.second = i;
            minh.push(d);
        }
        
        int prev = minh.top().first;
        int i = 1;
        while(!minh.empty()){
            if(prev!=minh.top().first) i++;
            d = minh.top();
            minh.pop();
            prev = d.first;
            ans[d.second] = i;    
        }
        
        return ans;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
