#include <bits/stdc++.h>
string dectobi(long long N){
	string ans="";
	while(N>0){
		string rem=to_string(N%2);
		ans=ans+rem;
		N=N/2;
	}
	return ans;
} 
bool checkPalin(string ans,int i,int j){
	if(i>j){
		return true;
	}
	bool value;
	if(ans[i]==ans[j]){
		i++;
		j--;
		value=checkPalin(ans,i,j);
	}
	else{
		return false;
	}
	return value;
}
bool checkPalindrome(long long N)
{
	string ans=dectobi(N);
	bool answer=checkPalin(ans,0,ans.length()-1);
	return answer;
}