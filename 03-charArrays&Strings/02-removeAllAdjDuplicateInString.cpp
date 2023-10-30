string remAllAdjDup(string str){
    string ans = "";
    for(int i=0; i<str.length(); i++){
        if(ans.length() > 0 && str[i]==ans[ans.size()-1]){
            ans.pop_back();
        }
        else{
            ans.push_back(str[i]);
        }
    }
    return ans;
}