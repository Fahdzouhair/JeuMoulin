#include "SplashScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
   // Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //Add Background + transition to next scene
    Point origin = Director::getInstance()->getVisibleOrigin();
    auto background = Sprite::create("splashScene.png");
    background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background, -1);

    float rX = visibleSize.width / background->getContentSize().width;
    float rY = visibleSize.height / background->getContentSize().height;
    background->setScaleX(rX);
    background->setScaleY(rY);

  
    // add a "close" icon to exit the progress

    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(SplashScene::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        //problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    Scene* scene = MainMenuScene::createScene();
    TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_TIME, scene);
    Director::getInstance()->replaceScene(transition);

    scheduleOnce(CC_SCHEDULE_SELECTOR(SplashScene::SwitchToMainMenu), SPLASH_SCENE_SHOW_TIME);
    return true;
}

void SplashScene::SwitchToMainMenu(float dt)
{
    Scene* scene = MainMenuScene::createScene();
    TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_TIME, scene);
    Director::getInstance()->replaceScene(transition);
}


void SplashScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}