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

//定义树的节点的
typedef struct Node
{
	int data;
	struct Node* lc;
	struct Node* rh;
} Node;

typedef Node* Tree;

//向树中插入节点 
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
		//递归查找
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
	
	//初始化一颗树
	Tree t = NULL;
	for( int i = 0; i < numN; ++i )   
	{
		int data;
		scanf("%d",&data);
		printf("%d\n",insertNode(t,data,-1));
	}
}

