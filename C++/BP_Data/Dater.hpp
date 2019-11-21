#ifndef Dater_hpp
#define Dater_hpp
#include <stdio.h>
#endif /* Dater_hpp */
class CDater
{
public:
    CDater(void);
    CDater(int y,int m,int d);
private:
    int m_nYear;
    int m_nMonth;
    int m_nDay;
public:
    bool IsLeapYear();
    int TotalDays();
//    bool IsRightDate();
};

