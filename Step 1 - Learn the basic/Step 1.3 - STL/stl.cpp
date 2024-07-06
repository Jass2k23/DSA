#include <bits/stdc++.h>
using namespace std;

//! Vector
void explainVector(){
    vector<int> v(5,100);   //<100,100,100,100,100>
    v.push_back(200);       //<100,100,100,100,100,200>
    vector<int> v2(v);     // copies the data of v1 to v2

    //! Iterators
    vector<int>::iterator it = v.begin();   // points to memory address the first element of the vector, to access the value we use // *it
    cout<<*it<<endl;                        // 100
    vector<int>::iterator it2 = v.end()-1;    
    cout<<*it2<<endl;                       // 200
    cout<<v.back()<<endl;                   // 200

    //Different ways to print the vector
    for(vector<int>::iterator it = v.begin(); it<v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //? for pair elements having first and second 
    vector<pair<int,int>>v_p = {{1,2},{2,3},{3,4}};
    vector<pair<int,int>>::iterator it;
    for(it=v_p.begin();it!=v_p.end();++it){
        // cout<<(*it).first<<" "<<(*it).second;
        cout<<it->first<<" "<<it->second;       //! use this form
    }

    //*using auto
    for(auto it = v.begin(); it<v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //using for each loop
    for(auto i:v){          //int i:v
        cout<<i<<" ";
    }
    cout<<endl;
}

    //* Insert
    vector<int> v(2,100);   //<100,100>
    v.insert(v.begin(),300);    //<300,100,100>
    v.insert(v.begin()+2,2,10); //<300,100,10,10,100>
    
    vector<int> copy(2,50);     //<50,50>
    v.insert(v.begin()+1,copy.begin(),copy.end()); //<300,50,50,100,10,10,100>


    //! Stack
    void explainStack(){
        stack<int> s;
        st.push(2);
        st.push(3);
        st.push(4);

        cout<<st.top()<<endl;   //4
        st.pop();
        cout<<st.top()<<endl;   //3
    }

    //! Queue
    void explainQueue(){
        queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);

        q.back() += 5;  //adds 5 to the last element
        cout<<q.front()<<endl;  //1
        q.pop();    //<2,8>
    }


    //! Priority Queue
    void explainPriorityQueue(){
        //* max heap
        priority_queue<int> pq;
        pq.push(5);
        pq.push(2);
        pq.push(8);
        pq.push(9);         //<9,8,5,2>

        cout<<pq.top()<<endl;   //9
        pq.pop();
        cout<<pq.top()<<endl;   //8

        //? push and pop takes O(logN) time and top takes O(1) time

        //* min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(5);
        pq.push(2);
        pq.push(8);
        pq.push(9);         //<2,5,8,9>
        cout<<pq.top()<<endl;   //2
    }


    //! Set
    void explainSet(){
        //? unique & sorted order
        set<int> s;
        //* Time complexity to insert is O(logN), same as ordereded map
        s.insert(1);
        s.insert(2);
        s.insert(2);
        s.insert(4);
        s.insert(3);    //<1,2,3,4>
        // begin,end,find,size,erase

        //<1,2,3,4,5>
        auto it = s.find(3);    //! returns iterator to 3
        auto it = s.find(8);    //returns iterator to s.end() which is just after the last element

        //operations are same as vector

        //! lower_bound and upper_bound in the description, https://www.youtube.com/watch?v=edJ19qIL8WQ
    }

    //! Multiset
    void explainMultiSet(){
        //? sorted order
        // the only difference is when you erase an element it deletes all the elements with the same value, so to delete only one element use it.erase(it.find(2) which uses iterator.
        multiset<int> ms;
        ms.insert(1);
        ms.insert(1);
        ms.insert(1);

        ms.erase(1);    //deletes all the 1's
        ms.erase(ms.find(1));   //deletes only one 1
    }


    //! Map
    //? stores unique keys in sorted order
    //? key value pair
    void explainMap(){
        map<int,int> m;
        //? inserting time complexity O(log(n)), n is the size of map. For string key s.size() * log(n) but O(1) if position is also given.
        m[1] = 2;
        m[3] = 6;
        m[2] = 0;   //<1,2>,<2,0>,<3,6>

        map<pair<int,int>, int> mp;
        mp[{1,2}] = 8;     //<1,2>,8>
        mp[{2,3}] = 10;    //<1,2>,8>,<2,3>,10>
        mp[{1,2}] = 9;     //<1,2>,9>,<2,3>,10>

        for(auto i:mp){
            cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
        }

        auto it = m.find(3);        // O(log(n))
        if(it == m.end())   cout<<"No value"<<endl;
        else    cout<<(*it)<<endl;                    //? gives the iterator of the key, if value doesn't exit it sents end()
    }

    //* unordered_map has O(1) for best and average and O(N) for worst for all operations (find,insert,etc).


    //? Upper Bound
    auto it = mp.upper_bound(11);  // 11 is the key
    cout<< (*it).first<< (*it).second<<endl;       // will return the pair which is just greater than 11.



    //! Multimap
    // same as map , but can have multiple keys with same value

    void comp(pair<int,int> p1, pair<int,int> p2){
        if(p1.second < p2.second) return true;
        if(p1.second > p2.second) return false;
        if(p1.second == p2.second) return true;
        return false;
    }
    //! Sorting
    void explainExtra(){
        v.sort(v.begin,v.end());    //sorts the vector
        v.sort(v.begin,v.end(),greater<int>());    //sorts the vector in reverse order, descending order

        //but for specific order we use comparator
        v.sort(v.begin,v.end(),comp);       //comp is a bollean func
    }

    //! Convert into bits
    int num = 7;
    int cnt = __builtin_popcount(num);  //returns the number of set bits in the number, 00000000000000000000000000000111, 3(32 bit number)
    long long num = 7;
    int cnt = __builtin_popcountll(num);    //returns the number of set bits in the number, 00000000000000000000000000000111, 3(64 bit number)

    //! Find permutations
    string s = "132";
    s.sort(s.begin(),s.end());  //sorts the string, 123
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()))

    //! max element 
    int maxi = *max_element(v.begin(),v.end());   //returns the max element in the vector

int main(){
    explainMap();
}
