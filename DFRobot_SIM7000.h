#ifndef __DFROBOT_SIM7000_H__
#define __DFROBOT_SIM7000_H__

#include "DFRobot_SIMcore.h"

#define ON  0
#define OFF 1

enum Protocol {
    CLOSED = 0,
    TCP    = 1,
    UDP    = 2,
};

enum Net{
    GPRS,
    NB,
};

enum DataType {
    CMD     = 0,
    DATA    = 1,
};

class DFRobot_SIM7000 : public DFRobot_SIMcore
{
public:
    int      recv(char* buf, int maxlen, int timeout);
    int      checkSignalQuality(void);
    int      batteryPower(void);
    bool     setNetMode(Net net);
    bool     attacthService(void);
    bool     setBaudRate(long rate);
    bool     checkSIMStatus(void);
    bool     openNetwork(Protocol ptl, const char *host, int port);
    bool     closeNetwork(void);
    bool     turnON(void);
    bool     initPos(void);
    bool     mqttConnect(char* iot_client, char* iot_username, char* iot_key);
    bool     mqttPublish(char* iot_topic, String iot_data);
    bool     mqttSubscribe(char* iot_topic);
    bool     mqttUnsubscribe(char* iot_topic);
    bool     mqttRecv(char* iot_topic, char* buf,int maxlen);
    bool     mqttDisconnect(void);
    bool     httpInit(Net mode);
    bool     httpConnect(const char *Host);
    bool     httpPost(const char *Host , char* data);
    void     httpGet(const char *Host);
    void     httpDisconnect(void);
    bool     send(void *buffer,size_t len);
    bool     send(char *data);
 // Ancienne version SIM70000   
	bool     getPosition(char  * latitude,  char *   longitude);
   	char*    getLatitude(void);
    char*    getLongitude(void);
// nouvelle version GPS SIM70000
	void     GetGpsCoordinates(char* trame, char* latitude, char* longitude);
	
	
	void     GetRemoteConfiguration(char * DeviceId);
	void     GetPropertyValue(char* trame,int idx, char* value);
	void     Split(char* trame, char* clientNameValue, char* frequencyValue);
	void     GetConfiguration(char* trame, char* clientName, char* frequencyInSecondes);
	
private:

    //char   * latitude;
  // char    * longitude;
    char     battery[3];
    int      mode_t=0;
 };

#endif