#include <iostream>
#include <string> 
#include <vector> 
#include <cstdio>
#include <cstdlib>
#include <cmath>

#define Debug 0

using namespace std;

int main() 
{
	if( Debug )
	{
		freopen("93in.txt","r",stdin); 
	}
	
	int caseN;
	cin >> caseN;
	for( int i = 0; i < caseN; ++i )
	{
		int numN;
		int prior = 0;
		int curent;
		cin >> numN;
		bool flag = false;
		for(int j = 0; j < numN; ++j)
		{
			cin >> curent;
			if(curent <= prior )
			{
				flag = true; 
			}
			prior = curent;
		}
		
		if( flag == true)
		{
			printf("%s\n","No");
		}else
		{
			printf("%s\n","Yes");
		}
	}
	return 0;
}
