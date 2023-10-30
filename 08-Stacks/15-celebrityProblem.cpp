class Solution 
{
    public:
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        //step1: push all element in stack
        for(int i=0; i<n; i++) {
            s.push(i);
        }   
        
        //step2: get 2 elements and compare them
        
        while(s.size() > 1) {
            
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(M[a][b])  //a is not celeb
                s.push(b);
            else
                s.push(a);
        }
        
        int ans = s.top();   //possible ans
        //step3: single element in stack is potential celeb
        //so verify it
        
        //Celeb. shouldn't know anyone
        for(int i=0; i<n; i++) {
            if(M[ans][i] != 0)
                return -1;
        }
        
        //Celeb. should be known to everyone except himself.
        
        for(int i=0; i<n; i++) {
            if(M[i][ans] == 0 && i!=ans)
                return -1;
        }
        
        return ans;
    }
};