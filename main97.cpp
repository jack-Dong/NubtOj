#include <iostream>
#include <string> 
#include <vector> 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iterator>

#define Debug 1 

using namespace std;

//�������Ľڵ��
typedef struct Node
{
	int data;
	struct Node* lc;
	struct Node* rh;
} Node;

typedef Node* Tree;

//�����в���ڵ� 
int insertNode(Tree &t,int data,int parent)
{
	if( t == NULL )
	{
		Node* node = new Node();
		node->data = data;
		node->lc = NULL;
		node->rh = NULL;
		t = node; 
		return parent;
	}else
	{
		//�ݹ����
		if( data < t->data )
		{
			return insertNode(t->lc,data,t->data);
		} 
		
		if( data > t->data)
		{
			return insertNode(t->rh,data,t->data);
		}
		
	}
} 

int main() 
{
	if( Debug )
	{
		freopen("97in.txt","r",stdin); 
	}
	int numN;
	scanf("%d",&numN);
	
	//��ʼ��һ����
	Tree t = NULL;
	for( int i = 0; i < numN; ++i )   
	{
		int data;
		scanf("%d",&data);
		printf("%d\n",insertNode(t,data,-1));
	}
}

