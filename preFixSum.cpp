#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double lld;
const ll mod = 1e9+7;

#define endl "\n"
#define read(a) for(auto &i:a) cin>>i
#define print(a) for(auto &i:a) cout<<i<<" ";cout<<endl

int main(){
    int n,q;
    cin>>n>>q;
    ll arr[n]; read(arr);
    ll pre[n+1];
    pre[0] = 0;

    for(int i=1; i<=n; i++){
        pre[i] = arr[i-1] + pre[i-1];
    }

    while(q--){
        int l,r; cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<endl;
    }
}