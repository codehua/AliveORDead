/*
	txt文件解析器
	author:codehua
	time:2016年8月30日14:20:33
*/

# ifndef __TEXT_PARSER__
# define __TEXT_PARSER__

# include "cocos2d.h"

using namespace cocos2d;
using namespace std;

enum DataType {
	FIRST_ROW,      //首行--描述行
	SCEND_ROW,		//第二行--类型行 
	THREE_ROW,		//第三行--字段名 
	OTHER_ROW,      //其它行--数据
	ERROR_ROW,		//有问题
};

class Row
{
public:
	Row() { }
	~Row() { }

	void push_back(const string& value) { m_values.push_back(value); }
	void setHeader(const vector<string>* header) { m_header = header; }
	void setType(const vector<string>* type) { m_type = type; }

public:

	// 每行数据有多少字段
	unsigned int size() const { return m_values.size(); }

	// 运算符 [] 重载
	string& operator[](unsigned int key)
	{
		if (key < size()) return m_values[key];
		throw "can't return this value (doesn't exist)";
	}

	// 运算符 [] 重载
	string& operator[](const string& key)
	{
		vector<string>::const_iterator it;
		int pos = 0;
		for (it = (*m_header).begin(); it != (*m_header).end(); it++) {
			if (key == *it) return m_values[pos];
			pos++;
		}
		throw "can't return this value (doesn't exist)";
	}

private:
	const vector<string>* m_header;
	const vector<string>* m_type;//类型
	vector<string> m_values;
};

class TextParser{
public:
	TextParser(const string& filename);
	~TextParser();

	void Parse(const string& filename);


	Row getRowById(int id);//根据id获得一行数据
	vector<Row> getAllData();//获得所有数据

private:
	// 读取整个文件的数据
	void Load(const string& filename, string& Data);
	// 设置列头字段，用于[]运算符，以键值对方式获取数据值
	void setHeader();
	// 运算符 [] 重载
	Row& operator[](unsigned int key);
private:
	// 原始表格数据
	vector<Row> m_content;   // 所有行的数据（包含列头）
	vector<string> m_header; // 列头字段
	vector<string> m_type; // 列头字段类型
	// 错误信息
	string m_strErrorInfo;
};


# endif