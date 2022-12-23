//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool isChar(string ch){
        if(ch>="a"&&ch<="z" || ch>="A"&&ch<="Z") return true;
        return false;
    }
    
    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        string final;
        for(int i=0;i<exp.length();i++){
            string ch(1, exp[i]);
            if(isChar(ch)){
                st.push(ch);
            }
            else{
                string sec=st.top();
                st.pop();
                string fir=st.top();
                st.pop();
                st.push("("+fir+ch+sec+")");
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
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends
