//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        map<int, int> freq;
        priority_queue<pair<int,int>> maxh;
        pair<int, int> p;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        
        
        for(auto el:freq){
            p.first = el.second;
            p.second = el.first;
            maxh.push(p);
        }
        
        while(k--){
            p = maxh.top();
            ans.push_back(p.second);
            maxh.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
