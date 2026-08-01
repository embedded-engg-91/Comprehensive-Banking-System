#include "transaction.h"

Transaction::Transaction(const string &t, double amt, const string &dt) : type(t), amount(amt), date(dt) {}

void Transaction::displayTransaction() const
{
    cout << "Type: " << type << ", Amount: " << amount << ", Date: " << date << endl;
}