class Solution {
public:
    string minWindow(string s, string t) {
        //edge
        if(t.length() > s.length()){
            return "";
        }

        unordered_map<char,int> mp;
        for(auto ch: t){
            mp[ch]++;
        }
        int count = mp.size();
        int i=0, j=0;
        int minLen = INT_MAX;
        int start = -1;

        while(j < s.length()){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }
            if(count == 0){
                while(count == 0){
                    if(mp.find(s[i]) != mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]] == 1){
                            count++;
                            if(j-i+1 < minLen){
                                minLen = j-i+1;
                                start = i;
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if(start == -1)
            return "";
        return s.substr(start, minLen);
    }
};