#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int maxval,minval;
typedef struct AVLNode{
   int data,num;
   int height;
   struct AVLNode *lchild;
   struct AVLNode *rchild;
}*AVLTree;

int Height(AVLTree T){//����߶�
    if(!T) return 0;
    return T->height;
}

void updateHeight(AVLTree &T){//���¸߶� 
	if(!T) return;
	T->height=max(Height(T->lchild),Height(T->rchild))+1;
}

AVLTree LL_Rotation(AVLTree &T){//LL��ת
    AVLTree temp=T->lchild;
    T->lchild=temp->rchild;
    temp->rchild=T;
    updateHeight(T);//���¸߶�
    updateHeight(temp);
    return temp;
}

AVLTree RR_Rotation(AVLTree &T){//RR��ת
    AVLTree temp=T->rchild;
    T->rchild=temp->lchild;
    temp->lchild=T;
    updateHeight(T);//���¸߶�
    updateHeight(temp);
    return temp;
}

AVLTree LR_Rotation(AVLTree &T){//LR��ת
    T->lchild=RR_Rotation(T->lchild);
    return LL_Rotation(T);
}

AVLTree RL_Rotation(AVLTree &T){//RL��ת
    T->rchild=LL_Rotation(T->rchild);
    return RR_Rotation(T);
}


void adjust(AVLTree &T){//��ƽ��
    if(!T)	return;
    if(Height(T->lchild)-Height(T->rchild)>1){//���Ÿ߶ȴ������·���ж�
        if(Height(T->lchild->lchild)>=Height(T->lchild->rchild))
            T=LL_Rotation(T);
        else
            T=LR_Rotation(T);
    }
    else if(Height(T->rchild)-Height(T->lchild)>1){//���Ÿ߶ȴ������·���ж�
        if(Height(T->rchild->rchild)>=Height(T->rchild->lchild))
            T=RR_Rotation(T);
        else
            T=RL_Rotation(T);
    }
}

AVLTree Insert(AVLTree &T,int num,int x){//���� 
    if(!T){ //���Ϊ�գ������½��
        T=new AVLNode;
        T->lchild=T->rchild=NULL;
        T->num=num;
		T->data=x;
        T->height=1;
        return T;
    }
    if(T->data==x) return T;//���ҳɹ���ʲôҲ����������ʧ��ʱ�Ų���
    if(x<T->data)
        T->lchild=Insert(T->lchild,num,x);//���뵽������
    else
        T->rchild=Insert(T->rchild,num,x);//���뵽������
    updateHeight(T);
    adjust(T);
    return T;
}

AVLTree Delete(AVLTree &T,int x){//ɾ�� 
    if(!T) return T;
    if(T->data==x){//����ҵ�ɾ���ڵ�
        if(!T->lchild||!T->rchild){//�����һ������Ϊ��,�ӳи�ҵ
            AVLTree temp=T;
            T=(T->lchild)?T->lchild:T->rchild;
            delete temp;
        }
        else{//������ֱ��ǰ���������������ҽڵ㣩����֮��Ȼ��ɾ����ֱ��ǰ�� 
        	AVLTree temp;
        	temp=T->lchild;
        	while(temp->rchild)
            	temp=temp->rchild;
            T->num=temp->num;//�滻����
        	T->data=temp->data;
        	T->lchild=Delete(T->lchild,T->data);
        }
    }
    else if(T->data>x)
        T->lchild=Delete(T->lchild,x);//����������ɾ�� 
    else
        T->rchild=Delete(T->rchild,x);//����������ɾ�� 
    updateHeight(T);
	adjust(T);
	return T;
}

void printmax(AVLTree T){//�����ȼ����Ľ���� 
	while(T->rchild){
		T=T->rchild;
	}
	cout<<T->num<<endl;
	maxval=T->data;
}

void printmin(AVLTree T){//�����ȼ���͵Ľ���� 
	while(T->lchild){
		T=T->lchild;
	}
	cout<<T->num<<endl;
	minval=T->data;
}

int main(){
    AVLTree root=NULL;//һ��Ҫ�ÿ� 
	int n,num,val;
	while(~scanf("%d",&n),n){//ע��ʹ��cin��ʱ 
		switch(n){
			case 1:
				scanf("%d%d",&num,&val);
				Insert(root,num,val);
				break;
			case 2:
				if(!root)
					cout<<0<<endl;
				else{
					printmax(root);
					Delete(root,maxval);
				}
				break;
			case 3:
				if(!root)
					cout<<0<<endl;
				else{
					printmin(root);
					Delete(root,minval);
				}
				break;
		}
	}
    return 0;
}
