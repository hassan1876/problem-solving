#include<bits/stdc++.h>
#define ll long long
#define el '\n'
#define MOD 1000000007
#define pb push_back
#define Hassan ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
vector<vector<int> > dir8 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
vector<vector<int> > dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

const int N = 2e5 + 7;
ll n,s;

void solve() {
    cin>>n>>s;
    vector<ll> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    ll sum=0,l=0;
    ll res=LLONG_MAX;
    for (int r=0;r<n;r++) {
        sum+=v[r];
        while (sum-v[l]>=s) {
            sum-=v[l];
            l++;
        }
        if (sum>=s) {
            res = min(res,r-l+1);
        }

    }
    if (res==LLONG_MAX) {
        cout<<"-1"<<endl;
        return;
    }
    cout<<res;
}

void file() {
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
}

signed main() {
    Hassan
    int t = 1;
    // cin>>t;
    // file();
    while (t--) {
        solve();
    }
}
