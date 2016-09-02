/*
	场景管理器
	author:codehua
	time:2016年9月2日00:33:52
*/

# ifndef __SCENE_MANAGER__
# define __SCENE_MANAGER__

# include "cocos2d.h"
# include "utils/UIUtils.h"
# include "manager/DataManager.h"
# include "scene/BaseLayer.h"
# include "scene/MainScene.h"

# define SCENE_M SceneManager::getInstance()

USING_NS_CC;

class SceneManager : public Ref
{
public:
	static SceneManager * getInstance();

	void addLayer(BaseLayer * baseLayer);
	void removeLayerByName(char * layerName);
	void removeLayer(BaseLayer * baseLayer);

private:
	SceneManager();
	static SceneManager * sceneManager;

	bool isPlayBg;
};

# endif