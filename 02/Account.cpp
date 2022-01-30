/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#include "iostream"
#include "ctime"
#include "Account.hpp"

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

int  Account::getNbAccounts(void) {
    return (_nbAccounts);
}

int  Account::getTotalAmount(void) {
    return (_totalAmount);
}

int  Account::getNbDeposits(void) {
    return (_totalNbDeposits);
}

int  Account::getNbWithdrawals(void) {
    return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void) {
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    std::cout << \
        "[" << \
        (now->tm_year + 1900) << \
        (now->tm_mon + 1) << \
        now->tm_mday << "_" << \
        now->tm_hour << \
        now->tm_min << \
        now->tm_sec << \
        "]" << " ";
}

Account::Account(int initial_deposit) {
    static unsigned int i;

    _accountIndex = i;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbAccounts++;
    Account::_displayTimestamp();
    std::cout << \
        "index:" << i << ";" << \
        "amount:" << initial_deposit << ";" << \
        "created" << std::endl;
    i++;
}

Account::~Account(void) {
    Account::_displayTimestamp();
    std::cout << \
        "index:" << _accountIndex << ";" << \
        "amount:" << _amount << ";" << \
        "closed" << std::endl;
}

void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << \
        "account:" << getNbAccounts() << ";" \
        "total:" << getTotalAmount() << ";" \
        "deposits:" << getNbDeposits() << ";" \
        "withdrawals:" << getNbWithdrawals() << ";" << std::endl;
}

void Account::displayStatus(void) const {
    Account::_displayTimestamp();
    std::cout << \
        "index:" << _accountIndex << ";" \
        "amount:" << _amount << ";" \
        "deposits:" << _nbDeposits << ";" \
        "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    int past_amount;

    past_amount = _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    Account::_displayTimestamp();
    std::cout << \
        "index:" << _accountIndex << ";" \
        "p_amount:" << past_amount << ";" \
        "deposit:" << deposit << ";" \
        "amount:" << _amount << ";" \
        "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    int new_amount;

    new_amount = _amount - withdrawal;
    Account::_displayTimestamp();
    std::cout << \
        "index:" << _accountIndex << ";" \
        "p_amount:" << _amount << ";";
    if (new_amount < 0) {
        std::cout << \
            "withdrawal:refused" << std::endl;
        return (0);
    } else {
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        std::cout << \
            "withdrawal:" << withdrawal << ";" \
            "amount:" << new_amount << ";" \
            "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (1);
    }
    return (0);
}
