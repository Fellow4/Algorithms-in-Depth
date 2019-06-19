#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define repi(i,a,n) for(int i = a; i < n; i++)

void lis(vector<pair<int,int>> const& a) {
    int n = a.size();
    vector<int> d(n, 1), p(n, -1);
    rep(i,n){
        rep(j,i){
            if (a[j].first < a[i].first && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }

    int ans = d[0], pos = 0;
    repi(i,1,n){
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    }

    vector<int> subseq;
    while (pos != -1) {
        subseq.push_back(a[pos].second);
        pos = p[pos];
    }
    reverse(subseq.begin(), subseq.end());
    int N = subseq.size();
    cout << N << endl;
    rep(i,N){
    	cout << subseq[i]+1 << " ";
    }
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,W,H;
    cin >> n >> W >> H;
    vector <pair <int,int> > v,w;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(b,i));
        w.push_back(make_pair(a,i));
    }
    sort(v.begin(),v.end());
    int idx = -1,flag = 0;
    /*vector <int> h;
    rep(i,n){
    	h.push_back(v[i].first);
    }
    vector <int> :: iterator ip;
    ip = upper_bound(h.begin(),h.end(),H);
    if(ip == h.end()) idx = n;
    else{
         //Elements of the subsequence beginning with idx
         idx = ip-h.begin();
        }*/
    rep(i,n){
    	if(v[i].first > H) {
    		idx = i;
    		flag = 1;
    		break;
    	}
    }
    if(!flag) cout << 0;
    else{
    //cout << "Index is:" << idx << endl;
    	flag = 0;
    	repi(i,idx,n){
          if(w[v[i].second].first > W){
          	flag = 1;
          	idx = i;
          	break;
          } 
    	}
    	//cout << "New index:" << idx << endl;
    	if(flag){
    	//Longest increasing subsequence beginning with idx;
    	vector <pair<int,int>> s;
        repi(i,idx,n){
        	s.push_back(make_pair(w[v[i].second].first,w[v[i].second].second));
        }
        lis(s);
    }
       else cout << 0;
   }
    return 0;
}