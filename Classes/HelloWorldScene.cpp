#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene() {
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init() {
	//////////////////////////////
	// 1. super init first
	if (!Layer::init()) {
		return false;
	}
//    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
//    CCSprite *pImg = CCSprite::create("vimlogo-564x564.png",CCRectMake(0,0,100,135));
//    pImg->setPosition(ccp(winSize.width*.5,winSize.height*.5));
//    this->addChild(pImg);

	bool isEmpty = false;
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	eventListener = EventListenerTouchOneByOne::create();

	eventListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);

	dispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);

	this->schedule(schedule_selector(HelloWorld::gameLogic), 1.0f);

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCSprite *pImg = CCSprite::create("collecter.png");
	pImg->setTag(1);
	pImg->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(pImg);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create("CloseNormal.png",
			"CloseSelected.png",
			CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(
			Vec2(
					origin.x + visibleSize.width
							- closeItem->getContentSize().width / 2,
					origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = LabelTTF::create("Hello World for myapplication", "Arial", 24);

	// position the label on the center of the screen
	label->setPosition(
			Vec2(origin.x + visibleSize.width / 2,
					origin.y + visibleSize.height
							- label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

//    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("HelloWorld.png");
//
//    // position the sprite on the center of the screen
//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//    // add the sprite as a child to this layer
//    this->addChild(sprite, 0);
	this->setTouchMode(kCCTouchesAllAtOnce);
	this->setTouchEnabled(true);

	return true;
}

void HelloWorld::addFood() {
//	CCSize winSize =CCDirector::sharedDirector()->getWinSize();
//	CCSprite *food = CCSprite::create("vimlogo-564x564.png",CCRectMake(0,0,100,130));
//	int height = rand() % (int)winSize.height;
//	food->setPosition(ccp(winSize.width + food-> getContentSize().width/2,height));
//	//あとで識別できるようにタグつける
//	food -> setTag(2);
//	this ->addChild(food);
//	//継続時間=早さ
//	float diration = 1.0f;
//	//アクションの作成
//	CCMoveTo* actionMove = CCMoveTo::create(diration,ccp(food->getContentSize().width*3,food->getPositionY()));
//	//アクションの実行
////	food->runAction(actionMove);
//
//	CCCallFuncN* actionMoveDone=
//			CCCallFuncN::create(this,
//					callfuncN_selector(HelloWorld::spriteMoveFinished));
//
//	food->runAction(CCSequence::create(
//			actionMove,actionMoveDone,NULL));

}

void HelloWorld::gameLogic(float hd) {
	this->addFood();
}

void HelloWorld::spriteMoveFinished(CCNode* sender) {
	CCSprite *sprite = (CCSprite *) sender;
	bool isCleanUp = true;
	this->removeChild(sprite, isCleanUp);
}
void HelloWorld::menuCloseCallback(Ref* pSender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
bool HelloWorld::onTouchBegan(cocos2d::Touch* touches,
		cocos2d::CCEvent* event) {

//	Touch *touch = (Touch *)touches->cocos2d::CCObject;
//	CCPoint location = touch->getLocationInView();
//	location=CCDirector::sharedDirector()->convertToGL(location);
//

//	CCSprite *player = (CCSprite *)this->getChildByTag(1);
//
//	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
////	float lengh = sqrtf(powf(location.x-player->getPositionX(),2.0f)+powf(location.y-player->getPositionY(),2.0f));
////	float duration = lengh /winSize.width * 1.5f;
////	CCMoveTo* actionMove = CCMoveTo::create(duration,location);
//	float duration = 1.0f;
//	CCMoveTo* actionMove = CCMoveTo::create(duration,ccp(player->getContentSize().width*3,player->getPositionY()));
//	player->runAction(actionMove);

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
//	int get = rand() % 10;
//	if(get > 3){
		int height = rand() % 10 + 1;
		int width = rand() % 16 + 1;
		CCSprite *pImg = CCSprite::create("44961977_big_p0.png",
				CCRectMake(192 * (height - 1), 256 * (width - 1), 192, 256));
//	    CCSprite *pImg = CCSprite::create("44961977_big_p0.png",CCRectMake(188*(height-1),256*(width-1),188*height,256*width));
		pImg->setPosition(ccp(winSize.width * .5, winSize.height * .5));
		this->addChild(pImg);

//		CCParticleSystemQuad* particle;
//		particle = CCParticleSystemQuad::create("particle_Ver2.plist");
		if(isEmpty == false){
//			isEmpty = true;
//		particle->setPosition(winSize.width / 2, winSize.height / 2);
//		this->addChild(particle);
//		}
	}else{

	}

	return true;
}
