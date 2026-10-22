// Notes: https://app.notion.com/p/352A-Jeff-and-Digits-3fedbda9215580a3af89e5bbfb65aa2c?source=copy_link

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n;
    cin>>n;
    int count5=0;
    
    for(int i=0; i<n; i++){
        int ele;
        cin>>ele;
        if(ele==5) count5++;
    }
    
    int numberOfFives = (count5/9)*9;
    
    if(n-count5==0){ // Without 0, cant be divisible by 90
        cout<<-1;
    }
    else if(numberOfFives==0){ // there is zero but less than 9 (5's)
        cout<<0<<endl;
    }
    else{ // there are at least 9 (5's) and at least one zero
        int i=1;
        while(i<=numberOfFives){
            cout<<5;
            i++;
        }
        i=1;
        while(i<=n-count5){ // number of zeroes
            cout<<0;
            i++;
        }
    }
}

// Time = O(N) to read input and print output
// Space = O(1)
