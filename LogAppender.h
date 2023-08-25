//
//  LogAppender.h
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/4.
//
#ifndef LogAppender_h
#define LogAppender_h
#include "cocos2d.h"

class LogAppender {

public:
    virtual ~LogAppender(){};
    virtual void append(std::string message) = 0;
    void setName(std::string appenderName) {m_appenderName = appenderName;};
    std::string getName() {return m_appenderName;};
private:
    std::string m_appenderName;
};

#endif /* LogAppender_h */
