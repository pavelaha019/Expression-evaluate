#include <bits/stdc++.h>
using namespace std;
bool isOperand(char ch){
    return (ch>='a' && ch<='z') || (ch>='A' && ch <='Z');
}
string postfixToPrefix(string postfix) {
  stack<string> st;
 
  int len = postfix.size();
  for (int i = 0; i < len; i++) {
      if(isOperand(postfix[i])){
          
          st.push(string(1,postfix[i]));
         
      }
      else{
          string operand1=st.top();
          st.pop();
          
          string operand2=st.top();
          st.pop();
          
          st.push( string(1,postfix[i]) + operand2 + operand1);
      }
  }
  return st.top();
}
int main() {
    string postfix="abc/-ad/e-*";
    string prefix=postfixToPrefix(postfix);
    cout<<"Postfix expression : "<<postfix<<endl;
    cout<<"Prefix expression : "<<prefix<<endl;
    return 0;
}