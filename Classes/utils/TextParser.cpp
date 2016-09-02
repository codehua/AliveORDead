# include "TextParser.h"


TextParser::TextParser(const string& filename)
{
	Parse(filename);

	auto xx = m_content;
	
	for (auto i = m_content.begin(); i != m_content.end();i++)
	{
		log("xxx = %s",(*i)["name"].c_str());
	}

}

TextParser::~TextParser()
{

}
void TextParser::Load(const string& filename, string& Data)
{
	// 读取文件数据
	FILE* pFile = fopen(filename.c_str(), "rb");
	if (!pFile) {
		return;
	}

	fseek(pFile, 0, SEEK_END);
	long len = ftell(pFile);

	char* pBuffer = new char[len + 1];
	 
	fseek(pFile, 0, SEEK_SET);
	fread(pBuffer, 1, len, pFile);
	fclose(pFile);

	pBuffer[len] = 0;
	Data.assign(pBuffer, len);

	delete[] pBuffer;
}

void TextParser::Parse(const string& filename)
{
	// 清除之前的数据
	m_content.clear();
	m_strErrorInfo.clear();

	string text;
	Load(filename, text);

	if (text.size() == 0) {
		return;
	}

	log("text = %s", text.c_str());

	Row Fields = Row();
	string strField;

	// 设置初始状态
	DataType state;

	for (int i = 0, size = text.size(); i < size; ++i) {
		const char& ch = text[i];
	
		if ('#' == ch)
		{
			//这是文件开头 描述字段，可以直接跳过
			state = FIRST_ROW;
		}
		else if ('\t' == ch)
		{
			//制表符
			if (SCEND_ROW == state)
			{
				//记录这个类型
				if ("string" == strField)
				{
				}
				else if ("int" == strField)
				{

				}
				log("字段类型为：%s \n", strField.c_str());
				Fields.push_back(strField);
				strField.clear();
			}
			else if (THREE_ROW == state)
			{
				log("字段名字为：%s  \n", strField.c_str());
				Fields.push_back(strField);
				strField.clear();
			}
			else if (OTHER_ROW == state)
			{
				log("字段内容为：%s \n", strField.c_str());
				Fields.push_back(strField);
				strField.clear();
			}
		}
		else if ('\n' == ch)
		{
			//换行符
			if (FIRST_ROW == state)
			{
				//跳过第一行，进入第二行
				state = SCEND_ROW;
			}
			else if (SCEND_ROW == state)
			{
				state = THREE_ROW;
				log("字段类型为：%s \n", strField.c_str());
				Fields.push_back(strField);
				strField.clear();
				m_content.push_back(Fields);

			}
			else if (THREE_ROW == state)
			{
				state = OTHER_ROW;
				log("字段名字为：%s \n", strField.c_str());
				Fields.push_back(strField);
				strField.clear();
				m_content.push_back(Fields);

			}
			else if (OTHER_ROW == state)
			{
				log("字段内容为：%s \n", strField.c_str());
				Fields.push_back(strField);
				strField.clear();

				m_content.push_back(Fields);

			}
			Fields = Row();
		}
		else if ('\r' == ch)
		{

		}
		else
		{
			if (SCEND_ROW == state)
			{
				//记录类型
				strField.push_back(ch);
			}
			else if (THREE_ROW == state)
			{
				strField.push_back(ch);
			}
			else if (OTHER_ROW == state)
			{
				strField.push_back(ch);
			}
		}
	}

	this->setHeader();
}

//根据id获得一行数据
Row TextParser::getRowById(int id)
{
	for (int i = 2; i <m_content.size(); i++) {
		if (stoi(m_content[i]["id"]) == id)
		{
			return m_content[i];
		}
	}
	Row row = Row();
	return row;
}

//获得所有数据
vector<Row> TextParser::getAllData()
{
	return m_content;
}


void TextParser::setHeader()
{
	m_header.clear();
	m_type.clear();

	for (int i = 0; i < m_content[0].size(); i++)
	{
		m_type.push_back(m_content[0][i]);
	}

	for (int i = 0; i < m_content[1].size(); i++) {
		m_header.push_back(m_content[1][i]);
	}

	for (int i = 0; i < m_content.size(); i++) {
		m_content[i].setType(&m_type);
		m_content[i].setHeader(&m_header);
	}
}


Row& TextParser::operator[](unsigned int key)
{
	if (key < m_content.size()) return m_content[key];
	throw "can't return this row (doesn't exist)";
}