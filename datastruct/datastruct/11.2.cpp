#include "11.2.h"
#include <windows.h>
#include <hash_map>

namespace Main_11_2
{
	Trie_Node::Trie_Node() : node(nullptr), count(0), iscomplete(false), utf8(0)
	{
	}

	Trie_Node::Trie_Node(const uint8_t& utf8, const bool& completem) : node(nullptr), count(0), iscomplete(completem),
		utf8(utf8)
	{
	}

	Trie_Node::~Trie_Node()
	{
		free();
	}

	void Trie_Node::free()
	{
		if (node != nullptr)
		{
			if (count > 1)
			{
				delete[]node;
			}
			else
			{
				delete node;
			}
			node = nullptr;
		}
	}

	/**
	 * \brief 动态分配内存方式的插入--其实这样每次插入都会申请内存，对于插入操作不频繁（稀疏树）来说还是不错的，稠密树还是定义哈希或者是256的数组比较好
	 * \param utf8
	 * \param iscomplete
	 */
	shared_ptr<Trie_Node>* Trie_Node::insert(const uint8_t& utf8, const bool& iscomplete)
	{
		if (count >= NODE_MAX)
			return nullptr;

		int new_index = 0;
		if (node == nullptr)
		{
			node = new shared_ptr<Trie_Node>;
			node[0] = make_shared<Trie_Node>(utf8, iscomplete);
			count = 1;
		}
		else
		{
			auto ptr = new shared_ptr<Trie_Node>[++count];
			bool is_insert = false;
			for (int i = 0, j = 0; i < count && j < count; i++)
			{
				if (is_insert == false)
				{
					if (j < count - 1)
					{
						if (node[j]->utf8_get() < utf8)
						{
							ptr[i] = node[j++];
						}
						else if (node[j]->utf8_get() > utf8)
						{
							ptr[i] = make_shared<Trie_Node>(utf8, iscomplete);
							new_index = i;
							is_insert = true;
						}
						else
						{
							//error
						}
					}
					else
					{
						ptr[i] = make_shared<Trie_Node>(utf8, iscomplete);
						new_index = i;
						is_insert = true;
					}
				}
				else
				{
					ptr[i] = node[j++];
				}
			}
			if (node != nullptr)
			{
				if (count <= 2)
					delete node;
				else
					delete[]node;
				node = nullptr;
			}
			node = ptr;
		}
		return &node[new_index];
	}

	/**
	 * \brief 二分查找
	 * \param utf8
	 * \param trie_node
	 */
	bool Trie_Node::search(const uint8_t& utf8, shared_ptr<Trie_Node>** trie_node)
	{
		if (count == 0 || node == nullptr)
			return false;

		int sta = 0, end = count - 1, mid = 0;
		while (sta <= end)
		{
			mid = (sta + end) / 2;
			if (node[mid]->utf8_get() < utf8)
			{
				sta = mid + 1;
			}
			else if (node[mid]->utf8_get() > utf8)
			{
				end = mid - 1;
			}
			else
			{
				*trie_node = &node[mid];
				return true;
			}
		}
		return false;
	}

	const uint8_t& Trie_Node::utf8_get() const
	{
		return utf8;
	}

	const bool& Trie_Node::complete_get() const
	{
		return iscomplete;
	}

	Trie::Trie()
	{
		trie_node = make_shared<Trie_Node>(0, false);
	}

	Trie::~Trie()
	{
	}

	void Trie::insert(const string& str)
	{
		if (str.empty())
			return;
		if (str.size() > 10)
			return;

		const char* src = str.c_str();
		const size_t len = strlen(str.c_str());
		shared_ptr<Trie_Node>* trieptr = &trie_node;
		shared_ptr<Trie_Node>* temp = nullptr;
		for (size_t i = 0; i < len && trieptr != nullptr; i++)
		{
			const bool ret = (*trieptr)->search(src[i], &temp);
			if (!ret)
			{
				trieptr = (*trieptr)->insert(src[i], i == len - 1 ? true : false);
			}
			else
			{
				trieptr = temp;
			}
		}
	}

	bool Trie::search(const string& str, vector<string>& bookstr)
	{
		if (str.empty())
			return false;

		const char* src = str.c_str();
		const size_t len = strlen(str.c_str());
		shared_ptr<Trie_Node>* trieptr = &trie_node;
		shared_ptr<Trie_Node>* temp = nullptr;
		for (size_t i = 0; i < len; i++)
		{
			const bool ret = (*trieptr)->search(src[i], &temp);
			if (!ret)
			{
				return false;
			}
			if (temp && (*temp)->complete_get())
			{
				bookstr.push_back(string(src, src + i + 1));
			}
			trieptr = temp;
		}
		return true;
	}

	static char* U2G(const char* utf8) {
		int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
		wchar_t* wstr = new wchar_t[len + 1];
		memset(wstr, 0, len + 1);
		MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
		len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
		char* str = new char[len + 1];
		memset(str, 0, len + 1);
		WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
		if (wstr) delete[] wstr;
		return str;
	}

	static char* G2U(const char* gb2312) {
		int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
		wchar_t* wstr = new wchar_t[len + 1];
		memset(wstr, 0, len + 1);
		MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
		len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
		char* str = new char[len + 1];
		memset(str, 0, len + 1);
		WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
		if (wstr) delete[] wstr;
		return str;
	}

	void main_11_2()
	{
		const char* const DICT_PATH = "cppjieba-5.0.3/dict/jieba.dict.utf8";
		const char* const HMM_PATH = "cppjieba-5.0.3/dict/hmm_model.utf8";
		const char* const USER_DICT_PATH = "cppjieba-5.0.3/dict/user.dict.utf8";
		const char* const IDF_PATH = "cppjieba-5.0.3/dict/idf.utf8";
		const char* const STOP_WORD_PATH = "cppjieba-5.0.3/dict/stop_words.utf8";

		const string books[] = {
			"懂.txt",
			"九月的阳光.txt",
			"秋雨敲打着我的窗.txt",
			"诗如秋叶.txt",
			"愿与草木，随遇而安.txt",
			"纵使寂寞开成海.txt"
		};

		struct bookdata
		{
			bookdata(int no, int offset) :book_no(no), offset(offset) {}
			int book_no;
			int offset;

			bool operator<(const bookdata& b)
			{
				return book_no < b.book_no;
			}
		};

		// cppjieba::Jieba jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH, IDF_PATH, STOP_WORD_PATH);
		// vector<cppjieba::Word> result;
		string src;
		Trie trie;
		hash_map<string, deque<bookdata>> bookinfo;

		for (size_t i = 0; i < books->size(); i++)
		{
			ifstream inFile;
			inFile.open("book/" + books[i], ios::in | ios::binary);
			if (!inFile)  //条件成立，则说明文件打开成功
			{
				cout << "test.txt doesn't exist" << endl;
				return;
			}
			int offset = 0;
			cout << "book open success: 《" << books[i] << "》" << endl;

			while (getline(inFile, src))
			{
				if (src.empty() || strlen(src.c_str()) == 0)
				{
					continue;
				}
				if (src[src.size() - 1] == '\r' || src[src.size() - 1] == '\n')
				{
					src[src.size() - 1] = '\0';
				}
				if (src.empty() || strlen(src.c_str()) == 0)
				{
					continue;
				}
				cout << "原文 = " << U2G(src.c_str()) << "  size = " << strlen(src.c_str()) << endl;
				cout << "切词 = " << endl;
				//jieba.Cut(string(src.begin(), src.end() - 1), result, true);

				// for (auto &item : result)
				// {
				// 	cout << U2G(item.word.c_str()) << "\t";
				// 	//把src和offset加入
				// 	trie.insert(item.word);
				// 	if (bookinfo.find(item.word) == bookinfo.end())
				// 	{
				// 		deque<bookdata> temp;
				// 		temp.push_back(bookdata(i, offset + result[0].offset));
				// 		bookinfo[item.word] = temp;
				// 	}
				// 	else
				// 	{
				// 		deque<bookdata> &temp = bookinfo[item.word];
				// 		temp.push_back(bookdata(i, offset + item.offset));
				// 	}
				// }
				cout << endl;
				cout << endl;
				offset = static_cast<int>(inFile.tellg());
				//cout << "inFile.tellg() = " << offset << endl;
			}
			inFile.close();
		}

		while (1)
		{
			string str;
			cout << "enter word for search :" << endl;
			cin >> str;
			if (str.empty())
				continue;
			string utf8_str = G2U(str.c_str());
			vector<string> srclist;
			if (trie.search(utf8_str, srclist) && srclist.size() > 0)
			{
				string src = srclist[srclist.size() - 1];
				if (bookinfo.find(src) == bookinfo.end())
				{
					//error
					cout << "Not found " << str << endl;
					continue;
				}
				deque<bookdata> &temp = bookinfo[src];
				cout << "found " << temp.size() << " item" << endl;
				for (auto& item : temp)
				{
					ifstream inFile;
					inFile.open("book/" + books[item.book_no], ios::in | ios::binary);
					if (!inFile)
					{
						cout << "test.txt doesn't exist" << endl;
						return;
					}
					inFile.seekg(item.offset > 0 ? item.offset : 0, ios::beg);
					char context[11];
					memset(context, 0, sizeof(context));
					inFile.read(context, 33);
					if (inFile.gcount() > 0)
					{
						cout << "book name: 《" << books[item.book_no] << "》  context: " << U2G(context) << endl;
					}
					else
					{
						cout << "book name: 《" << books[item.book_no] << "》  context: " << "context read error" << endl;
					}
					inFile.close();
				}
			}
			else
			{
				cout << "Not found " << str << endl;
			}
		}
	}
}

