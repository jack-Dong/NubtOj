#include <iostream>
#include <iostream>
#include <string> 
#include <vector> 
#include <cstdio>
#include <cstdlib>
#include <cmath>

#define Debug 0

using namespace std;

enum TYPE{DIRTYPE = 0,FILETYPE};

typedef struct Node
{
	int index;
	TYPE type;
	string name;
	vector<int> chirdren;
}Node;

int main() 
{
	if( Debug )
	{
		freopen("91in.txt","r",stdin); 
	}
	int caseN;
	cin >> caseN;
	for(int i = 0; i < caseN; ++i)
	{
		int index = 0;
		//�����������ڵ� 
		vector<Node> FS; 
		//��ʼ��һ�����ڵ�
		Node root;
		root.type = DIRTYPE;
		root.index = index++;
		root.name = "root";
		
		FS.push_back(root);
		//����������� 
		int cmdN;
		cin>>cmdN;
	
		for(int j = 0; j < cmdN; ++j)
		{
			//������ִ������ 
			string cmd;
			string name,dirName;
			cin >> cmd;
			if(cmd == "CREATEFILE" || cmd == "CREATEDIR")
			{
				cin>>name>>dirName;
					//�����µĽڵ�Ž��ļ�ϵͳ 
					Node node;
					node.index = index;
					node.name = name;
					if(cmd == "CREATEFILE")
					{
						node.type = FILETYPE;
					}else if(cmd == "CREATEDIR")
					{
						node.type = DIRTYPE;
					}
					FS.push_back(node);
					//�ҵ���ӦĿ¼
					for(int k = 0; k < FS.size(); ++k)
					{
						if( dirName == FS[k].name && FS[k].type == DIRTYPE )
						{
							FS[k].chirdren.push_back(index);
							break;
						}
					}
					index++; 
			}else if(cmd ==  "LISTFILE" || cmd == "LISTDIR" )
			{
				cin>> dirName;
				//�ҵ���ӦĿ¼index
				int k = 0;
				for(k = 0; k < FS.size(); ++k)
				{
					if( dirName == FS[k].name)
					{
						break;	 
					}
				}
				//������ӽڵ����� 
				for(int n = 0; n < FS[k].chirdren.size(); ++n)
				{
					TYPE type;
					if(cmd == "LISTFILE")
					{
						type = FILETYPE;
					}else if(cmd == "LISTDIR")
					{
						type = DIRTYPE;
					}
					
					if( FS[ FS[k].chirdren[n] ].type  == type )
					{
						printf("%s\n",FS[ FS[k].chirdren[n] ].name.c_str());
					}
				}
			}
		}
	}
	return 0;
}
