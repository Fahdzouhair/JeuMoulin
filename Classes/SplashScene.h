#pragma once
#ifndef __SPLASH_SCENE_H__
#define __SPLASH_SCENE_H__

#include "SplashScene.h"

#include "MainMenuScene.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

#define SCENE_TRANSITION_TIME 1.5f
#define SPLASH_SCENE_SHOW_TIME 1.0f

#include "cocos2d.h"

class SplashScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(SplashScene);
    void SplashScene::menuCloseCallback(cocos2d::Ref* pSender);

private:
    void SwitchToMainMenu(float dt);
};

#endif // __SPLASH_SCENE_H__
