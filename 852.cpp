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

int peakIndexInMountainArray(vector<int>& a, int n) {
    //binary search
    int l = 0, h = n-1, mid = -1;
    while(l <= h){
        mid = l + (h-l)/2;
        if((mid == 0 || a[mid-1] < a[mid]) && (mid == n-1 || a[mid+1] < a[mid]))
            return mid;
        else if(a[mid+1] >= a[mid])
            l = mid+1;
        else h = mid-1;
    }
    return mid;
}

int main(){
    int n; //size of array
    cin >> n;
    vector<int> a(n);
    loop(i,n) cin >> a[i];
    cout << peakIndexInMountainArray(a, n);
}