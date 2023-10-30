class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            // erase all words that has been
            // used in the previous levels to transform
            if(vec.size() > level){
                level++;
                for(auto it: usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();  
            }
            
            string word = vec.back();  //pick last word
            // store the answers
            
            if(word == endWord){
                // the first sequence where we reached end
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size()){// only if no. of words matches with min no. of words already stored.
                    ans.push_back(vec);
                }
            }
            
            // wordlength*26
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char c = 'a'; c<='z'; c++){
                    word[i] = c;
                    if(st.count(word) > 0){  // found
                        vec.push_back(word);
                        q.push(vec);
                        //mark as visited on the level
                        usedOnLevel.push_back(word);
                        vec.pop_back(); // so that on same level store another possibility of word.
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};