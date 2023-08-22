#include<iostream>
#include<algorithm>
using namespace std;
const int M=100;
int s[M],n;

int BinarySearch(int x){//���ֲ��ң��ǵݹ��㷨
	int l=0,r=n-1;  //lָ���1��Ԫ���±꣬rָ�����1��Ԫ���±�
	while(l<=r){
    	int mid=l+(r-l)/2;  //midΪ���ҷ�Χ���м�λ�� 
    	if(x==s[mid])      //x����s[mid]�����ҳɹ�
        	return mid;
    	else if(x>s[mid]) //x����s[mid]�����ǰ�벿�ֲ���
        		l=mid+1;
        	else         //xС��s[mid]����Ӻ�벿�ֲ���
            	r=mid-1;
    }
    return -1; //����ʧ�� 
}

int recursionBS(int x,int l,int r){ //���ֲ��ҵݹ��㷨
	if(l>r)              //�ݹ��������
    	return -1;
    int mid=l+(r-l)/2;
    if(x==s[mid])        //x����s[mid]�����ҳɹ�
        return mid;
    else if(x<s[mid])    //xС��s[mid]�����ǰ�벿�ֲ���
            return recursionBS(x,l,mid-1);
        else            //x����s[mid]����Ӻ�벿�ֲ���
            return recursionBS(x,mid+1,r);
}

int main(){
	int x;
	cout<<"�������е�Ԫ�ظ���nΪ��";
    cin>>n;
    cout<<"���������������е�Ԫ�أ�";
    for(int i=0;i<n;i++)
    	cin>>s[i];
    sort(s,s+n); //���ֲ��ҵ����б���������ģ����������Ҫ������
    cout<<"����������Ϊ��";
    for(int i=0;i<n;i++)
    	cout<<s[i]<<" ";
    cout<<endl;
    cout<<"������Ҫ���ҵ�Ԫ�أ�";
    cin>>x;
    int k=recursionBS(x,0,n-1);
    if(k==-1)
		cout<<"��������û��Ҫ���ҵ�Ԫ��"<<endl;
    else
		cout<<"Ҫ���ҵ�Ԫ���ڵ�"<<k+1<<"λ"<<endl;//λ����±��1
    return 0;
}
/*
11
5 8 15 17 25 30 34 39 45 52 60
*/
