#include "UIUtils.h"
//处理
Node* UIUtils::seekNodeByTag(Node* root, int tag){ 
    if (!root) 
    { 
        return nullptr; 
    } 
    if (root->getTag() == tag) 
    { 
        return root; 
    } 
    const auto& arrayRootChildren = root->getChildren(); 
    ssize_t length = arrayRootChildren.size(); 
    for (ssize_t i=0;i<length;i++) 
    { 
        Node* child = dynamic_cast<Node*>(arrayRootChildren.at(i)); 
        if (child) 
        { 
			Node* res = seekNodeByTag(child,tag); 
            if (res != nullptr) 
            { 
                return res; 
            } 
		}
    } 
    return nullptr; 
} 
Node* UIUtils::seekNodeByName(Node* root, const std::string& name) 
{ 
    if (!root) 
    { 
        return nullptr; 
    } 
    if (root->getName() == name) 
    { 
        return root; 
    } 
    const auto& arrayRootChildren = root->getChildren(); 
    for (auto& subWidget : arrayRootChildren) 
    { 
        Node* child = dynamic_cast<Node*>(subWidget); 
        if (child) 
        { 
			Node* res = seekNodeByName(child,name); 
            if (res != nullptr) 
            { 
                return res; 
            } 
        } 
    } 
    return nullptr; 
}

Scene * UIUtils::createScene(Layer * layer)
{
	auto scene = Scene::create();
	layer->setName("MyLayer");
	scene->addChild(layer);
	return scene;
}

//弹窗显示动画 --- 
void UIUtils::runShowAction(Node* xx)
{
	xx->getParent()->setVisible(true);
	xx->setScale(0);
	xx->setVisible(true);
	xx->runAction(Sequence::create(EaseBounceOut::create(ScaleTo::create(0.8, 1)), NULL));

}

void UIUtils::runEaseBounceAction(Node * xx)
{
	xx->setScaleX(0);
	//添加动画
	xx->runAction(Sequence::create(DelayTime::create(0.4), EaseBounceOut::create(ScaleTo::create(1, 1, 1)), NULL));
}

//弹窗动画 --- 
void UIUtils::runShowCloseAction(Node* xx, Node * root)
{
	xx->runAction(Sequence::create(ScaleTo::create(0.1, 0), DelayTime::create(0.2), CallFunc::create([xx, root]{
		xx->getParent()->setVisible(false);
		xx->setVisible(false);
		//xx->getParent()->removeFromParent();
		xx->getParent()->removeFromParentAndCleanup(true);
		if (nullptr != root)
		{
			//这样能强力销毁界面
			root->removeFromParentAndCleanup(true);
		}
	}), NULL));
}

void UIUtils::playMoveAction(Node * target, Point delayPos)
{
	target->setPosition(target->getPosition()+delayPos);
	target->runAction(EaseElasticOut::create(MoveBy::create(1, Point(-delayPos.x, -delayPos.y))));
}

void UIUtils::playReMoveAction(Node * target, Point delayPos)
{
	target->runAction(MoveBy::create(0.3, Point(delayPos.x, delayPos.y)));
}

Action * UIUtils::getEffectAction(int num, char* fileNames[], float time,bool isLoop)
{
	Vector<SpriteFrame *> spriteFrameVector;
	for (int i = 0; i < num; i++)
	{
		spriteFrameVector.pushBack(LoadPictuerByName(fileNames[i]));
	}
	auto pAnimation = Animation::createWithSpriteFrames(spriteFrameVector, time);
	auto pAnimate = Animate::create(pAnimation);
	if (isLoop)
	{
		return RepeatForever::create(pAnimate);
	}
	else
	{
		return pAnimate;
	}
}

//对按钮进行初始化
Button * UIUtils::initButtonClick(Node * uiRoot, const std::string& name, std::function<void(Ref *)> clickCallback)
{
	auto btn = FIND_NODE(Button *,uiRoot,name);
	btn->addClickEventListener(clickCallback);
	return btn;
}

Button * UIUtils::initButtonTouch(Node * uiRoot, const std::string& name, std::function<void(Ref *, Widget::TouchEventType)> clickCallback)
{
	auto btn = FIND_NODE(Button *, uiRoot, name);
	btn->addTouchEventListener(clickCallback);
	return btn;
}

int UIUtils::getJsonIntData(const char * jsonName, int id, const char * attName)
{
	ssize_t size = 0;
	unsigned char * data = FileUtils::getInstance()->getFileData(jsonName, "r", &size);

	rapidjson::Document d;
	std::string load_str((const char *)data, size);
	d.Parse<0>(load_str.c_str());
	if (d.HasParseError())
	{
		return 0;
	}
	if (d.IsArray() && d.Size() >= id)
	{
		const rapidjson::Value &dd = d[id - 1];
		if (dd.IsObject())
		{
			if (dd.HasMember(attName))
			{
				const rapidjson::Value &ddd = dd[attName];
				return ddd.GetInt();
			}
		}
	}
	return 0;
}

string UIUtils::getJsonStringData(const char * jsonName, int id, const char * attName)
{
	ssize_t size = 0;
	unsigned char * data = FileUtils::getInstance()->getFileData(jsonName, "r", &size);

	rapidjson::Document d;
	std::string load_str((const char *)data, size);
	d.Parse<0>(load_str.c_str());
	if (d.HasParseError())
	{
		return "???";
	}
	if (d.IsArray() && d.Size() >= id)
	{
		const rapidjson::Value &dd = d[id - 1];
		if (dd.IsObject())
		{
			if (dd.HasMember(attName))
			{
				const rapidjson::Value &ddd = dd[attName];
				return ddd.GetString();
			}
		}
	}
}	
