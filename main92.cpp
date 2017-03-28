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
		vector<Edge> es( numN - 1 ); //����� 
		vector<int> degree( numN ); //���涨���Ӧ�ĳ���+��� 
		for( int j = 0; j <  numN - 1; ++j)
		{
			int fa,ch;
			scanf("%d %d",&fa,&ch);
			//����� 
			Edge e;
			e.fa = fa;
			e.ch = ch;
			es[j] = e;
			//�������
			degree[fa]++;
			degree[ch]++; 
		}
		
		//����жϽڵ��Ƿ�����P�ڵ�Ҫ�� 
		int pCount = 0;
		for(int k = 0 ; k < numN; ++k)
		{
			bool flag = false;
			//�������еı߿��Ƿ���� �ýڵ�Ķ� < ���ڵ� ���� �ӽڵ�	�Ķ� 
			for( int n = 0; n < es.size(); ++n )
			{ 
				int compareObj = -1;
				//����Ǻ��� 
				if( es[n].ch == k )	
				{
					compareObj = es[n].fa; 
				}
				//����Ǹ��� 
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
