# include "BaseLayer.h"


BaseLayer::BaseLayer()
{

}

BaseLayer::~BaseLayer()
{
	
}

void BaseLayer::initUI()
{

}
void BaseLayer::initData()
{

}
bool BaseLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	vSize = Director::getInstance()->getVisibleSize();
	this->initData();
	this->initUI();


	//设置一些参数
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(BaseLayer::onTouchBegan,this);
	listener->onTouchMoved = CC_CALLBACK_2(BaseLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(BaseLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);


	return true;
}

Scene * BaseLayer::createScene()
{
	//auto scene = Scene::create();
	//scene->addChild(BaseLayer::create());
	//return scene;
	return UIUtils::createScene(BaseLayer::create());
}

BaseLayer * BaseLayer::createLayer()
{
	auto baseLayer = new BaseLayer();
	baseLayer->init();
	baseLayer->autorelease();
	return baseLayer;
}

bool BaseLayer::onTouchBegan(Touch * t, Event * e)
{
	return true;
}

void BaseLayer::onTouchMoved(Touch * t,Event * e)
{

}

void BaseLayer::onTouchEnded(Touch * t,Event * e)
{

}

//刷新界面
void BaseLayer::refush()
{

}