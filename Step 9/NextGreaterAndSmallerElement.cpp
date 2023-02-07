#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> ngr(vector<int> v){
    vector<int> ans;
    stack<int> stk; 
    for(int i=v.size()-1;i>=0;i--){
        int val = v[i];
        if(stk.empty()){
            ans.push_back(-1);
        }
        else if(stk.size()>0 && stk.top()>val){
            ans.push_back(stk.top());
        }
        else if(stk.size()>0 && stk.top()<=val){
            while(stk.size()>0 && stk.top()<=val){
                stk.pop();
            }
            if(stk.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(stk.top());
            }
        }
        stk.push(val);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> ngl(vector<int> v){
    vector<int> ans;
    stack<int> stk;
    for(int i=0;i<v.size();i++){
        int val = v[i];
        if(stk.empty()){
            ans.push_back(-1);
        }
        else if(stk.size()>0 && stk.top()>val){
            ans.push_back(stk.top());
        }
        else if(stk.size()>0 && stk.top()<=val){
            while(stk.size()>0 && stk.top()<=val){
                stk.pop();
            }
            if(stk.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(stk.top());
            }
        }
        stk.push(val);
    }
    return ans;
}

vector<int> nsl(vector<int> v){
    stack<int> stk;
    vector<int> ans;
    for(int i=0;i<v.size();i++){
        int val = v[i];
        if(stk.empty()){
            ans.push_back(-1);
        }
        else if(stk.size()>0 && stk.top()<val){
            ans.push_back(stk.top());
        }
        else if(stk.size()>0 && stk.top()>=val){
            while(stk.size()>0 && stk.top()>=val){
                stk.pop();
            }
            if(stk.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(stk.top());
            }
        }
        stk.push(val);
    }
    return ans;
}

vector<int> nsr(vector<int> v){
    vector<int> ans;
    stack<int> stk;
    for(int i=v.size()-1;i>=0;i--){
        int val = v[i];
        if(stk.empty()){
            ans.push_back(-1);
        }
        else if(stk.size()>0 && val>stk.top()){
            ans.push_back(stk.top());
        }
        else if(stk.size()>0 && val<=stk.top()){
            while(stk.size()>0 && val<=stk.top()){
                stk.pop();
            }
            if(stk.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(stk.top());
            }
        }
        stk.push(val);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> v = {1,3,2,4};
    cout<<"NGR:"<<endl;
    for(auto x: ngr(v)) cout<<x<<" ";
    cout<<endl<<"NGL:"<<endl;
    for(auto x: ngl(v)) cout<<x<<" ";
    cout<<endl<<"NSL:"<<endl;
    for(auto x: nsl(v)) cout<<x<<" ";
    cout<<endl<<"NSR:"<<endl;
    for(auto x: nsr(v)) cout<<x<<" ";
    return 0;
}
