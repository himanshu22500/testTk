#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double lld;
const ll mod = 1e9+7;

#define endl "\n"
#define read(a) for(auto &i:a) cin>>i
#define print(a) for(auto &i:a) cout<<i<<" ";cout<<endl

int main(){
    
    int n; cin>>n;
    int arr[n]; read(arr);
    vector<vector<int>> all;
    vector<int> temp;

    function<void(vector<int>, int)> makeSub = [&](vector<int> curr, int idx){
        if(idx==n){
            all.push_back(curr);
            return;
        }

        curr.push_back(arr[idx]);
        makeSub(curr, idx+1);
        curr.pop_back();
        makeSub(curr, idx+1);
    };

    makeSub(temp, 0);
    for(auto &i:all){
        print(i);
    }

    cout<<all.size()<<endl;

}