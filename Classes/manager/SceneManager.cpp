# include "SceneManager.h"

SceneManager * SceneManager::sceneManager = nullptr;

SceneManager::SceneManager()
{

}

SceneManager * SceneManager::getInstance()
{
	if (sceneManager == nullptr)
	{
		sceneManager = new SceneManager();
	}

	return sceneManager;
}


void SceneManager::addLayer(BaseLayer * baseLayer)
{
	MainScene::g_mainScene->addLayer(baseLayer);
}

void SceneManager::removeLayerByName(char * layerName)
{
	MainScene::g_mainScene->removeLayerByName(layerName);
}

void SceneManager::removeLayer(BaseLayer * baseLayer)
{
	MainScene::g_mainScene->removeLayer(baseLayer);
}