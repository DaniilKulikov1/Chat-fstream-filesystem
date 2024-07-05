#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include<filesystem>

using namespace std;




void hello()
{

    cout << R"(

� � � � � � � � �___====-_ �_-====___
� � � � � �_--^^^#####// � � �\\#####^^^--_
� � � � _-^##########// ( � �) \\##########^-_
� � � �-############// �|\^^/| �\\############-
� � �_/############// � (@::@) � \\############\_
� � /#############(( � � \\// � � ))#############\
� �-###############\\ � �(oo) � �//###############-
� -#################\\ �/ VV \ �//#################-
�-###################\\/ � � �\//###################-
_#/|##########/\######( � /\ � )######/\##########|\#_
|/ |#/\#/\#/\/ �\#/\##\ �| �| �/##/\#/ �\/\#/\#/\#| \|
` �|/ �V �V �` � V �\#\| | �| |/#/ �V � ' �V �V �\| �'
� �` � ` �` � � �` � / | | �| | \ � ' � � �' �' � '
� � � � � � � � � � ( �| | �| | �)
� � � � � � � � � �__\ | | �| | /__
� � � � � � � � � (vvv(VVV)(VVV)vvv)

�)";
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "���������� ��� ������������ �� ����� � ���!" << endl;
    cout << "��� ������ ����:" << endl;
    cout << "���������� � ������� User � Messege" << endl;
    cout << "��������� filesystem � fstream ��� ������ � ����������" << endl;
    cout << "��� ��������� ����� ��� ������" << endl;
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


           /* cout << "� ���� ���� ���������!!! ����: " << item.getRecepient() << ". �� ����: " << item.getSend() << endl;
            cout << "C��������: " << "" << item.getText() << "" << endl;*/

        }

    };

};


class Message
{
private:
    string recepient_p; /*����*/
    string send_p;/* ���*/
    string text_p; /*����� ���*/
public:


    Message()
    {
        recepient_p = " ";
        send_p = " ";
        text_p = " ";
    }

    Message(const string& recepient, const string& send, const string& text) :recepient_p(recepient), send_p(send), text_p(text)
    {};

  const  string& getRecepient() const { // �������� ����������� const
        return recepient_p;
    }

  const  string& getSend() const { // �������� ����������� const
        return send_p;
    }

   const string& getText() const { // �������� ����������� const
        return text_p;
    }
};



class Chat
{
    Memory<Message>messages;
public:
    //�������� ���� ������
    void sendMessage(const string& recepient, const string& send, const string& text)
    {
        //������ ������ ������� ������ � ���������
        Message message1(recepient, send, text);

        messages.AddSms(message1);//�������� � ������

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

    cout << "�����������\n";
    cout << "������� �����: " << endl;
    cin >> username;
    cout << "������� ������: " << endl;
    cin >> password;
    User First(username, password);
    Tolpa.push_back(First);
    cout << "�� ������� ������������������!������ ������� � �������." << endl;

    cout << " \n";
    cout << "�������� ��������:\n ";

    cout << "1. ������� ���������\n";

    cout << "2. ����� � ������������ �������\n";

    cout << "3. ������� ����� �������\n";

    cout << "4. ����� �� ��������\n";

    cout << "5. ���������� ���� ����� � ������ � ������ ����� ���������\n";

    cout << "6. ���������\n";

    cout << " \n";

    cout << "� ���������� ����������� ����� ��������" << endl;





    Chat chat;
    int choice;

    do {
        cin >> choice;
        switch (choice)
        {///////////
            {
        case 1:
            if (currentUser != nullptr) { // ������ ���� ������������ �����
                string recipient, text;
                cout << "������� ����������: ";
                cin >> recipient;
                cout << "������� ����� ���������: ";
                cin.ignore();
                getline(cin, text);

                //������ ������ � �������
                string fileName = "HistoryMessegeUser_" + currentUser->getName() + ".txt";
               std::filesystem::path filePath = std::filesystem::current_path() / fileName;
                
                    ofstream HistoryMessege(filePath, std::ios::app );//������ ������ �����
                    if (HistoryMessege.is_open())
                    {
                        HistoryMessege << "����: " << recipient << "." << " C��������: " << text << "." << " �� ����: " << currentUser->getName() << endl;
                    }
                    else
                    {
                        cout << "���� �� ������" << endl;
                    }
                    HistoryMessege.close();

                    //������ ������ ��� � ����
                //����� �� ���� �������
                    std::filesystem::permissions(filePath, std::filesystem::perms::owner_read | std::filesystem::perms::owner_write);

                //����� �� ���� �������



                    string fileName1 = "HistoryUser_" + currentUser->getName() + ".txt";
                    std::filesystem::path filePath1 = std::filesystem::current_path() / fileName1;

                    // �������� ������� ���� ��� ������
                    ofstream HistoryUser(filePath1, std::ios::app);
                    if (HistoryUser.is_open())
                    {
                        HistoryUser << "���� ����� � ������" << endl;
                        HistoryUser << "�����: " << currentUser->getName() << endl;
                        HistoryUser << "������: " << currentUser->getPassword() << endl;
                        HistoryUser.close(); // ��������� ���� ����� ������
                    }
                    else
                    {
                        cout << "���� �� ������" << endl;
                    }

                    // ������������� ����� �� ����
                    std::filesystem::permissions(filePath1, std::filesystem::perms::owner_read | std::filesystem::perms::owner_write);











                chat.sendMessage(recipient, currentUser->getName(), text);
                cout << "��������� ����������!\n";
                cout << " \n";
                cout << " \n";
            }
            else {
                cout << "�� �� ����� � �������. ������� ������� � ���� ������� ����� 2.\n";
            }
            break;
            }


            {
        case 2:
            cout << "���� � ������������ �������\n" << endl;
            string username1, password1;
            cout << "������� �����: " << endl;
            cin >> username1;
            cout << "������� ������: " << endl;
            cin >> password1;



            for (int k = 0; k < Tolpa.size(); k++) {
                User* user = &Tolpa[k]; // �������� ��������� �� ������������
                if (user != nullptr && user->getName() == username1 && user->getPassword() == password1)
                {
                    currentUser = user; // ������������� currentUser ��������
                    cout << "�� ������� ����� � �������!" << endl;
                    chat.DisplayMessages();
                    break;
                }
            }
            if (currentUser == nullptr) {
                cout << "������������ ����� ��� ������." << endl;
            }
            break;
            }



            {
        case 3:
            cout << "�����������\n";
            cout << "������� �����: " << endl;
            cin >> username;
            cout << "������� ������: " << endl;
            cin >> password;


            User newUser(username, password);
           

            Tolpa.push_back(newUser);  //��� ����������� ���

            int lastuser = Tolpa.size() - 1;


            currentUser = &Tolpa.at(lastuser); //�������� � �������������� ���
            cout << "�� ������� ������������������!" << endl;
            cout << "  " << endl;
  
            break;
            }

            {
        case 4:
            currentUser = nullptr;
            cout << "����� ��������. ������� � ������������ ������� ����� 2 ��� ����������������� ����� 3\n";
            cout << " \n";
            cout << " \n";
            break;
            }


            {
        case 5:
                   // ��� ��� ����� ����������� ��������� � ���� �����
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
                    cout << "�� ������� ������� ���� HistoryUser_" << currentUser->getName() << ".txt" << endl;
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
                    cout << "�� ������� ������� ���� HistoryMessegeUser_" << currentUser->getName() << ".txt" << endl;
                }

                cout << "�� ���������� ���� ����� � ������ � ������� ����� ���������\n";
            }
            else
            {
                cout << "�� �� ����� � �������. ������� ������� � ���� ������� ����� 2.\n";
            }
               
         
            break;
            }




            {
        case 6:

            cout << "�� ��������� ������� ����� �� ����\n";
            cout << "� ������� ��� ������ ����� �������� ��� �������\n";
            cout << "� ���� - ��� ������ ������� ������" << endl;
            break;
            }



        default:
            cout << "�� ����� ������������ ��������" << endl;
            break;

        }//////

    } while (choice != 6);


    return 0;
}









