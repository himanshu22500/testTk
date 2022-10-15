#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double lld;
const ll mod = 10e17;

#define endl "\n"
#define read(a) for(auto &i:a) cin>>i
#define print(a) for(auto &i:a) cout<<i<<" ";cout<<endl

vector<string> ways(0);
string s = "";

void makeWays(string s, int n){
    if(s.size()==n-1){
        ways.push_back(s);
        return;
    }

    makeWays(s+"+",n);
    makeWays(s+"-",n);
}

void solve(){
    int n,x; cin>>n>>x;
    int arr[n]; read(arr);
    if(n==1){
        if(arr[0]==x) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
        return;
    }

    makeWays(s,n);

    int sw = 0;

    for(auto way:ways){
        ll ans = 0;
        if(way[0]=='+') ans = arr[0]+arr[1];
        else ans = arr[0]-arr[1];

        for(int i=1; i<n-1; i++){
            if(way[i]=='+') ans += arr[i+1];
            else ans -= arr[i+1];
        }

        if(ans==x){
            sw = 1;
            break;
        }
        // cout<<way[0];
    }

    if(sw) cout<<"YES";
    else cout<<"NO";
    cout<<endl;

}

int main(){
    solve();
}