#include "Branch.h"

#include <iostream>

Branch::Branch() = default;

Branch::Branch(std::string name, int branch_id) :
    name_{name}, branch_id_{branch_id} {}

bool Branch::operator==(const Branch& other) const 
{
    return branch_id_ == other.branch_id_;
}
std::string Branch::get_name() const
{
    return name_;
}

int Branch::get_branch_id() const
{
    return branch_id_;
}

// void Branch::add_account(const Account& account)
// {
//     accounts_.add(account);
// }

// ArrayList<Account> Branch::get_account_array_() 
// {
//     return accounts_;
// }
