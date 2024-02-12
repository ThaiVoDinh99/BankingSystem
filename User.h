#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

namespace User {

class Person {
public:
    Person(std::string name, int age, std::string sex);
    virtual ~Person();

    static int numberOfUser;

    void setName(const std::string name);
    std::string getName() const;

    void setAge(const int age);
    int getAge() const;

    void setSex(const std::string sex);
    std::string getSex() const;

    virtual bool checkPassword(std::string password) = 0;

protected:
    std::string mName;
    int mAge;
    std::string mSex;
};
}

class Bank;
namespace Acc {
class Account : public User::Person {
    friend class Bank;
public: 
    Account(std::string name, int age, std::string sex, long code, double balance, std::string password);
    ~Account();

    static int numberOfAccount;

    void setAccountCode(const long code);
    long getAccountCode() const;

    void setAccountBalance(const double balance);
    double getAccountBalance() const;

    void setNewPassword(const std::string password);
    std::string getPassword() const;

    int getNumberOfAccount();

    bool checkPassword(std::string password) override;

    
private:
    long mCode;
    double mBalance;
    std::string mPassword;
};
}

#endif //USER_H