#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <bitset>
#include <cstdio>

#define BIT_SUM 64

using namespace std;


int main() 
{
	int caseN;
	int numN; //每个测试用例的输入个数 
	long long temp;	 //要超出范围  
	long long rest = 0;
	vector<long long> bitCount(BIT_SUM); 
	long long rt;	
	while( cin>>numN )  //EOF 结束 ctr + z
	{		
		for(int i = 0; i < numN;i++)
		{ 
			cin>>temp;
			//得二进制表示
			bitset<BIT_SUM> b(temp);  
			rest = 0;
			for(int j = 0; j < BIT_SUM; ++j)
			{
				if( b[j] == 1)
				{
					bitCount[j]++;
				}		
			}
		}	
		//bitCount遍历得到出现次数为一个的数
		bitset<BIT_SUM> rtb(0); 
		for(int k = 0; k < bitCount.size(); ++k)
		{
			if( bitCount[k] % 3 == 1)
			{
				rtb.flip(k);
			}
			//用完就清0
			bitCount[k] = 0; 
		}
		rt = rtb.to_ulong();//bit转整数 
		printf("%d\n",rt); 		 		
	}
	
}


