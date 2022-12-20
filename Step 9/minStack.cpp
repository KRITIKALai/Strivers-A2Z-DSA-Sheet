//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    stack<long long> s;
    long long mini;
    
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty()) return -1;
           else return mini;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
        if(s.empty()) return -1;
        
        long long x = s.top();
        s.pop();
        
        if(x <= mini)
        {
             long long res = mini;
             mini = 2*mini*1LL - x;
             return res;
        }
        return x;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(s.empty()){
               mini = x;
               s.push(x);
           }
           else{
               if(x<=mini){
                   s.push((2*x*1LL)-mini);
                   mini = x;
               }
               else{
                   s.push(x);
               }
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
