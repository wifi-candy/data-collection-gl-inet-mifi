#include <string.h> 

#define REQUEST_INTERNATIONAL_MOBILE_EQUIPMENT_IDENTITY "echo -e \"AT+GSN\r\n\" > /dev/ttyUSB2; cat /dev/ttyUSB2"

#define REQUEST_SIM_CCID "echo -e \"AT+QCCID\r\n\" > /dev/ttyUSB2; cat /dev/ttyUSB2"

#define REQUEST_IMSI "echo -e \"AT+CIMI\r\n\" > /dev/ttyUSB2; cat /dev/ttyUSB2"

#define CHECK_NETWORK_REGISTRATION "echo -e \"AT+CREG?\r\n\" > /dev/ttyUSB2; cat /dev/ttyUSB2"

#define REQUEST_SIGNAL_QUALITY_REPORT "echo -e \"AT+CSQ \r\n\" > /dev/ttyUSB2; cat /dev/ttyUSB2"

#define QUERY_THE_CURRENTLY_SELECTED_NETWORK_OPERATOR "echo -e \"AT+COPS?\r\n\" > /dev/ttyUSB2; cat /dev/ttyUSB2"

#define RESET_MODEM "echo -e \“AT+QRST=1,0\” > /dev/ttyUSB2"


