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
	int numN; //ÿ������������������� 
	long long temp;	 //Ҫ������Χ  
	long long rest = 0;
	vector<long long> bitCount(BIT_SUM); 
	long long rt;	
	while( cin>>numN )  //EOF ���� ctr + z
	{		
		for(int i = 0; i < numN;i++)
		{ 
			cin>>temp;
			//�ö����Ʊ�ʾ
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
		//bitCount�����õ����ִ���Ϊһ������
		bitset<BIT_SUM> rtb(0); 
		for(int k = 0; k < bitCount.size(); ++k)
		{
			if( bitCount[k] % 3 == 1)
			{
				rtb.flip(k);
			}
			//�������0
			bitCount[k] = 0; 
		}
		rt = rtb.to_ulong();//bitת���� 
		printf("%d\n",rt); 		 		
	}
	
}


