//
//  LogConfig.cpp
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/4.
//

#include "LogConfig.h"
#include "BulldogFile.h"
#include "consoleLogAppender.h"
#include "fileLogAppender.h"

LogConfig * LogConfig:: _instance = nullptr;
LogConfig* LogConfig::getInstance() {
    if (_instance == nullptr) {
        _instance = new (std::nothrow) LogConfig();
        _instance->_init();
    }
    return _instance;
}

void LogConfig::_init() {
    std::string configPath = "log.json";
    //读取本地的配置文件log.json
    std::string logConfig = FileUtils::getInstance()->getStringFromFile(configPath);
    string err = "";
    json11::Json json = json11::Json::parse(logConfig, err);
    if (!err.empty() && json.is_null()) {
            
    } else {
        localLogConfig = json;
        _initLogFormat(json);
        _initLogAppender(json);
        _initLogger(json);
    }
}

void LogConfig::_initLogFormat(const json11::Json &config) {
    auto root = config.object_items();
    if (root.find("formats") != root.end()) {
        json11::Json json = root["formats"];
        //读取列表，根据配置创建多个对象存于map中
        if (json.is_array()) {
            const auto& arrayData = json.array_items();
            for(auto&item : arrayData) {
                LogFormat * tempFormat = new (nothrow) LogFormat();
                tempFormat->init(item);
                mFormats.insert(std::make_pair(tempFormat->getFormatName(), tempFormat));
                
            }
        }
    }
}

void LogConfig::_initLogAppender(const json11::Json &config) {
    auto root = config.object_items();
    if (root.find("appenders") != root.end()) {
        json11::Json json = root["appenders"];
        //读取列表，根据配置创建多个对象存于map中
        if (json.is_array()) {
            const auto& arrayData = json.array_items();
            for(auto&item : arrayData) {
                std::string appenderName = item["name"].string_value();
                if (appenderName == "console") {
                    consoleLogAppender * tempAppender = new (nothrow) consoleLogAppender();
                    tempAppender->init(item);
                    mAppenders.insert(std::make_pair(tempAppender->getName(), tempAppender));
                } else if (appenderName == "file") {
                    fileLogAppender * tempAppender = new (nothrow) fileLogAppender();
                    tempAppender->init(item);
                    mAppenders.insert(std::make_pair(tempAppender->getName(), tempAppender));
                }
                
            }
        }
    }
}

void LogConfig::_initLogger(const json11::Json &config) {
    auto root = config.object_items();
    if (root.find("loggers") != root.end()) {
        json11::Json json = root["loggers"];
        //读取列表，根据配置创建多个对象存于map中
        if (json.is_array()) {
            const auto& arrayData = json.array_items();
            for (auto&item : arrayData) {
                string loggerName = item["name"].string_value();
                string loggerLevel = item["level"].string_value();
                string loggerAppenderName = item["appender"].string_value();
                string loggerFomatName = item["format"].string_value();
                
                LogFormat * tempLogFormat = getLogFormat(loggerFomatName);
                LogAppender* tempLogAppender = getLogAppender(loggerAppenderName);
                
                if (tempLogFormat && tempLogAppender) {
                    Logger * tempLogger = new (nothrow) Logger();
                    tempLogger->init(*tempLogFormat, *tempLogAppender, loggerName, loggerLevel);
                    mLoggers.insert(std::make_pair(loggerName, tempLogger));
                }
            }
        }
    }
}

LogFormat * LogConfig:: getLogFormat(string formatName) {
    if (mFormats.find(formatName) != mFormats.end()) {
        return mFormats[formatName];
    } else {
        return nullptr;
    }
}

LogAppender* LogConfig:: getLogAppender(string appenderName) {
    if (mAppenders.find(appenderName) != mAppenders.end()) {
        return mAppenders[appenderName];
    } else {
        return nullptr;
    }
}

Logger* LogConfig:: getLogger(string loggerName) {
    if (mLoggers.find(loggerName) != mLoggers.end()) {
        return mLoggers[loggerName];
    } else {
        return nullptr;
    }
}



