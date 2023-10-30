void remAllOccSubstr(string& s, string& part){
    int found = s.find(part);
    if(found != string::npos){
        string left = s.substr(0, found);
        string right = s.substr(found+part.size(), s.size());

        s = left + right;
        remAllOccSubstr(s,part);
    }
    else{ //all occ has been removed
        return;
    }
}