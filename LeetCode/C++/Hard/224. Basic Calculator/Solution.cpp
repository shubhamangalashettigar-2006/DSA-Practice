// class Solution {
// public:
//     int calculate(string s) {
//     stack<string> st;
//     string postfix="";
//     int n=s.size();
//     bool expectoperand=true;
//     for(int i=0;i<n;i++){
//         char ch=s[i];
//         if(ch==' '){
//             continue;
//         }
//         else if(isdigit(ch)){
//             long long num=0;
//             while(i<n&&isdigit(s[i])){
//                 num=num*10+(s[i]-'0');
//                 i++;
//             }
//             postfix+=to_string(num)+" ";
//             i--;  
//             expectoperand=false;
//         }
//         else if(ch=='('){
//             st.push("(");
//             expectoperand=true;
//         }
//         else if(ch==')'){
//             while(!st.empty() && st.top()!="("){
//                 postfix+=st.top()+" ";
//                 st.pop();
//             }
//             st.pop();
//             if(!st.empty()&&st.top()=="NEG"){
//                 postfix+="NEG ";
//                 st.pop();
//             }
//             expectoperand=false;
//         }
//         else if(ch=='+'||ch=='-'){
//             if(ch=='-'&&expectoperand){
//                 st.push("NEG");
//                 continue;
//             }
//             while(!st.empty()&&st.top()!="("){
//                 postfix+=st.top()+" ";
//                 st.pop();
//             }
//             string op(1,ch);
//             st.push(op);
//             expectoperand=true;
//         }
//     }
//     while(!st.empty()){
//         postfix+=st.top()+" ";
//         st.pop();
//     }
//     stack<long long> st1;
//     stringstream ss(postfix);
//     string token;
//     while(ss>>token){
//         if(token=="NEG"){
//             long long a=st1.top();
//             st1.pop();
//             st1.push(-a);
//         }
//         else if(token=="+"||token=="-"){
//             long long a=st1.top();
//             st1.pop();
//             long long b=st1.top();
//             st1.pop();
//             if(token=="+"){
//                 st1.push(b+a);
//             }
//             if(token=="-"){
//                 st1.push(b-a);
//             }
//         }
//         else{
//             st1.push(stoll(token));
//         }
//     }
//     return st1.top();
//     }
// };

class Solution {
public:
    int calculate(string s) {
    long long res=0;
    long long num=0;
    stack<long long> st;
    int sign=1;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(isdigit(ch)){
            num=num*10+(ch-'0');
        }
        else if(ch=='+'){
            res+=num*sign;
            num=0;
            sign=1;
        }
        else if(ch=='-'){
            res+=num*sign;
            num=0;
            sign=-1;
        }
        else if(ch=='('){
            st.push(res);
            st.push(sign);
            res=0;
            sign=1;
        }
        else if(ch==')'){
            res+=sign*num;
            num=0;
            res*=st.top();
            st.pop();
            res+=st.top();
            st.pop();
        }
    }
    res+=sign*num;
    return (int)res;
    }
};