//
//  Logger.h
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/4.
//
#ifndef Logger_h
#define Logger_h

#if COCOS2D_DEBUG !=1

#endif

#include <string>
#include "LogLevel.h"
#include "LogFormat.h"
#include "LogAppender.h"


class Logger {

public:
    //支持不定类型不定长参数的传入，但是需要保证参数可以被转换为str
    template<typename... Args>
    inline void mylog(Args...args) {
        std::ostringstream oss;
        (oss << ... << args);
        string message = oss.str();
        string output = "";
        LogEvent * logEvent = new (nothrow) LogEvent(message, getLogName(), getLevel());
        output = m_logFormat->format(*logEvent);
        m_logAppender->append(output);
        delete logEvent;
    };
    void mylog(logLevel level, std::string message);
    void info(std::string message);
    void error(std::string message);
    void warn(std::string message);
    void fatal(std::string message);
    void debug(std::string message);
    
    void setLevel(std::string level);
    void setLevel(int level);
    void setLogName(std::string loggerName);
    void setMessage(std::string message);
    void setThreshold(logLevel level);
    
    logLevel getLevel();
    logLevel getLevel(int level);
    std::string getLogName();
    std::string getMessage();
    logLevel getThreshold();
    
    bool isVaild(logLevel level);
    //根据配置文件得到该logger所绑定的format, appender
    void init(LogFormat & logFormat, LogAppender & logAppender, std::string logName, std::string logLevel);
    
private:
    LogAppender* m_logAppender;
    LogFormat* m_logFormat;
    std::string m_logName;
    std::string m_message;
    logLevel m_threshold;
    logLevel m_level;
};

#endif
