//
//  ImagePath.h
//  AprinpicMock
//
//  Created by 吉村 智志 on 2015/03/07.
//
//

#ifndef __AprinpicMock__ImagePath__
#define __AprinpicMock__ImagePath__

#include <stdio.h>

struct ImagePath
{
    struct Character{
        static const char* CHARACTER_BLACK;
        static const char* CHARACTER_BALL;
    };
    
    struct BackGround{
        static const char* BACKGROUND_TEST;
    };
    
};

#endif /* defined(__AprinpicMock__ImagePath__) */
