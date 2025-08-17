#include<bits/stdc++.h>
#define ll long long
#define int long long
#define el '\n'
#define MOD 1000000007
#define pb push_back
#define Hassan ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
vector<vector<int> > dir8 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
vector<vector<int> > dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

const int N = 2e5 + 7;
int n,s;

void solve() {
    cin>>n>>s;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int l=0,res=0;
    for (int r=0;r<n;r++) {
        while (v[r]-v[l]>s) {
            l++;
        }
        res+=l;
    }
    cout<<res<<endl;
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
