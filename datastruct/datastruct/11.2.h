#ifndef __11_2_H__
#define __11_2_H__


#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stack>
#include <queue>
#include <fstream>
#include "myiterator.h"
//#include <boost/lexical_cast.hpp>

namespace Main_11_2
{	//256叉trie树实现倒排索引，代码需要一个叫jieba的分词软件才可以用
	using namespace std;
	#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

/**
 * \brief utf8的256叉trie树
 * \tparam T
 */
	class Trie_Node
	{
	public:
		Trie_Node();
		Trie_Node(const uint8_t& utf8, const bool& iscompletem);
		Trie_Node(const Trie_Node&) = delete;
		Trie_Node(const Trie_Node&&) = delete;
		Trie_Node& operator=(const Trie_Node& _Right) = delete;
		Trie_Node& operator=(Trie_Node&& _Right) = delete;
		~Trie_Node();
		void free();
		shared_ptr<Trie_Node>* insert(const uint8_t& utf8, const bool& iscomplete);
		bool search(const uint8_t& utf8, shared_ptr<Trie_Node>** trie_node);
		const uint8_t& utf8_get() const;
		const bool& complete_get() const;

#define NODE_MAX 256
	private:
		shared_ptr<Trie_Node> *node;
		uint16_t count;
		bool iscomplete;
		uint8_t utf8;
	};


	class Trie
	{
	public:
		Trie();
		~Trie();
		void insert(const string& str);
		bool search(const string& str, vector<string>& bookstr);

	private:
		shared_ptr<Trie_Node> trie_node;
	};

	void main_11_2();
}

#endif
