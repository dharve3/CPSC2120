#include <iostream>
#include <iomanip>

using namespace std;

class Time
{
    public:
        Time();
        Time(unsigned int h, unsigned int m, unsigned int s);
        void displayTime() const;
        void displayTimeAMPM() const;
        void setTime(unsigned int h, unsigned int m, unsigned int s);
        void setAMPM(bool useAMPM);
        Time operator+(const Time time2) const;
        Time operator-(const Time time2) const;
        friend ostream& operator<<(ostream& out, const Time t);
    private:
        unsigned int second;
        bool ampm;
};

Time::Time() : second(0), ampm(false) {}

Time::Time(unsigned int h, unsigned int m, unsigned int s) : second(h*3600 + m*60 + s), ampm(false) {}

void Time::displayTime() const
{
    unsigned int h = second/3600;
    unsigned int m = second/60 % 60;
    unsigned int s = second % 60;
    char fillChar = cout.fill('0');
    cout << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s;
    cout.fill(fillChar);
}

void Time::displayTimeAMPM() const
{
    unsigned int h = second/3600;
    unsigned int m = second/60 % 60;
    unsigned int s = second % 60;
    unsigned int hourAMPM = h % 12;
    char fillChar = cout.fill('0');
    if (hourAMPM == 0) hourAMPM += 12;
    cout << hourAMPM << ":" << setw(2) << m << ":" << setw(2) << s;
    if (h >= 12) cout << "PM";
    else cout << "AM";
    cout.fill(fillChar);
}

void Time::setTime(unsigned int h, unsigned int m, unsigned int s)
{
    second = h*3600 + m*60 + s;
}

void Time::setAMPM(bool useAMPM)
{
    ampm = useAMPM;
}

Time Time::operator+(const Time time2) const
{
    Time result;
    result.second = (second + time2.second)%86400;
    result.ampm = ampm;
    return result;
}

Time Time::operator-(const Time time2) const
{
    Time result;
    result.second = (second + (86400-time2.second))%86400;
    result.ampm = ampm;
    return result;
}

ostream& operator<<(ostream& out, const Time t)
{
    unsigned int h = t.second/3600;
    unsigned int m = t.second/60 % 60;
    unsigned int s = t.second % 60;
    if (t.ampm)
    {
        unsigned int hourAMPM = h % 12;
        char fillChar = out.fill('0');
        if (hourAMPM == 0) hourAMPM += 12;
        out << hourAMPM << ":" << setw(2) << m << ":" << setw(2) << s;
        if (h >= 12) out << "PM";
        else out << "AM";
        out.fill(fillChar);
    }
    else
    {
        char fillChar = out.fill('0');
        out << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s;
        out.fill(fillChar);
    }
    return out;
}

int main()
{
    Time midnight;
    Time section1(11,15,0);
    Time section2(13,25,0);
    Time endOfDay(16,45,0);
    Time hour(1,0,0);
    
    cout << "midnight: " << midnight;
    midnight.setAMPM(true);
    cout << " - 24H    " << midnight << endl;
    
    cout << "section1: " << section1 << "   section2: " << section2 << "   endOfDay: " << endOfDay << " - 24H" << endl;
    
    section1.setAMPM(true);
    section2.setAMPM(true);
    endOfDay.setAMPM(true);
    
    cout << "section1: " << section1 << "   section2: " << section2 << "   endOfDay: " << endOfDay << endl;
    
    endOfDay = endOfDay + hour;
    
    cout << "section1: " << section1 << "   section2: " << section2 << "   endOfDay (+1 hour): " << endOfDay << endl;
    
    endOfDay = endOfDay - hour;
    
    cout << "section1: " << section1 << "   section2: " << section2 << "   endOfDay: " << endOfDay << endl;
    
    return 0;
}