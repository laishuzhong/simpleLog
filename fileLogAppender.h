//
//  fileLogAppender.h
//  bulldog_sdk
//
//  Created by laishuzhong on 2023/5/5.
//
#include "LogAppender.h"
#include <fstream>
#include <mutex>
#include <iostream>
class fileLogAppender: public LogAppender {

public:
    fileLogAppender(){};
    ~fileLogAppender(){};
    string getFilePath();
    void setFilePath(string filePath);
    void append(string message);
    void init(const json11::Json& config);

private:
    string m_filename;
    mutex m_mutex;
    ofstream m_ofs;
};
