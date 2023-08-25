//
//  LogManager.h
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/4.
//
#ifndef LogManager_h
#define LogManager_h


#ifndef COCOS2D_DEBUG
#define BDLOG(...)  do {} while(false)
#define BDDEBUG(x)  do {} while(false)
#define BDFATAL(x)  do {} while(false)
#define BDERROR(x)  do {} while(false)
#define BDINFO(x)   do {} while(false)
#define BDWARN(x)   do {} while(false)
#else
#define BDLOG(...)  LogManager::log(__VA_ARGS__)
#define BDDEBUG(x)  LogManager::debug(x)
#define BDFATAL(x)  LogManager::fatal(x)
#define BDERROR(x)  LogManager::error(x)
#define BDINFO(x)   LogManager::info(x)
#define BDWARN(x)   LogManager::warn(x)

#endif

#include "LogConfig.h"
#include "BulldogLanguage.h"
class LogManager {
public:
    static void log(string message);
    static void error(string message);
    static void fatal(string message);
    static void debug(string message);
    static void info(string message);
    static void warn(string message);
    template<typename... Args>
    static void log(Args...args){
        LogManager::getInstance()->getLogger("default")->mylog(args...);
    };
    static LogManager *  getInstance();
    Logger * getLogger(string loggerName);
    void setLogMode(int level, string loggerName);
    void setLogMode(string level, string loggerName);
    string transferPlatformNumToString(int num);
    string transferLanguageToString(cocos2d::LanguageType language);

private:
    static LogManager * _instance;
    LogConfig * m_logConfig;
    
private:
    void _init();//在init中完成读取，config的初始化
    LogConfig * getLogConfig();
    void setLogConfig(LogConfig* logConfig);

};

#endif
