#ifndef GENERATOR_H
#define GENERATOR_H
#include "models/billing.h"

class Generator
{
public:
    Generator(Models::Billing *b);
    ~Generator();

    void generate();

    Models::Billing* getBilling() const;
    void setBilling(Models::Billing* getBilling);

private:
    Models::Billing* _billing;
};

#endif // GENERATOR_H
