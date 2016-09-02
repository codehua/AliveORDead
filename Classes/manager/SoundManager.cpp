# include "SoundManager.h"

SoundManager * SoundManager::soundManager = nullptr;

SoundManager::SoundManager()
{

}

SoundManager * SoundManager::getInstance()
{
	if (soundManager == nullptr)
	{
		soundManager = new SoundManager();
		soundManager->isPlayBg = false;
		SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
		SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5);
	}

	return soundManager;
}

//播放背景音效
void SoundManager::playGameBgMusic()
{
	if (IS_MUSIC)
	{
		if (isPlayBg == false)
		{
			isPlayBg = true;
			PLAYBGMUSIC(GAME_MUSIC, true);
		}
	}
}

//恢复播放背景音效
void SoundManager::resumeGameBgMusic()
{
	if (isPlayBg)
	{
		RESUMEBGMUSIC();
	}
	else
	{
		playGameBgMusic();
	}
}

//停止播放背景音效
void SoundManager::pauseGameBgMusic()
{
	PAUSEBGMUSIC();
}

//播放老鼠敲击音效
void SoundManager::playBadgetHit()
{
	//随机个音效 BADGER_HIT_0  BADGER_HIT_1

	if (IS_AUDIO)
	{
		int randomIndex = (int)(CCRANDOM_0_1()*2);
		PLAYEFFECT(randomIndex == 0 ? BADGER_HIT_0 : BADGER_HIT_1);
	}
}

//按钮点击音效
void SoundManager::playBtnClickAudio()
{
	if (IS_AUDIO)
	{
		PLAYEFFECT(BTN_CLICK);
	}
}

//其他音效
void SoundManager::playEffectMusic(char * audioFileName)
{
	if (IS_AUDIO)
	{
		PLAYEFFECT(audioFileName);
	}
}