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
    private:
        unsigned int hour, minute, second;
};

Time::Time()
{
    hour = minute = second = 0;
}

Time::Time(unsigned int h, unsigned int m, unsigned int s)
{
    hour = h % 24;
    minute = m % 60;
    second = s % 60;
}

void Time::displayTime() const
{
    char fillChar = cout.fill('0');
    cout << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
    cout.fill(fillChar);
}

void Time::displayTimeAMPM() const
{
    unsigned int hourAMPM = hour % 12;
    char fillChar = cout.fill('0');
    if (hourAMPM == 0) hourAMPM += 12;
    cout << hourAMPM << ":" << setw(2) << minute << ":" << setw(2) << second;
    if (hour >= 12) cout << "PM";
    else cout << "AM";
    cout.fill(fillChar);
}

void Time::setTime(unsigned int h, unsigned int m, unsigned int s)
{
    hour = h % 24;
    minute = m % 60;
    second = s % 60;
}

int main()
{
    Time midnight;
    Time section1(11,15,0);
    Time section2(13,25,0);
    Time endOfDay(16,45,0);
    
    cout << "midnight: ";
    midnight.displayTime();
    cout << " - 24H    ";
    midnight.displayTimeAMPM();
    cout << endl;
    
    cout << "section1: ";
    section1.displayTime();
    cout << " - 24H    ";
    section1.displayTimeAMPM();
    cout << endl;
    
    cout << "section2: ";
    section2.displayTime();
    cout << " - 24H    ";
    section2.displayTimeAMPM();
    cout << endl;
    
    cout << "endOfDay: ";
    endOfDay.displayTime();
    cout << " - 24H    ";
    endOfDay.displayTimeAMPM();
    cout << endl;
    
    cout << "Changing endOfDay to 5:30PM" << endl;
    endOfDay.setTime(17,30,00);
    
    cout << "endOfDay: ";
    endOfDay.displayTime();
    cout << " - 24H    ";
    endOfDay.displayTimeAMPM();
    cout << endl;
    
    return 0;
}