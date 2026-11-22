
class Solution {
public:
    int calculate(string s) {

        // Step 1: Convert infix to postfix
        stack<string> st;
        string postfix = "";

        int n = s.size();
        bool expectOperand = true;

        for(int i = 0; i < n; i++) {

            char ch = s[i];

            if(ch == ' ') {
                continue;
            }

            // Read complete number
            if(isdigit(ch)) {

                int num = 0;

                while(i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                postfix += to_string(num) + " ";
                i--;

                expectOperand = false;
            }

            // Opening bracket
            else if(ch == '(') {
                st.push("(");
                expectOperand = true;
            }

            // Closing bracket
            else if(ch == ')') {

                while(!st.empty() && st.top() != "(") {
                    postfix += st.top() + " ";
                    st.pop();
                }

                if(!st.empty()) {
                    st.pop();  // Remove '('
                }

                // Handle unary minus before brackets
                if(!st.empty() && st.top() == "NEG") {
                    postfix += "NEG ";
                    st.pop();
                }

                expectOperand = false;
            }

            // Plus or minus
            else if(ch == '+' || ch == '-') {

                // Unary minus
                if(ch == '-' && expectOperand) {
                    st.push("NEG");
                    continue;
                }

                // Unary plus
                if(ch == '+' && expectOperand) {
                    continue;
                }

                // Pop previous operators
                while(!st.empty() && st.top() != "(") {
                    postfix += st.top() + " ";
                    st.pop();
                }

                string op(1, ch);
                st.push(op);

                expectOperand = true;
            }
        }

        // Pop remaining operators
        while(!st.empty()) {
            postfix += st.top() + " ";
            st.pop();
        }


        // Step 2: Evaluate postfix
        stack<int> st1;

        stringstream ss(postfix);
        string token;

        while(ss >> token) {

            if(token == "NEG") {

                int a = st1.top();
                st1.pop();

                st1.push(-a);
            }

            else if(token == "+" || token == "-") {

                int a = st1.top();
                st1.pop();

                int b = st1.top();
                st1.pop();

                if(token == "+") {
                    st1.push(b + a);
                }
                else {
                    st1.push(b - a);
                }
            }

            else {
                st1.push(stoi(token));
            }
        }

        return st1.top();
    }
};
