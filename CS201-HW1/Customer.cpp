#include "Customer.h"

Customer::Customer() = default;
Customer::Customer(std::string customer_name, int customer_id) :
    name_{customer_name}, customer_id_{customer_id} {}

std::string Customer::get_name() const 
{
    return name_;
}

int Customer::get_customer_id() const
{
    return customer_id_;
}

bool Customer::operator==(const Customer& other) const 
{
    return customer_id_ == other.customer_id_;
}