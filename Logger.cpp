//
//  Logger.cpp
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/5.
//

#if COCOS2D_DEBUG !=1

#endif

#include "Logger.h"

void Logger::init(LogFormat &logFormat, LogAppender &logAppender, std::string logName, std::string logLevel) {
    m_logFormat = &logFormat;
    m_logAppender = &logAppender;
    m_logName = logName;
    setLevel(logLevel);
    
}

void Logger::debug(std::string message) {
    if (isVaild(DEBUG)) {
        mylog(DEBUG, message);
    }
}

void Logger::fatal(std::string message) {
    if (isVaild(FATAL)) {
        mylog(FATAL, message);
    }
}

void Logger::warn(std::string message) {
    if (isVaild(WARN)) {
        mylog(WARN, message);
    }
}

void Logger::error(std::string message) {
    if (isVaild(ERROR)) {
        mylog(ERROR, message);
    }
}

void Logger::info(std::string message) {
    if (isVaild(INFO)) {
        mylog(INFO, message);
    }
}

void Logger:: mylog(logLevel level, std::string message) {
    string output = "";
    LogEvent * logEvent = new (nothrow) LogEvent(message, getLogName(), level);
    output = m_logFormat->format(*logEvent);
    m_logAppender->append(output);
    delete logEvent;
}


//比较当前日志输出级别与logger规定的级别
bool Logger:: isVaild(logLevel level) {
    if (level <= m_level && level != CLOSE) {
        return true;
    }
    return false;
}

string Logger::getLogName() {
    return m_logName;
}

string Logger::getMessage() {
    return m_message;
}

logLevel Logger::getThreshold() {
    return m_level;
}

logLevel Logger:: getLevel() {
    return m_level;
}

logLevel Logger:: getLevel(int level) {
    logLevel tempLevel;
    switch (level) {
        case 0:
            tempLevel =  CLOSE;
            break;
        case 1:
            tempLevel =  FATAL;
            break;
        case 2:
            tempLevel =  ERROR;
            break;
        case 3:
            tempLevel =  DEBUG;
            break;
        case 4:
            tempLevel =  INFO;
            break;
        case 5:
            tempLevel =  WARN;
            break;
        case 6:
            tempLevel =  ALL;
            break;
        default:
            tempLevel = ALL;
            break;
    }
    return tempLevel;
}

void Logger::setLevel(std::string level) {
    int tempLevel;
    if (level == "close") {
        tempLevel = 0;
    } else if (level == "fatal") {
        tempLevel = 1;
    } else if (level == "error") {
        tempLevel = 2;
    } else if (level == "debug") {
        tempLevel = 3;
    } else if (level == "info") {
        tempLevel = 4;
    } else if (level == "warn") {
        tempLevel = 5;
    } else if (level == "all") {
        tempLevel = 6;
    } else {
        tempLevel = 6;
    }
    m_level = getLevel(tempLevel);
}

void Logger::setMessage(std::string message) {
    m_message = message;
}

void Logger::setThreshold(logLevel level) {
    m_threshold = level;
}

void Logger::setLogName(std::string loggerName) {
    m_logName = loggerName;
}

void Logger::setLevel(int level) {
    m_level = getLevel(level);
}
