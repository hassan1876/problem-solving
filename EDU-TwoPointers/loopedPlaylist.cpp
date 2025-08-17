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
int n,k;

void solve() {
    cin>>n>>k;
    vector<int> v(n);
    int total=0;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        total+=v[i];
    }
    for (int i=0;i<n;i++) {
        v.pb(v[i]);
    }
    if (k % total == 0) {
        cout << 1 << " " << (k/total)*n << "\n";
        return;
    }
    int sum=0,l=0,mnIndex=0,mn=LONG_LONG_MAX;
    int base = (k/total)*n;
    int rem = k%total;
    for (int r=0;r<v.size();r++) {
        sum+=v[r];
        while (sum >= rem) {
            if (r - l + 1 < mn) {
                mn = r - l + 1;
                mnIndex = l % n;
            }
            sum -= v[l];
            l++;
        }

        if (sum>=rem && r-l+1<mn) {
            mn=r-l+1;
            mnIndex=l%n;
        }
    }
    cout<<mnIndex+1<<" "<<mn+base<<endl;
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
