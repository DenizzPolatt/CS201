#include "BankingSystem.h"
#include "Branch.h"
#include "Account.h"
#include <iostream>
#include <iomanip>

BankingSystem::BankingSystem() = default;
BankingSystem::~BankingSystem() = default;

void BankingSystem::addBranch(const int branchId, const std::string branchName)
{
    for(int i = 0; i < branches_.size(); ++i)
    {
        if(branches_.get(i).get_branch_id() == branchId)
        {
            std::cout << "Branch " << branchId << " already exists" << std::endl;
            return;
        }
    }

    branches_.add(Branch{branchName, branchId});
    std::cout << "Branch " << branchId << " has been added" << std::endl;
}

void BankingSystem::deleteBranch(const int branchId)
{
    for(int i = 0; i < branches_.size(); ++i)
    {
        if(branches_.get(i).get_branch_id() == branchId)
        {
            int j = 0;
            while(j < accounts_.size())
            {
                if(accounts_.get(j).get_branch_id() == branchId)
                {
                    accounts_.remove(accounts_.get(j));
                }
                else
                {
                    j += 1;
                }
            }

            branches_.remove(Branch{"", branchId});
            std::cout << "Branch " << branchId << " has been deleted" << std::endl;
            return;
        }
    }

    std::cout << "Branch " << branchId << " does not exist" << std::endl;
}

void BankingSystem::addCustomer(const int customerId, const std::string customerName)
{
    for(int i = 0; i < customers_.size(); ++i)
    {
        if(customers_.get(i).get_customer_id() == customerId)
        {
            std::cout << "Customer " << customerId << " already exists" << std::endl;
            return;
        }
    }
    customers_.add(Customer{customerName, customerId});
    std::cout << "Customer " << customerId << " has been added" << std::endl;
}

void BankingSystem::deleteCustomer(const int customerId)
{
    for(int i = 0; i < customers_.size(); ++i)
    {
        if(customers_.get(i).get_customer_id() == customerId)
        {
            for(int j = 0; j < accounts_.size(); j++)
            {
                if(accounts_.get(j).get_customer_id() == customerId)
                {
                    accounts_.remove(accounts_.get(j));
                }
            }

            customers_.remove(Customer{"", customerId});
            std::cout << "Customer " << customerId << " has been deleted" << std::endl;
            return;
        }
    }
    std::cout << "Customer " << customerId << " does not exist" << std::endl;
}

int BankingSystem::addAccount(const int branchId, const int customerId, const double amount)
{
    bool found_branch{false};
    bool found_customer{false};

    for(int i = 0; i < customers_.size(); ++i)
    {
        if(customers_.get(i).get_customer_id() == customerId)
        {
            found_customer = true;
        }
    }

    for(int i = 0; i < branches_.size(); ++i)
    {
        if(branches_.get(i).get_branch_id() == branchId)
        {
            found_branch = true;
        }
    }

    if(!found_branch)
    {
        std::cout << "Branch " << branchId << " does not exist" << std::endl;
        return -1;
    }

    if(!found_customer)
    {
        std::cout << "Customer " << customerId << " does not exist" << std::endl;
        return -1;
    }

    if(found_customer && found_branch)
    {
        account_id_++;
        Account newAccount = Account(branchId, customerId, amount, account_id_);
        //add this account to the accounts array in BankingSystem
        accounts_.add(newAccount);
        std::cout << "Account " << account_id_ << " added for customer " << customerId <<  " at branch " << branchId << std::endl;
    }

    return account_id_;
}

void BankingSystem::deleteAccount(const int accountId)
{
    for(int i = 0; i < accounts_.size(); ++i)
    {
        if(accounts_.get(i).get_account_id() == accountId)
        {
            accounts_.remove(accounts_.get(i));
            std::cout << "Account " << accountId << " has been deleted" << std::endl;
            return;
        }
    }

    std::cout << "Account " << accountId << " does not exist" << std::endl;
}

void BankingSystem::showAllAccounts()
{
    std::cout << "Account id Branch id Branch name Customer id Customer name Balance"<< std::endl;
    for(int i = 0; i < accounts_.size(); i++)
    {
        int accountId = accounts_.get(i).get_account_id();
        int branchId = accounts_.get(i).get_branch_id();
        int customerId = accounts_.get(i).get_customer_id();
        double amount = accounts_.get(i).get_amount();
        std::string branchName = "";
        std::string customerName = "";

        for(int j = 0; j < branches_.size(); ++j)
        {
            if(branches_.get(j).get_branch_id() == accounts_.get(i).get_branch_id())
            {
                branchName = branches_.get(j).get_name();
            }
        }

        for(int k = 0; k < customers_.size(); ++k)
        {
            if(customers_.get(k).get_customer_id() == accounts_.get(i).get_customer_id())
            {
                customerName = customers_.get(k).get_name();
            }
        }
        
        std::cout << accountId << " " << branchId << " " << branchName << " "
            << customerId << " " << customerName << " " << std::fixed << std::setprecision(2) << amount << std::endl;
    }
}

void BankingSystem::showBranch(const int branchId)
{
    /**
    * The banking system will allow to specify
    a branch id and display detailed information about that particular branch. This information includes
    the branch id, the branch name, the number of accounts opened at this branch, the list of accounts at
    this branch including the account id, the customer id, the customer name, and the account balance for
    each account.
    If the branch does not exist (i.e., if there is no branch with the specified branch id), the system should
    display a warning message.
    */
    int noOfAccounts = 0;
    std::string branchName = "";
    bool found_branch{false};

    for(int i = 0; i < branches_.size(); ++i)
    {
        if(branches_.get(i).get_branch_id() == branchId)
        {
            found_branch = true;
            branchName = branches_.get(i).get_name();
        }
    }

    if(!found_branch)
    {
        std::cout << "Branch " << branchId << " does not exist" << std::endl;
        return;
    }

    //find the number of accounts in this branch
    for(int i = 0; i < accounts_.size(); ++i)
    {
        if(accounts_.get(i).get_branch_id() == branchId)
        {
            noOfAccounts++;
        }
    }

    std::cout << "Branch id: " << branchId << " Branch name: " << branchName << " Number of accounts: " << noOfAccounts << std::endl;

    if(noOfAccounts > 0)
    {
        std::cout << "Accounts at this branch:" << std::endl;
        std::cout << "Account id Customer id Customer name Balance" << std::endl;
        for(int i = 0; i < accounts_.size(); ++i)
        {
            std::string customerName = "";

            if(accounts_.get(i).get_branch_id() == branchId)
            {
                int accountId = accounts_.get(i).get_account_id();
                int customerId = accounts_.get(i).get_customer_id();
                double amount = accounts_.get(i).get_amount();

                for(int j = 0; j < customers_.size(); j++)
                {
                    if(accounts_.get(i).get_customer_id() == customers_.get(j).get_customer_id())
                    {
                        customerName = customers_.get(j).get_name();
                    }
                }
                std::cout << accountId << " " << customerId << " " << customerName << " " << amount << std::endl;
            }
        }
    }   
}

void BankingSystem::showCustomer(const int customerId)
{
    int noOfAccounts = 0;
    bool found_customer{false};
    std::string customerName = "";

    for(int i = 0; i < customers_.size(); i++)
    {
        if(customers_.get(i).get_customer_id() == customerId)
        {
            found_customer = true;
            customerName = customers_.get(i).get_name();
        }
    }

    if(!found_customer)
    {
        std::cout << "Customer " << customerId << " does not exist" << std::endl;
        return;
    }

    //number of accounts of this customer
    for(int i = 0; i < accounts_.size(); i++)
    {
        if(accounts_.get(i).get_customer_id() == customerId)
        {
            noOfAccounts++;
        }
    }

    std::cout << "Customer id: " << customerId << " Customer name: " << customerName << " Number of accounts: " << noOfAccounts << std::endl;

    if(noOfAccounts > 0)
    {
        std::cout << "Accounts of this customer:" << std::endl;
        std::cout << "Account id Branch id Branch name Balance" << std::endl;

        for(int i = 0; i < accounts_.size(); ++i)
        {
            int accountId = 0;
            int branchId = 0;
            std::string branchName = "";
            double amount = 0;

            if(accounts_.get(i).get_customer_id() == customerId)
            {
                accountId = accounts_.get(i).get_account_id();
                branchId = accounts_.get(i).get_branch_id();
                amount = accounts_.get(i).get_amount();

                for(int j = 0; j < branches_.size(); j++)
                {
                    if(branches_.get(j).get_branch_id() == branchId)
                    {
                        branchName = branches_.get(j).get_name();
                    }
                }

                std::cout << accountId << " " << branchId << " " << branchName << " " << std::fixed << std::setprecision(2) << amount << std::endl;
            }
        }
    }
}