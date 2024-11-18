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

std::string SocialNetwork::getNetworkName() const
{
	return _networkName;
}

int SocialNetwork::getMinAge() const
{
	return _minAge;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < _minAge)
		return false;
	_profiles.add(profile_to_add);
	
}

std::string SocialNetwork::getWindowsDevices() const
{
	ProfileNode* profilecurr = _profiles.get_first();
	std::string deviceANDid = "";
	std::string  deviceid = "";
	DeviceNode* deviceCurr = nullptr;
	std::string devicesString = "";
	int devicesStringLength = 0;
	while (profilecurr) //every profile has its own list of devices, we need to loop through the profiles and then through the devices
	{
		deviceCurr = profilecurr->get_data().getOwner().getDevices().get_first(); //get the first device in the devices linked list
		while (deviceCurr) //loop through the devices linked list inside the profile
		{
			if (deviceCurr->get_data().getOS().find("Windows") != std::string::npos) //check if the device os is windows
			{
				deviceid = std::to_string(deviceCurr->get_data().getID()); //get the id of the device
				deviceANDid = deviceANDid + "[" + deviceid + ", " + deviceCurr->get_data().getOS() + "]"; //connect the id and the os
				devicesString = devicesString + deviceANDid + ", "; //connect it all into the deviceString
				deviceid.clear(); //clear the device id for the next iteration
				deviceANDid.clear(); //clear the deviceANDid for the next iteration
			}
			deviceCurr = deviceCurr->get_next(); //skip to the next device
		}
		profilecurr = profilecurr->get_next(); //skip to the next profile
	}
	devicesStringLength = devicesString.length(); //check if we even have something in the devicesString
	if (devicesStringLength > 1)
		devicesString.resize(devicesStringLength - 2); //if we do then remove the trailing comma
	return devicesString;
}
