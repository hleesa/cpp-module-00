#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() <<
			";total:" << getTotalAmount() <<
			";deposits:" << getNbDeposits() <<
			";withdrawals:" << getNbWithdrawals() << "\n";
	return;
}

Account::Account(int initial_deposit) {
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	_accountIndex = getNbAccounts();
	++_nbAccounts;
	_totalAmount += checkAmount();
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";created\n";
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";closed\n";
}

void Account::makeDeposit(int deposit) {
	++_nbDeposits;
	++_totalNbDeposits;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() - deposit
			<< ";deposit:" << deposit << ";amount:" << checkAmount() << ";nb_deposits:" << _nbDeposits << "\n";
	return;
}

bool Account::makeWithdrawal(int withdrawal) {
	bool ret;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";withdrawal:";
	if (withdrawal > checkAmount()) {
		std::cout << "refused\n";
		ret = false;
	}
	else {
		++_nbWithdrawals;
		++_totalNbWithdrawals;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:" << _nbWithdrawals << "\n";
		ret = true;
	}
	return ret;
}

int Account::checkAmount( void ) const{
	return _amount;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount()
			<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
	return ;
}

void Account::_displayTimestamp() {
	std::time_t now = std::time(0);
	std::tm* time_info = std::localtime(&now);
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", time_info);
	std::string currentTime(buffer);
	std::string message = "[" + currentTime + "] ";
	std::cout << message;
}

Account::Account() {
}
