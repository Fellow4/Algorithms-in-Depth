#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define repi(i,a,n) for(int i = a; i < n; i++)


int Mex(set <int> &s){
	int max = 0;
	while(s.find(max) != s.end()) max++;
	return max;
}

int tb(int dp[][18],int p[][18],int i,int j){
	if(p[i][j]) return dp[i][j];
	else {
		set <int> s;
		s.insert(tb(dp,p,i-2,j-1));
       	s.insert(tb(dp,p,i-2,j+1));
       	s.insert(tb(dp,p,i-1,j-2));
       	s.insert(tb(dp,p,i+1,j-2));
       	dp[i][j] = Mex(s);
       	p[i][j] = 1;
       	return dp[i][j];
	}
}

void winner(int dp[][18], vector <pair <int,int> > v){
       int ans = dp[v[0].first][v[0].second];
       repi(i,1,v.size()){
       	int temp = dp[v[i].first][v[i].second];
       	ans = ans ^ temp;
       }
       if(ans == 0) cout << "Second\n";
       else cout << "First\n";
}

void print(int dp[][18]){
	repi(i,2,17){
		repi(j,2,17){
			cout << dp[i][j] << " ";
		}
		cout << endl;
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
    int dp[18][18],p[18][18];
    memset(dp,-1,sizeof(dp));
    memset(p,1,sizeof(p));
    repi(i,2,17){
    	repi(j,2,17){
    		p[i][j] = 0;
    	}
    }
    repi(i,2,17){
    	repi(j,2,17){
    		dp[i][j] = tb(dp,p,i,j);
    	}
    }
    int t;
    cin >> t;
    rep(iter,t){
    int k;
    cin >> k;
    vector <pair <int,int> > pos;
    rep(i,k){
    	int a,b;
    	cin >> a >> b;
    	pos.push_back(make_pair(a+1,b+1));
    }
    winner(dp,pos);
}
    return 0;
}