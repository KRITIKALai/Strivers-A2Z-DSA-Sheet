//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
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
    
    string infixToPostfix(string s) {
        // Your code here
        stack<char> ch;
        string final;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c>='a'&&c<='z' || c>='A'&&c<='Z' || c>='0'&&c<='9'){
                final+=c;
            }
            else if(c=='('){
                ch.push(c);
            }
            else if(c==')'){
                while(ch.top()!='('){
                    final+=ch.top();
                    ch.pop();
                }
                ch.pop();
            }
            else{
                while(!ch.empty() && prec(c)<=prec(ch.top())){
                    final+=ch.top();
                    ch.pop();
                }
                ch.push(c);
            }
        }
        while(!ch.empty()){
            final+=ch.top();
            ch.pop();
        }
        return final;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends
