//
//  LogManager.cpp
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/4.
//
#include "LogManager.h"

LogManager * LogManager:: _instance = nullptr;

LogManager * LogManager::getInstance() {
    if (_instance == nullptr) {
        _instance = new (nothrow) LogManager();
        _instance->_init();
    }
    return _instance;
}

void LogManager::_init() {
    LogConfig * m_logConfig = LogConfig::getInstance();
    setLogConfig(m_logConfig);
}

void LogManager::setLogConfig(LogConfig* logConfig) {
    m_logConfig = logConfig;
}

LogConfig* LogManager::getLogConfig() {
    return m_logConfig;
}

Logger* LogManager:: getLogger(string loggerName) {
    return m_logConfig->getLogger(loggerName);
}

void LogManager::setLogMode(int level, string loggerName) {
    m_logConfig->getLogger(loggerName)->setLevel(level);
}

void LogManager::setLogMode(string level, string loggerName) {
    m_logConfig->getLogger(loggerName)->setLevel(level);
}

void LogManager::log(string message) {
    LogManager::getInstance()->getLogger("default")->mylog(message);
}

void LogManager::fatal(string message) {
    LogManager::getInstance()->getLogger("default")->fatal(message);
}

void LogManager::error(string message) {
    LogManager::getInstance()->getLogger("default")->error(message);
}

void LogManager::debug(string message) {
    LogManager::getInstance()->getLogger("default")->debug(message);
}

void LogManager::info(string message) {
    LogManager::getInstance()->getLogger("default")->info(message);
}

void LogManager::warn(string message) {
    LogManager::getInstance()->getLogger("default")->warn(message);
}

string LogManager::transferPlatformNumToString(int num) {
    string platformName = "";
    switch (num) {
        case 0:
            platformName = "admob";
            break;
        case 1:
            platformName = "facebook";
            break;
        case 2:
            platformName = "chartboost";
            break;
        case 3:
            platformName = "applovin";
            break;
        case 4:
            platformName = "vungle";
            break;
        case 5:
            platformName = "unity";
            break;
        case 6:
            platformName = "bulldog";
            break;
        case 7:
            platformName = "ironSource";
            break;
        case 8:
            platformName = "tapjoy";
            break;
        case 9:
            platformName = "facebook_bid";
            break;
        case 10:
            platformName = "criteo";
            break;
        case 11:
            platformName = "pangle";
            break;
        case 12:
            platformName = "pangle_bid";
            break;
        case 14:
            platformName = "bigo_bid";
            break;
        case 15:
            platformName = "inmobi_bid";
            break;
        case 16:
            platformName = "fyber";
            break;
        case 17:
            platformName = "verve";
            break;
        default:
            platformName = "unknown";
            break;
    }
    return platformName;
};

string LogManager::transferLanguageToString(cocos2d::LanguageType language) {
    string languageStr = "";
    switch (language) {
        case LanguageType::CHINESE://中文
            languageStr = "中文";
            break;
        case LanguageType::FRENCH://法语
            languageStr = "法语";
            break;
        case LanguageType::ITALIAN://意大利语
            languageStr = "意大利语";
            break;
        case LanguageType::GERMAN://德语
            languageStr = "德语";
            break;
        case LanguageType::SPANISH://西班牙语
            languageStr = "西班牙语";
            break;
//        case LanguageType::DUTCH://荷兰语
//            break;
        case LanguageType::RUSSIAN://俄语
            languageStr = "俄语";
            break;
        case LanguageType::KOREAN://韩语
            languageStr = "韩语";
            break;
        case LanguageType::JAPANESE://日语
            languageStr = "日语";
            break;
        case LanguageType::HUNGARIAN://匈牙利语
            languageStr = "匈牙利语";
            break;
        case LanguageType::PORTUGUESE://葡萄牙语
            languageStr = "葡萄牙语";
            break;
        case LanguageType::ARABIC://阿拉伯语
            languageStr = "阿拉伯语";
            break;
//        case LanguageType::NORWEGIAN://挪威语
//            break;
        case LanguageType::POLISH://波兰语
            languageStr = "波兰语";
            break;
        case LanguageType::TURKISH://土耳其语
            languageStr = "土耳其语";
            break;
        case LanguageType::UKRAINIAN://乌克兰语
            languageStr = "乌克兰语";
            break;
        case LanguageType::ROMANIAN://罗马尼亚语
            languageStr = "罗马尼亚语";
            break;
        case LanguageType::BULGARIAN://保加利亚语
            languageStr = "保加利亚语";
            break;
        case LanguageType::THAI://泰语
            languageStr = "泰语";
            break;
        case LanguageType::HINDI://印地语
            languageStr = "印地语";
            break;
        case LanguageType::MALAY://马来语
            languageStr = "马来语";
            break;
        case LanguageType::INDONESIAN://印尼语
            languageStr = "印尼语";
            break;
        case LanguageType::VIETNAMESE://越南语
            languageStr = "越南语";
            break;
        case LanguageType::FILIPINO://菲利宾语
            languageStr = "菲利宾语";
            break;
        default://默认英文
            languageStr = "英语";
            break;
    }
    return languageStr;
}









