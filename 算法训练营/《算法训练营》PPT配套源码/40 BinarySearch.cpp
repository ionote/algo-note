#include<iostream>
#include<algorithm>
using namespace std;
const int M=100;
int s[M],n;

int BinarySearch(int x){//二分查找，非递归算法
	int l=0,r=n-1;  //l指向第1个元素下标，r指向最后1个元素下标
	while(l<=r){
    	int mid=l+(r-l)/2;  //mid为查找范围的中间位置 
    	if(x==s[mid])      //x等于s[mid]，查找成功
        	return mid;
    	else if(x>s[mid]) //x大于s[mid]，则从前半部分查找
        		l=mid+1;
        	else         //x小于s[mid]，则从后半部分查找
            	r=mid-1;
    }
    return -1; //查找失败 
}

int recursionBS(int x,int l,int r){ //二分查找递归算法
	if(l>r)              //递归结束条件
    	return -1;
    int mid=l+(r-l)/2;
    if(x==s[mid])        //x等于s[mid]，查找成功
        return mid;
    else if(x<s[mid])    //x小于s[mid]，则从前半部分查找
            return recursionBS(x,l,mid-1);
        else            //x大于s[mid]，则从后半部分查找
            return recursionBS(x,mid+1,r);
}

int main(){
	int x;
	cout<<"该数列中的元素个数n为：";
    cin>>n;
    cout<<"请依次输入数列中的元素：";
    for(int i=0;i<n;i++)
    	cin>>s[i];
    sort(s,s+n); //二分查找的序列必须是有序的，如果无序需要先排序
    cout<<"排序后的数组为：";
    for(int i=0;i<n;i++)
    	cout<<s[i]<<" ";
    cout<<endl;
    cout<<"请输入要查找的元素：";
    cin>>x;
    int k=recursionBS(x,0,n-1);
    if(k==-1)
		cout<<"该数列中没有要查找的元素"<<endl;
    else
		cout<<"要查找的元素在第"<<k+1<<"位"<<endl;//位序和下标差1
    return 0;
}
/*
11
5 8 15 17 25 30 34 39 45 52 60
*/
