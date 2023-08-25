//
//  LogEvent.h
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/4.
//
#include <string>

class LogEvent {

public:
    int getLevel() const;
    std::string getMessage() const;
    std::string getTimeMills() const;
    std::string getLoggerName() const;
    std::string getStringLevel(int level) const;

    void setLevel(int level);
    void setMessage(std::string message);
    void setTimeMills(std::string timeMills);
    void setLoggerName(std::string loggerName);
        
    LogEvent(std::string logStr, std::string loggerName, int level);
    
    std::string getNowTime();


private:
    int m_level;
    std::string m_message;
    std::string m_timeMills;
    std::string m_loggerName;
};
