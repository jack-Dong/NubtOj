#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//��Ľṹ�� 
typedef struct Point
{
	double x,y;
}Point;


//�ж��Ƿ���һ��ֱ���� 
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
	cin>>caseN; //�õ������������� 
	vector<Point> nums;
	vector<string> rts; //��� 
	int numN;
	Point temp;
	for(int i = 0; i < caseN;i++)
	{
		cin>>numN;//�õ��������������������� 
		//�õ����е����� 
		for(int j = 0; j < numN;j++)
		{
			cin>>temp.x>>temp.y;
			nums.push_back(temp);
		}
		//�����������������Ƿ���һ��ֱ����
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
	//����� 
	for(int i = 0; i < rts.size();i++)
	{
		cout << rts[i]<<endl;
	}	
}

