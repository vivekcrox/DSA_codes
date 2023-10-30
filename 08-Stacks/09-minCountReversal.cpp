
int countRev (string s)
{   
    //if string len is odd, not possible
    if(s.length() & 1) return -1;
    
    stack<char> st;
    for(auto ch: s){
        if(ch=='{'){
            st.push('{');
        }
        else{
            if(!st.empty() && st.top() == '{')
                st.pop();
            else
                st.push(ch);
        }
    }
    
    //valid paren removed, now count reversals.
    int count = 0;
    while(!st.empty()){
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();
        
        if(a==b)
            count += 1;
        else
            count +=2;
    }
    return count;
}