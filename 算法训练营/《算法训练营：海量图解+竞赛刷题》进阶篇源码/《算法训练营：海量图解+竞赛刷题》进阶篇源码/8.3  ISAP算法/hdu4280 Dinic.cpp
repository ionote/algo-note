#include<cstdio>//G++ 9703ms
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=100010;
const int M=200010;
int cnt;
int head[N],d[N];
struct Edge{
   int v,next;
   int cap,flow;
}E[M<<1];//双边

void init(){//初始化 
    memset(head,-1,sizeof(head));
    cnt=0;
}

void add(int u,int v,int c){
    E[cnt].v=v;
    E[cnt].cap=c;
    E[cnt].flow=0;
    E[cnt].next=head[u];
    head[u]=cnt++;
}

void adde(int u,int v,int c){
    add(u,v,c);
    add(v,u,0);
}

bool bfs(int s,int t){//分层
    memset(d,0,sizeof(d));
    queue<int>q;
    d[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];~i;i=E[i].next){
        	int v=E[i].v;
        	if(!d[v]&&E[i].cap>E[i].flow){
                d[v]=d[u]+1;
				q.push(v);
				if(v==t)  return 1;
			}	
		}
    }
    return 0;
}

int dfs(int u,int flow,int t){//在分层的基础上dfs 
    if(u==t) return flow;
	int rest=flow;
    for(int i=head[u];~i&&rest;i=E[i].next){
    	int v=E[i].v;
    	if(d[v]==d[u]+1&&E[i].cap>E[i].flow){
            int k=dfs(v,min(rest,E[i].cap-E[i].flow),t);
			if(!k) d[v]=0;
			E[i].flow+=k;
			E[i^1].flow-=k;
			rest-=k;
		}	
	}
	return flow-rest;
}

int Dinic(int s,int t){
	int maxflow=0;
	while(bfs(s,t)){
		maxflow+=dfs(s,inf,t);
	}
	return maxflow;
}

int main(){
	int T,n,m,s,t;
    scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int minx=inf;
		int maxx=-inf;
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if(x>maxx){
				maxx=x;
				t=i;
			}
			if(minx>x){
				minx=x;
				s=i;
			}
		}//找到源点和汇点。 
		init();
		while(m--){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			adde(u,v,w);
			adde(v,u,w);
		}
		printf("%d\n",Dinic(s,t));
	} 
    return 0;
}
