#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string &s){
  int n = s.size();
  vector <int> v;
  v.push_back(0);
  int i = 1,j = 0;
  while(i<n){
    if(s[i] != s[j]) {
       //Move to the value at the previous location and compare the characters
       //at the moved to location and location i
       while(j>0){
       j = v[j-1];
       if(s[i] == s[j]){
         v.push_back(j+1);
         i++;
         j++;
       }
     }
     if(j == 0){
       if(s[i] == s[j]){
         v.push_back(j+1);
         i++;
         j++;
       }
       else {
         v.push_back(0);
         i++;
       }
     }
    }
    else if(s[i] == s[j]){
      v.push_back(j+1);
      i++;
      j++;
    }
  }
  return v;
}
int check(string &txt,string &pat,vector <int> &pre){
	int counter = 0;
    //text = abxabcabcaby
    //pattern = abcaby
    //prefix = 000120
    int i = 0,j = 0;
    while(j < (int)pat.size() && i < (int)txt.size()){
    	if(txt[i] == pat[j]){
    		i++;
    		j++;
        counter++;
    	}
    	else {
       if(j >= 1){
    		j = pre[j-1];
        counter = j;
    		if(txt[i] == pat[j]){
    			i++;
    			j++;
          counter++;
    		}
    		else i++;
      }
      else{
        if(txt[i] == pat[j]){
          i++;
          j++;
          counter++;
        }
        else i++;
      }
    	}
    }
    if(counter == (int)pat.size()) return 1;
    return 0;
}

int main(){
  string txt = "abxabcabcaby";
  string pat = "abcaby";
  vector <int> pre(prefix(pat));
  for(int i = 0; i < (int)pre.size(); i++) cout<<pre[i]<<" ";
  cout<<endl;
  if(check(txt,pat,pre)) cout<<"Pattern exists in the text";
  else cout<<"Pattern does not exist in the text";
  return 0;
}
