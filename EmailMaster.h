#ifndef EMAIL_MASTER
#define EMAIL_MASTER

#include <string>
#include <queue>
#include <stack>
#include <iostream>
// FQDN - fully qualified domain name

enum Status {
	VALID, INVALID
};

class EmailAdress {
private:

	//-----------------------------FIELDS---------------------------//
	std::string email;
	Status emStatus;
	std::string userName;
	
	class FQDN {
	public:
		class Domain {
		public:
			//int lvl;
			std::string dName;
			Domain(const std::string);
		};
		std::stack<Domain> domainStack;
		Status fdStatus = INVALID;
		std::stack <Domain> getStack();
		Status checkStack();
		FQDN();
		FQDN(const std::string domainLine);
	};

	FQDN* fqdn = NULL;	
	//--------------------------METHODS------------------------------//
public:
	EmailAdress(const std::string email);
	std::string getStatus();
	void showStack();
	void setEmail(const std::string);
};

#endif