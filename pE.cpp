    #include <iostream>
    #include <stdlib.h>
    #include <stdio.h>
    #include <algorithm>
    #include <bits/stdc++.h>
    #include <iomanip>
    #include <vector>
    #include <map>
    #include <queue>
    #include <set>
    #define ll long long int 
    #define pb push_back
    using namespace std;
    typedef pair<int,int> pp;
    ll ary[1000000],psum[1000000];
    int main() {
      ios::sync_with_stdio(false);
      cin.tie(0);
      ll n,w;
      cin>>n>>w;
      for (int i=1;i<=n;i++) cin>>ary[i], psum[i]=psum[i-1]+ary[i];
      
      ll l=0,r=w;
      for (int i=1;i<=n;i++){
        // cout<<l<<"____"<<r<<"\n";
        ll templ=l,tempr=r;
        while (templ<=tempr){
          ll mid=(templ+tempr)/2;
          if (psum[i]>=0){
            if (mid+psum[i]>=0 and mid+psum[i]<=w){
              templ=mid+1;
            }else{
              tempr=mid-1;
            }
          }else{
            if (mid+psum[i]>=0 and mid+psum[i]<=w){
              tempr=mid-1;
            }else{
              templ=mid+1;
            }
          }
          // cout<<templ<<" "<<tempr<<"\n";
        }
        // cout<<templ<<" "<<tempr<<"\n";
        if (psum[i]<0) l=max(templ,tempr);
        else r=min(templ,tempr);
      }
      cout<<r-l+1;
      return 0;
    }
     
