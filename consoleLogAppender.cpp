//
//  consoleLogAppender.cpp
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/5.
//

#include <iostream>
#include "consoleLogAppender.h"

void consoleLogAppender::init(const json11::Json &config) {
    string appenderName = config["name"].string_value();
    setName(appenderName);
}

void consoleLogAppender::append(string message) {
    std::cout << message << std::endl;
}
