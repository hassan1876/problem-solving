#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=1e5+9;
const int Q=3e5+9;
const int SQ=317;
int arr[N];

struct item {
    int m,c;
};

struct segtree {
    ll size;
    vector<item> vals;
    item NEUTRAL_ELEMNT ={LONG_LONG_MAX,0};
    void init(int n) {
        size=1;
        while (size<n) size*=2;
        vals.resize(size*2);
    }

    item merge(item a, item b) {
        if (a.m<b.m) return a;
        if (b.m<a.m) return b;
        return {a.m,a.c+b.c};
    }
    item single(int v) {
        return {v,1};
    }
    void build(vector<ll>& a,int x,int lx,int rx) {
        if (rx-lx==1) {
            if (lx<(int)a.size()) {
                vals[x]=single(a[lx]);
            }
            return;
        }
        int mid=(lx+rx)/2;
        build(a,x*2+1,lx,mid);
        build(a,x*2+2,mid,rx);
        vals[x] = merge(vals[x*2+1] , vals[x*2+2]);
    }
    void build(vector<ll>& a) {
        build(a,0,0,size);
    }
    void set(int i,int v,int x,int lx,int rx) {
        if (rx-lx==1) {
            vals[x]=single(v);
            return;
        }
        int mid = (lx+rx)/2;
        if (i<mid) {
            set(i,v,x*2+1,lx,mid);
        }else {
            set(i,v,x*2+2,mid,rx);
        }
        vals[x] = merge(vals[x*2+1],vals[x*2+2]);
    }
    void set(int i,int v) {
        set(i,v,0,0,size);
    }

    item calc(int x,int l,int r,int lx,int rx) {
        if (lx>=r || l>=rx) return NEUTRAL_ELEMNT;
        if (lx>=l && rx<=r) return vals[x];
        int mid = (lx+rx)/2;
        item s1 = calc(x*2+1,l,r,lx,mid);
        item s2 = calc(x*2+2,l,r,mid,rx);
        return merge(s1,s2);
    }
    item calc(int l,int r) {
        return calc(0 ,l,r,0,size);
    }
};

void solve() {
    int n,m;cin>>n>>m;
    segtree st;
    st.init(n);
    vector<ll> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    st.build(v);
    while (m--) {
        int op;cin>>op;
        if (op==1) {
            int i,v;cin>>i>>v;
            st.set(i,v);
        }else {
            int l,r;cin>>l>>r;
            item res = st.calc(l,r);
            cout<<res.m<<" "<<res.c<<endl;
        }
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}
