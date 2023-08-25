//
//  fileLogAppender.cpp
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/5.
//

#include "fileLogAppender.h"

void fileLogAppender::init(const json11::Json &config) {
    string appenderName = config["name"].string_value();
    string filePath = config["fileName"].string_value();
    setName(appenderName);
    setFilePath(filePath);
}

void fileLogAppender::setFilePath(string filePath) {
    m_filename = filePath;
}

string fileLogAppender::getFilePath() {
    return m_filename;
}

void fileLogAppender::append(string message) {
    std::cout << message << " should be saved in file." << std::endl;
    m_ofs.open(m_filename, std::ios::out | std::ios::app);
    std::lock_guard<std::mutex> lock(m_mutex);
    m_ofs << message << std::endl;
    m_ofs.close();
}
