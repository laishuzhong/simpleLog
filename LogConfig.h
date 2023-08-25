//
//  LogConfig.hpp
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/4.
//
#ifndef LogConfig_h
#define LogConfig_h

#include "cocos2d.h"
#include "Logger.h"
class LogConfig {

public:
    static LogConfig* getInstance();
    LogAppender* getLogAppender(string appenderName);
    Logger* getLogger(string loggerName);
    LogFormat* getLogFormat(string formatName);
    

private:
    void _initLogger(const json11::Json& config);
    void _initLogFormat(const json11::Json& config);
    //需要根据配置创建多个appender添加到m_logAppenders中
    void _initLogAppender(const json11::Json& config);
    void _init();

private:
    static LogConfig * _instance;
    json11::Json localLogConfig;
    
    //若多实例则：
    std::unordered_map<std::string, Logger* > mLoggers;
    std::unordered_map<std::string, LogAppender* > mAppenders;
    std::unordered_map<std::string, LogFormat* > mFormats;
    
};

#endif
