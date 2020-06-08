#include <bits/stdc++.h>
using namespace std;
#define pb push_back  
#define loop(i,n) for(int i = 0; i < n; i++)
#define mp make_pair
#define F first
#define S second
#define asort(a) sort(a,a+n)
#define vsort(v) sort(v.begin(), v.end())
#define remdup(v) v.erase(unique(v.begin(), v.end()), v.end())
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

bool isIsomorphic(string s, string t) {
        map<char, char> ms;
        map<char, bool> mt;
        string str = "";
        for(int i = 0; i < s.length(); i++){
           if(ms.count(s[i]) == 0){
               if(mt.count(t[i]) > 0) return false;
               else{
                   ms[s[i]] = t[i];
                   mt[t[i]] = true;
                   str+=t[i];
               }
           }
            else{
                str+=ms[s[i]];
            }
        }
        return str == t;
}

int main(){
    string s, target;
    cin >> s >> target;
    if(isIsomorphic(s, target)) cout << "YES";
    else cout << "NO";
}