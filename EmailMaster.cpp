#include "EmailMaster.h"
#include <algorithm>


EmailAdress::EmailAdress(const std::string email) {
	if (std::count_if(email.begin(), email.end(), [](char ch) {return (ch == '@'); }) > 1) {
		this->emStatus = INVALID;
		this->email = "Invalid adress";
		this->fqdn = new FQDN();
	}
	else {
		int comAt = email.find('@');
		this->email = email.substr(0,comAt);
		this->fqdn = new FQDN(email.substr(comAt+1));
		if (fqdn->checkStack() == INVALID)
			this->emStatus = INVALID;
	}
}

Status EmailAdress::FQDN::checkStack() {
	std::stack<FQDN::DomainName> copy;
	while (!copy.empty()) {
		if (copy.top().dName == "")
			return INVALID;
		copy.pop();
	}
	return VALID;
}


std::stack<EmailAdress::FQDN::DomainName> EmailAdress::FQDN::getStack() {
	return domainStack;
}

EmailAdress::FQDN::FQDN() {}

std::string EmailAdress::getStatus() {
	if (this->emStatus == VALID)
		return "Valid email adress\n";
	else return "Invalid email adress\n";
}
void EmailAdress::showStack()
{
	std::stack<FQDN::DomainName> stack = fqdn->getStack();
	while (!stack.empty()) {
		std::cout << stack.top().dName << std::endl;
		stack.pop();
	}
}
EmailAdress::FQDN::FQDN(std::string domainLine)
{
	int dot = domainLine.find('.');
	while (dot != std::string::npos){
		std::string lvlName = domainLine.substr(0,dot);
		this->domainStack.push(DomainName(lvlName));
		domainLine = domainLine.substr(dot+1);
		dot = domainLine.find('.');
	}
	this->domainStack.push(domainLine);
}

EmailAdress::FQDN::DomainName::DomainName(const std::string name) :dName(name) {}