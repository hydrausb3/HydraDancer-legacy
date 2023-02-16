#ifndef USB_DESCRIPTORS_H
#define USB_DESCRIPTORS_H


/* enums */
struct Device_t {
    char *s_name;
    unsigned char *descriptorDevice;
    unsigned char *descriptorConfig;
    unsigned char *descriptorHidReport;
};

struct DeviceConfig_t {
    char *s_name;
    unsigned char class;
    unsigned char subClass;
    unsigned char protocol;
};

/* variables */
extern struct Device_t g_deviceGeneric;
extern struct Device_t g_deviceKeyboard;

extern struct DeviceConfig_t g_audioDeviceConfig;

#endif /* USB_DESCRIPTORS_H */
