#ifndef ACCOUNT_H_
#define ACCOUNT_H_


class Account {
    int branch_id_{};
    int customer_id_{};
    double amount_{};
    int account_id_{};

public:
    Account();
    Account(int branch_id_, int customer_id,  double amount,  int accountId);

    int get_account_id() const;
    int get_customer_id() const;
    int get_branch_id() const;
    double get_amount() const;

    bool operator==(const Account& other) const;
};
#endif 