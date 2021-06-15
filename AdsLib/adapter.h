#ifndef ADAPTER_H_
#define ADAPTER_H_

#include <string>
#include <vector>
#include <map>
using namespace std;

#define	ADAPTER_OK	0

#ifdef WIN_ISESOL
#define ADAPTER_EXPORTS __declspec(dllexport)
#else
#define ADAPTER_EXPORTS
#endif

#ifdef __cplusplus
extern "C"  //C++
{
#endif

    ADAPTER_EXPORTS short connect_to_server(const string &ipAddr,unsigned short port, const string &user, const string &password, long timeout,void **handle);
	
    ADAPTER_EXPORTS short read_param_val(void *handle, const string &itemName, string &itemValue);
	
    ADAPTER_EXPORTS short write_param_val(void *handle, const string &itemName, const string &itemValue);
	
    ADAPTER_EXPORTS short disconnect(void **handle);
	
    ADAPTER_EXPORTS bool is_connect(void *handle);

    ADAPTER_EXPORTS bool needReconnect();

    ADAPTER_EXPORTS int setAttribute(const string& attr, const string& val);

#ifdef __cplusplus
}
#endif
 
#endif /* ADAPTER_H_ */
