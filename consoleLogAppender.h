//
//  consoleLogAppender.h
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/5.
//
#include "LogAppender.h"
class consoleLogAppender : public LogAppender {

public:
    consoleLogAppender(){};
    ~consoleLogAppender(){};
    void append(string message);
    void init(const json11::Json& config);
    
private:
    
};
