#include "6.3.h"


namespace Main_6_3
{
	class_6_3::class_6_3()
	{
	}


	class_6_3::~class_6_3()
	{
	}

	void class_6_3::Numbering(int number)
	{
		number = 12;
		vertexNode.clear();
		if (number >= 0 && number < Main_6_3_MaxSize)
		{
			Node tmp;
			for (int i = 0; i < number; i++)
			{
				tmp.idx = i;
				vertexNode.push_back(tmp);
			}

			//debug 数据
			vertexNode[0].x = 0;
			vertexNode[0].y = 0;
			vertexNode[1].x = 10;
			vertexNode[1].y = 10;
			vertexNode[2].x = 30;
			vertexNode[2].y = 30;
			vertexNode[3].x = 0;
			vertexNode[3].y = 20;
			vertexNode[4].x = -15;
			vertexNode[4].y = 25;
			vertexNode[5].x = -25;
			vertexNode[5].y = 15;
			vertexNode[6].x = -35;
			vertexNode[6].y = 5;
			vertexNode[7].x = -40;
			vertexNode[7].y = -5;
			vertexNode[8].x = -30;
			vertexNode[8].y = -20;
			vertexNode[9].x = 0;
			vertexNode[9].y = -25;
			vertexNode[10].x = 0;
			vertexNode[10].y = -40;
			//debug 

			vertexNode[vertexNode.size() - 1].x = 50;		//标志岸边节点
			vertexNode[vertexNode.size() - 1].y = 50;		//标志岸边节点
		}
	}

	bool class_6_3::IsSecurelyArrived(uint16_t num)
	{
		if (num >= vertexNode.size())
			return false;

		memset(vertexNums, 0, sizeof(vertexNums));
		return DFS(num);
	}

	vector<uint16_t> class_6_3::JumpVertexs(uint16_t num)
	{
		vector<uint16_t> ret;
		if (num < vertexNode.size())
		{
			for (auto item : vertexNode)
			{
				if (item.idx != num && IsInStep(vertexNode[num], item))
				{
					ret.push_back(item.idx);
				}
			}

			#if Main_6_3_DeBug_Log
			cout << "Vertex: " << num << " 邻接点为: " ;
			for (auto item : ret)
			{
				cout << item << " ";
			}
			cout << endl;
			#endif
		}
		return ret;
	}

	bool class_6_3::DFS(uint16_t num)
	{
		if (num >= vertexNode.size())
			return false;

		vertexNums[num] = true;
		if (IsSafe(num))
		{
			return true;
		}
		else
		{
			auto tmp = JumpVertexs(num);
			for (auto item : tmp)
			{
				if (IsSafe(item))
				{
					return true;
				}
			}
			for (uint16_t i = 0; i < tmp.size(); i++)
			{
				if (!vertexNums[tmp[i]])
				{
					if (DFS(tmp[i]) == true)
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	bool class_6_3::IsSafe(uint16_t num)
	{
		if (num < vertexNode.size())
		{
			if (abs(vertexNode[num].x) >= 50 || abs(vertexNode[num].y) >= 50)
			{
				return true;
			}
		}
		return false;
	}

	bool class_6_3::IsInStep(Node src, Node item)
	{
		if (sqrt((src.x - item.x)*(src.x - item.x) + (src.y - item.y)*(src.y - item.y)) <= step)
			return true;
		else if((item.idx == vertexNode.size() - 1) && (abs(src.x) + step >= 50 || abs(src.y) + step >= 50))	//岸边节点特殊判断
			return true;
		return false;
	}


	void main_6_3()
	{
		class_6_3 assistant;
		uint16_t num = 0;

		assistant.Numbering(20);
		auto ret = assistant.IsSecurelyArrived(num);
		cout << "从" << num << "节点出发" << (ret ? "可以抵达岸边！" : "被鳄鱼吃掉！") << endl;

		num = 10;
		ret = assistant.IsSecurelyArrived(num);
		cout << "从" << num << "节点出发" << (ret ? "可以抵达岸边！" : "被鳄鱼吃掉！") << endl;

		num = 3;
		ret = assistant.IsSecurelyArrived(num);
		cout << "从" << num << "节点出发" << (ret ? "可以抵达岸边！" : "被鳄鱼吃掉！") << endl;

		num = 9;
		ret = assistant.IsSecurelyArrived(num);
		cout << "从" << num << "节点出发" << (ret ? "可以抵达岸边！" : "被鳄鱼吃掉！") << endl;
	}

}