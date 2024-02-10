#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

/**
 * Implements User functionality and information storage
 *  You should not need to derive anything from User at this time
 */
class User {
public:
    User();
    User(std::string name, double balance, int type);
    virtual ~User();

    double getBalance() const;
    std::string getName() const;
    void deductAmount(double amt);
    virtual void dump(std::ostream& os);

    // added getter functions
    std::string getName() const { return name_; }
    double getBalance() const { return balance_; }
    int getType() const { return type_; }

private:
    std::string name_;
    double balance_;
    int type_;
};
#endif
