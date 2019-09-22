#include "6.5.h"


namespace Main_6_5
{
	void main_6_5()
	{
		class_6_5<int> a(8, true);

		a.InsertEdge(a.CreatEdge(1, 2, 2));
		a.InsertEdge(a.CreatEdge(1, 4, 1));
		a.InsertEdge(a.CreatEdge(2, 5, 10));
		a.InsertEdge(a.CreatEdge(2, 4, 3));
		a.InsertEdge(a.CreatEdge(3, 6, 5));
		a.InsertEdge(a.CreatEdge(3, 1, 4));
		a.InsertEdge(a.CreatEdge(4, 3, 2));
		a.InsertEdge(a.CreatEdge(4, 5, 2));
		a.InsertEdge(a.CreatEdge(4, 6, 8));
		a.InsertEdge(a.CreatEdge(4, 7, 4));
		a.InsertEdge(a.CreatEdge(5, 7, 6));
		a.InsertEdge(a.CreatEdge(7, 6, 1));
		a.print();

		cout << "DFS :" << endl;
		a.DFSReady(1);
		cout << endl;

		cout << "BFS :" << endl;
		a.BFS(1);
		cout << endl;

		cout << "Ȩ��Ϊ1�ĵ�Դ���·���㷨 :" << endl;
		a.ShortestPath_unweight_Print(1, 6);
		cout << endl;

		cout << "��Դ��Ȩ�����·���Ͻ���˹���㷨 :" << endl;
		a.Dijkstra_Print(1, 6);
		cout << endl;

		cout << "��Դ��Ȩ�����·��Floyd�㷨 :" << endl;
		a.Floyd_Print(1, 6);
		cout << endl;
	}
}