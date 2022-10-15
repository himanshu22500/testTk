#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double lld;
const ll mod = LLONG_MAX >> 1;
 
#define endl "\n"
#define read(a) for(auto &i:a) cin>>i
#define print(a) for(auto &i:a) cout<<i<<" ";cout<<endl
 
int n,m;
ll arr[15][15];

ll getMax(int i, int j){
    if(i==n-1 && j==m-1) return arr[i][j];
    if(i==n || j==m) return -mod;
 
    return arr[i][j] + max(getMax(i+1,j), getMax(i,j+1));
}
 
int main(){
int n ; cin>>n;
cout<<n<<endl;
}