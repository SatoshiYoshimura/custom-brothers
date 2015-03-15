#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
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
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    //シングルタップ用リスナを設定する
    auto touchListener = EventListenerTouchOneByOne::create();
//    touchListener->setSwallowTouches(_swallowsTouches);
    touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    //CCSpriteクラスを初期化しています。
    sprite = Sprite::create("barnia.jpg");
    //位置を設定
    sprite->setPosition(Point(300,200));
    //画面に追加をしています。
    this->addChild(sprite);
    
    return true;
}

//ccTouchMoved()関数->タッチ中
void HelloWorld::onTouchEnded(Touch *pTouch, Event *pEvent) {
    Point test = pTouch->getLocationInView();
    float distance = start.getDistance(test);
    
    //移動距離しきい値100より大きければスワイプそうさだと判断
    if(distance > 100){
        float angle = start.getAngle(test);
        CCLOG("angle %f",angle);
        angle = CC_RADIANS_TO_DEGREES(angle);
        angle *= -1;
        Point sas = sprite->getPosition().forAngle(angle);
        CCLOG("forAngle x %f y %f", sas.x,sas.y );
        
        float moveV = 1000;
        Point laser;
        laser.x = (50 * cosf(angle));
        laser.y = (50 * sinf(angle));
        
        auto action = MoveTo::create(1.0f, sprite->getPosition() + laser);
        //アニメーション開始
        sprite->runAction(action);
    }
    
}

//ccTouchEnded()関数->タッチ終了
void HelloWorld::onTouchMoved(Touch *pTouch, Event *pEvent) {
}

//ccTouchBegan()関数->タッチ開始
bool HelloWorld::onTouchBegan(Touch *pTouch, Event *unused_event){
    start = pTouch->getStartLocationInView();
    return true;
}