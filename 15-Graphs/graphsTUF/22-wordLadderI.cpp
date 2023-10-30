class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        
        //TC: O( N * word.length * 26 * logN)
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == targetWord)  // reached to our targetWord
                return steps;
            
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){ //found in the set.
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
            
        }
        return 0;  // if not possible
    }
};