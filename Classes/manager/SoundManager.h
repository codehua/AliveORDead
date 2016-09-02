/*
	音效管理器
	author:codehua
	time:2016年9月2日00:33:26
*/

# ifndef __SOUND_MANAGER__
# define __SOUND_MANAGER__

# include "cocos2d.h"
# include "utils/UIUtils.h"
# include "manager/DataManager.h"

# define SOUND_M SoundManager::getInstance()

USING_NS_CC;

class SoundManager : public Ref
{
public:
	static SoundManager * getInstance();

	void playGameBgMusic(); //播放背景音效
	void resumeGameBgMusic(); //恢复播放背景音效
	void pauseGameBgMusic(); //停止播放背景音效
	void playBadgetHit();	//播放老鼠敲击音效

	void playBtnClickAudio();//按钮点击音效

	void playEffectMusic(char * audioFileName);	//其他音效
private:
	SoundManager();
	static SoundManager * soundManager;

	bool isPlayBg;
};

# endif