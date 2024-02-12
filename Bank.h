#ifndef BANK_H
#define BANK_H

#include "User.h"
#include <unordered_map>
#include <memory>

using Code = long;

class Bank {
public:
    ~Bank();

    static Bank* initialize();
    static Bank& getInstance();

public:
    void initData();

    void withdraw();
    void deposit();
    void createNewAccount();
    void checkBalance();
    void removeAccount();
    void checkInformation();
    void changePassword();

    void enterInforUser();
    void checkCode(const long code);
    void checkPassword();

    void selectOption();

    void updateDataBase();




private:
    std::unordered_map<Code, Acc::Account*> mListAccount;
    long currentUserCode {0};
    std::string currentUser {""};
private:
    Bank();
};

#endif //BANK_H