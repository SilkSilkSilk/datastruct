#ifndef __MAIN_6_3_H__
#define __MAIN_6_3_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stack>
#include <queue>


namespace Main_6_3
{	//007������������ת��Ϊͼ������
	using namespace std;
	#define Main_6_3_DeBug_Log 1

	class class_6_3
	{
	public:
		#define Main_6_3_MaxSize 100
		struct Node
		{
			uint16_t idx = 0;
			int x = 0;
			int y = 0;
		};

	public:
		class_6_3();
		~class_6_3();
		void Numbering(int number);		//ɨ�������������ź�
		bool IsSecurelyArrived(uint16_t num);		//�ӵ�num���ڵ�������Ƿ�ȫ�ִﰶ��

	private:
		vector<uint16_t> JumpVertexs(uint16_t num);
		bool DFS(uint16_t num);
		bool IsSafe(uint16_t num);
		bool IsInStep(Node src, Node item);

	private:
		uint16_t step = 20;	//��Ծ����20m
		bool vertexNums[Main_6_3_MaxSize] = { 0 };
		uint16_t vertexNum = 0;
		vector<Node> vertexNode;		//��ͼ����
	};

	void main_6_3();
}

#endif
