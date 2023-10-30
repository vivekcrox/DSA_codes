class Solution {
public:

    void solve(vector<string>& ans, string& output, int index, string& digits, vector<string>& mapping){
        //base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        //1 case solve, baaki recursion will handle
        int digit = digits[index]-'0';
        string value = mapping[digit];
        for(int i=0; i<value.length(); i++){
            char ch = value[i];
            //include
            output.push_back(ch);
            //recursion
            solve(ans,output,index+1,digits,mapping);
            //exclude
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        
        int index = 0;
        string output = "";
        vector<string> mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        solve(ans, output, index, digits, mapping);

        return ans;
    }
};