// Containers:-
// 1. Array
// 2. Vector
// 3. DEQue
// 4. List
// 5. Stack
// 6. Queue
// 7. Priority Queue
// 8. Set
// 9. Map

#include<iostream>
// #include<array>
// #include<vector>
// #include<deque>
// #include<list>
// #include<stack>
// #include<queue>
// #include<set>
#include<map>

using namespace std;

int main(){
    // 1. ARRAY
    // array<int,4> a = {1,2,3,4};

    // int size = a.size();
    // for(int i=0; i<size; i++){
    //     cout<<a[i]<<endl;
    // }

    // cout<<"Element at 2nd Index: "<<a.at(2)<<endl;
    // cout<<"Empty or not: "<<a.empty()<<endl;
    // cout<<"First Element: "<<a.front()<<endl;
    // cout<<"Last Element: "<<a.back()<<endl;

//*****************************************

    // 2. VECTOR
    // *when size of the vector gets full -> it create another vector of x2 size &copied element to it & old one deleted. 

    // vector<int> v;   // size will be 0
    // cout<<"capacity "<<v.capacity()<<endl;

    // vector<int> a(5,1);
    // vector<int> last(a);  //copy a in last vector
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);

    // cout<<"size: "<<v.size()<<endl;
    // cout<<"Element at 2nd index: "<<v.at(2)<<endl;

    // cout<<"Front: "<<v.front()<<endl;
    // cout<<"back: "<<v.back()<<endl;
    
    // cout<<"before pop "<<endl;
    // for(int i:v){
    //     cout<<i<<" ";
    // }cout<<endl;

    // v.pop_back();

    // cout<<"after pop "<<endl;
    // for(int i:v){
    //     cout<<i<<" ";
    // }cout<<endl;

    // // v.clear();  //size become 0 but capacity remain same

//*****************************************

    // 3. DEQueue (Double ended queue)
    // dynamic & random access possible

    // deque<int> d;

    // d.push_back(1);
    // d.push_front(2);
    // d.push_front(3);
    // d.push_front(5);

    // for(int i:d){
    //     cout<<i<<" ";
    // }cout<<endl;

    // d.pop_back();

    // // d.pop_front();

    // cout<<"First element"<<d.at(1)<<endl;
    // cout<<"front element"<<d.front()<<endl;
    // cout<<"back element"<<d.back()<<endl;

    // cout<<"before erase"<<d.size()<<endl;
    // d.erase(d.begin(),d.begin()+1);
    // cout<<"after erase"<<d.size()<<endl;

//*****************************************

    // 4. LIST
    // * Implemented using doubly Linked list (i.e front and end pointer)
    // direct access not possible

    // list<int> l;

    // // list<int> a(l);  //list l will copied in list 'a'
    // list<int> n(3,100); // (100,100,100)

    // l.push_back(1);
    // l.push_front(2);

    // for(int i:l){
    //     cout<<i<<" ";
    // }cout<<endl;

    // l.erase(l.begin());  //begin deleted
    // cout<<"after erase: "<<endl;
    // for(int i:l){
    //     cout<<i<<" ";
    // }cout<<endl;

    // cout<<"size"<<l.size()<<endl;

//*****************************************

    // 5. STACK

    // stack<string> s;

    // s.push("vivek");
    // s.push("singh");
    // s.push("vscrox");

    // cout<<"Top Element: "<<s.top()<<endl;
    // s.pop();
    // cout<<"size : "<<s.size()<<endl;

    // cout<<"Empty or not : "<<s.empty()<<endl;

//*****************************************

    // 6. QUEUE

    // queue<string> q;

    // q.push("vivek");
    // q.push("singh");
    // q.push("vscrox");

    // cout<<q.size()<<endl;

    // cout<<q.front()<<endl;
    // q.pop();
    // cout<<q.front()<<endl;

//*************************************   
    // 7. PRIORITY QUEUE

    // Default: max heap = when fetch element, it will be max element


    // //Max Heap
    // priority_queue<int> maxi;

    // //Min Heap
    // priority_queue<int,vector<int>,greater<int>> mini;

    // maxi.push(1);
    // maxi.push(5);
    // maxi.push(3);
    // maxi.push(0);

    // cout<<"size: "<<maxi.size()<<endl;

    // int n = maxi.size();  // declare outside as inside loop it will decrease at each step
    // for(int i=0; i<n; i++){
    //     cout<<maxi.top()<<" ";
    //     maxi.pop();
    // }cout<<endl;


    // mini.push(1);
    // mini.push(5);
    // mini.push(3);
    // mini.push(0);

    // int m = mini.size();  // declare outside as inside loop it will decrease at each step
    // for(int i=0; i<m; i++){
    //     cout<<mini.top()<<" ";
    //     mini.pop();
    // }cout<<endl;

    // cout<<"Khali h kya bhai?: "<<mini.empty()<<endl;

//*****************************************

    // 8. SET
    // *unique element stored
    // * implementeed using BST & can't be modified, only insert or delete
    // *Return elements in sorted order
    // insert(), find(), count() or erase() == T.C.=O(logn)

    // set<int> s;

    // s.insert(5);
    // s.insert(5);
    // s.insert(3);
    // s.insert(6);
    // s.insert(0);

    // for(auto i:s){
    //     cout<<i<<" ";
    // }cout<<endl;

    // set<int>::iterator it = s.begin();
    // it++;

    // s.erase(it);

    // for(auto i:s){
    //     cout<<i<<" ";
    // }cout<<endl;

    // cout<<"5 is present or not: "<<s.count(5)<<endl;

    // set<int>::iterator itr = s.find(5);
    // for(auto it=itr; it!=s.end(); it++){
    //     cout<< *it <<" ";
    // }cout<<endl;

//*****************************************

    // 9. MAP
    // *Implemented using red-black tree or balanced tree : O(logn)
    // *All key are unique and points to only 1 value
    // *map = sorted order m key print hoti h...but in case of unordered_map = random order(implemented using hash table : O(1) in unordered_map)

    // map<int,string> m;
    // m[1] = "Vivek";
    // m[3] = "singh";
    // m.insert( {5,"vscrox"} );

    // for(auto i:m){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    // cout<<"Finding 13: "<<m.count(13)<<endl;

    // cout<<"after erase"<<endl;
    // for(auto i:m){
    //     cout<<i.first<<" "<<e.second<<endl;
    // }cout<<endl;

    // auto it = m.find(3);

    // for(auto i=it; i!=m.end(); i++){
    //     cout<<(*i).first<<endl;
    // }


    return 0;
}