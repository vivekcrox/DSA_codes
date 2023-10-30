int findMinDiff(vector<string>& timePoints){
    // step 1 : calc minutes
    vector<int> minutes;
    for(int i=0; i<timePoints.size(); i++){
        string currTime = timePoints[i];
        int hour = stoi(currTime.substr(0,2));
        int mint = stoi(currTime.substr(3,2));

        int minute = hour*60 + mint;
        minutes.push_back(minute); 
    }

    //step 2: sort
    sort(minutes.begin(), minutes.end());
    
    //step 3: calc diff
    int mini = INT_MAX;
    int n = minutes.size();
    for(int i=1; i<n; i++){
        int diff = minutes[i] - minutes[i-1];
        mini = min(mini, diff);
    }

    //step 4: corner case diff
    int lastDiff1 = minutes[n-1] - minutes[0];
    int lastDiff2 = (minutes[0] + 1440) - minutes[n-1];
    int lastDiff = min(lastDiff1, lastDiff2);

    mini = min(mini, lastDiff);

    return mini;
}