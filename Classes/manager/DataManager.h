/*
	数据管理器
	author:codehua
	time:2016年9月2日00:34:11
*/
# ifndef __DATA_MANAGER__
# define __DATA_MANAGER__

# include "cocos2d.h"
# include "utils/UIUtils.h"

# define DATA_M DataManager::getInstance()
# define IS_MUSIC DATA_M->getIsMusic()
# define IS_AUDIO DATA_M->getIsAudio()

# define SET_IS_MUSIC(isMusic) DATA_M->setIsMusic(isMusic)
# define SET_IS_AUDIO(isAudio) DATA_M->setIsAudio(isAudio)

USING_NS_CC;


class DataManager : public Ref
{
public:
	static DataManager * getInstance();

	bool getIsMusic();
	void setIsMusic(bool isMusic);
	bool getIsAudio();
	void setIsAudio(bool isMusic);

	int getBestArcadeScore(int score); //返回街机模式的最高分数

	int getDaojuNum(int daojuType);
	void setDaojuNum(int daojuType,int delayNum); //设置道具数量

	bool getIsTeach();
	void setIsTeach(bool isTeach);

	int getTotalScore();//总得分
	void setTotalScore(int delayNum);//叠加

	int getTotalKillNum();
	void setTotalKillNum(int delayNum);

	void setRankData(int killNum,int score);
	int ** getAllRankData();

	bool getLevelLockStatus(int levelId);
	void openLevelLock(int levelId); //解锁

	int getLevelStarNum(int levelId);
	void setLevelStarNum(int levelId, int starNum);

	//发放道具
	void giveDaoju(int daojuType);
	void setNowDealLevel(int levelId);

	int getNowDay();	//当前天数
	void setNowDay(int day);

	int getKeepDay();		//登录次数
	void setKeepDay(int keepDay);

private:
	DataManager();
	static DataManager * dataManager;

	bool isMusic; //音乐
	bool isAudio; //音效
	bool isTeach; //教程
	int bestArcadeScore;
	int totalScore;
	int totalKillNum;
	int daojuNums[5];
	
	
	int **rankData;			//排行榜的数据
	bool * levelLockData;	//关卡数据
	int * levelStarData;	//关卡数据
};

# endif