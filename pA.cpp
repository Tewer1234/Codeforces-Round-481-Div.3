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
int ary[1000000];
vector <int> ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  set <int> st;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
  }
  for (int i=n;i>=1;i--){
    auto it=st.find(ary[i]);
    if (it==st.end()){
      ans.pb(ary[i]);
      st.insert(ary[i]);
    }
  }
  cout<<ans.size()<<"\n";
  for (int i=ans.size()-1;i>=0;i--){
    cout<<ans[i]<<" ";
  }
  return 0;
}
