#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>

class Customer {
    std::string name_{};
    int customer_id_{};

public:
    Customer();
    Customer(std::string customer_name, int customer_id);

    std::string get_name() const;
    int get_customer_id() const;

    bool operator==(const Customer& other) const;
};

#endif //CUSTOMER_H_