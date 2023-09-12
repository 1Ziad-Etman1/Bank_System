#include <bits/stdc++.h>
using namespace std;

string file_name;

class Client;
class Bank_account;
class Saving_bank_account;
class user;
class special_user;
class Bank_application;
class IDGenerator;



class IDGenerator
{
protected:
    string s;
    int i;
public:
    IDGenerator(){}
    IDGenerator(string _s, int _i)
    {
        s = _s;
        i = _i;
    }
    void set_num(int _i)
    {
        i = _i;
    }
    int get_num ()
    {
        return i;
    }
    void set_s(string _s)
    {
        s = _s;
    }
    string get_s ()
    {
        return s;
    }
    string nextLabel()
    {
        i+=1;
        string label = s;
        label = s + to_string(i);
        return label;
    }
    string current_label()
    {
        string label = s + to_string(i);
    }
};
IDGenerator u_id;
IDGenerator su_id;
//Client //......................................................................................................
class Client
{
private:
    string ID;
    string name;
    string address;
    string phone_num;

public:
    // Client() = default;
    Client (){}
    Client(string _name, string _address, string _phone, string _ID);
    void set_values(string _name, string _address, string _phone, string _ID);
    void set_name(string _name);
    void set_address(string _address);
    void set_phone(string _phone_num);
    void set_ID(string _ID);
    string get_name();
    string get_address();
    string get_phone();
    string get_ID();
};

Client::Client(string _name, string _address, string _phone, string _ID)
{
    name = _name;
    address = _address;
    phone_num = _phone;
    ID = _ID;
}

void Client::set_name(string _name)
{
    name = _name;
}

void Client::set_values(string _name, string _address, string _phone, string _ID)
{
    name = _name;
    address = _address;
    phone_num = _phone;
    ID = _ID;
}

void Client::set_address(string _address)
{
    address = _address;
}

void Client::set_phone(string _phone_num)
{
    phone_num = _phone_num;
}

void Client::set_ID(string _ID)
{
    ID = _ID;
}

string Client::get_name()
{
    return name;
}

string Client::get_address()
{
    return address;
}

string Client::get_phone()
{
    return phone_num;
}

string Client::get_ID()
{
    return ID;
}

// bank account //......................................................................................................
class Bank_account{

protected:
    double balance ;

public:

    Bank_account(double _balance);
    Bank_account();
    void set_balance(double _balance);
    double get_balance();
    void with_draw(double _withdraw);
    void deposit (double _deposit);
};

Bank_account::Bank_account(double _balance) {
    balance =_balance;
}

Bank_account::Bank_account() {
    balance = 0;
}

double Bank_account::get_balance() {
    return balance;
}

void Bank_account::set_balance(double _balance) {
    balance = _balance;
}

void Bank_account::with_draw(double _withdraw){
    if (_withdraw > balance)
    {
        cout << "\nyour balance is just " << balance << "  you can't withdraw! \n";
    }
    else
    {
        balance = balance - _withdraw;
    }
}

void Bank_account::deposit (double _deposit){
    balance = balance + _deposit;
}






//saving bank account//......................................................................................................
class Saving_bank_account : public Bank_account{

private:

    double min_balance = 1000;

public:
    Saving_bank_account(){}
    Saving_bank_account (double _balance);
    double get_min_balance();
    void with_draw2(double _withdraw);
    void deposit2 (double _deposit);

};

Saving_bank_account::Saving_bank_account(double _balance){
    balance = _balance;
    min_balance = 1000;
}

double Saving_bank_account::get_min_balance(){
    return min_balance;
}

void Saving_bank_account::with_draw2(double _withdraw){
    if (balance - _withdraw > 1000){
        balance -= _withdraw;
    }
    else {
        cout << "Sorry your minimum balance is 1000 \nYou can't withdraw more than "<<(balance - 1000)<<endl;
    }
}

void Saving_bank_account::deposit2 (double _deposit){
    if (_deposit >= 100){
        balance += _deposit;
    }
    else{
        cout << "Sorry the minimum money to deposit in saving account is 100"<<endl;
    }
}

//......................................................................................................

class user
{
private:
    Client C;
    Bank_account B;
public:
    user(Client &_C, Bank_account& _B)
    {
        C=_C;
        B=_B;
    }
    void operator=(Client& f)
    {
        C.set_name(f.get_name());
        C.set_address(f.get_address());
        C.set_phone(f.get_phone());
        C.set_ID(f.get_ID());
    }

    void set_client(Client& _C)
    {
        C=_C;
    }
    void set_bank_account(Bank_account& _B)
    {
        B=_B;
    }
    Client get_client()
    {
        return C;
    }
    Bank_account get_bank_account()
    {
        return B;
    }
    string user_data()
    {
        string s="" ;

        s= s + "username :";
        s= s + C.get_name();
        s= s + "\naddress :";
        s= s + C.get_address();
        s= s + "\nphone number :";
        s= s + C.get_phone();
        s= s + "\ncurrent balance :";
        s= s + to_string(B.get_balance());
        s= s + "\nID :";
        s= s + C.get_ID();

        return s;
    }
    void with_draw(double _b)
    {
        B.with_draw(_b);
    }

    void depo_sit(double _b)
    {
        B.deposit(_b);
    }

};

class special_user
{
private:
    Client C;
    Saving_bank_account B;
public:
    special_user(Client& _C, Saving_bank_account& _B)
    {
        C=_C;
        B=_B;
    }
    void operator=(Client& f)
    {
        C.set_name(f.get_name());
        C.set_address(f.get_address());
        C.set_phone(f.get_phone());
        C.set_ID(f.get_ID());
    }

    void set_client(Client& _C)
    {
        C=_C;
    }
    void set_bank_account(Saving_bank_account _B)
    {
        B=_B;
    }
    Client get_client()
    {
        return C;
    }
    Saving_bank_account get_bank_account()
    {
        return B;
    }
    string user_data()
    {
        string s="" ;

        s= s + "username :";
        s= s + C.get_name();
        s= s + "\naddress :";
        s= s + C.get_address();
        s= s + "\nphone number :";
        s= s + C.get_phone();
        s= s + "\ncurrent balance :";
        s= s + to_string(B.get_balance());
        s= s + "\nID :";
        s= s + C.get_ID();

        return s;
    }

    void with_draw(double _b)
    {
        B.with_draw2(_b);
    }

    void depo_sit(double _b)
    {
        B.deposit2(_b);
    }
};

//...................................................................................................................
class Bank_application{
private:

    double in_out;
    vector<user>users;
    vector<special_user>special_users;
    vector<string> data;
public:

    bool check_if_num(string s);
    void set_in_out(double _in_out);
    double get_in_out();
    void system_manger();
    Client creat_account(int i);
    Bank_account create_bank_account();
    Saving_bank_account create_saving_bank_account();
    user add_user(Client x, Bank_account y);
    special_user add_special_user(Client x, Saving_bank_account y);
    void add_user_to_data(string s);
    void print_data(vector<string> _data);
    void load_file(vector<string>& text, fstream& file);
    void save_to_file(vector<string>& text, fstream& file);
    void turn_text_into_data(vector<string>& text);
    bool check_valid_user_id(string id);
    bool check_valid_special_user_id(string id);
    void refill_vector();
};


bool Bank_application::check_if_num(string s)
{
    for (int i=0 ; i<s.size() ; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}




void Bank_application ::set_in_out(double _in_out) {
    in_out = _in_out;
}

double Bank_application::get_in_out() {

    return in_out;

}
Client Bank_application::creat_account(int i){
    string name;
    string address;
    string phone;
    string ID;
    Client User;
    cout << "Please Enter Client Name \n";

    getline(cin,name);
    cin.ignore();


    cout << "Please Enter Client Address \n";
    getline(cin,address);
    cin.ignore();

    cout << "Please Enter Client phone number \n";
    cin >> phone;
    cin.ignore();

    if (i == 1)
    {
        string id = u_id.nextLabel();
        User.set_values(name,address,phone,id);
        cout << id;
    }
    else if (i == 2)
    {
        string id = su_id.nextLabel();
        User.set_values(name,address,phone,id);
        cout << id;
    }

    return User;

}


Bank_account Bank_application::create_bank_account(){
    double _balance ;
    string s;
    cout << "\nEnter the Balance you want to start with : ";
    cin >> s;
    cin.ignore();
    while (true)
    {
        if (check_if_num(s))
        {
            _balance = stod(s);
            break;
        }
        else
        {
            cout << "Invalid input!!  Please try again\n";
            cout << "\nEnter the Balance you want to start with : ";
            cin >> s;
            cin.ignore();
            continue;
        }
    }
    Bank_account b(_balance);
    return b;

}

Saving_bank_account Bank_application::create_saving_bank_account(){
    double _balance ;
    string s;
    cout << "\nEnter the Balance you want to start with : ";
    cin >> s;
    cin.ignore();
    while (true)
    {
        if (check_if_num(s))
        {
            _balance = stod(s);
            if (_balance < 1000)
            {
                cout << "Your min balance must be 1000 L.E or more , try again\nEnter your balance : ";
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            cout << "Invalid input!!  Please try again\n";
            cout << "\nEnter the Balance you want to start with : ";
            cin >> s;
            cin.ignore();
            continue;
        }
    }
    while (_balance<1000){
        cout << "Your min balance must be 1000 L.E or more , try again\nEnter your balance : ";
        cin >> _balance;
        cin.ignore();
    }

    Saving_bank_account b(_balance);
    return b;
}

user Bank_application::add_user(Client _C, Bank_account _B)
{
    user x(_C, _B);
    return x;
}

special_user Bank_application::add_special_user(Client _C, Saving_bank_account _B)
{
    special_user x(_C, _B);
    return x;
}

void Bank_application::add_user_to_data(string s)
{
    data.push_back(s);
}

void Bank_application::refill_vector()
{
    vector<string> vec;
    data = vec;
    for (int i=0 ; i<users.size() ; i++)
    {
        add_user_to_data(users[i].user_data());
    }
    for (int i=0 ; i<special_users.size() ; i++)
    {
        add_user_to_data(special_users[i].user_data());
    }

}

void Bank_application::print_data(vector<string> _data)
{
    char line[100];
    cout<< endl;
    for (string line: _data)
    {
        cout << line << endl;
    }
    cout << endl ;
}

void Bank_application::load_file(vector<string>& text, fstream& file)
{
    vector<string> text1;
    u_id.set_s("u");
    u_id.set_num(1);
    su_id.set_s("su");
    su_id.set_num(1);
    char line[100];
    file.open(file_name,ios::in);
    if (file) {
        while (!file.eof()) {
            file.getline(line, 100, '\n');
            text.push_back(string(line));
        }

    }
    file.close();
    file.open(file_name,ios::in);
    if (file) {
        while (!file.eof()) {
            file.getline(line, 100, '\n');
            text1.push_back(string(line));
        }

    }

    int n = text1.size();
    for (int i = 0; i < n; i+= 5) {
        if (i>=n)
        {
            break;
        }
        // _______________________name_______________________
        int pos = text1[i].find(':');
        int pos2 = text1[i].find('\n');

        text1[i].erase(0, pos + 1);

        string name = text1[i].substr(0, pos2);

        // _______________________address____________________

         pos = text1[i+1].find(':');
         pos2 = text1[i+1].find('\n');

        text1[i+1].erase(0, pos + 1);

        string address = text1[i+1].substr(0, pos2);

        // _______________________phone______________________

         pos = text1[i+2].find(':');
         pos2 = text1[i+2].find('\n');

        text1[i+2].erase(0, pos + 1);

        string phone = text1[i+2].substr(0, pos2);

        // _______________________Balance____________________

         pos  = text1[i+3].find(':');
         pos2 = text1[i+3].find('\n');

        text1[i+3].erase(0, pos + 1);

        double balance = atof(text1[i+3].substr(0, pos2).c_str());

        //________________________ID_________________________

         pos  = text1[i+4].find(':');
         pos2 = text1[i+4].find('\n');

        text1[i+4].erase(0, pos + 1);

        string ID = text1[i+4].substr(0, pos2);
        if (ID[0]=='u')
        {
            u_id.set_num(ID[1]-'0');

            Client C(name,address,phone,ID);
            Bank_account B(balance);

            users.push_back(add_user(C,B));
        }
        else if(ID[0]=='s')
        {
            su_id.set_num(ID[2]-'0');

            Client C(name,address,phone,ID);
            Saving_bank_account B(balance);

            special_users.push_back(add_special_user(C,B));
        }

    }

    file.close();
}




void Bank_application::save_to_file(vector<string>& text, fstream& file)
{
    file.close();
    file.open(file_name, ios::out);

    for (int i = 0; i< text.size() ; i++)
    {
        file << text[i];
        file << '\n';

    }
    file.close();
}

bool Bank_application::check_valid_user_id(string id)
{
    bool x = false;
    for (int i =0 ; i < users.size() ; i++)
    {
        if (id == users[i].get_client().get_ID())
        {
            x=true;
            break;
        }
    }
    return x;
}

bool Bank_application::check_valid_special_user_id(string id)
{
    bool x = false;
    for (int i =0 ; i < users.size() ; i++)
    {
        if (id == special_users[i].get_client().get_ID())
        {
            x = true;
            break;
        }
    }
    return x;
}


void Bank_application::system_manger(){
    fstream database;
    file_name = "users.txt";
    load_file(data, database);
    while (true){
        char choice ;
        cout <<"\n\nWelcome to FCAI Banking Application \n\n"
               "1. Create a New Account \n"
               "2. List Clients and Accounts \n"
               "3. Withdraw Money \n"
               "4. Deposit Money\n"
               "5. Exit\n"
               "Please Enter Choice : ";

        cin >> choice;
        cin.ignore();


        while (choice < '1' || choice > '5'){
            cout << "\n\nWrong input please try again\n";

            cout <<
                 "1. Create a New Account \n"
                 "2. List Clients and Accounts \n"
                 "3. Withdraw Money \n"
                 "4. Deposit Money\n"
                 "Please Enter Choice : ";
            cin >> choice;
            cin.ignore();

        }


        if (choice == '1'){

            char _choice;
            while(true)
            {
                cout << "\nEnter the account type \n1.Normal \n2.Saving bank account\n";
                cin >> _choice;
                cin.ignore();
                if (_choice=='1'){
                    Client x =creat_account(1);
                    Bank_account y=create_bank_account();
                    users.push_back(add_user(x,y));
                    add_user_to_data(add_user(x,y).user_data());
                    refill_vector();
                    save_to_file(data,database);
                    break;
                }
                else if (_choice=='2'){
                    Client x =creat_account(2);
                    Saving_bank_account y = create_saving_bank_account();
                    special_users.push_back(add_special_user(x,y));
                    add_user_to_data(add_special_user(x,y).user_data());
                    refill_vector();
                    save_to_file(data,database);
                    break;
                }
                else
                {
                    cout << "Invalid input!! Try again\n";
                    continue;
                }
            }

        }


        else if(choice == '2')
        {
            print_data(data);
        }


        else if(choice == '3')
        {
            string id;
            string s;
            while (true)
            {
                string id;
                cout << "Enter your ID: ";
                cin >> id;
                cin.ignore();
                if (check_valid_user_id(id))
                {
                    cout << "Enter the amount you wanna withdraw :";
                    cin >> s;
                    cin.ignore();
                    while (true)
                    {
                        if (check_if_num(s))
                        {
                            in_out = stod(s);
                            break;
                        }
                        else
                        {
                            cout << "Invalid input!!  Please try again\n";
                            cout << "Enter the amount you wanna withdraw :";
                            cin >> s;
                            cin.ignore();
                            continue;
                        }
                    }

                    users[id[1]-'0'-1].with_draw(in_out);
                    refill_vector();
                    save_to_file(data,database);
                    break;
                }
                else if (check_valid_special_user_id(id))
                {
                    cout << (int(id[2])-int('0')-1) << endl;
                    cout << "Enter the amount you wanna withdraw :";
                    cin >> s;
                    cin.ignore();
                    while (true)
                    {
                        if (check_if_num(s))
                        {
                            in_out = stod(s);
                            break;
                        }
                        else
                        {
                            cout << "Invalid input!!  Please try again\n";
                            cout << "Enter the amount you wanna withdraw :";
                            cin >> s;
                            cin.ignore();
                            continue;
                        }
                    }
                    special_users[int(id[2])-int('0')-1].with_draw(in_out);
                    refill_vector();
                    save_to_file(data,database);
                    break;
                }
                else
                {
                    cout << "invalid id!!\nTry again\n";
                    continue ;
                }
            }
        }



        else if(choice == '4')
        {
            string s;
            while (true)
            {
                string id;
                cout << "Enter your ID: ";
                cin >> id;
                cin.ignore();
                if (check_valid_user_id(id))
                {
                    cout << "Enter the amount you wanna deposit :";
                    cin >> s;
                    cin.ignore();
                    while (true)
                    {
                        if (check_if_num(s))
                        {
                            in_out = stod(s);
                            break;
                        }
                        else
                        {
                            cout << "Invalid input!!  Please try again\n";
                            cout << "Enter the amount you wanna deposit :";
                            cin >> s;
                            cin.ignore();
                            continue;
                        }
                    }
                    users[id[1]-'0'-1].depo_sit(in_out);
                    refill_vector();
                    save_to_file(data,database);
                    break;
                }
                else if (check_valid_special_user_id(id))
                {
                    cout << "Enter the amount you wanna deposit :";
                    cin >> s;
                    cin.ignore();
                    while (true)
                    {
                        if (check_if_num(s))
                        {
                            in_out = stod(s);
                            break;
                        }
                        else
                        {
                            cout << "Invalid input!!  Please try again\n";
                            cout << "Enter the amount you wanna deposit :";
                            cin >> s;
                            cin.ignore();
                            continue;
                        }
                    }
                    special_users[id[2]-'0'-1].depo_sit(in_out);
                    refill_vector();
                    save_to_file(data,database);
                    break;
                }
                else
                {
                    cout << "invalid id!!\nTry again\n";
                    continue ;
                }
            }
        }

        else if (choice == '5')
        {
            break;
        }

    }
    refill_vector();
    save_to_file(data,database);

}

int main()
{
    Bank_application h;
    h.system_manger();
}
