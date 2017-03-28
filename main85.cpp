#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//点的结构体 
typedef struct Point
{
	double x,y;
}Point;


//判断是否在一条直线上 
inline bool jugleOnALine(Point p1,Point p2,Point p3)
{
	double det = (p2.y - p1.y)*(p3.x - p1.x) - (p2.x - p1.x)*(p3.y - p1.y);  
	if( fabs(det) < 0.0001 )
	{
		return true;
	}
	return false;
}


 
int main() 
{
	int caseN;
	cin>>caseN; //得到测试用例个数 
	vector<Point> nums;
	vector<string> rts; //结果 
	int numN;
	Point temp;
	for(int i = 0; i < caseN;i++)
	{
		cin>>numN;//得到单个测试用例参数个数 
		//得到所有的坐标 
		for(int j = 0; j < numN;j++)
		{
			cin>>temp.x>>temp.y;
			nums.push_back(temp);
		}
		//计算任意三个坐标是否在一条直线上
		bool flag = false;
		for(int m = 0; m < nums.size();++m)
		{
			for(int n = 0; n < nums.size() && n != m ; ++n)
			{
				for(int k = 0; k < nums.size() && k != m && k != n; ++k)
				{
					if( jugleOnALine(nums[m],nums[n],nums[k]) ) 
					{
						flag = true;
						break;
					}
				}
				if(flag)
				{
					break;
				}
			}
			if(flag)
			{
				break;
			}
		} 
		
		if(flag)
		{
			rts.push_back("Yes");
		}else
		{
			rts.push_back("No");
		}	
		nums.clear();
	}
	//输出答案 
	for(int i = 0; i < rts.size();i++)
	{
		cout << rts[i]<<endl;
	}	
}

