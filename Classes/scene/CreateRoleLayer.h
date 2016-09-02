# ifndef __CREATEROLE_LAYER__
# define __CREATEROLE_LAYER__

# include "BaseLayer.h"
# include "manager/DataManager.h"
# include "manager/SoundManager.h"
# include "MainLayer.h"
# include "MainScene.h"

class CreateRoleLayer : public BaseLayer
{
public:

	CREATE_FUNC(CreateRoleLayer);

	static Scene * createScene();
	static CreateRoleLayer * createLayer();
	virtual void initUI();
	virtual bool init();
	
	void initData(); //初始化数据

	void dealButtonClick(Ref * pSender);// , ui::TouchEventType teType);
	void dealButtonTouch(Ref * pSender,Widget::TouchEventType touchType);
	virtual bool onTouchBegan(Touch * t, Event * e);
	virtual void onTouchMoved(Touch * t, Event * e);
	virtual void onTouchEnded(Touch * t, Event * e);

	void update(float dt);
	
private:

};

# endif