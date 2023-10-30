// Algorithm:-
// * binary_search(3p)  where, p = parameter
// * lower_bound(3p)-v.begin()
// * upper_bound(3p)-v.begin()
// * max(a,b) && min(a,b)
// * swap(a,b)
// * reverse(string.begin(),string.end())
// * rotate(v.begin(),v.begin()+1,v.end())
// * sort(v.begin(),v.end())


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);

    cout<<binary_search(v.begin(), v.end(),5)<<endl;

    cout<<"lower bound: "<<lower_bound(v.begin(),v.end(),5)-v.begin()<<endl;
    cout<<"upper bound: "<<upper_bound(v.begin(),v.end(),4)-v.begin()<<endl;

    int a = 3;
    int b =4;

    cout<<"max: "<<max(a,b)<<endl;
    cout<<"min: "<<min(a,b)<<endl;

    swap(a,b);
    cout<<endl<<"a: "<<a<<endl;

    string abcd = "abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<"string: "<<abcd<<endl;

    rotate(v.begin(),v.begin()+1,v.end());
    cout<<"after rotate"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;


    //sort() = intro sort [quick, heap, insertion sort ]
    sort(v.begin(),v.end());
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;


    return 0;
}