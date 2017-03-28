#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std; 

int main()
{
	int caseN;
	cin>>caseN;
	int hour1 = 0; 
	int sec1 = 0; 
	int hour2 = 0; 
	int sec2 = 0; 
	for(int i = 0; i < caseN; ++i)
	{	
		scanf("%d:%d",&hour1,&sec1);
		scanf("%d:%d",&hour2,&sec2);
		//把时间转成全分钟表示
		int t1 = hour1 * 60 + sec1;
		int t2 = hour2 * 60 + sec2;
		
		int rt = t2 - t1;
		if(rt < 0)
		{
			rt += 1440;
		}	
    	printf("%d\n",rt);
//		cout <<rt<<endl; 用cout就超时了。 
	} 
	
	return 0;
}


