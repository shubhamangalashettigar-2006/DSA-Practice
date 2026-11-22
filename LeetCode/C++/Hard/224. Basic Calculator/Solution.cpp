class Solution {
public:
    int calculate(string s) {
    stack<string> st;
    string postfix="";
    int n=s.size();
    bool expectoperand=true;
    for(int i=0;i<n;i++){
        char ch=s[i];
        if(ch==' '){
            continue;
        }
        else if(isdigit(ch)){
            int num=0;
            while(i<n&&isdigit(s[i])){
                num=num*10+(s[i]-'0');
                i++;
            }
            postfix+=to_string(num)+" ";
            expectoperand=false;
            i--;  
        }
        else if(ch=='('){
            st.push('(');
            expectoperand=true;
        }
    }
};