#include <stddef.h>

#ifndef USB_COMMUNICATION_H
#define USB_COMMUNICATION_H

typedef enum {
    USB_EVENT_CONNECT,
    USB_EVENT_DISCONNECT,
    USB_EVENT_DATA_RECEIVED,
    // Add more event types as needed
} USBEventType;

typedef void (*USBEventCallback)(USBEventType event);

class USBCommunication {
public:
    USBCommunication();

    void begin(USBEventCallback eventCallback);
    bool isConnected();
    bool sendData(const uint8_t *data, size_t length);
    void update();

private:
    USBEventCallback usbEventHandler;
    bool usbConnected;
};

#endif // USB_COMMUNICATION_H
