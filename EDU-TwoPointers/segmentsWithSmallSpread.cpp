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

struct stack {
    vector<int> st,stMx{LLONG_MIN},stMn{LLONG_MAX};
    void push(int x) {
        st.pb(x);
        stMx.pb(::max(stMx.back(), x));
        stMn.pb(::min(stMn.back(), x));
    }
    int pop() {
        int res = st.back();
        st.pop_back();
        stMx.pop_back();
        stMn.pop_back();
        return res;
    }
    int min() {
        return stMn.back();
    }
    int max() {
        return stMx.back();
    }
    bool empty() {
        return st.empty();
    }
};

int n,k;
const int N = 2e5 + 7;
::stack s1,s2;

void add(int x) {
    s2.push(x);
}
void remove() {
    if (s1.empty()) {
        while (!s2.empty()) {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

bool good() {
    int mn = min(s1.min(),s2.min());
    int mx = max(s1.max(),s2.max());
    return mx-mn<=k;
}

void solve() {
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int res=0,l=0;
    for (int r=0;r<n;r++) {
        add(v[r]);
        while (!good()) {
            remove();
            l++;
        }
        res+=r-l+1;
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
