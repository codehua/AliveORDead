# ifndef __MAIN_SCENE__
# define __MAIN_SCENE__

# include "utils/UIUtils.h"
# include "manager/DataManager.h"
# include "manager/SoundManager.h"
# include "manager/SceneManager.h"
# include "MainLayer.h"
# include "CreateRoleLayer.h"

class MainScene : public Scene
{
public:

	MainScene();
	~MainScene();

	static Scene * createScene();
	virtual void initUI();
	virtual bool init();
	
	void initData(); //初始化数据

	void dealButtonClick(Ref * pSender);// , ui::TouchEventType teType);

	virtual bool onTouchBegan(Touch * t, Event * e);
	virtual void onTouchMoved(Touch * t, Event * e);
	virtual void onTouchEnded(Touch * t, Event * e);

	void update(float dt);

	

	void addLayer(Layer * layer);		//添加界面
	void removeLayer(Layer * layer);	//移除界面
	void removeLayerByName(const char * name);
	void removeLayerByTag(int tag);
public:
	static MainScene * g_mainScene; 
private:

	bool isMusic;
	bool isAudio;

};

# endif