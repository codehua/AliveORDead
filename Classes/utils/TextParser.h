/*
	txt�ļ�������
	author:codehua
	time:2016��8��30��14:20:33
*/

# ifndef __TEXT_PARSER__
# define __TEXT_PARSER__

# include "cocos2d.h"

using namespace cocos2d;
using namespace std;

enum DataType {
	FIRST_ROW,      //����--������
	SCEND_ROW,		//�ڶ���--������ 
	THREE_ROW,		//������--�ֶ��� 
	OTHER_ROW,      //������--����
	ERROR_ROW,		//������
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

	// ÿ�������ж����ֶ�
	unsigned int size() const { return m_values.size(); }

	// ����� [] ����
	string& operator[](unsigned int key)
	{
		if (key < size()) return m_values[key];
		throw "can't return this value (doesn't exist)";
	}

	// ����� [] ����
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
	const vector<string>* m_type;//����
	vector<string> m_values;
};

class TextParser{
public:
	TextParser(const string& filename);
	~TextParser();

	void Parse(const string& filename);


	Row getRowById(int id);//����id���һ������
	vector<Row> getAllData();//�����������

private:
	// ��ȡ�����ļ�������
	void Load(const string& filename, string& Data);
	// ������ͷ�ֶΣ�����[]��������Լ�ֵ�Է�ʽ��ȡ����ֵ
	void setHeader();
	// ����� [] ����
	Row& operator[](unsigned int key);
private:
	// ԭʼ�������
	vector<Row> m_content;   // �����е����ݣ�������ͷ��
	vector<string> m_header; // ��ͷ�ֶ�
	vector<string> m_type; // ��ͷ�ֶ�����
	// ������Ϣ
	string m_strErrorInfo;
};


# endif