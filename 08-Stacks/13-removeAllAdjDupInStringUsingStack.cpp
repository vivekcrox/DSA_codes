class Solution {
public:
    string removeDuplicates(string s) {
        // string ans = "";
        // int i=0;
        // while(i<s.length()){
        //     if(ans.length() > 0 && ans[ans.length()-1]==s[i]){
        //         ans.pop_back();
        //     }else{
        //         ans.push_back(s[i]);
        //     }
        //     i++;
        // }
        // return ans;

        //2.Using Stacks
        stack<char> st;

        for(auto ch: s){
            if(!st.empty() && ch==st.top()){   
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};