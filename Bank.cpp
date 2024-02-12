#include "Bank.h"
#include <fstream>
using namespace std;

static Bank* instance = nullptr;

Bank::Bank() {
    initData();
}

Bank::~Bank() {
    cout << "Destroy data";
    for (auto &it : mListAccount) {
        delete it.second;
    }
    delete instance;
}

void Bank::initData() {
    ifstream getData("../DataBase.dat", ios::in);

    if (!getData.is_open()) {
        cerr << "Data base not found!";
        return;
    }

    std::string name;
    int age;
    std::string sex;
    long code;
    double balance;
    std::string password;

    while (getData >> name >> age >> sex >> code >> balance >> password) {
        mListAccount[code] = new Acc::Account(name, age, sex, code, balance, password);
    }
}

Bank* Bank::initialize() {
    if (instance == nullptr) {
        instance = new Bank();
    }
    return instance;
};

Bank& Bank::getInstance() {
    try {
        if (instance == nullptr) {
            throw Bank();
        }
    } 
    catch (Bank e) {
        cout << "You need to init instance!" << endl;
    }
    return *instance;
};

void Bank::enterInforUser() {
    cout << "Please enter your information!" << endl;
    cout << "Enter your code: " << endl;
    long code;
    cin >> code;
    checkCode(code);
}

void Bank::checkCode(const long code) {
    if (code == 0) {
        return;
    }

    std::unordered_map<Code, Acc::Account*>::iterator it = mListAccount.begin();
    for (it; it != mListAccount.end(); it++) {
        if (it->first == code) {
            currentUserCode = code;
            checkPassword();
        }
    }
    cout << "User not found!" << endl;
}

void Bank::checkPassword() {
    cout << "Please enter your password:" << endl;
    std::string password;
    cin >> password;
    bool resultCheck = mListAccount[currentUserCode]->checkPassword(password);
    if (resultCheck) {
        cout << "Password correct. Please select your option!" << endl;
        currentUser = mListAccount[currentUserCode]->getName();
        selectOption();
    } else {
        cout << "Password incorrect!" << endl;
    }
}

void Bank::selectOption() {
    cout << "\n\n=================== OPTIONS ==================" << endl;
    cout << "\tUSER NAME: " << currentUser << endl;
    cout << "\t1. Withdraw money." << endl;
    cout << "\t2. Deposit money." << endl;
    cout << "\t3. Check your information." << endl;
    cout << "\t4. Remove account." << endl;
    cout << "\t0. Exit." << endl;
    cout << "\tYour option: " << endl;

    int option;
    cin >> option;

    switch (option) {
    case 1:
    {
        withdraw();
        break;
    }
    case 2:
    {
        deposit();
        break;
    }
    case 3:
    {
        checkInformation();
        break;
    }
    case 4:
    {
        removeAccount();
        break;
    }
    case 5:
    {
        changePassword();
        break;
    }
    default:
    {
        break;
    }
    }
}

void Bank::withdraw() {
    cout << "Enter the number of money you want to withdraw: " << endl;
    double remainderMoney = mListAccount[currentUserCode]->getAccountBalance();
    do {
        double money;
        cin >> money;
        if (money < 0) {
            cout << "Invalid! Please enter again: ";
        } else if (money > remainderMoney) {
            cout << "The remainder of your money is not enough. Please enter again: ";
        } else {
            mListAccount[currentUserCode]->setAccountBalance(remainderMoney - money);
            updateDataBase();
            break;
        }
    } while (true);

}

void Bank::deposit() {

}

void Bank::createNewAccount() {
    std::string name;
    int age;
    std::string sex;
    long code;
    std::string password;
    cout << "Enter information for new account: " << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Sex: ";
    cin >> sex;
    cout << "Code: ";
    cin >> code;
    cout << "Password: ";
    cin >> password;
    try {
        Acc::Account* newAccount = new Acc::Account(name, age, sex, code, 0, password);
        if (newAccount == nullptr) {
            throw -1;
        }
        mListAccount[code] = newAccount;
        updateDataBase();
    }
    catch(...) {
        cerr << "Create new account fail!" << endl;
    }
}

void Bank::removeAccount() {

}

void Bank::checkBalance() {

}

void Bank::checkInformation() {

}

void Bank::updateDataBase() {
    ofstream update("../DataBase.dat", ios::out);
    if (!update.is_open()) {
        cerr << "Data base not found!";
        return;
    }

    #define UPDATE(FILE,X) FILE<<X->getName()<<" "<<X->getAge()<<" "<<X->getSex()<<" "<<X->getAccountCode()<<" "<<X->getAccountBalance()<<" "<<X->getPassword()<<"\n"

    for (auto &it : mListAccount) {
        UPDATE(update,it.second);
    }
}

void Bank::changePassword() {
    cout << "Please enter your new password: " << endl;
    string password;
    cin >> password;
    mListAccount[currentUserCode]->setNewPassword(password);
    updateDataBase();
}