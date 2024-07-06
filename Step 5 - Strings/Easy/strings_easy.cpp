#include <bits/stdc++.h>
using namespace std;


//! Remove Outermost Parentheses
string removeOuterParentheses(string s) {
        string ans = "";
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' && st.empty()){
                st.push(s[i]);
            }
            else if(s[i] == '(' && !st.empty()){
                ans+=s[i];
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                st.pop();
                if(!st.empty()){
                    ans+=s[i];
                }
            }
        }
        return ans;
    }





//! Maximum Nesting Depth of Parentheses
int maxDepth(string s) {
    int ans=0,cnt=0;
    for(int i=0;i<s.size();i++){
        ans=max(ans,cnt);
        if(s[i]=='('){
            cnt++;
        }
        else if(s[i] == ')'){
            cnt--;
        }
    }
    return ans;
}





//! Reverse Words in a String
string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int l=0,r=0,i=0;
        int n = s.length();

        while(i<n){
            while(i<n && s[i] != ' '){
                s[r++] = s[i++];
            }
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r++] = ' ';
                l = r;
            }
            i++;
        }
        return s.substr(0,r-1);
    }

//* Different way
string reverseString(string &str)
{
    // If the string is " " then return "".
    if(str == "" || str == " ")
    {
        return "";
    }
    string ans;
    int start = str.length() - 1;
    while(start >= 0)
    {       
        // Skip multiple spaces.
        if(str[start] == ' ')
        {
            start--;
        }
        else
        {          
            // Add space between words.
            if(ans.length() > 0)
            {
                ans.push_back(' ');
            }
            int j = start;
            while(j >= 0 && str[j] != ' ')
            {
                j--;
            }
            // Add current word to ans.
            ans.append(str.substr(j+1, start-j));
            start = j;
        }
    }
    return ans;
}




//! Largest Odd number in a String 
string largestOddNumber(string s) {
        for(int i=s.length()-1;i>=0;i--){
            int temp = s[i] - '0';
            if(temp % 2 == 1){
                return s.substr(0,i+1);
            }
        }
        return "";
    }





//! Longest Common Prefix
string longestCommonPrefix(vector<string>& arr) {
        string ans = "";
        for(int i=0;i<arr[0].size();i++){
            bool match = true;
            char element = arr[0][i];
            for(int j=1;j<arr.size();j++){
                int ind_size = arr[j].size();
                if(i < ind_size){
                    if(element != arr[j][i]){
                        match = false;
                        break;
                    }
                }
                else{
                    match = false;
                    break;
                } 
            }
            if(match == true)
                ans += element;
            else
                break;;
        }
        return ans;
}




//! Isomorphic Strings
//* O(N)
bool areIsomorphic(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    if(n!=m)
        return false;
    unordered_map<char,char> m1,m2;
    for(int i=0;i<n;i++){
        char el1 = str1[i];
        char el2 = str2[i];

        if(m1.find(el1) == m1.end() && m2.find(el2) == m2.end()){
            m1[el1] = el2;
            m2[el2] = el1;
        }
        else if(m1[el1] != el2 || m2[el2] != el1)
            return false;
    }
    return true;
}




//! Rotation of a String
bool check(string p, string q, int index){
    string temp = q;
    reverse(temp.begin(),temp.begin()+index);
    reverse(temp.begin()+index,temp.end());
    reverse(temp.begin(),temp.end());
    if(temp == p)
        return true;
    else
        return false;
}

int isCyclicRotation(string &p, string &q) 
{
    char el = p[0];
    for(int i=0;i<p.length();i++){
        if(q[i] == el){
            bool value = check(p,q,i);
            if(value)
                return true;
        }
    }
    return false;
}

//* Optimal, using Queue
#include <bits/stdc++.h>
int isCyclicRotation(string &s1, string &s2) 
{
    if(s1.size()!=s2.size())
        return false;
    queue<int>q1;
    queue<int>q2;
    for(int i=0;i<s1.size();i++){
        q1.push(s1[i]);
    }
    for(int i=0;i<s2.size();i++){
        q2.push(s2[i]);
    }
    int k=s2.size()-1;
    while(k>0){
        char el = q2.front();
        q2.pop();
        q2.push(el);
        if(q1 == q2)
            return true;
        k--;
    }
    return false;
}



//! Anagram Pairs
bool isAnagram(string str1, string str2)
{
    if(str1.length()!=str2.length())
            return false;
        int len = str1.length();
        unordered_map<char,int>m1,m2;
        for(int i=0;i<len;i++){
            m1[str1[i]]++;
            m2[str2[i]]++;
        }
        for(int i=0;i<len;i++){
            char el = str1[i];
            if(m2.find(el) == m2.end())
                return false;
            else if(m2.find(el) != m2.end()){
                if(m1[el] != m2[el])
                    return false;
            }
        }
        return true;
}

//* Another approach
bool CheckAnagrams1(string str1, string str2)
{
  // when both of the strings have different lengths
  if (str1.length() != str2.length())
    return false;
 
  int freq[26] = {0};
  for (int i = 0; i < str1.length(); i++)
  {
    freq[str1[i] - 'A']++;
  }
  for (int i = 0; i < str2.length(); i++)
  {
    freq[str2[i] - 'A']--;
  }
  for (int i = 0; i < 26; i++)
  {
    if (freq[i] != 0)
      return false;
  }
  return true;
}
int main()
{
  string Str1 = "INTEGER";
  string Str2 = "TEGERNI";
  if(CheckAnagrams(Str1, Str2))
  cout << "True" << endl;
  else
  cout<<"False"<<endl;
  return 0;
}

int main(){
    cout<<areIsomorphic("badc","baba")<<endl;
}