#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;

struct Date{
  Date(const string &s) {
    string::size_type pos;
    string::size_type pos_day;
    string::size_type pos_month;
    string::size_type pos_year;

    string s_month;
    string s_day;


    if(s.find_first_of("0123456789") == 0){
      pos_month = 0;
      pos = s.find_first_of('/');
      pos_day = pos + 1;
      for(; pos_month != pos; ++pos_month){
        s_month += s[pos_month];
      }
      month = stoi(s_month);
      //cout << month << endl;

      pos = s.find_first_of('/', pos + 1);
      for(; pos_day != pos; ++pos_day)
        s_day += s[pos_day];

      day = stoi(s_day);
      //cout << day << endl;

      pos_year = s.find_first_of("0123456789", pos);
      year = stoi(s.substr(pos_year));
      //cout << year << endl;

    }else{
      pos_day = s.find_first_of("0123456789");
      //cout << pos_day << endl;
      pos = s.find_first_of(',');
      s_month = s.substr(0, pos_day - 1);
      //cout << s[pos_day] << endl;
      string s_day;
      for(; pos_day != pos; ++pos_day){
        s_day += s[pos_day];
      }
      //cout << s_day <<endl;
      day = stoi(s_day);
      //cout << day << endl;
      //cout << pos << endl;
      pos_year = s.find_first_of("0123456789", pos);
      //cout << pos_year << endl;
      //cout << s.substr(pos_year) << endl;
      year = stoi(s.substr(pos_year));
      //cout << year << endl;
      //cout << s_month << endl;
      vector<string> months{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
      for(string::size_type i = 0; i != months.size(); ++i){
        //cout << months[i] << endl;
        //cout << months[i].find(s_month) << endl;
        if((months[i].find(s_month)) != string::npos){
          //cout << months[i] << endl;
          month = i + 1;
          break;
        }
      }
      //cout << month << endl;
      //string sa = "Mar";
      //cout << months[2].find(s_month) << endl;
    }
  }
  unsigned year = 0;
  unsigned month = 0;
  unsigned day = 0;
};

int main(int argc, char const *argv[]) {
  Date date("January 1, 1900");
  cout << date.year << endl;
  cout << date.month << endl;
  cout << date.day << endl;
  return 0;
}
