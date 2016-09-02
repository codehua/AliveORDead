# include "DBHelper.h"

sqlite3* DBHelper:: pDB=NULL ;//数据库指针 

//创建数据库 传入数据库名称
bool DBHelper::createDB(const string dbName)
{
	//创建数据库
	sqlite3 * pdb = NULL;
	//路径
	string path = dbName;
	int result;
	result = sqlite3_open(path.c_str(),&pdb);
	if(result == SQLITE_OK){
		return true;
	}
	sqlite3_get_table(pdb,NULL,NULL,NULL,NULL,NULL);
	return false;
}
//执行语句 == 语句都是由 sqlite3_exec(pdb,sql.c_str(),NULL,NULL,NULL);

void DBHelper::OpenDB()
{
	auto sharedFileUtils = FileUtils::getInstance();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	//如果在IOS平台需要打开相应的数据库路径
	std::string path = sharedFileUtils->fullPathForFilename("data/gameData.db");
	//log("sqlite-->path:%s", path.c_str());
	int result = sqlite3_open(path.c_str(), &pDB);
	if (result != SQLITE_OK)
	{
			log("sqlite-->>open db fail,error code is %d", result);
	}
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	// android 系统不能对assets目录下的文件进行fopen操作，所以copy到 /data/data/包名/files/ 下面再操作
	std::string path = sharedFileUtils->fullPathForFilename("data/gameData.db");
	//log("sqlite android path origin:%s", path.c_str());
	std::string writalePath = sharedFileUtils->getWritablePath() + "gameData.db";
	ssize_t len = 0;
	unsigned char *data = NULL;
	data = sharedFileUtils->getFileData(path.c_str(), "r", &len);
	FILE *fp = fopen(writalePath.c_str(), "r");
	if (fp)
	{
		fclose(fp);
		//log("sqlite path Writable:copy from %s to %s", path.c_str(),writalePath.c_str());
		FILE *fp1 = fopen(writalePath.c_str(), "w+");
		fwrite(data, sizeof(char), len, fp1);
		fclose(fp1);
	}
	else{
		//WritablePath数据库不存在，从fullPath copy过去
		//log("sqlite path Writable:copy from %s to %s", path.c_str(),writalePath.c_str());
		FILE *fp1 = fopen(writalePath.c_str(), "w+");
		fwrite(data, sizeof(char), len, fp1);
		fclose(fp1);
	}
	if(len >0 && data) delete[] data;  
	int result = sqlite3_open(writalePath.c_str(), &pDB);
	if (result != SQLITE_OK)
	{
	}
#endif
}
void DBHelper::CloseDB()
{
	if (NULL != pDB)
	{
		sqlite3_close(pDB);
		pDB=NULL;
	}
}
int DBHelper::excute(string sql)
{
	OpenDB();
	int result = sqlite3_exec(pDB,sql.c_str(),NULL,NULL,NULL);  
	CloseDB();
	return result;
}
int loadRecord( void * para, int n_column, char ** column_value, char ** column_name )
{
	string v_Value = "";
	map<string,string> hmap ;
	for (int i =0;i<n_column;i++)
	{
		if (column_value[i]){
			v_Value=column_value[i];
		}
		else{
			v_Value = "";
		}
		hmap.insert(make_pair<string, string>((string)column_name[i], (string)v_Value));

	}
	vector<map<string,string>>* vect =(vector<map<string,string>>*)para;
	vect->push_back(hmap);
	return 0; 
}
vector<map<string,string> > DBHelper::GetTable(string sql)
{
	OpenDB();
	vector<map<string, string>> vect;
	int result = sqlite3_exec(pDB, sql.c_str(), loadRecord, &vect,NULL);
	CloseDB();
	return vect;
}