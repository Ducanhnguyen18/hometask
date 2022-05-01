#include<iostream>
#include<string>
using namespace std;

struct User
{
string login;
string password;

User()
{
login = "DUC_ANH";
password = "1234";
}
};

bool request(string login, string user_login, string user_password)
{
try
{
string password;
int counter = 0;
cout << "Введите пароль" << endl;
cin >> password;
while (true)
{
if (login == user_login && password == user_password)
{
return true;
}
if ((login != user_login || password != user_password) && counter == 3)
{
throw password;
}
else {
cout << "Не верно , давайте попробуем снова" << endl;
cout << endl;
cout << "Введите пароль" << endl;
cin >> password;
counter++;
}
}
}
catch(const string str)
{
cout << "Не верно попыток больше нет" << endl;
return false;
}

}

int main()
{
User us;
bool result;
setlocale(LC_ALL, "ru");
string login;
cout << "Введите логин" << endl;
cin >> login;
result = request(login, us.login, us.password);
if (result == true)
{
cout <<"Поздравляю вы вошли" << endl;
}
return 0;
}
