// Notes: https://app.notion.com/p/Subarray-Divisibility-3fbdbda92155808dad5bfba719ca50a2?source=copy_link

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(ll n, vector<ll>& v){
    ll ans=0;
    unordered_map<ll, ll> mpp; // {remainder, count}
    mpp[0] = 1; // Base Case: An empty prefix sum has a remainder of 0 with frequency 1
    ll sum=0;
    
    for(auto i: v){
        sum += i;
        ll rem = ((sum % n) + n) % n; // Normalize remainder to range [0, n - 1]
        if(mpp.find(rem) != mpp.end()){
            ans += mpp[rem];
            mpp[rem]++;
        }
        else{
            mpp[rem] = 1;
        }
    }
    
    return ans;
}

int main()
{
		ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i=0; i<n; i++){
        cin>> v[i];
    }
    
    cout << solve(n, v);
}

// Time = O(N)
// Space = O(N)
