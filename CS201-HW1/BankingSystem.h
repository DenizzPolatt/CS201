#ifndef BANKINGSYSTEM_H_
#define BANKINGSYSTEM_H_
#include "ArrayList.h"
#include "Branch.h"
#include "Customer.h"
#include "Account.h"

#include <string>

class BankingSystem {
    ArrayList<Branch> branches_{};
    ArrayList<Customer> customers_{};
    ArrayList<Account> accounts_{};
    int account_id_{0};

public :
    BankingSystem();
    ~ BankingSystem();
    void addBranch(const int branchId, const std::string branchName); //done
    void deleteBranch(const int branchId); //done
    void addCustomer(const int customerId, const std::string customerName); //done
    void deleteCustomer(const int customerId); //done
    int addAccount (const int branchId, const int customerId, const double amount); //done
    void deleteAccount(const int accountId); //done
    void showAllAccounts(); //done
    void showBranch(const int branchId);
    void showCustomer(const int customerId);
};

#endif
