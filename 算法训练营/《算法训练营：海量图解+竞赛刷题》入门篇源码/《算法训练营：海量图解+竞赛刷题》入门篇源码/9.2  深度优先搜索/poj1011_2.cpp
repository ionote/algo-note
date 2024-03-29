#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
const int maxn=70;
int n;
int stick[maxn];
bool used[maxn];
int InitLen;

bool dfs(int len,int index,int num){
	if(num==n)
		return true;
	for(int i=index;i<n;i++){
		if(used[i]||(i&&!used[i-1]&&stick[i]==stick[i-1]))//已使用或与上一个相同 
			continue;
		used[i]=true;
		if(len+stick[i]<InitLen){
			if(dfs(len+stick[i],i+1,num+1))
				return true;
		}
		else if(len+stick[i]==InitLen){
			if(dfs(0,0,num+1))
				return true;
		}
		used[i]=false;//回溯复位 
		if(len==0)
			break;
	}
	return false;
}
 
int main(){
	while(~scanf("%d",&n),n){
		int sumlen=0;
		for(int i=0;i<n;i++){
			scanf("%d",&stick[i]);
			sumlen+=stick[i];
			used[i]=false;
		}
		sort(stick,stick+n,greater<int>());
		int maxlen=stick[0];
		bool flag=false;
		for(InitLen=maxlen;InitLen<=sumlen/2;InitLen++){
			if(!(sumlen%InitLen)&&dfs(0,0,0)){
				printf("%d\n",InitLen);
				flag=true;
				break;
			}
		}
		if(!flag)
			printf("%d\n",sumlen);
	}
	return 0;
}
