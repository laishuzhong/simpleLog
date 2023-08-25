//
//  LogFormat.h
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/4.
//
#ifndef LogFormat_h
#define LogFormat_h

#include "LogEvent.h"
#include "cocos2d.h"
class LogFormat{

public:
    //在format中将logEvent对象转变为格式化后的string
    std::string format(const LogEvent& event);
    
    std::string getFormatString();
    std::string getFormatName();
    void setFormatString(std::string LogformatString);
    void setFormatName(std::string LogformatName);
    
    void init(const json11::Json & config);
    
private:
    std::string defaultFormat(const LogEvent & event);
    std::string patternFormat(const LogEvent & event);

    
private:
    std::string formatString;
    std::string formatName;

};

#endif /* LogFormat_h */
