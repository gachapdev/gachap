#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
private:
    cocos2d::EventListenerTouchOneByOne *eventListener;

public:


	bool isEmpty = false;
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    void addFood();

    void gameLogic(float hd);

    void spriteMoveFinished(cocos2d::CCNode* sender);

    bool onTouchBegan(cocos2d::Touch* touches,cocos2d::Event* event);
};

#endif // __HELLOWORLD_SCENE_H__
