#include "Dater.hpp"
CDater::CDater(void)
{
    m_nYear = 0;
    m_nMonth = 0;
    m_nDay = 0;
}
CDater::CDater(int nYear,int nMonth,int nDay)
{
    m_nYear = nYear;
    m_nMonth = nMonth;
    m_nDay = nDay;
}
bool CDater::IsLeapYear()
{
    if((m_nYear % 4 == 0 && m_nYear % 100 != 0)||(m_nYear % 400 == 0))
        return true;
    else
        return false;
}
int CDater::TotalDays()
{
    int nMonthDay = 0;
    int nSum = 0;
    for(int i =1;i<m_nMonth;i++)
    {
        switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                    nMonthDay =31;break;
             case 4:
             case 6:
             case 9:
             case 11:
                    nMonthDay =30;break;
             case 2:
                 {
                    if(IsLeapYear())
                        nMonthDay = 29;
                    else
                        nMonthDay = 28;
                 }
                 break;
        }
        nSum+=nMonthDay;
    }
    return nSum+m_nDay;
}
//bool CDater::IsRightDate()
//{
//    
//}
