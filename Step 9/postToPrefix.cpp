//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    string postToPre(string post_exp) {
        // Write your code here
        //string s = postToInfix(post_exp);
        stack<string> st;
        
        for(int i=0;i<post_exp.length();i++){
            string ch(1, post_exp[i]);
            if(ch=="+" || ch=="-" || ch=="*" || ch=="/"){
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                st.push(ch+s2+s1);
            }
            else{
                st.push(ch);   
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
