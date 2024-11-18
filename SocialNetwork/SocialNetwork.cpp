#include "SocialNetwork.h"

void SocialNetwork::init(std::string networkName, int minAge)
{
	_networkName = networkName;
	_minAge = minAge;
	_profiles.init();
}

void SocialNetwork::clear()
{
	_networkName.clear();
	_minAge = 0;
}

std::string SocialNetwork::getNetworkName()
{
	return _networkName;
}

int SocialNetwork::getMinAge()
{
	return _minAge;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < _minAge)
		return false;
	_profiles.add(profile_to_add);
	
}

std::string SocialNetwork::getWindowsDevices()
{
	ProfileNode* profilecurr = _profiles.get_first();
	std::string deviceANDid = "";
	std::string  deviceid = "";
	DeviceNode* deviceCurr = nullptr;
	std::string devicesString = "";
	int devicesStringLength = 0;
	while (profilecurr)
	{
		deviceCurr = profilecurr->get_data().getOwner().getDevices().get_first();
		while (deviceCurr)
		{
			if (deviceCurr->get_data().getOS().find("Windows") != std::string::npos)
			{
				deviceid = std::to_string(deviceCurr->get_data().getID());
				deviceANDid = deviceANDid + "[" + deviceid + ", " + deviceCurr->get_data().getOS() + "]";
				devicesString = devicesString + deviceANDid + ", ";
				deviceid.clear();
				deviceANDid.clear();
			}
			deviceCurr = deviceCurr->get_next();
		}
		profilecurr = profilecurr->get_next();
	}
	devicesStringLength = devicesString.length();
	if (devicesStringLength > 1)
		devicesString.resize(devicesStringLength - 2);
	return devicesString;
}
