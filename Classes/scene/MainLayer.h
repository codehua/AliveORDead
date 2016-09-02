# ifndef __MAINLAYER__
# define __MAINLAYER__

# include "BaseLayer.h"
# include "manager/DataManager.h"
# include "manager/SoundManager.h"

class MainLayer : public BaseLayer
{
public:

	CREATE_FUNC(MainLayer);

	static Scene * createScene();
	static MainLayer * createLayer();
	virtual void initUI();
	virtual bool init();
	
	void initData(); //初始化数据

	void dealButtonClick(Ref * pSender);// , ui::TouchEventType teType);
	void dealButtonTouch(Ref * pSender,Widget::TouchEventType touchType);
	virtual bool onTouchBegan(Touch * t, Event * e);
	virtual void onTouchMoved(Touch * t, Event * e);
	virtual void onTouchEnded(Touch * t, Event * e);

	void update(float dt);
	
	void hidePanel(); // 隐藏面板
	void showPanel(); // 显示面板
private:

	Node * mainLayer;
	Node * panel_play;
	bool isMusic;
	bool isAudio;

	Node * panel_head, *panel_right, *panel_bottom, *panel_gold;

};

# endif