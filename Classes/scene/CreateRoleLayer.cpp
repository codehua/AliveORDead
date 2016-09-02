# include "CreateRoleLayer.h"

Scene * CreateRoleLayer::createScene()
{
	return UIUtils::createScene(CreateRoleLayer::create());
}

CreateRoleLayer * CreateRoleLayer::createLayer()
{
	auto CreateRoleLayer = CreateRoleLayer::create();
	CreateRoleLayer->setName("CreateRoleLayer");
	return CreateRoleLayer;
}

bool CreateRoleLayer::init()
{
	if (!BaseLayer::init())
	{
		return false;
	}
	//SM->playGameBgMusic(); //播放背景音效

	this->scheduleUpdate();
	return true;
}

void CreateRoleLayer::initData()
{
}

void CreateRoleLayer::initUI()
{
	auto node = CSLoader::createNode("CreateRoleLayer.csb");
	this->addChild(node);


	auto btn_begin = INIT_BTN(node, "btn_begin", CC_CALLBACK_1(CreateRoleLayer::dealButtonClick,this));

}



void CreateRoleLayer::dealButtonClick(Ref * pSender)
{
	auto dealBtn = dynamic_cast<Button *>(pSender);
	auto btnName = dealBtn->getName();

	SOUND_M->playBtnClickAudio();

	if ("btn_begin" == btnName)
	{
		SCENE_M->removeLayerByName("CreateRoleLayer");
		SCENE_M->addLayer(MainLayer::createLayer());
	}

}

void CreateRoleLayer::dealButtonTouch(Ref * pSender, Widget::TouchEventType touchType)
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

void CreateRoleLayer::update(float dt)
{
	
}

bool CreateRoleLayer::onTouchBegan(Touch * t, Event * e)
{
	auto position = t->getLocation();
	return true;
}

void CreateRoleLayer::onTouchMoved(Touch * t, Event * e)
{
}

void CreateRoleLayer::onTouchEnded(Touch * t, Event * e)
{
}