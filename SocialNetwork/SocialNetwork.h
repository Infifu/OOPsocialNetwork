#pragma once
#include <string>
#include "Profile.h"
#include "ProfileList.h"

class SocialNetwork
{
private:
	std::string _networkName;
	int _minAge;
	ProfileList _profiles;
public:
	void init(std::string networkName, int minAge);
	void clear();
	std::string getNetworkName() const;
	int getMinAge() const;
	bool addProfile(Profile profile_to_add);
	std::string getWindowsDevices() const;
};