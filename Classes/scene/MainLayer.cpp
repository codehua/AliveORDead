# include "MainLayer.h"

Scene * MainLayer::createScene()
{
	//auto scene = Scene::create();
	//scene->addChild(MainLayer::create());
	//return scene;
	return UIUtils::createScene(MainLayer::create());
}

MainLayer * MainLayer::createLayer()
{
	auto mainLayer = MainLayer::create();
	mainLayer->setName("MainLayer");
	return mainLayer;
}

bool MainLayer::init()
{
	if (!BaseLayer::init())
	{
		return false;
	}
	//SM->playGameBgMusic(); //播放背景音效

	this->scheduleUpdate();
	return true;
}

void MainLayer::initData()
{
	isMusic = DATA_M->getIsMusic();
	isAudio = DATA_M->getIsAudio();
}

void MainLayer::initUI()
{
	mainLayer = CSLoader::createNode("MainScene.csb");
	this->addChild(mainLayer);

	panel_head = UIUtils::seekNodeByName(mainLayer,"panel_head");
	panel_right = UIUtils::seekNodeByName(mainLayer,"panel_right");
	panel_bottom = UIUtils::seekNodeByName(mainLayer,"panel_bottom");
	panel_gold = UIUtils::seekNodeByName(mainLayer,"panel_gold");

	panel_gold->setPosition(Point(vSize.width/2+100,vSize.height));
	panel_head->setPosition(Point(0,vSize.height));
	panel_right->setPosition(Point(vSize.width,vSize.height));
	panel_bottom->setPosition(Point(vSize.width/2,0));

	auto xx = INIT_TOUCH_BTN(panel_bottom, "btn_world", CC_CALLBACK_2(MainLayer::dealButtonTouch, this));
}

// 隐藏面板
void MainLayer::hidePanel()
{

}

// 显示面板
void MainLayer::showPanel()
{

}

void MainLayer::dealButtonClick(Ref * pSender)
{
	auto dealBtn = dynamic_cast<Button *>(pSender);
	auto btnName = dealBtn->getName();

	SOUND_M->playBtnClickAudio();
}

void MainLayer::dealButtonTouch(Ref * pSender, Widget::TouchEventType touchType)
{
	auto btn = static_cast<Button *>(pSender);
	switch (touchType)
	{
	case Widget::TouchEventType::BEGAN:
		btn->setScale(1.1);
		break;
	case Widget::TouchEventType::ENDED:
		btn->setScale(1);
		break;
	case Widget::TouchEventType::CANCELED:
		btn->setScale(1);
		break;
	case Widget::TouchEventType::MOVED:
		break;
	default:
		break;
	}
}

void MainLayer::update(float dt)
{
	
}

bool MainLayer::onTouchBegan(Touch * t, Event * e)
{
	auto position = t->getLocation();
	return true;
}

void MainLayer::onTouchMoved(Touch * t, Event * e)
{
}

void MainLayer::onTouchEnded(Touch * t, Event * e)
{
}