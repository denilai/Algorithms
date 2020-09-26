#include "EmailMaster.h"
#include <algorithm>


EmailAdress::EmailAdress(const std::string email) {
	setEmail(email);
}

void EmailAdress::setEmail(const std::string email) {
	int countComAt = std::count_if(email.begin(), email.end(), [](char ch) {return (ch == '@'); });
	int countDot = std::count_if(email.begin(), email.end(), [](char ch) {return (ch == '.'); });
	if (countComAt > 1 || countDot == 0 || countComAt == 0) {
		this->emStatus = INVALID;
		this->email = "Invalid adress";
		this->fqdn = new FQDN();
	}
	else {
		int comAt = email.find('@');
		this->email = email.substr(0, comAt);
		this->fqdn = new FQDN(email.substr(comAt + 1));
		if (fqdn->checkStack() == INVALID)
			this->emStatus = INVALID;
	}
}

Status EmailAdress::FQDN::checkStack() {
	std::stack<FQDN::Domain> copy = this->getStack();
	while (!copy.empty()) {
		if (copy.top().dName == "")
			return INVALID;
		copy.pop();
	}
	return VALID;
}


std::stack<EmailAdress::FQDN::Domain> EmailAdress::FQDN::getStack() {
	return domainStack;
}

EmailAdress::FQDN::FQDN() {}

std::string EmailAdress::getStatus() {
	if (this->emStatus == VALID)
		return "Valid";
	else return "Invalid";
}


void EmailAdress::showStack()
{
	std::stack<FQDN::Domain> stack = fqdn->getStack();
	while (!stack.empty()) {
		std::cout << stack.top().dName << std::endl;
		stack.pop();
	}
}
EmailAdress::FQDN::FQDN(std::string domainLine)
{
	int dot = domainLine.find('.');
	while (dot != std::string::npos) {
		std::string lvlName = domainLine.substr(0, dot);
		this->domainStack.push(Domain(lvlName));
		domainLine = domainLine.substr(dot + 1);
		dot = domainLine.find('.');
	}
	this->domainStack.push(domainLine);
}

EmailAdress::FQDN::Domain::Domain(const std::string name) :dName(name) {}