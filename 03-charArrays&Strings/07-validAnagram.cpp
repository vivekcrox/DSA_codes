bool isAnagram(string s, string t) {
        //I) Using sorting
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s.compare(t)==0;


        //II) Using hash table
        int freqTable[256] = {0};
        for(int i=0; i<s.size(); i++){
            freqTable[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            freqTable[t[i]]--;
        }

        for(int i=0; i<255; i++){
            if(freqTable[i] != 0){
                return false;
            }
        }
        return true;
    }