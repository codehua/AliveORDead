# include "DataManager.h"

DataManager * DataManager::dataManager = nullptr;

DataManager::DataManager()
{
	isMusic = GETBOOL("isMusic",true);
	isAudio = GETBOOL("isAudio", true);
	isTeach = GETBOOL("isTeach", true);

	totalScore = GETINTEGER("totalScore",0);
	totalKillNum = GETINTEGER("totalKillNum",0);
	daojuNums[0] = GETINTEGER("daoju_num_1", 3);
	daojuNums[1] = GETINTEGER("daoju_num_2", 3);
	daojuNums[2] = GETINTEGER("daoju_num_3", 2);
	daojuNums[3] = GETINTEGER("daoju_num_4", 4);
	daojuNums[4] = GETINTEGER("daoju_num_5", 1);

	bestArcadeScore = GETINTEGER("bestArcadeScore", 0);
	rankData = (int**)malloc(12 * sizeof(int));
	levelLockData = (bool *)malloc(LEVEL_NUM * sizeof(bool));
	levelStarData = (int *)malloc(LEVEL_NUM * sizeof(int));

	string str_starNum;
	string str_lock;
	for (int i = 1; i <= LEVEL_NUM; i++)
	{
		str_starNum = "starNum_" + toString(i);
		str_lock = "lock_" + toString(i);
		//SETBOOL(str_lock.c_str(), true);
		levelStarData[i - 1] = GETINTEGER(str_starNum.c_str(), 0);
		if (i <= 3)
		{
			levelLockData[i - 1] = GETBOOL(str_lock.c_str(), false);
		}
		else
		{
			levelLockData[i - 1] = GETBOOL(str_lock.c_str(), true);

		}
	}

	for (int i = 0; i < 2; i++)
	{
		rankData[i] = (int*)malloc(6 * sizeof(int));
		memset(rankData[i], 0, sizeof(int)* 6);
	}

	//memset(rankData, 0, sizeof(int)*12);
	for (int i = 1; i <= 6; i++)
	{
		string str_text_dishu = "text_dishu_" + toString(i);
		string str_text_score = "text_score_" + toString(i);

		rankData[0][i - 1] = GETINTEGER(str_text_dishu.c_str(), 0);
		rankData[1][i - 1] = GETINTEGER(str_text_score.c_str(), 0);
	}


}

DataManager * DataManager::getInstance()
{
	if (dataManager == nullptr)
	{
		dataManager = new DataManager();
	}

	return dataManager;
}

bool DataManager::getIsMusic()
{
	return isMusic;
}

void DataManager::setIsMusic(bool isMusic)
{
	this->isMusic = isMusic;
	SETBOOL("isMusic",isMusic);
}

bool DataManager::getIsAudio()
{
	return isAudio;
}

void DataManager::setIsAudio(bool isAudio)
{
	this->isAudio = isAudio;
	SETBOOL("isAudio", isAudio);
}

bool DataManager::getIsTeach()
{
	return this->isTeach;
}

void DataManager::setIsTeach(bool isTeach)
{
	this->isTeach = isTeach;
	SETBOOL("isTeach",isTeach);
}

int DataManager::getTotalScore()
{
	return this->totalScore;
}

void DataManager::setTotalScore(int delayNum)
{
	this->totalScore = this->totalScore + delayNum;
	SETINTEGER("totalScore", this->totalScore);
}

int DataManager::getTotalKillNum()
{
	return this->totalKillNum;
}

void DataManager::setTotalKillNum(int delayNum)
{
	this->totalKillNum = this->totalKillNum + delayNum;
	SETINTEGER("totalKillNum", this->totalKillNum);
}

bool DataManager::getLevelLockStatus(int levelId)
{
	return levelLockData[levelId - 1];
}

//解锁
void DataManager::openLevelLock(int levelId)
{
	string str_lock = "lock_" + toString(levelId);
	levelLockData[levelId - 1] = false;
	SETBOOL(str_lock.c_str(), false);
}

int DataManager::getLevelStarNum(int levelId)
{
	return levelStarData[levelId - 1];
}

void DataManager::setLevelStarNum(int levelId,int starNum)
{

	if (starNum > levelStarData[levelId - 1])
	{
		string str_starNum = "starNum_" + toString(levelId);
		levelStarData[levelId - 1] = starNum;
		SETINTEGER(str_starNum.c_str(), starNum);
	}
}

void DataManager::setRankData(int killNum, int score)
{
	string str_text_dishu;
	string str_text_score;

	int index = 7;//默认没有进榜
	//比较高分 -- 用killNum进行比较
	for (int i = 1; i <= 6;i++)
	{
		if (rankData[0][i - 1] < killNum)
		{
			index = i;
			break;
		}
		else if (rankData[0][i - 1] == killNum)
		{
			if (rankData[1][i - 1] < score)
			{
				index = i;
				break;
			}
		}
	}
	if (index == 7)
	{
		return;
	}
	//重新排序排行榜
	for (int i = 6; i >= index; i--)
	{
		str_text_dishu = "text_dishu_" + toString(i);
		str_text_score = "text_score_" + toString(i);

		if (i == index)
		{
			rankData[0][i - 1] = killNum;
			rankData[1][i - 1] = score;
		}
		else
		{
			rankData[0][i - 1] = rankData[0][i - 2];
			rankData[1][i - 1] = rankData[1][i - 2];
		}
		SETINTEGER(str_text_dishu.c_str(), rankData[0][i - 1]);
		SETINTEGER(str_text_score.c_str(), rankData[1][i - 1]);
	}
}

int ** DataManager::getAllRankData()
{
	return rankData;
}

//返回街机模式的最高分数
int DataManager::getBestArcadeScore(int score)
{
	if (score > bestArcadeScore)
	{
		SETINTEGER("bestArcadeScore", score);
		bestArcadeScore = score;
	}
	return bestArcadeScore;
}

int DataManager::getDaojuNum(int daojuType)
{
	return daojuNums[daojuType - 1];

	/*string daojuStr = "daoju_num_" + toString(daojuType);
	switch (daojuType)
	{
	case DAOJU_TYPE_NAOZHONG:
		return GETINTEGER(daojuStr.c_str(), 3);
		break;
	case DAOJU_TYPE_ZHADAN:
		return GETINTEGER(daojuStr.c_str(), 3);
		break;
	case DAOJU_TYPE_HUOQIU:
		return GETINTEGER(daojuStr.c_str(), 5);
		break;
	case DAOJU_TYPE_TIECHAN:
		return GETINTEGER(daojuStr.c_str(), 2);
		break;
	case DAOJU_TYPE_MOFABANG:
		return GETINTEGER(daojuStr.c_str(), 4);
		break;
	default:
		break;
	}
	return 0;*/
}

//设置道具数量
void DataManager::setDaojuNum(int daojuType, int delayNum)
{
	string daojuStr = "daoju_num_" + toString(daojuType);
	SETINTEGER(daojuStr.c_str(), this->getDaojuNum(daojuType) + delayNum);
	daojuNums[daojuType - 1] = daojuNums[daojuType - 1] + delayNum;
}

void DataManager::giveDaoju(int daojuType)
{
	string daojuStr = "daoju_num_" + toString(daojuType);
	switch (daojuType)
	{
	case DAOJU_TYPE_NAOZHONG:
	case DAOJU_TYPE_ZHADAN:
	case DAOJU_TYPE_HUOQIU:
	case DAOJU_TYPE_TIECHAN:
	case DAOJU_TYPE_MOFABANG:
		this->setDaojuNum(daojuType, 5);
		break;
	case GIFT_TYPE_MIESHU:
		this->setDaojuNum(DAOJU_TYPE_NAOZHONG, 10);
		this->setDaojuNum(DAOJU_TYPE_ZHADAN, 10);
		this->setDaojuNum(DAOJU_TYPE_HUOQIU, 10);
		break;
	case GIFT_TYPE_GANEN:
		this->setDaojuNum(DAOJU_TYPE_NAOZHONG, 20);
		this->setDaojuNum(DAOJU_TYPE_ZHADAN, 20);
		this->setDaojuNum(DAOJU_TYPE_HUOQIU, 20);
		this->setDaojuNum(DAOJU_TYPE_TIECHAN, 20);
		this->setDaojuNum(DAOJU_TYPE_MOFABANG, 20);
		break;
	case GIFT_TYPE_MAOXUE:
		break;
	case GIFT_OPEN_ALL_LEVEL:
		for (int i = 1; i <= LEVEL_NUM;i++)
		{
			this->openLevelLock(i);
		}
		break;
	case GIFT_OPEN_LEVEL:
		this->openLevelLock(GETINTEGER("nowDealLevel", 1));
		break;
	default:
		break;
	}
}

void DataManager::setNowDealLevel(int levelId)
{
	SETINTEGER("nowDealLevel",levelId);
}

int DataManager::getNowDay()
{
	return GETINTEGER("preDay",0);
}

void DataManager::setNowDay(int day)
{
	SETINTEGER("preDay", day);
}

int DataManager::getKeepDay()
{
	SETINTEGER("keepDay", 1);
	return GETINTEGER("keepDay", 1);
}

void DataManager::setKeepDay(int keepDay)
{
	SETINTEGER("keepDay", keepDay);
	switch (keepDay)
	{
	case 1:
		this->setDaojuNum(DAOJU_TYPE_TIECHAN, 1);
		break;
	case 2:
		this->setDaojuNum(DAOJU_TYPE_NAOZHONG, 1);
		break;
	case 3:
		this->setDaojuNum(DAOJU_TYPE_ZHADAN, 1);
		break;
	case 4:
		this->setDaojuNum(DAOJU_TYPE_MOFABANG, 1);
		break;
	case 5:
		this->setDaojuNum(DAOJU_TYPE_HUOQIU, 1);
		break;
	case 6:
		this->setDaojuNum(DAOJU_TYPE_ZHADAN, 3);
		break;
	case 7:
		this->setDaojuNum(DAOJU_TYPE_NAOZHONG, 1);
		this->setDaojuNum(DAOJU_TYPE_ZHADAN, 1);
		this->setDaojuNum(DAOJU_TYPE_MOFABANG, 1);
		this->setDaojuNum(DAOJU_TYPE_TIECHAN, 1);
		this->setDaojuNum(DAOJU_TYPE_HUOQIU, 1);
		break;
	default:
		break;
	}
}