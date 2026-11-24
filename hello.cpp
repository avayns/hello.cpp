#include <iostream>
#include <string>
#include <ctime>
#include "CLI11.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    CLI::App app{"Мое приложение"};

    std::string userName = "странник";
    int year = 0;
    app.add_option("-n,--name", userName, "имя пользователя");
    app.add_option("-y,--year", year, "год рождения");

    CLI11_PARSE(app, argc, argv);

    auto t = time(nullptr);
    auto lt = localtime(&t);
    int currentYear = lt->tm_year + 1900;

    cout << "Привет, " << userName << endl;
    if (year > 0) {
        cout << "ты родился в " << year << " году" << endl
             << "тебе " << currentYear - year << " лет" << endl;
    }
    return 0;
}
