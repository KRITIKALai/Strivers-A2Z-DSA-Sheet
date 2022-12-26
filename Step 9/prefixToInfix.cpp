//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int prec(char c){
        if(c=='^'){
            return 3;
        }
        else if(c=='*' || c=='/'){
            return 2;
        }
        else if(c=='+' || c=='-'){
            return 1;
        }
        else{
            return -1;
        }
    }
    
    bool isChar(string ch){
        if(ch>="a"&&ch<="z" || ch>="A"&&ch<="Z"){
            return true;
        }    
        return false;
    }
    
    string preToInfix(string pre_exp) {
        // Write your code here
        int len = pre_exp.length();
        stack<string> st;
        
        for(int i=len-1;i>=0;i--){
            
            string ch(1, pre_exp[i]);
            
            if(isChar(ch)){
                st.push(ch);
            }
            else{
                string first=st.top();
                st.pop();
                string second=st.top();
                st.pop();
                st.push("("+first+ch+second+")");
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
