# ifndef __DBHELPER__
# define __DBHELPER__

# include "../sqlite/sqlite3.h"
#include "cocos2d.h"
#include <map>
USING_NS_CC;
using namespace std;

class DBHelper
{

public:
	DBHelper();
	~DBHelper();
	//创建数据库 传入数据库名称
	static bool createDB(const string dbName);
	//执行语句 -- 
	static sqlite3 *pDB ;//数据库指针 
	static void OpenDB();//打开数据库
	static int  excute(string sql);//增删改,将result返回，在业务逻辑里判断数据库是否操作成功
	static vector<map<string,string>> GetTable(string sql);//查询数据，如果数据里含有汉字，请vs里，文件-》高级保存选项-》Unicode (utf-8)无签名，65001
	static void CloseDB();//关闭数据库
};


# endif