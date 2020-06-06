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

string findLongestWord(string s, vector<string>& d) {
        int len = 0;
        string res = "";
        for(int i = 0; i < d.size(); i++){
            int j = 0, k= 0;
            while(j < d[i].length() && k < s.length()){
                if(s[k] == d[i][j]){
                    k++;
                    j++;
                }
                else k++;
            }
            if(j == d[i].length()){
                if(j > len || j == len && d[i] < res){
                    len = j;
                    res = d[i];
                }
            }
        }
        return res;
}

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> dictionary(n);
    loop(i,n) cin >> dictionary[i];
    cout << findLongestWord(s, dictionary);
    
}