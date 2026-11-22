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
            long long num=0;
            while(i<n&&isdigit(s[i])){
                num=num*10+(s[i]-'0');
                i++;
            }
            postfix+=to_string(num)+" ";
            i--;  
            expectoperand=false;
        }
        else if(ch=='('){
            st.push("(");
            expectoperand=true;
        }
        else if(ch==')'){
            while(!st.empty() && st.top()!="("){
                postfix+=st.top()+" ";
                st.pop();
            }
            st.pop();
            if(!st.empty()&&st.top()=="NEG"){
                postfix+="NEG ";
                st.pop();
            }
            expectoperand=false;
        }
        else if(ch=='+'||ch=='-'){
            if(ch=='-'&&expectoperand){
                st.push("NEG");
                continue;
            }
            while(!st.empty()&&st.top()!="("){
                postfix+=st.top()+" ";
                st.pop();
            }
            string op(1,ch);
            st.push(op);
            expectoperand=true;
        }
    }
    while(!st.empty()){
        postfix+=st.top()+" ";
        st.pop();
    }
    stack<long long> st1;
    stringstream ss(postfix);
    string token;
    while(ss>>token){
        if(token=="NEG"){
            long long a=st1.top();
            st1.pop();
            st1.push(-a);
        }
        else if(token=="+"||token=="-"){
            int a=st1.top();
            st1.pop();
            int b=st1.top();
            st1.pop();
            if(token=="+"){
                st1.push(b+a);
            }
            if(token=="-"){
                st1.push(b-a);
            }
        }
        else{
            st1.push(stoll(token));
        }
    }
    return st1.top();
    }
};