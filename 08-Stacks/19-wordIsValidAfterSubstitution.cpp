class Solution {
public:
    bool isValid(string s) {
        //1. brute force
        // int pos = s.find("abc");
        // while(pos != string::npos){
        //     string left = s.substr(0, pos);
        //     string right = s.substr(pos+3, s.size());
        //     s = left + right;
            
        //     pos = s.find("abc");
        // }
        // if(s==""){
        //     return true;
        // }
        // else{
        //     return false;
        // }
/************************************************/
        //2. using stack
        if(s[0] != 'a') return false;

        stack<char> st;
        for(char ch:s){
            if(ch == 'a')
                st.push(ch);
            else if(ch == 'b'){
                if(!st.empty() && st.top() == 'a')
                    st.push('b');
                else
                    return false;
            }
            else{
                //ch == 'c'
                if(!st.empty() && st.top() == 'b'){
                    st.pop();
                    if(!st.empty() && st.top() == 'a')
                        st.pop();
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        return st.empty();
    }
};