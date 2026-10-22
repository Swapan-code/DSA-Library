// Notes: https://app.notion.com/p/633B-A-Trivial-Problem-3ffdbda9215580888b92eba209816373?source=copy_link

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(int mid){
    int zeroes = 0;
    for(ll i=5; mid/i > 0; i*=5){
        zeroes += mid/i;
    }
    return zeroes;
}

int main()
{
    int m;
    cin>>m;
    
    int s=5, e=1e6;
    int mid;
    
    while(s<=e){
        mid = (s+e)/2;
        int zeroes = solve(mid);
        if(zeroes == m){
            break;
        }
        else if(zeroes > m){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    
    if(s<=e){
        cout<<5<<endl;
        int firstValue = mid - (mid % 5);
        for(int i=0; i<5; i++){
            cout<<firstValue+i<<" ";
        }
    }
    else{
        cout<<0;
    }
}

// Time = O(log_2(M) * log_5(N))
// Space = O(1)
