# ifndef __BASELAYER__
# define __BASELAYER__

# include "cocos2d.h"
# include "utils/UIUtils.h"

USING_NS_CC;

class BaseLayer : public Layer
{
public:
	static Scene * createScene();
	static BaseLayer * createLayer();
	BaseLayer();
	~BaseLayer();
	virtual bool init();
	virtual void initUI();
	virtual void initData();
	virtual bool onTouchBegan(Touch * t,Event * e);
	virtual void onTouchMoved(Touch * t,Event * e);
	virtual void onTouchEnded(Touch * t,Event * e);
	virtual void refush();//Ë¢ÐÂ½çÃæ
	Size vSize;
private:

};


# endif