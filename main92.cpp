#include <iostream>
#include <string> 
#include <vector> 
#include <cstdio>
#include <cstdlib>
#include <cmath>

#define Debug 1

using namespace std;

typedef struct Edge
{
	int fa;
	int ch;
}Edge;


int main() 
{
	if( Debug )
	{
		freopen("92in.txt","r",stdin); 
	}
	
	int caseN;
	cin >> caseN;
	for( int i = 0; i < caseN; ++i )
	{
		int numN;
		cin >> numN;
		vector<Edge> es( numN - 1 ); //保存边 
		vector<int> degree( numN ); //保存定点对应的出度+入度 
		for( int j = 0; j <  numN - 1; ++j)
		{
			int fa,ch;
			scanf("%d %d",&fa,&ch);
			//保存边 
			Edge e;
			e.fa = fa;
			e.ch = ch;
			es[j] = e;
			//保存度数
			degree[fa]++;
			degree[ch]++; 
		}
		
		//逐次判断节点是否满足P节点要求 
		int pCount = 0;
		for(int k = 0 ; k < numN; ++k)
		{
			bool flag = false;
			//遍历所有的边看是否存在 该节点的度 < 父节点 或者 子节点	的度 
			for( int n = 0; n < es.size(); ++n )
			{ 
				int compareObj = -1;
				//如果是孩子 
				if( es[n].ch == k )	
				{
					compareObj = es[n].fa; 
				}
				//如果是父亲 
				if( es[n].fa == k )	
				{
					compareObj = es[n].ch; 
				}
				
				if( compareObj >= 0 )
				{
					if( degree[k] < degree[compareObj] )
					{
						flag = true;
						break;
					}
				}
				
			}
			if( flag == false )
			{
				pCount++;
			} 
		}
		printf("%d\n",pCount);	
	}	
	return 0;
}
