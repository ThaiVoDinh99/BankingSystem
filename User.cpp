#include "User.h"

int User::Person::numberOfUser = 0;
int Acc::Account::numberOfAccount = 0;

User::Person::Person(std::string name, int age, std::string sex)
    : mName(name), mAge(age), mSex(sex)
{
    numberOfUser++;
}

User::Person::~Person() {
    std::cout << "Delete person!" << std::endl;
}

void User::Person::setName(const std::string name) {
    if (mName != name) {
        mName = name;
    }
}

std::string User::Person::getName() const {
    return mName;
}

void User::Person::setAge(const int age) {
    if (mAge != age) {
        mAge = age;
    }
}

int User::Person::getAge() const {
    return mAge;
}

void User::Person::setSex(const std::string sex) {
    if (mSex != sex) {
        mSex = sex;
    }
}

std::string User::Person::getSex() const {
    return mSex;
}

Acc::Account::Account(std::string name, int age, std::string sex, long code, double balance, std::string password) 
    : User::Person(name, age, sex)
    , mCode(code)
    , mBalance(balance)
    , mPassword(password)
{
    numberOfAccount++;
}

Acc::Account::~Account() {

}

void Acc::Account::setAccountCode(const long code) {
    if (mCode != code) {
        mCode = code;
    }
}

long Acc::Account::getAccountCode() const {
    return mCode;
}

void Acc::Account::setAccountBalance(const double balance) {
    if (mBalance != balance) {
        mBalance = balance;
    }
}

double Acc::Account::getAccountBalance() const {
    return mBalance;
}

void Acc::Account::setNewPassword(const std::string password) {
    if (mPassword != password) {
        mPassword = password;
    }
}

std::string Acc::Account::getPassword() const {
    return mPassword;
}

int Acc::Account::getNumberOfAccount() {
    return numberOfAccount;
}

bool Acc::Account::checkPassword(std::string password) {
    if (mPassword == password) {
        return true;
    }
    return false;
}


