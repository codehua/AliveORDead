# ifndef __UIUTILS__
# define __UIUTILS__

# include "cocos2d.h"
# include "ui/CocosGUI.h"
# include"cocostudio/CocoStudio.h"
# include "SimpleAudioEngine.h"
# include "xxtea/xxtea.h"
# include "AppConstant.h"


# define PLAYBGMUSIC SimpleAudioEngine::getInstance()->playBackgroundMusic
# define RESUMEBGMUSIC SimpleAudioEngine::getInstance()->resumeBackgroundMusic
# define PLAYEFFECT SimpleAudioEngine::getInstance()->playEffect
# define PAUSEBGMUSIC SimpleAudioEngine::getInstance()->pauseBackgroundMusic
# define STOPBGMUSIC SimpleAudioEngine::getInstance()->stopBackgroundMusic
# define PRELOADMUSIC SimpleAudioEngine::getInstance()->preloadBackgroundMusic
# define PRELOADEFFECT SimpleAudioEngine::getInstance()->preloadEffect
# define LoadPictuerByName SpriteFrameCache::getInstance()->getSpriteFrameByName

# define GETINTEGER UserDefault::getInstance()->getIntegerForKey
# define SETINTEGER UserDefault::getInstance()->setIntegerForKey
# define GETBOOL UserDefault::getInstance()->getBoolForKey
# define SETBOOL UserDefault::getInstance()->setBoolForKey
# define SETSTR UserDefault::getInstance()->setStringForKey
# define GETSTR UserDefault::getInstance()->getStringForKey

# define FIND_NODE(Type,uiRoot,btnName) dynamic_cast<Type>(UIUtils::seekNodeByName(uiRoot,btnName))
# define INIT_BTN(uiRoot,btnName,func) UIUtils::initButtonClick(uiRoot,btnName,func)
# define INIT_TOUCH_BTN(uiRoot,btnName,func) UIUtils::initButtonTouch(uiRoot,btnName,func)


# define DIRECTOR Director::getInstance()
# define GOTOSCENE(scene) Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene, Color3B(0, 0, 0)))

//StringUtils::toString
template <typename T> 
std::string toString(const T& value)
{ 
	std::ostringstream oss; 
	oss << value; 
	return oss.str();
}
USING_NS_CC;
using namespace cocostudio;
using namespace CocosDenshion;
using namespace ui;
using namespace std;

class UIUtils
{
public :
	static Node* seekNodeByTag(Node* root, int tag);
	static Node* seekNodeByName(Node* root, const std::string& name);
	static void runShowAction(Node* xx);
	static void runShowCloseAction(Node* xx,Node * root = nullptr);
	static void runEaseBounceAction(Node * xx);
	static Action * getEffectAction(int num, char* fileNames[], float time,bool isLoop = true);

	static int getJsonIntData(const char * jsonName, int id, const char * attName);
	static string getJsonStringData(const char * jsonName, int id, const char * attName);


	static Scene * createScene(Layer * layer);

	//对按钮进行初始化
	static Button * initButtonClick(Node * uiRoot, const std::string& name, std::function<void(Ref *)> clickCallback);
	static Button * initButtonTouch(Node * uiRoot, const std::string& name, std::function<void(Ref*, Widget::TouchEventType)> clickCallback);

	//控件播放出现动作
	static void playMoveAction(Node * target,Point delayPos);
	//控件播放移除动作
	static void playReMoveAction(Node * target, Point delayPos);
};
# endif