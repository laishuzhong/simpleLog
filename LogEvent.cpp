//
//  LogEvent.cpp
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/5.
//

#include "LogEvent.h"
#include <chrono>
#include <ctime>

LogEvent::LogEvent(std::string logStr, std::string loggerName, int level) {
    m_message = logStr;
    m_loggerName = loggerName;
    m_level = level;
    m_timeMills = getNowTime();
}

std::string LogEvent::getStringLevel(int level) const {
    std::string tempLevel;
    switch (level) {
        case 0:
            tempLevel =  "ALL";
            break;
        case 1:
            tempLevel =  "FATAL";
            break;
        case 2:
            tempLevel =  "ERROR";
            break;
        case 3:
            tempLevel =  "DEBUG";
            break;
        case 4:
            tempLevel =  "INFO";
            break;
        case 5:
            tempLevel =  "WARN";
            break;
        case 6:
            tempLevel =  "CLOSE";
            break;
        default:
            tempLevel = "ALL";
            break;
    }
    return tempLevel;
}

int LogEvent::getLevel() const {
    return m_level;
}

std::string LogEvent::getMessage() const {
    return m_message;
}

std::string LogEvent::getLoggerName() const {
    return m_loggerName;
}

std::string LogEvent::getTimeMills() const {
    return m_timeMills;
}

void LogEvent::setLevel(int level) {
    m_level = level;
}

void LogEvent::setMessage(std::string message) {
    m_message = message;
}

void LogEvent::setTimeMills(std::string timeMills) {
    m_timeMills = timeMills;
}

void LogEvent::setLoggerName(std::string loggerName) {
    m_loggerName = loggerName;
}

std::string LogEvent::getNowTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    return std::ctime(&now_c);
}

