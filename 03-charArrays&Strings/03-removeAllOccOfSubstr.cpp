string remAllOccOfSubstr(string str, string target){
    int pos = str.find(target);
    while(pos != string::npos){
        str.erase(pos, target.size());

        pos = str.find(target);
    }
    return s;
}