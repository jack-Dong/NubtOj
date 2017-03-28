#include <iostream>
#include <string> 
#include <vector> 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iterator>

#define Debug 0 

using namespace std;

//二分查找 返回index
int bin_search(vector<int> &nums,int key)
{
    int rt = -1;
    if( nums.size() > 0 )
    {
        int low = 0,high = nums.size();
        int mid;
        while( high >= low )
        {
            mid = ( low + high ) / 2;
            if( nums[mid] == key )
            {
                return mid;
            } else if( nums[mid] > key )
            {
                high = mid - 1;
            } else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main() 
{
	if( Debug )
	{
		freopen("94in.txt","r",stdin); 
	}
	int caseN;
	scanf("%d",&caseN);
	for( int i = 0; i < caseN; ++i )   
	{
		char src[100000];
		scanf("%s",src);
		
		//存特定字符的位置 加快速度
		vector< vector<int> > chIndexs(26); 
		for(int j = 0; j < strlen(src); ++j)
		{
			chIndexs[ src[j] - 'a'].push_back(j);
		}
		
		int numN;
		scanf("%d",&numN);
		for( int j = 0; j < numN; ++j )
		{
			char action[10];
			scanf("%s ",action); //这里这个空格要注意啊。 
						
			if( strcmp(action,"INSERT") == 0 )
			{
				char ic[5];
				scanf("%s",ic);
				chIndexs[ ic[0] - 'a'].push_back( strlen(src) );
				strcat(src,ic);
				
			}else if( strcmp(action,"QUERY") == 0 )
			{
				int index;
				int len = strlen(src);
				scanf("%d",&index);
				int dis = -1;
				int n = src[index] - 'a';
				
				int chSize = chIndexs[n].size();						
				int dt =  bin_search( chIndexs[n],index );
				
				if( chSize < 2 )//别处没有这个字符 
				{
					dis = -1;
				}else  
				{
					int db =  len, dp = len;
					if( dt + 1 < chSize )
					{
						db = chIndexs[n][ dt + 1] - index;
					} 
					
					if( dt - 1 >= 0 )
					{
						dp = index - chIndexs[n][ dt - 1 ];
					}
					
					dis = (db < dp) ? db : dp; 
				} 
				printf("%d\n",dis);
			}
		}
	}
	
	return 0;
}
