class Solution {
public:
    int minCostHelper(vector<int>& days, vector<int>& costs, int i){
        //base case
        if(i >= days.size()){
            return 0;
        }

        //1 day pass
        int cost1 = costs[0] + minCostHelper(days, costs, i+1);

        //7 days pass
        int passEndDay = days[i] + 7 - 1;
        int j =i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost2 = costs[1] + minCostHelper(days, costs, j);

        //30 days pass
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost3 = costs[2] + minCostHelper(days, costs, j);

        return min(cost1, min(cost2, cost3));
    }

    int solveMem(vector<int>& days, vector<int>& costs, int i, vector<int>& dp){
         //base case
        if(i >= days.size()){
            return 0;
        }

        if(dp[i] != -1)
            return dp[i];

        //1 day pass
        int cost1 = costs[0] + solveMem(days, costs, i+1, dp);

        //7 days pass
        int passEndDay = days[i] + 7 - 1;
        int j =i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost2 = costs[1] + solveMem(days, costs, j, dp);

        //30 days pass
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost3 = costs[2] + solveMem(days, costs, j, dp);

        dp[i] = min(cost1, min(cost2, cost3));
        return dp[i];
    }

    int solveTab(vector<int>& days, vector<int>& costs, int i){
        int n = days.size();
        vector<int> dp(n+1, INT_MAX);

        dp[n] = 0;

        for(int i=n-1; i>=0; i--){
            //1 day pass
            int cost1 = costs[0] + dp[i+1];

            //7 days pass
            int passEndDay = days[i] + 7 - 1;
            int j =i;
            while(j < days.size() && days[j] <= passEndDay){
                j++;
            }
            int cost2 = costs[1] + dp[j];

            //30 days pass
            passEndDay = days[i] + 30 - 1;
            j = i;
            while(j < days.size() && days[j] <= passEndDay){
                j++;
            }
            int cost3 = costs[2] + dp[j];

            dp[i] = min(cost1, min(cost2, cost3));
        }
        return dp[0];
    }

    // space opt. as queue month or week ka 30 or 7 entries hogi -> const space O(1)
    int solveSO(vector<int>& days, vector<int>& costs){
        int n = days.size();

        int ans = 0;   // if INT_MAX -> ans + cost[0] => given INT_MIN answer.
        // Intitution of queue -> sliding window of removing old days.
        queue<pair<int,int> > month;   // first int -> day, second int -> cost till that day
        queue<pair<int,int> > week;

        for(int day: days){
            //step1: remove expired days (i.e. old days ab 30 din se purana hogya h isliye remove as now curr
            // is day >= 30 from old day)
            while(!month.empty() && month.front().first + 30 <= day){
                month.pop();
            }
            while(!week.empty() && week.front().first + 7 <= day){
                week.pop();
            }

            //step2: add cost for current day
            week.push(make_pair(day, ans+costs[1]));
            month.push(make_pair(day, ans+costs[2]));

            //step3: ans update
            ans = min(ans+costs[0], min(week.front().second, month.front().second));
        }
        return ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return minCostHelper(days,costs,0);

        // int n = days.size();
        // vector<int> dp(n+1, -1);
        // return solveMem(days, costs, 0, dp);

        // return solveTab(days, costs, 0);
        return solveSO(days, costs);
    }
};