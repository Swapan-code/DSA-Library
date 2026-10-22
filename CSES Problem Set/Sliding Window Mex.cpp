// Notes: https://app.notion.com/p/Sliding-Window-Mex-3fbdbda921558085b8f7fe024ff0855a?source=copy_link

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    vector<ll> res;
    for(ll i=0; i<n; i++){
        cin>> v[i];
    }
    
    set<ll> missingNumbers;
    vector<ll> freq(k+1, 0);
    
    for(ll i=0; i<=k; i++){
        missingNumbers.insert(i);
    }
    
    for(ll i=0; i<n; i++){
        ll eleToInsert = v[i];
        if(eleToInsert <= k){
            freq[eleToInsert]++;
            if(freq[eleToInsert] == 1){
                missingNumbers.erase(eleToInsert);
            }
        }
        
        if(i>=k-1){
            res.push_back(*missingNumbers.begin());
            
            ll eleToDelete = v[i-k+1];
            if(i < n && eleToDelete <= k){
                freq[eleToDelete]--;
                if(freq[eleToDelete] == 0){
                    missingNumbers.insert(eleToDelete);
                }
            }
        }
    }
    
    for(auto i: res){
        cout << i << " ";
    }
}

// Time = O(N logK)
// Space = O(K)
