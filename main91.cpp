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
		//搞个向量保存节点 
		vector<Node> FS; 
		//初始化一个根节点
		Node root;
		root.type = DIRTYPE;
		root.index = index++;
		root.name = "root";
		
		FS.push_back(root);
		//读入命令个数 
		int cmdN;
		cin>>cmdN;
	
		for(int j = 0; j < cmdN; ++j)
		{
			//解析并执行命令 
			string cmd;
			string name,dirName;
			cin >> cmd;
			if(cmd == "CREATEFILE" || cmd == "CREATEDIR")
			{
				cin>>name>>dirName;
					//创建新的节点放进文件系统 
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
					//找到对应目录
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
				//找到对应目录index
				int k = 0;
				for(k = 0; k < FS.size(); ++k)
				{
					if( dirName == FS[k].name)
					{
						break;	 
					}
				}
				//输出孩子节点名称 
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
