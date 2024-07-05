#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include<filesystem>

using namespace std;




void hello()
{

    cout << R"(

                 ___====-_  _-====___
           _--^^^#####//      \\#####^^^--_
        _-^##########// (    ) \\##########^-_
       -############//  |\^^/|  \\############-
     _/############//   (@::@)   \\############\_
    /#############((     \\//     ))#############\
   -###############\\    (oo)    //###############-
  -#################\\  / VV \  //#################-
 -###################\\/      \//###################-
_#/|##########/\######(   /\   )######/\##########|\#_
|/ |#/\#/\#/\/  \#/\##\  |  |  /##/\#/  \/\#/\#/\#| \|
`  |/  V  V  `   V  \#\| |  | |/#/  V   '  V  V  \|  '
   `   `  `      `   / | |  | | \   '      '  '   '
                    (  | |  | |  )
                   __\ | |  | | /__
                  (vvv(VVV)(VVV)vvv)

 )";
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "ПРИВЕТСТУЮ ВАС ПОЛЬЗОВАТЕЛЬ ВЫ ВОШЛИ В ЧАТ!" << endl;
    cout << "Это старый долг:" << endl;
    cout << "Применение к классам User и Messege" << endl;
    cout << "Библиотек filesystem и fstream для записи и извлечения" << endl;
    cout << "Мне следовало сдать его раньше" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
};



class User
{
private:
    string name_p;
    string password_p;

public:

    User()//
    {
        name_p = " ";
        password_p = " ";
    };


    User(const string& name, const string& password) :name_p(name), password_p(password)
    {};


    string& getName()
    {
        return name_p;
    };

    string& getPassword()
    {
        return password_p;
    };

};


template<typename T>
class Memory
{
private:
    vector<T>data;
public:
    void AddSms(const T& value)
    {
        data.push_back(value);
    };


    void Display()
    {

        for (const auto& item : data)
        {


           /* cout << "В чате есть сообщение!!! Кому: " << item.getRecepient() << ". От кого: " << item.getSend() << endl;
            cout << "Cообщение: " << "" << item.getText() << "" << endl;*/

        }

    };

};


class Message
{
private:
    string recepient_p; /*кому*/
    string send_p;/* кто*/
    string text_p; /*текст смс*/
public:


    Message()
    {
        recepient_p = " ";
        send_p = " ";
        text_p = " ";
    }

    Message(const string& recepient, const string& send, const string& text) :recepient_p(recepient), send_p(send), text_p(text)
    {};

  const  string& getRecepient() const { // Добавлен модификатор const
        return recepient_p;
    }

  const  string& getSend() const { // Добавлен модификатор const
        return send_p;
    }

   const string& getText() const { // Добавлен модификатор const
        return text_p;
    }
};



class Chat
{
    Memory<Message>messages;
public:
    //функцией берём данные
    void sendMessage(const string& recepient, const string& send, const string& text)
    {
        //создаём обьект другого класса и наполняем
        Message message1(recepient, send, text);

        messages.AddSms(message1);//помещаем в массив

    };

    void DisplayMessages()
    {
        messages.Display();
    };
};




int main()
{
    system("chcp 1251");

    hello();

    User* currentUser = nullptr;

    string username, password;

    vector<User>Tolpa;

    cout << "Регистрация\n";
    cout << "Введите логин: " << endl;
    cin >> username;
    cout << "Введите пароль: " << endl;
    cin >> password;
    User First(username, password);
    Tolpa.push_back(First);
    cout << "Вы успешно зарегистрировались!Теперь войдите в аккаунт." << endl;

    cout << " \n";
    cout << "Выберите действие:\n ";

    cout << "1. Послать сообщение\n";

    cout << "2. Войти в существующий аккаунт\n";

    cout << "3. Создать новый аккаунт\n";

    cout << "4. Выход из аккаунта\n";

    cout << "5. Посмотреть свои логин и пароль и исторю своих сообщений\n";

    cout << "6. Завершить\n";

    cout << " \n";

    cout << "В дальнейшем пользуйтесь этими кнопками" << endl;





    Chat chat;
    int choice;

    do {
        cin >> choice;
        switch (choice)
        {///////////
            {
        case 1:
            if (currentUser != nullptr) { // только если пользователь вошел
                string recipient, text;
                cout << "Введите получателя: ";
                cin >> recipient;
                cout << "Введите текст сообщения: ";
                cin.ignore();
                getline(cin, text);

                //начало записи в блокнот
                string fileName = "HistoryMessegeUser_" + currentUser->getName() + ".txt";
               std::filesystem::path filePath = std::filesystem::current_path() / fileName;
                
                    ofstream HistoryMessege(filePath, std::ios::app );//запись данных юзера
                    if (HistoryMessege.is_open())
                    {
                        HistoryMessege << "Кому: " << recipient << "." << " Cообщение: " << text << "." << " От кого: " << currentUser->getName() << endl;
                    }
                    else
                    {
                        cout << "Файл не создан" << endl;
                    }
                    HistoryMessege.close();

                    //запись данных смс в файл
                //права на этот блокнот
                    std::filesystem::permissions(filePath, std::filesystem::perms::owner_read | std::filesystem::perms::owner_write);

                //права на этот блокнот



                    string fileName1 = "HistoryUser_" + currentUser->getName() + ".txt";
                    std::filesystem::path filePath1 = std::filesystem::current_path() / fileName1;

                    // Пытаемся открыть файл для записи
                    ofstream HistoryUser(filePath1, std::ios::app);
                    if (HistoryUser.is_open())
                    {
                        HistoryUser << "Ваши логин и пароль" << endl;
                        HistoryUser << "Логин: " << currentUser->getName() << endl;
                        HistoryUser << "Пароль: " << currentUser->getPassword() << endl;
                        HistoryUser.close(); // Закрываем файл после записи
                    }
                    else
                    {
                        cout << "Файл не создан" << endl;
                    }

                    // Устанавливаем права на файл
                    std::filesystem::permissions(filePath1, std::filesystem::perms::owner_read | std::filesystem::perms::owner_write);











                chat.sendMessage(recipient, currentUser->getName(), text);
                cout << "Сообщение отправлено!\n";
                cout << " \n";
                cout << " \n";
            }
            else {
                cout << "Вы не вошли в систему. Сначала войдите в свой аккаунт нажав 2.\n";
            }
            break;
            }


            {
        case 2:
            cout << "Вход в существующий аккаунт\n" << endl;
            string username1, password1;
            cout << "Введите логин: " << endl;
            cin >> username1;
            cout << "Введите пароль: " << endl;
            cin >> password1;



            for (int k = 0; k < Tolpa.size(); k++) {
                User* user = &Tolpa[k]; // Получаем указатель на пользователя
                if (user != nullptr && user->getName() == username1 && user->getPassword() == password1)
                {
                    currentUser = user; // Устанавливаем currentUser напрямую
                    cout << "Вы успешно вошли в аккаунт!" << endl;
                    chat.DisplayMessages();
                    break;
                }
            }
            if (currentUser == nullptr) {
                cout << "Неправильный логин или пароль." << endl;
            }
            break;
            }



            {
        case 3:
            cout << "Регистрация\n";
            cout << "Введите логин: " << endl;
            cin >> username;
            cout << "Введите пароль: " << endl;
            cin >> password;


            User newUser(username, password);
           

            Tolpa.push_back(newUser);  //тут использован стл

            int lastuser = Tolpa.size() - 1;


            currentUser = &Tolpa.at(lastuser); //изменено с использованием стл
            cout << "Вы успешно зарегистрировались!" << endl;
            cout << "  " << endl;
  
            break;
            }

            {
        case 4:
            currentUser = nullptr;
            cout << "Выход выполнен. Войдите в существующий аккаунт нажав 2 или зарегестрируйтесь нажав 3\n";
            cout << " \n";
            cout << " \n";
            break;
            }


            {
        case 5:
                   // тут даём юзеру возможность заглянуть в свои файлы
            if (currentUser != nullptr)
            {
                string fileName1 = "HistoryUser_" + currentUser->getName() + ".txt";
                std::filesystem::path filePath1 = std::filesystem::current_path() / fileName1;

                ifstream HistoryUser(filePath1);
                if (HistoryUser.is_open())
                {
                    string line;
                    while (getline(HistoryUser, line))
                    {
                        cout << line << std::endl;
                    }
                    HistoryUser.close();
                }
                else
                {
                    cout << "Не удалось открыть файл HistoryUser_" << currentUser->getName() << ".txt" << endl;
                }

                string fileName2 = "HistoryMessegeUser_" + currentUser->getName() + ".txt";
                std::filesystem::path filePath2 = std::filesystem::current_path() / fileName2;

                ifstream HistoryMessegeUser(filePath2);
                if (HistoryMessegeUser.is_open())
                {
                    string line;
                    while (getline(HistoryMessegeUser, line))
                    {
                        cout << line << std::endl;
                    }
                    HistoryMessegeUser.close();
                }
                else
                {
                    cout << "Не удалось открыть файл HistoryMessegeUser_" << currentUser->getName() << ".txt" << endl;
                }

                cout << "Вы посмотрели свой логин и пароль и историю своих сообщений\n";
            }
            else
            {
                cout << "Вы не вошли в систему. Сначала войдите в свой аккаунт нажав 2.\n";
            }
               
         
            break;
            }




            {
        case 6:

            cout << "Вы выполнили учебный выход из чата\n";
            cout << "В будущем эта кнопка будет закрывть всю консоль\n";
            cout << "А пока - это только учебный проект" << endl;
            break;
            }



        default:
            cout << "Вы ввели неправильное значение" << endl;
            break;

        }//////

    } while (choice != 6);


    return 0;
}









