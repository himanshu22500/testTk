#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double lld;
const ll mod = 1e9+7;

#define endl "\n"
#define read(a) for(auto &i:a) cin>>i
#define print(a) for(auto &i:a) cout<<i<<" ";cout<<endl

int main(){
    string original; cin>>original;
    string got; cin>>got;

    int des = 0;
    for(auto &i:original){
        if(i=='+') des++;
        else if(i=='-') des--;
    }

    int got_des = 0;
    int unkn = 0;
    for(auto &i:got){
        if(i=='+') got_des++;
        else if(i=='-') got_des--;
        else if(i=='?') unkn++;
    }

    int total_ways = (1<<unkn);
    int fav_ways = 0;

    function<void(string)> makeWays = [&](string s){
        if(s.size()==unkn){
            int added_des = 0;
            for(auto &i:s){
                if(i=='+') added_des++;
                else if(i=='-') added_des--;
            }

            if(got_des+added_des == des){
                fav_ways++;
            }
            return;
        }

        makeWays(s+"+");
        makeWays(s+"-");
    };

    makeWays("");
    double ans = (double) fav_ways/ (double)total_ways;
    cout<<setprecision(12)<<ans<<endl;
}