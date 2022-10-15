#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double lld;
const ll mod = 1e9+7;

#define endl "\n"
#define read(a) for(auto &i:a) cin>>i
#define print(a) for(auto &i:a) cout<<i<<" ";cout<<endl

vector<int> prime;

void getPrimes(int r){
    prime.resize(r+1);

    for(int &x:prime) x = 1;
    prime[0] = 0;
    prime[1] = -1;

    for(int i=2; i<=r; i++){
        if(prime[i]==0) continue;
        for(int j = i+i; j<=r; j+=i){
            prime[j] = 0;
        }
    }
}

int count(int l, int r){
    int c = 0;
    int p = 0;

    for(int i=l; i<=r; i++){
        if(prime[i]==1) p++;
        else if(prime[i]==0) c++;
    }

    return c-p;
}

int main(){
    int l,r; cin>>l>>r;
    getPrimes(r);
    // print(prime);
    for(int i=0; i<=r; i++) cout<<i<<" "<<prime[i]<<endl;
    int ans = count(l,r);
    cout<<ans<<endl;
}