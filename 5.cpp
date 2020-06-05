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
   
    string expandAroundCentre(string s, int i, int j){
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            i--;
            j++;
        }
        //cout << s.substr(i+1, j-i-1)<<endl;
        return s.substr(i+1, j-i-1);
    }
    
    string longestPalindrome(string s) {
        int len = 0; string str = "";
        for(int i = 0; i < s.length(); i++){
            string s1 = expandAroundCentre(s, i, i); //odd
            string s2 = expandAroundCentre(s, i, i+1); //even
            if(s1.length() > len){
                len = s1.length();
                str = s1;
            }if(s2.length() > len){
                len = s2.length();
                str = s2;
            }
        }
        return str;
    }

int main(){
    string s;
    cin >> s;
    cout << longestPalindrome(s);
}