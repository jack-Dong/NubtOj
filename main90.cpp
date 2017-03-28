#include <iostream>
#include <string> 
#include <vector> 
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() 
{
	int caseN;
	cin >> caseN;
	for(int i = 0; i < caseN; ++i)
	{
		string str;
		cin>>str;
		//依次判断该字符串转为c,构成简单字符串，所需要的花费 
		int min = 10000 * 13;
		for(char c = 'a';c <= 'z'; ++c)
		{
			int sum = 0;
			int temp = 0;
			for(int j = 0; j < str.size(); ++j)
			{
				temp = str[j] - c;
				if( temp > 0 )
				{
					if( (26 - temp) < temp )
					{
						temp = 26 - temp;
					} 
				}else if(temp < 0)
				{
					if(temp + 26 < abs(temp))
					{
						temp = temp + 26;
					}else
					{
						temp = abs(temp);
					}
				}	
				
				sum += temp;			
			}
			
			if( sum < min )
			{
				min = sum;
			}
		}
		
		printf("%d\n",min);
	} 
	return 0;
}
