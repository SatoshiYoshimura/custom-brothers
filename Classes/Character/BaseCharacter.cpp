//
//  BaseCharacter.cpp
//  AprinpicMock
//
//  Created by 吉村 智志 on 2015/03/07.
//
//

#include "BaseCharacter.h"
USING_NS_CC;
using namespace std;

bool BaseCharacter::init(const std::string& filename) {
    return this->initWithFile(filename);
}

BaseCharacter* BaseCharacter::create(const std::string& filename)
{
    BaseCharacter *actor = new BaseCharacter();
    if (actor && actor->init(filename))
    {
        actor->autorelease();
        return actor;
    }
    CC_SAFE_DELETE(actor);
    return nullptr;
}
