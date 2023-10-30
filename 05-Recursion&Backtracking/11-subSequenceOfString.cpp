void subSequence(string str, string output, int i){
    if(i >= str.length()){
        cout<<output<<" ";
        return;
    }

    //exclude
    subSequence(str,output,i+1);

    //include
    output.push_back(str[i]);
    subSequence(str,output,i+1);
}