#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=1e5+9;
const int Q=3e5+9;
const int SQ=317;
int arr[N];


struct segtree {
    ll size;
    vector<ll> sums;
    void init(int n) {
        size=1;
        while (size<n) size*=2;
        sums.assign(size*2,0LL);
    }
    void build(vector<ll>& a,int x,int lx,int rx) {
        if (rx-lx==1) {
            if (lx<(int)a.size()) {
                sums[x]=a[lx];
            }
            return;
        }
        int mid=(lx+rx)/2;
        build(a,x*2+1,lx,mid);
        build(a,x*2+2,mid,rx);
        sums[x] = sums[x*2+1] + sums[x*2+2];
    }
    void build(vector<ll>& a) {
        build(a,0,0,size);
    }
    void set(int i,int v,int x,int lx,int rx) {
        if (rx-lx==1) {
            sums[x]=v;
            return;
        }
        int mid = (lx+rx)/2;
        if (i<mid) {
            set(i,v,x*2+1,lx,mid);
        }else {
            set(i,v,x*2+2,mid,rx);
        }
        sums[x] = sums[x*2+1]+sums[x*2+2];
    }
    void set(int i,int v) {
        set(i,v,0,0,size);
    }

    ll sum(int x,int l,int r,int lx,int rx) {
        if (lx>=r || l>=rx) return 0;
        if (lx>=l && rx<=r) return sums[x];
        int mid = (lx+rx)/2;
        ll s1 = sum(x*2+1,l,r,lx,mid);
        ll s2 = sum(x*2+2,l,r,mid,rx);
        return s1+s2;
    }
    ll sum(int l,int r) {
        return sum(0 ,l,r,0,size);
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
            cout<<st.sum(l,r)<<endl;
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
