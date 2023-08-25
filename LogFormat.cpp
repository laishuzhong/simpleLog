//
//  LogFormat.cpp
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/5.
//

#include "LogFormat.h"

void LogFormat::init(const json11::Json &config) {
    formatName = config["name"].string_value();
    formatString = config["pattern"].string_value();
}

string LogFormat::getFormatName() {
    return formatName;
}

string LogFormat::getFormatString() {
    return formatString;
}

void LogFormat::setFormatName(std::string LogformatName) {
    formatName = LogformatName;
}

void LogFormat::setFormatString(std::string LogformatString) {
    formatString = LogformatString;
}

//默认为default格式
string LogFormat::format(const LogEvent& event) {
    if (formatName == "default") {
        return defaultFormat(event);
    } else if (formatName == "pattern") {
        return patternFormat(event);
    } else {
        return defaultFormat(event);
    }
}

string LogFormat::defaultFormat(const LogEvent& event) {
    time_t current_time = time(nullptr);
    tm* local_time = std::localtime(&current_time);
    char time_buf[100];
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", local_time);
    string time_str(time_buf);
    
    int m_level = event.getLevel();
    string level = event.getStringLevel(m_level);
    string loggerName = event.getLoggerName();
    string message = event.getMessage();
    
    string output = time_str + " [" + level +  "] : " + message;
    
    return output;
}

string LogFormat::patternFormat(const LogEvent &event) {
    //待实现
    return defaultFormat(event);
}

