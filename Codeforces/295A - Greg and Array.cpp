// Notes: https://app.notion.com/p/295A-Greg-and-Array-3fddbda92155801d849ddf7cf736e010?source=copy_link

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m, k;
    cin>>n>>m>>k;
    vector<ll>arr(n+1);
    vector<vector<ll>> ops(m+1, vector<ll>(3));
    vector<vector<ll>> queries(k, vector<ll>(2));
    for(ll i=1; i<=n; i++){
        cin>>arr[i];
    }
    for(ll i=1; i<=m; i++){
        cin >> ops[i][0];
        cin >> ops[i][1];
        cin >> ops[i][2];
    }
    for(ll i=0; i<k; i++){
        cin>>queries[i][0];
        cin>>queries[i][1];
    }
    
    vector<ll> diffArray1(m+2, 0); // diffArray1[i] = No. of times operation[i] was performed
    for(ll i=0; i<k; i++){
        diffArray1[queries[i][0]]++;
        diffArray1[queries[i][1]+1]--;
    }
    // Take Prefix Sum
    for(ll i=1; i<=m; i++){
        diffArray1[i] += diffArray1[i-1];
    }
    
    vector<ll> diffArray2(n+2, 0); // diffArray2[i] = value by which index i in arr was incremented
    for(ll i=1; i<=m; i++){
        diffArray2[ops[i][0]] += ops[i][2] * diffArray1[i];
        diffArray2[ops[i][1]+1] -= ops[i][2] * diffArray1[i];
    }
    // Take Prefix Sum
    for(ll i=1; i<=n; i++){
        diffArray2[i] += diffArray2[i-1];
    }
    
    // Add initial arr to get final result
    for(ll i=1; i<=n; i++){
        cout << diffArray2[i] + arr[i] << " ";
    }
}

// Time = O(N+M+K)
// Auxiliary Space = O(N+M)
