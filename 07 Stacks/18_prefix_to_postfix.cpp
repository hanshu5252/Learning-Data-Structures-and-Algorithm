#include<iostream>
#include<stack>
using namespace std;
string eval(string &pre){
    stack<string> st;
    reverse(pre.begin(),pre.end());
    for(int i =0;i< pre.size(); i++){
        if(isdigit(pre[i])){
            st.push(to_string(pre[i]-'0')); 
        }
        else{
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            string newxp = v1+v2+pre[i];
            st.push(newxp);
        }
    }
    retun st.top();
}
int main(){
    string str = "*+3-15";
    string ans =eval(str);
    cout<ans<<endl;
return 0;
}