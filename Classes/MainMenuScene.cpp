#include "MainMenuScene.h"
#include"GameScene.h"
#include"definitions.h"
#include "ui/CocosGUI.h"
#include<iostream>
#include"SplashScene.h"
#include"GameOverScene.h"
#include "GameSceneIA.h"

using namespace std;

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
   // Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//background///////////////////////////////////////////////////////////////////////////////////////////////
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto background = Sprite::create("background_menu.png");
	background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(background, -1);

	float rX = visibleSize.width / background->getContentSize().width;
	float rY = visibleSize.height / background->getContentSize().height;
	background->setScaleX(rX);
	background->setScaleY(rY);

	


	//menu1////////////////////////////////////////////////////////////////////////////////////////////////////
	menu1 = Layer::create();


	auto PlayervPlayerButton = cocos2d::ui::Button::create("2jrs.png", "2jrs_selected.png");
	PlayervPlayerButton->setPosition(Point(visibleSize.width / 5 + origin.x, visibleSize.height * 0.68f + origin.y));
	menu1->addChild(PlayervPlayerButton);
	PlayervPlayerButton->addTouchEventListener([&](Ref * sender, cocos2d::ui::Widget::TouchEventType type) {
		
		switch (type)
		{

		case ui::Widget::TouchEventType::ENDED:
			auto scene = GameScene::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
			cout << true << endl;
		}
		});
		
	auto CPUvPlayerButton = cocos2d::ui::Button::create("1jr.png", "1jrs_selected.png");
	CPUvPlayerButton->setPosition(Point(visibleSize.width / 5 + origin.x, PlayervPlayerButton->getPosition().y - PlayervPlayerButton->getBoundingBox().size.height * 1.2f));
	menu1->addChild(CPUvPlayerButton);
	CPUvPlayerButton->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
		switch (type)
		{

		case ui::Widget::TouchEventType::ENDED:
			auto scene = GameSceneIA::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		}
		});

	auto quitter = cocos2d::ui::Button::create("quitter.png", "quitter_selected.png");
	quitter->setPosition(Point(visibleSize.width / 5 + origin.x, CPUvPlayerButton->getPosition().y - CPUvPlayerButton->getBoundingBox().size.height * 1.2f));
	menu1->addChild(quitter);
	quitter->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {

		switch (type)
		{

		case ui::Widget::TouchEventType::ENDED:
			//auto scene = GameSceneIA::createScene();
			//Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
			Director::getInstance()->end();
		}
		});
		



	menu1->setScale(rY);
	this->addChild(menu1);

    return true;
}
