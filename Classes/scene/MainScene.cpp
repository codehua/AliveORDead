# include "MainScene.h"
MainScene * MainScene::g_mainScene = nullptr;

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}

Scene * MainScene::createScene()
{
	if (nullptr == g_mainScene)
	{
		g_mainScene = new MainScene();
		g_mainScene->init();
		g_mainScene->autorelease();
	}
	return g_mainScene;
}

bool MainScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	//SOUND_M->playGameBgMusic(); //播放背景音效
	
	//第一次加载主界面
	SCENE_M->addLayer(CreateRoleLayer::createLayer());
	this->scheduleUpdate();
	return true;
}

void MainScene::initData()
{
	isMusic = DATA_M->getIsMusic();
	isAudio = DATA_M->getIsAudio();
}

void MainScene::initUI()
{
}

void MainScene::dealButtonClick(Ref * pSender)
{
	auto dealBtn = dynamic_cast<Button *>(pSender);
	auto btnName = dealBtn->getName();

	SOUND_M->playBtnClickAudio();
}

void MainScene::update(float dt)
{
	
}

bool MainScene::onTouchBegan(Touch * t, Event * e)
{
	auto position = t->getLocation();
	return true;
}

void MainScene::onTouchMoved(Touch * t, Event * e)
{
}

void MainScene::onTouchEnded(Touch * t, Event * e)
{
}

//添加界面
void MainScene::addLayer(Layer * layer)
{
	this->addChild(layer);
}

//移除界面
void MainScene::removeLayer(Layer * layer)
{
	this->removeChild(layer);
}

void MainScene::removeLayerByName(const char * name)
{
	auto child = this->getChildByName(name);
	if (child)
	{
		this->removeChild(child);
	}
}

void MainScene::removeLayerByTag(int tag)
{
	auto child = this->getChildByTag(tag);
	if (child)
	{
		this->removeChild(child);
	}
}