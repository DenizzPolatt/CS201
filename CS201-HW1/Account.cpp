#include "Account.h"

Account::Account() = default;
Account::Account( int branch_id_,  int customer_id_,  double amount,  int account_id_) :
    branch_id_{branch_id_}, customer_id_{customer_id_}, amount_{amount}, account_id_{account_id_} {}

int Account::get_account_id() const 
{
    return account_id_;
}

int Account::get_customer_id() const
{
    return customer_id_;
}

int Account::get_branch_id() const
{
    return branch_id_;
}

double Account::get_amount() const
{
    return amount_;
}

bool Account::operator==(const Account& other) const 
{
    return account_id_ == other.account_id_;
}



