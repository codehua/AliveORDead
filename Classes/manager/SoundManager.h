/*
	��Ч������
	author:codehua
	time:2016��9��2��00:33:26
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

	void playGameBgMusic(); //���ű�����Ч
	void resumeGameBgMusic(); //�ָ����ű�����Ч
	void pauseGameBgMusic(); //ֹͣ���ű�����Ч
	void playBadgetHit();	//���������û���Ч

	void playBtnClickAudio();//��ť�����Ч

	void playEffectMusic(char * audioFileName);	//������Ч
private:
	SoundManager();
	static SoundManager * soundManager;

	bool isPlayBg;
};

# endif