//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> brackets;
        for(bracket:x){
            if(brackets.empty()) brackets.push(bracket);
            else{
                if(bracket=='}'){
                    if(brackets.top()=='{'){
                        brackets.pop();
                        continue;
                    }
                }
                else if(bracket==']'){
                    if(brackets.top()=='['){
                        brackets.pop();
                        continue;
                    }
                }
                else if(bracket==')'){
                    if(brackets.top()=='('){
                        brackets.pop();
                        continue;
                    }
                }
                brackets.push(bracket);
            }
        }
        return brackets.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
