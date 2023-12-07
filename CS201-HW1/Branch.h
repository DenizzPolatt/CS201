#ifndef BRANCH_H_
#define BRANCH_H_

#include "ArrayList.h"
#include "Account.h"
#include <string>

class Branch {
    std::string name_{};
    int branch_id_{};

public:
    Branch();
    Branch(std::string name_, int branch_id_);

    std::string get_name() const;
    int get_branch_id() const;

    bool operator==(const Branch& other) const;
};

#endif