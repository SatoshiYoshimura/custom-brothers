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
#include "../Gun/BaseGun.h"

USING_NS_CC;

class BaseCharacter : public Sprite{

public:
    virtual bool init(const std::string& filename);
    static BaseCharacter* create(const std::string& filename);
private:
    BaseGun* myGun;
};

#endif /* defined(__AprinpicMock__BaseCharacter__) */
