class Solution {
public:
    void generateParenthesis_Helper(int open, int close, string& output, vector<string>& parenthesis){
        if(open == 0 && close == 0){
            parenthesis.push_back(output);
            return;
        }

        if(open > 0){
            output.push_back('(');
            generateParenthesis_Helper(open-1,close,output,parenthesis);
            //backtracking  : if we don't pass string& output as by reference and simplify concat with  output string the brackets we don't need push or pop back operation
            output.pop_back();
        }
        if(close > open){   //means remaining close brackets is more than open brackets as some of the opening brackets have been used
            output.push_back(')');
            generateParenthesis_Helper(open,close-1,output,parenthesis);
            //backtracking
            output.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        string output = "";

        int open = n;
        int close = n;

        generateParenthesis_Helper(open,close,output,parenthesis);
        return parenthesis;
    }
};