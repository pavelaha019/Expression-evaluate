#include <bits/stdc++.h>
using namespace std;
bool isOperand(char ch){
    return (ch>='a' && ch<='z') || (ch>='A' && ch <='Z');
}
string prefixToPostfix(string prefix) {
  stack<string> st;
 
  int len = prefix.size();
  for (int i = len - 1; i >= 0; i--) {
      if(isOperand(prefix[i])){
          
          st.push(string(1,prefix[i]));
         
      }
      else{
          string operand1=st.top();
          st.pop();
          
          string operand2=st.top();
          st.pop();
          
          st.push( operand1 + operand2  + string(1,prefix[i]));
      }
  }
  return st.top();
}
int main() {
    string prefix="*-a/bc-/ade";
    string postfix=prefixToPostfix(prefix);
    cout<<"Prefix expression : "<<prefix<<endl;
    cout<<"Postfix expression : "<<postfix<<endl;
    
    return 0;
}