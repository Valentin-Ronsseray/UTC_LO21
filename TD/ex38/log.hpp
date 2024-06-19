#if !defined(LOG_H)
#define LOG_H

#include "evenement.hpp"
#include "timing.h"
#include <iostream>

using namespace std;
using namespace TIME;


class Log {
public:
    virtual void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string& s) = 0;
    virtual void displayLog(std::ostream& f) const = 0;
};

class MyLog : public Log, private TIME::Agenda {
private:
    Agenda evts;
public:
    void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string& s);
    void displayLog(std::ostream& f = std::cout);
};

class LogError : public exception
{
private:
    string info;
public:
    LogError(const char* s) noexcept : info(s) {}
    ~LogError() {}
    const char* what() const noexcept {return info.c_str();}
    
};


#endif