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

string decodeString(string s) {
        int i = 0;
        string res = "";
        stack<int> count;
        stack<string> st;
        while(i < s.length()){
            if(isdigit(s[i])){
                int dig = 0;
                while(isdigit(s[i])){
                    dig = dig*10 + s[i]-'0';
                    i++;
                }
                count.push(dig);
            }
            else if(s[i] == '['){
                st.push(res);
                i++;
                res = "";
            }else if(s[i] == ']'){
                string temp = st.top();
                st.pop();
                int x = count.top();
                while(x--){
                    temp+=res;
                }
                res = temp;
                count.pop();
                i++;
            }else{
                res+=s[i];
                i++;
            }
            
        }
        return res;
    }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
    cin >> s;
    cout << decodeString(s);
}
