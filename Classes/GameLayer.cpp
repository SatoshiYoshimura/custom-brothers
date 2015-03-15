//
//  GameLayer.cpp
//  AprinpicMock
//
//  Created by 吉村 智志 on 2015/02/20.
//
//

#include "GameLayer.h"
#include "./Data/ImagePath.h"
#include "Data/ActionData.h"

#define WINSIZE Director::getInstance()->getWinSize()

bool GameLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }

    auto touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    return true;

}

//シーン作成
Scene* GameLayer::createScene()
{
    auto scene = Scene::createWithPhysics(); //シーンを生成
    auto layer = GameLayer::create();
    
    scene->addChild(layer);
    

    return scene;
}

void GameLayer::onEnter()
{
    Layer::onEnter();
    
    //重力
    auto v = Vect(0, 0);
    myScene = dynamic_cast<Scene*>(this->getParent());
    myScene->getPhysicsWorld()->setGravity(v);
    myScene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    //背景の生成
    createBackground();

    createMyMacine();
    createEnemy();
}

//背景の生成
void GameLayer::createBackground()
{
    //背景の設定
    auto background = Sprite::create(ImagePath::BackGround::BACKGROUND_TEST);
    background->setAnchorPoint(Point(0,0.5));
    background->setPosition(Point(0,WINSIZE.height / 2 ));
    addChild(background, Z_Background, T_Background);
}

//地面の生成
void GameLayer::createGround()
{
}

void GameLayer::createEnemy()
{
    ch_Enemy = new BaseCharacter();
    //自分の生成
    ch_Enemy->sp_Character = Sprite::create(ImagePath::Character::CHARACTER_BLACK);
    ch_Enemy->sp_Character->setPosition(Vect(100,200));
    ch_Enemy->sp_Character->setTag(T_Enemy);
    
    //物質特徴
    PhysicsMaterial material;
    material.density = 0.5;
    material.restitution = 0.5;
    material.friction = 0.3;
    
    //物質構造の設定
    auto body = PhysicsBody::createCircle(ch_Enemy->sp_Character->getContentSize().width * 0.47, material);
    body->setGravityEnable(false);
    ch_Enemy->sp_Character->setPhysicsBody(body);
    
    ch_Enemy->sp_Character->setZOrder(Z_Enemy);
    this->addChild(ch_Enemy->sp_Character);
}

void GameLayer::createMyMacine()
{
    //自分の生成
    ch_MyMacine = new BaseCharacter();
    ch_MyMacine->sp_Character = Sprite::create(ImagePath::Character::CHARACTER_BALL);
    ch_MyMacine->sp_Character->setPosition(Vect(300,300));
    ch_MyMacine->sp_Character->setTag(T_MyMacine);
    
//    //物質特徴
    PhysicsMaterial material;
    material.density = 0.5;
    material.restitution = 0.5;
    material.friction = 0.3;
    
    //物質構造の設定
    auto body = PhysicsBody::createCircle(ch_MyMacine->sp_Character->getContentSize().width * 0.47, material);
    body->setGravityEnable(false);
    ch_MyMacine->sp_Character->setPhysicsBody(body);
    
    ch_MyMacine->sp_Character->setZOrder(Z_MyMacine);
    this->addChild(ch_MyMacine->sp_Character);
}

void GameLayer::onTouchEnded(Touch *pTouch, Event *unused_event)
{
    //タッチ終了位置を保持
    Point currentPoint = pTouch->getLocation();
    //スタート位置確認
    CCLOG("start x:%f y:%f",touchStart_.x,touchStart_.y);
    //終了位置確認
    CCLOG("end x:%f y:%f",currentPoint.x,currentPoint.y);
    //スワイプの直角の座標
    Point rightAngleSwipe = Point(currentPoint.x, touchStart_.y);
    CCLOG("rightAngle x:%f y:%f", rightAngleSwipe.x, rightAngleSwipe.y);
    //rを求める
    float r = touchStart_.getDistance(currentPoint);
    CCLOG("r :%f", r);
    
    //移動距離しきい値100より大きければスワイプそうさだと判断
    if(r > ActionData::swipeLine){
        //自分の位置確認
        CCLOG("ch_MyMacine x:%f y:%f", ch_MyMacine->sp_Character->getPosition().x, ch_MyMacine->sp_Character->getPosition().y);
        Point myPoint = ch_MyMacine->sp_Character->getPosition();
        float n = f_myMoveDistance;
        float tmp1  = (n / r);
        //動きたい位置
        //  (c2_x, c2_y) = (c1_x, c1_y) + (f2_x - f1_x, f2_y - f1_y) * (n / r)
        float tmpX = (currentPoint.x - touchStart_.x) * tmp1;
        float c2_x = myPoint.x + tmpX;
        float tmpY = (currentPoint.y - touchStart_.y) * tmp1;
        float c2_y = myPoint.y + tmpY;
        Point toMove_ = Point(c2_x, c2_y);
        
        //ダッシュ中はダッシュできない
        if ( ch_MyMacine->sp_Character->getNumberOfRunningActions() == 0 ) {
            ch_MyMacine->sp_Character->runAction(MoveTo::create(f_myMoveTime,toMove_));
        }
    
    }
}

//ccTouchBegan()関数->タッチ開始
bool GameLayer::onTouchBegan(Touch *pTouch, Event *unused_event){
    //タッチスタート位置を保持
    touchStart_ = pTouch->getLocation();
    return true;
}

void GameLayer::setMyMacineDynamicFalse(float tm)
{
    ch_MyMacine->sp_Character->getPhysicsBody()->setDynamic(false);
    this->scheduleOnce(schedule_selector(GameLayer::setMyMacineDynamicTrue), 2);
}

void GameLayer::setMyMacineDynamicTrue(float tm)
{
    ch_MyMacine->sp_Character->getPhysicsBody()->setDynamic(true);
}