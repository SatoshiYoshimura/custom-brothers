//
//  BaseCharacter.h
//  AprinpicMock
//
//  Created by 吉村 智志 on 2015/03/07.
//
//

#ifndef __AprinpicMock__BaseCharacter__
#define __AprinpicMock__BaseCharacter__

#include "cocos2d.h"

USING_NS_CC;

class BaseCharacter {

public:
    Sprite* sp_Character;
    //自分の生成
//    sp_Enemy = Sprite::create(ImagePath::Character::CHARACTER_BLACK);
//    sp_Enemy->setPosition(Vect(100,200));
//    sp_Enemy->setTag(T_Enemy);
    
//    //    //物質特徴
//    PhysicsMaterial material;
//    material.density = 0.5;
//    material.restitution = 0.5;
//    material.friction = 0.3;
//    
//    //物質構造の設定
//    auto body = PhysicsBody::createCircle(sp_Enemy->getContentSize().width * 0.47, material);
//    body->setGravityEnable(false);
//    sp_Enemy->setPhysicsBody(body);
//
    
//    sp_Enemy->setZOrder(Z_Enemy);
//    this->addChild(sp_Enemy);
    
};

#endif /* defined(__AprinpicMock__BaseCharacter__) */
