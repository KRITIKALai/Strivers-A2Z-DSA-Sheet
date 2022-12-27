//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool isChar(string ch){
        if(ch>="a"&&ch<="z" || ch>="A"&&ch<="Z"){
            return true;
        }
        return false;
    }
    
    bool isOperator(string ch){
        if(ch=="+"||ch=="-"||ch=="*"||ch=="/"){
            return true;
        }
        return false;
    }
    
    int prec(string ch){
        if(ch=="^") return 3;
        else if(ch=="*" || ch=="/") return 2;
        else if(ch=="+" || ch=="-") return 1;
        else return -1;
    }
    
    string preToInfix(string s){
        stack<string> st;
        for(int i=s.length()-1;i>=0;i--){
            string ch(1, s[i]);
            if(isChar(ch)){
                st.push(ch);
            }
            else{
                string first = st.top();
                st.pop();
                string second = st.top();
                st.pop();
                st.push("("+first+ch+second+")");
            }
        }
        return st.top();
    }
    
    string infixToPost(string s){
        stack<string> st;
        string final;
        
        for(int i=0;i<s.length();i++){
            string ch(1, s[i]);
            if(isChar(ch)){
                final+=ch;
            }
            else if(ch=="("){
                st.push("(");
            }
            else if(ch==")"){
                while(st.top()!="("){
                    final+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && prec(st.top())>=prec(ch)){
                    final += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        
        while(!st.empty()){
            final+=st.top();
            st.pop();
        }
        return final;
    }
    
    string preToPost(string pre_exp){
        return infixToPost(preToInfix(pre_exp));
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
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
