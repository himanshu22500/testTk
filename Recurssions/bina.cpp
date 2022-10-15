#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double lld;
const ll mod = 1e9+7;

#define endl "\n"
#define read(a) for(auto &i:a) cin>>i
#define print(a) for(auto &i:a) cout<<i<<" ";cout<<endl

int main(){
    int tt; 
    cin>>tt;
    while(tt--){
        ll k,x; cin>>k>>x;

        // if arr = [1,3,6,8,9] 
        // can to binary search on this array
        // can't store this array -> use maths to get element of this array

        ll l = 0;    // good
        ll r = 2*k;

        function<bool(ll)> good = [&](ll m){
            // check if value at idx m is <= x
            ll off = 2*k-1 - m;
            ll val = 0;
            if(m<=k) val = m*(m+1)/2;
            else val = k*(k+1)/2 + k*(k-1)/2 - off*(off+1)/2;

            // cout<<val<<" ";
            return val<=x;
        };

        // for(int m=1; m<=2*k-1; m++){
        //     ll off = 2*k-1 - m;
        //     ll val = 0;
        //     if(m<=k) val = m*(m+1)/2;
        //     else val = k*(k+1)/2 + k*(k-1)/2 - off*(off+1)/2;   
        //     cout<<val<<" ";        
        // }
        // cout<<endl;

        function<ll(ll)> val = [&](ll m){
             // check if value at idx m is <= x
            ll off = 2*k-1 - m;
            ll val = 0;
            if(m<=k) val = m*(m+1)/2;
            else val = k*(k+1)/2 + k*(k-1)/2 - off*(off+1)/2;

            // cout<<val<<" ";
            return val;
        };


        while(l+1<r){
            ll m = (l+r)/2;
            if(good(m)) l = m;
            else r = m;
        }

        if(val(l)<x && l<2*k-1) cout<<l+1;
        else cout<<l;
        cout<<endl;
    }
}