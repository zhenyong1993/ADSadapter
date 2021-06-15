#include "adapter.h"
#include "AdsLib.h"
#include "AdsNotificationOOI.h"
#include "AdsVariable.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <string>
using namespace std;

void Split(const string &str, const string &delimiter, vector<string> &dest)
{
	size_t pos = 0, found = 0;
	while (found != string::npos)
	{
		found = str.find(delimiter, pos);
		dest.push_back(string(str, pos, found - pos));
		pos = found + 1;
	}
}

short connect_to_server(const string &ipAddr,unsigned short port, const string &user, const string &password, long timeout,void **handle)
{
    vector<string> ipv;
    Split(ipAddr, ".", ipv);
    if(ipv.size() != 4)
    {
        return -1;
    }
    static const AmsNetId remoteNetId { stoi(ipv[0]), stoi(ipv[1]), stoi(ipv[2]), stoi(ipv[3]), 1, 1 };
    static const char remoteIpV4[] = "ads-server";
    static AdsDevice route {remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
    *handle = &route;

}

short read_param_val(void *handle, const string &itemName, string &itemValue)
{
    AdsVariable<uint8_t> readVar {*(AdsDevice*)handle, itemName};// MAIN.byByte[4]
    itemValue = to_string((uint32_t)readVar);

//    std::ostream << __FUNCTION__ << "():\n";
//    for (size_t i = 0; i < 8; ++i) {
//            std::ostream << "ADS read " << std::hex << (uint32_t)readVar << '\n';
//    }
}

short write_param_val(void *handle, const string &itemName, const string &itemValue)
{
    AdsVariable<uint8_t> simpleVar {*(AdsDevice*)handle, "MAIN.byByte[0]"};
    simpleVar = stoi(itemValue);
    return 0;
}

short disconnect(void **handle)
{
    return 0;
}

bool is_connect(void *handle)
{
    return true;
}

bool needReconnect()
{
    return true;
}

int setAttribute(const string& attr, const string& val)
{
    return 0;
}
