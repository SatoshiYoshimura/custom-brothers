//
//  GameLayer.h
//  AprinpicMock
//
//  Created by 吉村 智志 on 2015/02/20.
//
//

#ifndef __AprinpicMock__GameLayer__
#define __AprinpicMock__GameLayer__

#include "cocos2d.h"
#include "./Character/BaseCharacter.h"

USING_NS_CC;

class GameLayer: public Layer
{
public:
    static Scene* createScene();
    virtual bool init();
    virtual void onEnter();
    CREATE_FUNC(GameLayer);

    virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
    virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
//    virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
    void setMyMacineDynamicFalse(float tm);
    void setMyMacineDynamicTrue(float tm);
protected:
    enum Tag
    {
        T_Background = 1,
        T_MyMacine,
        T_Enemy
    };
    
    //Zオーダー
    enum ZOrder
    {
        Z_Background = 1,
        Z_MyMacine,
        Z_Enemy
    };
    
    void createBackground();
    void createGround();
    void createMyMacine();
    void createEnemy();
    Point touchStart_;
    
    BaseCharacter* ch_MyMacine;
    BaseCharacter* ch_Enemy;
    Scene* myScene;
    
    const float f_myMoveTime = 0.6f;
    const float f_myMoveDistance = 130.0;
    
};

#endif /* defined(__AprinpicMock__GameLayer__) */
