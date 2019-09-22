#ifndef __MAIN_6_5_H__
#define __MAIN_6_5_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stack>
#include <queue>


namespace Main_6_5
{	//二维数组实现图
	using namespace std;

	template<class T> class class_6_5
	{
	public:
		struct ENode
		{
			uint16_t V1, V2;	//v1 -> v2  可以表达又向图
			T weight;			//权重
		};
		typedef shared_ptr<struct ENode> PtrToNode;
		typedef PtrToNode Edge;

		struct DijkstraType
		{
			vector<uint16_t> dist;
			vector<uint16_t> path;
		};

		struct FloydType
		{
			vector<vector<uint16_t>> dist;
			vector<vector<uint16_t>> path;
		};

	public:
		class_6_5(uint16_t num, bool dir = false);
		~class_6_5();
		Edge CreatEdge(uint16_t V1, uint16_t V2, T weight);
		void InsertEdge(Edge E);
		void DeleteEdge(Edge E);
		vector<uint16_t> GetAdjacentEdge(uint16_t V);	//获取v的邻接点
		void DFSReady(uint16_t v);
		void DFS(vector<bool> &visited, uint16_t v);	//depth 深度优先搜索
		void BFS(uint16_t v);	//广度优先搜索
		void ShortestPath_unweight_Print(uint16_t startv, uint16_t endv);	//权重为1的单源最短路径算法 -- 打印start-end的路径
		vector<int> ShortestPath_unweight(uint16_t v);	//权重为1的单源最短路径算法 -- 返回路径顺序数组
		void Dijkstra_Print(uint16_t startv, uint16_t endv);	//单源有权重最短路径迪杰特斯拉算法 -- 打印start-end的路径
		DijkstraType Dijkstra(uint16_t v);	//单源有权重最短路径迪杰特斯拉算法
		void Floyd_Print(uint16_t startv, uint16_t endv);	//多源有权重最短路径Floyd算法 -- 打印start-end的路径
		FloydType Floyd(uint16_t v);	//多源有权重最短路径Floyd算法

		void print();

	private:
		uint16_t GetDijkstraMin(vector<uint16_t> dist, vector<bool> collected);	//迪杰特斯拉算法返回dist中为收集最小值

	private:
		#define Main_6_5_Debug 1
		#define Main_6_5_MaxSize 1000
		#define Main_6_5_Infinite 999
		bool isdir = false;		//有向图或无向图
		int Nv;		//节点数
		int Ne;		//边数
		vector<shared_ptr<vector<shared_ptr<T>>>> VertexEdge;
	};

	template<class T>
	inline class_6_5<T>::class_6_5(uint16_t num, bool dir):isdir(dir)
	{
		if (num >= Main_6_5_MaxSize)
			return;

		for (int i = 0; i < num; i++)
		{
			shared_ptr<vector<shared_ptr<T>>> item = make_shared<vector<shared_ptr<T>>>();
			for (int j = 0; j < num; j++)
			{
				item->push_back(make_shared<T>(Main_6_5_Infinite));
			}
			VertexEdge.push_back(item);
		}
		Nv = num;
		Ne = 0;
	}

	template<class T>
	inline class_6_5<T>::~class_6_5()
	{
	}

	template<class T>
	inline typename class_6_5<T>::Edge class_6_5<T>::CreatEdge(uint16_t V1, uint16_t V2, T weight)
	{
		auto ret = make_shared<ENode>();
		ret->V1 = V1;
		ret->V2 = V2;
		ret->weight = weight > Main_6_5_Infinite ? Main_6_5_Infinite : weight;
		return ret;
	}

	template<class T>
	inline void class_6_5<T>::InsertEdge(Edge E)
	{
		if (E == nullptr || E->V1 >= Nv || E->V2 >= Nv)
			return;

		if (*VertexEdge[E->V1]->at(E->V2) == Main_6_5_Infinite)
		{
			*VertexEdge[E->V1]->at(E->V2) = E->weight;
			Ne++;
		}
		
		//无向图
		if (isdir == false)
		{
			if (*VertexEdge[E->V2]->at(E->V1) == Main_6_5_Infinite)
			{
				*VertexEdge[E->V2]->at(E->V1) = E->weight;
				Ne++;
			}
		}
	}

	template<class T>
	inline void class_6_5<T>::DeleteEdge(Edge E)
	{
		if (E == nullptr || E->V1 >= Nv || E->V2 >= Nv)
			return;

		if (*VertexEdge[E->V1]->at(E->V2))
		{
			*VertexEdge[E->V1]->at(E->V2) = Main_6_5_Infinite;
			Ne--;
		}
		//无向图
		if (isdir == false)
		{
			if (*VertexEdge[E->V2]->at(E->V1))
			{
				*VertexEdge[E->V2]->at(E->V1) = Main_6_5_Infinite;
				Ne--;
			}
		}
	}

	template<class T>
	inline vector<uint16_t> class_6_5<T>::GetAdjacentEdge(uint16_t V)
	{
		vector<uint16_t> ret;

		if (V >= Nv || V >= VertexEdge.size())
			return ret;

		for (size_t j = 0; j < VertexEdge[V]->size(); j++)
		{
			if (*VertexEdge[V]->at(j) != Main_6_5_Infinite)
				ret.push_back(static_cast<uint16_t>(j));
		}
		return ret;
	}

	template<class T>
	inline void class_6_5<T>::DFSReady(uint16_t v)
	{
		if (v >= Nv)
			return;

		vector<bool> visited(Nv, false);
		DFS(visited, v);
	}

	template<class T>
	inline void class_6_5<T>::DFS(vector<bool> &visited, uint16_t v)
	{
		if (v >= visited.size())
			return;

		#if Main_6_5_Debug
		cout << v << " ";
		#endif
		visited[v] = true;
		auto src = GetAdjacentEdge(v);
		for (auto &item : src)
		{
			if (!visited[item])
				DFS(visited, item);
		}
	}

	template<class T>
	inline void class_6_5<T>::BFS(uint16_t v)
	{
		if (v >= Nv)
			return;

		vector<bool> visited(Nv, false);
		deque<uint16_t> deq;

		visited[v] = true;
		deq.push_back(v);

		while (deq.size())
		{
			auto src = GetAdjacentEdge(deq.front());
			deq.pop_front();
			for (auto &item : src)
			{
				if (!visited[item])
				{
					#if Main_6_5_Debug
					cout << item << " ";
					#endif
					visited[item] = true;
					deq.push_back(item);
				}
			}
		}
	}

	template<class T>
	inline void class_6_5<T>::ShortestPath_unweight_Print(uint16_t startv, uint16_t endv)
	{
		if (startv >= Nv || endv >= Nv)
			return;

		auto ret = ShortestPath_unweight(startv);
		stack<uint16_t> stk;
		int i = endv;
		stk.push(endv);
		while (ret[i] != -1)
		{
			stk.push(ret[i]);
			if (ret[i] == startv)
				break;
			i = ret[i];
		}

		cout << "from " << startv << " to " << endv << " path: ";
		for (size_t i = 0; !stk.empty(); i++)
		{
			cout << stk.top() << " -> ";
			stk.pop();
		}
		cout << endl;
	}

	template<class T>
	inline vector<int> class_6_5<T>::ShortestPath_unweight(uint16_t v)
	{
		vector<int> dist(Nv, -1);
		vector<int> path(Nv, -1);
		deque<uint16_t> deq;

		dist[v] = 0;
		deq.push_back(v);

		while (deq.size())
		{
			v = deq.front();
			auto src = GetAdjacentEdge(v);
			deq.pop_front();
			for (auto &item : src)
			{
				if (dist[item] == -1)
				{
					dist[item] = dist[v] + 1;
					path[item] = v;
					deq.push_back(item);
				}
			}
		}
		return path;
	}

	template<class T>
	inline void class_6_5<T>::Dijkstra_Print(uint16_t startv, uint16_t endv)
	{
		if (startv >= Nv || endv >= Nv)
			return;

		DijkstraType ret = Dijkstra(startv);
		stack<uint16_t> stk;
		int i = endv;
		stk.push(endv);
		while (ret.path[i] != Main_6_5_Infinite)
		{
			stk.push(ret.path[i]);
			if (ret.path[i] == startv)
				break;
			if (ret.path[i] < Nv)
				i = ret.path[i];
			else
				break;
		}

		cout << "from " << startv << " to " << endv << " path: ";
		for (size_t i = 0; !stk.empty(); i++)
		{
			cout << stk.top() << " -> ";
			stk.pop();
		}
		cout << endl;
		cout << "total distance = " << ret.dist[endv] << endl;
	}

	template<class T>
	inline typename class_6_5<T>::DijkstraType class_6_5<T>::Dijkstra(uint16_t v)
	{
		DijkstraType ret;
		if (v >= Nv)
			return ret;

		vector<uint16_t> dist(Nv, Main_6_5_Infinite);
		vector<uint16_t> path(Nv, Main_6_5_Infinite);
		vector<bool> collected(Nv, false);
		dist[v] = 0;

		while (1)
		{
			v = GetDijkstraMin(dist, collected);
			if (v == Main_6_5_Infinite)
				break;
			collected[v] = true;
			#if Main_6_5_Debug
			cout << v << " ";
			#endif
			auto src = GetAdjacentEdge(v);
			for (auto &item : src)
			{
				if (!collected[item])
				{
					if (dist[v] + *VertexEdge[v]->at(item) < dist[item])
					{
						dist[item] = dist[v] + *VertexEdge[v]->at(item);
						path[item] = v;
					}
				}
			}
		}
		
		ret.dist.assign(dist.begin(), dist.end());
		ret.path.assign(path.begin(), path.end());
		return ret;
	}

	template<class T>
	inline void class_6_5<T>::Floyd_Print(uint16_t startv, uint16_t endv)
	{
		if (startv >= Nv || endv >= Nv)
			return;

		FloydType src = Floyd(startv);
		stack<uint16_t> stk;
		int i = startv;
		int j = endv;
		stk.push(endv);
		while (src.path[i][j] != Main_6_5_Infinite)
		{
			stk.push(src.path[i][j]);
			if (src.path[i][j] == startv)
				break;

			if (src.path[i][j] < Nv)
				j = src.path[i][j];
			else
				break;
		}
		stk.push(startv);

		cout << "from " << startv << " to " << endv << " path: ";
		for (size_t i = 0; !stk.empty(); i++)
		{
			cout << stk.top() << " -> ";
			stk.pop();
		}
		cout << endl;
		cout << "total distance = " << src.dist[startv][endv] << endl;
	}

	template<class T>
	inline typename class_6_5<T>::FloydType class_6_5<T>::Floyd(uint16_t v)
	{
		vector<vector<uint16_t>> dist(Nv, vector<uint16_t>(Nv, Main_6_5_Infinite));
		vector<vector<uint16_t>> path(Nv, vector<uint16_t>(Nv, Main_6_5_Infinite));

		for (size_t i = 0; i < VertexEdge.size(); i++)
		{
			for (size_t j = 0; j < VertexEdge[i]->size(); j++)
			{
				dist[i][j] = *VertexEdge[i]->at(j);
			}
		}

		for (int k = 0; k < Nv; k++)
		{
			for (int i = 0; i < Nv; i++)
			{
				for (int j = 0; j < Nv; j++)
				{
					if (dist[i][k] + dist[k][j] < dist[i][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						path[i][j] = k;
					}
				}
			}
		}
		FloydType ret;
		ret.dist = dist;
		ret.path = path;
		return ret;
	}

	template<class T>
	inline void class_6_5<T>::print()
	{
		cout << "" << "\t";
		for (size_t i = 0; i < VertexEdge.size(); i++)
		{
			cout << i << ":\t";
		}
		cout << endl;
		for (size_t i = 0; i < VertexEdge.size(); i++)
		{
			cout << i << ":\t";
			for (size_t j = 0; j < VertexEdge[i]->size(); j++)
			{
				if (*VertexEdge[i]->at(j) == Main_6_5_Infinite)
					cout << "-" << "\t";
				else
					cout << *VertexEdge[i]->at(j) << "\t";
			}
			cout << endl;
		}
	}

	template<class T>
	inline uint16_t class_6_5<T>::GetDijkstraMin(vector<uint16_t> dist, vector<bool> collected)
	{
		struct temptype{
			uint16_t value;
			uint16_t id;
		};
		vector<temptype> tempdist;
		struct temptype item;
		for (size_t i = 0; i < collected.size(); i++)
		{
			if (collected[i] == false)
			{
				item.id = i;
				item.value = dist[i];
				tempdist.push_back(item);
			}
		}
		if (tempdist.empty())
			return Main_6_5_Infinite;		//为收集的结点可能dist未被赋值，所以返回初始值：Main_6_5_Infinite

		auto min = 0;
		uint16_t ret = 0;
		for (size_t i = 0; i < tempdist.size(); i++)
		{
			if (tempdist[min].value > tempdist[i].value)
			{
				min = i;
			}	
		}
		return tempdist[min].id;
	}

	void main_6_5();
}

#endif
