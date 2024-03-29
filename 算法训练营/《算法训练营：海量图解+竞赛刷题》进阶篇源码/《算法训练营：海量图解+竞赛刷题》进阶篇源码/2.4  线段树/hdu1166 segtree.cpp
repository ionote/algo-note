#include<cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=55555;
int sum[maxn<<2];

void PushUP(int rt){//更新和值
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void build(int l,int r,int rt){//构建线段树
    if(l==r){
	    scanf("%d",&sum[rt]);
	    return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUP(rt);
}

void update(int p,int add,int l,int r,int rt){//单点更新
    if (l==r){
        sum[rt]+=add;
        return ;
	}
    int m=(l+r)>>1;
    if(p<=m) update(p,add,lson);
    else update(p,add,rson);
    PushUP(rt);
}

//int query(int L,int R,int l,int r,int rt)//区间查询1
//{
//    if(L<=l&&r<=R)//覆盖 
//        return sum[rt];
//    int m=(l+r)>>1;
//    int ret=0;
//    if(L<=m) ret+=query(L,R,lson);
//    if(R>m) ret+=query(L,R,rson);
//    return ret;
//}

int query(int L,int R,int l,int r,int rt){//区间查询2
    if(L==l&&r==R)//判断条件为相等
        return sum[rt];
    int m=(l+r)>>1;
    if(R<=m)
		return query(L,R,lson);
    else if(L>m)
			return query(L,R,rson);
    	else return query(L,m,lson)+query(m+1,R,rson);
}

int main(){
    int T,n;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
        printf("Case %d:\n",cas);
        scanf("%d",&n);
        build(1,n,1);
        char op[10];
        while(scanf("%s",op)){
            if(op[0]=='E') break;
            int i,j;
            scanf("%d%d",&i,&j);
            if(op[0]=='Q') printf("%d\n",query(i,j,1,n,1));
            else if(op[0]=='S') update(i,-j,1,n,1);
                else update(i,j,1,n,1);
        }
    }
    return 0;
}
