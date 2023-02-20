#include <stddef.h>

#include "usb_descriptors.h"


/*******************************************************************************
 * DEVICE GENERIC
 */
unsigned char _genericDescriptorDevice[] = {
    0x12,   // bLength
    0x01,   // bDescriptorType
    0x00,   // bcdUSB (low)
    0x02,   // bcdUSB (high)
    0x00,   // bDeviceClass (Defined in the interface descriptor)
    0x00,   // bDeviceSubClass
    0x00,   // bDeviceProtocol
    64,     // bMaxPacketSize0
    0x34,   // idVendor (low)
    0x12,   // idVendor (high)
    0xCD,   // idProduct (low)
    0xAB,   // idProduct (high)
    0x00,   // bcdDevice (low)
    0x42,   // bcdDevice (high)
    0x00,   // iManufacturer
    0x00,   // iProduct
    0x00,   // iSerialNumber
    0x01,   // bNumConfigurations
};

unsigned char _genericDescriptorConfig[] = {
    //  Descriptor Config
	0x09, // bLength
	0x02, // bDescriptorType
	0x19, // wTotalLengthL
	0x00, // wTotalLengthH
	0x01, // bNumInterfaces
	0x01, // bConfigurationValue
	0x00, // iConfiguration
	0x80, // bmAttributes
	0x64, // MaxPower
    //  Descriptor Interface
	0x09, // bLength
	0x04, // bDescriptorType
	0x00, // bInterfaceNumber
	0x00, // bAlternateSetting
	0x01, // bNumEndpoint
	0x00, // bInterfaceClass
	0x00, // bInterfaceSubClass
	0x00, // bInterfaceProtocol
	0x00, // iInterface
    //  Descriptor Endpoint
	0x07, // bLength
	0x05, // bDescriptorType
	0x01, // bEndpointAddress (OUT)
	0x02, // bmAttributes
	0x00, // wMaxPacketSizeL
	0x02, // wMaxPacketSizeH
	0x00, // bInterval
};

struct Device_t g_deviceGeneric = { "Generic", _genericDescriptorDevice, _genericDescriptorConfig, NULL };


/*******************************************************************************
 * GENERIC DEVICES CONFIGURATIONS
 */
struct DeviceConfig_t g_genericDeviceConfig = { "Generic Config", 0x00, 0x00, 0x00 };


/*******************************************************************************
 * DEVICE AUDIO
 */

// Based on https://www.usb.org/sites/default/files/audio10.pdf
unsigned char _audioDescriptorDevice[] = {
    // Table B-1: USB Microphone Device Descriptor
    0x12, // bLength                Size of this descriptor, in bytes.
    0x01, // bDescriptorType        DEVICE descriptor.
    0x00, // bcdUSBL                1.00 - current revision of USB specification.
    0x02, // bcdUSBH                1.00 - current revision of USB specification.
    0x00, // bDeviceClass           Device defined at Interface level.
    0x00, // bDeviceSubClass        Unused.
    0x00, // bDeviceProtocol        Unused.
    0x40, // bMaxPacketSize0        8 bytes.
    0x34, // idVendorL              Vendor ID.
    0x12, // idVendorH              Vendor ID.
    0xCD, // idProductL             Product ID.
    0xAB, // idProductH             Product ID.
    0x00, // bcdDeviceL             Device Release Code.
    0x42, // bcdDeviceH             Device Release Code.
    0x00, // iManufacturer          Index to string descriptor that contains the string <Your Name> in Unicode.
    0x00, // iProduct               Index to string descriptor that contains the string <Your Product Name> in Unicode.
    0x00, // iSerialNumber          Unused.
    0x01, // bNumConfigurations     One configuration.
};

unsigned char _audioDescriptorConfig[] = {
    // Table B-2: USB Microphone Configuration Descriptor
    0x09, //  bLength                 Size of this descriptor, in bytes.
    0x02, //  bDescriptorType         CONFIGURATION descriptor.
    0x64, //  wTotalLengthL           Length of the total configuration block, including this descriptor, in bytes.
    0x00, //  wTotalLengthH           Length of the total configuration block, including this descriptor, in bytes.
    0x02, //  bNumInterfaces          Two interfaces.
    0x01, //  bConfigurationValue     ID of this configuration.
    0x00, //  iConfiguration          Unused.
    0x80, //  bmAttributes            Bus Powered device, not Self Powered, no Remote wakeup capability.
    0x0A, //  MaxPower                20 mA Max. power consumption.

    // Table B-3: USB Microphone Standard AC Interface Descriptor
    0x09, //  bLength             Size of this descriptor, in bytes.
    0x04, //  bDescriptorType     INTERFACE descriptor.
    0x00, //  bInterfaceNumber    Index of this interface.
    0x00, //  bAlternateSetting   Index of this setting.
    0x00, //  bNumEndpoints       0 endpoints.
    0x01, //  bInterfaceClass     AUDIO.
    0x01, //  bInterfaceSubclass  AUDIO_CONTROL.
    0x00, //  bInterfaceProtocol  Unused.
    0x00, //  iInterface          Unused.

    // Table B-4: USB Microphone Class-specific AC Interface Descriptor
    0x09, //  bLength             Size of this descriptor, in bytes.
    0x24, //  bDescriptorType     CS_INTERFACE.
    0x01, //  bDescriptorSubtype  HEADER subtype.
    0x00, //  bcdADCL             Revision of class specification - 1.0
    0x01, //  bcdADCH             Revision of class specification - 1.0
    0x1E, //  wTotalLengthL       Total size of class specific descriptors.
    0x00, //  wTotalLengthH       Total size of class specific descriptors.
    0x01, //  bInCollection       Number of streaming interfaces.
    0x01, //  baInterfaceNr(1)    AudioStreaming interface 1 belongs to this AudioControl interface.

    // Table B-5: USB Microphone Input Terminal Descriptor
    0x0C, //  bLength             Size of this descriptor, in bytes.
    0x24, //  bDescriptorType     CS_INTERFACE.
    0x02, //  bDescriptorSubtype  INPUT_TERMINAL subtype.
    0x01, //  bTerminalID         ID of this Input Terminal.
    0x01, //  wTerminalTypeL      Terminal is Microphone.
    0x02, //  wTerminalTypeH      Terminal is Microphone.
    0x00, //  bAssocTerminal      No association.
    0x01, //  bNrChannels         One channel.
    0x00, //  wChannelConfigL     Mono sets no position bits.
    0x00, //  wChannelConfigH     Mono sets no position bits.
    0x00, //  iChannelNames       Unused.
    0x00, //  iTerminal           Unused.

    // Table B-6: USB Microphone Output Terminal Descriptor
    0x09, //  bLength             Size of this descriptor, in bytes.
    0x24, //  bDescriptorType     CS_INTERFACE.
    0x03, //  bDescriptorSubtype  OUTPUT_TERMINAL subtype.
    0x02, //  bTerminalID         ID of this Output Terminal.
    0x01, //  wTerminalTypeL      USB Streaming.
    0x01, //  wTerminalTypeH      USB Streaming.
    0x00, //  bAssocTerminal      Unused.
    0x01, //  bSourceID           From Input Terminal.
    0x00, //  iTerminal           Unused.

    // Table B-7: USB Microphone Standard AS Interface Descriptor (Alt. Set. 0)
    0x09, //  bLength             Size of this descriptor, in bytes.
    0x04, //  bDescriptorType     INTERFACE descriptor.
    0x01, //  bInterfaceNumber    Index of this interface.
    0x00, //  bAlternateSetting   Index of this alternate setting.
    0x00, //  bNumEndpoints       0 endpoints.
    0x01, //  bInterfaceClass     AUDIO.
    0x02, //  bInterfaceSubclass  AUDIO_STREAMING.
    0x00, //  bInterfaceProtocol  Unused.
    0x00, //  iInterface          Unused.

    // Table B-8: USB Microphone Standard AS Interface Descriptor
    0x09, //  bLength             Size of this descriptor, in bytes.
    0x04, //  bDescriptorType     INTERFACE descriptor.
    0x01, //  bInterfaceNumber    Index of this interface.
    0x01, //  bAlternateSetting   Index of this alternate setting.
    0x01, //  bNumEndpoints       One endpoint.
    0x01, //  bInterfaceClass     AUDIO.
    0x02, //  bInterfaceSubclass  AUDIO_STREAMING.
    0x00, //  bInterfaceProtocol  Unused.
    0x00, //  iInterface          Unused.

    // Table B-9: USB Microphone Class-specific AS General Interface Descriptor
    0x07, //  bLength             Size of this descriptor, in bytes.
    0x24, //  bDescriptorType     CS_INTERFACE descriptor.
    0x01, //  bDescriptorSubtype  GENERAL subtype.
    0x02, //  bTerminalLink       Unit ID of the Output Terminal.
    0x01, //  bDelay              Interface delay.
    0x01, //  wFormatTagL         PCM Format.
    0x00, //  wFormatTagH         PCM Format.

    // Table B-10: USB Microphone Type I Format Type Descriptor
    0x0B, //  bLength             Size of this descriptor, in bytes.
    0x24, //  bDescriptorType     CS_INTERFACE descriptor.
    0x02, //  bDescriptorSubtype  FORMAT_TYPE subtype.
    0x01, //  bFormatType         FORMAT_TYPE_I.
    0x01, //  bNrChannels         One channel.
    0x02, //  bSubFrameSize       Two bytes per audio subframe.
    0x10, //  bBitResolution      16 bits per sample.
    0x01, //  bSamFreqType        One frequency supported.
    0x40, //  tSamFreqL           8000Hz.
    0x1F, //  tSamFreqM           8000Hz.
    0x00, //  tSamFreqH           8000Hz.

    // Table B-11: USB Microphone Standard Endpoint Descriptor
    0x09, //  bLength           Size of this descriptor, in bytes.
    0x05, //  bDescriptorType   ENDPOINT descriptor.
    0x81, //  bEndpointAddress  IN Endpoint 1.
    0x01, //  bmAttributes      Isochronous, not shared.
    0x10, //  wMaxPacketSizeL   16 bytes per packet.
    0x00, //  wMaxPacketSizeH   16 bytes per packet.
    0x01, //  bInterval         One packet per frame.
    0x00, //  bRefresh          Unused.
    0x00, //  bSynchAddress     Unused.

    // Table B-12: USB Microphone Class-specific Isoc. Audio Data Endpoint Descriptor
    0x07, //  bLength             Size of this descriptor, in bytes.
    0x25, //  bDescriptorType     CS_ENDPOINT descriptor
    0x01, //  bDescriptorSubtype  GENERAL subtype.
    0x00, //  bmAttributes        No sampling frequency control, no pitch control, no packet padding.
    0x00, //  bLockDelayUnits     Unused.
    0x00, //  wLockDelayL         Unused
    0x00, //  wLockDelayH         Unused
};

struct Device_t g_deviceAudio = { "Audio", _audioDescriptorDevice, _audioDescriptorConfig, NULL };


/* CDC descriptors is based on
 * https://gist.github.com/tai/acd59b125a007ad47767
 */
/*******************************************************************************
 * DEVICE CDC
 */
unsigned char _cdcDescriptorDevice[] = {
    18,     // bLength
    1,      // bDescriptorType
    0x00,   // bcdUSB (low)
    0x02,   // bcdUSB (high)
    0x02,   // bDeviceClass (Defined in the interface descriptor)
    0x00,   // bDeviceSubClass
    0x00,   // bDeviceProtocol
    64,     // bMaxPacketSize0
    0x34,   // idVendor (low)
    0x12,   // idVendor (high)
    0xCD,   // idProduct (low)
    0xAB,   // idProduct (high)
    0x00,   // bcdDevice (low)
    0x42,   // bcdDevice (high)
    0x00,   // iManufacturer
    0x00,   // iProduct
    0x00,   // iSerialNumber
    1,      // bNumConfigurations
};

unsigned char _cdcDescriptorConfig[] = {
    //  Descriptor Config
    0x09, // bLength
    0x02, // bDescriptorType
    0x43, // wTotalLengthL
    0x00, // wTotalLengthH
    0x02, // bNumInterfaces
    0x01, // bConfigurationValue
    0x00, // iConfiguration
    0x80, // bmAttributes
    0x64, // MaxPower
    //  Descriptor Interface 0 (Communication Class)
    0x09, // bLength
    0x04, // bDescriptorType
    0x00, // bInterfaceNumber
    0x00, // bAlternateSetting
    0x01, // bNumEndpoint
    0x02, // bInterfaceClass        (Communication Interface Class)
    0x02, // bInterfaceSubClass     (Abstract Control Model)
    0x01, // bInterfaceProtocol     (AT Commands V.250)
    0x00, // iInterface
        //  Descriptors Functional
        //  Descriptor Functional Header
        0x05, // bLength
        0x24, // bDescriptorType
        0x00, // bDescriptorSubtype (Header FD)
        0x10, // bcdCDCL
        0x01, // bcdCDCH
        //  Descriptor Functional Abstract Control Model
        0x04, // bLength
        0x24, // bDescriptorType
        0x02, // bDescriptorSubtype (ACM-FD)
        0x02, // bmCapabilities
        //  Descriptor Functional Union
        0x05, // bLength
        0x24, // bDescriptorType
        0x06, // bDescriptorSubtype (Union FD)
        0x00, // bControlInterface      (I/F# of Communication Class Interface)
        0x01, // bSubordinateInterface0 (I/F# of Data Class Interface)
        //  Descriptor Functional Call Management
        0x05, // bLength
        0x24, // bDescriptorType
        0x01, // bDescriptorSubtype (CM-FD)
        0x00, // bmCapabilities
        0x01, // bDataInterface
        //  Descriptor Endpoint 1
        0x07, // bLength
        0x05, // bDescriptorType
        0x81, // bEndpointAddress   (ep1 IN)
        0x03, // bmAttributes
        0x10, // wMaxPacketSizeL
        0x00, // wMaxPacketSizeH
        0x02, // bInterval
    //  Descriptor Interface 1 (Data Class)
    0x09, // bLength
    0x04, // bDescriptorType
    0x01, // bInterfaceNumber
    0x00, // bAlternateSetting
    0x02, // bNumEndpoint
    0x0A, // bInterfaceClass        (CDC-Data)
    0x00, // bInterfaceSubClass
    0x00, // bInterfaceProtocol
    0x00, // iInterface
        //  Descriptor Endpoint 1
        0x07, // bLength
        0x05, // bDescriptorType
        0x01, // bEndpointAddress   (ep1 OUT)
        0x02, // bmAttributes
        0x40, // wMaxPacketSizeL
        0x00, // wMaxPacketSizeH
        0x00, // bInterval
        //  Descriptor Endpoint 8
        0x07, // bLength
        0x05, // bDescriptorType
        0x88, // bEndpointAddress   (ep8 IN)
        0x02, // bmAttributes
        0x00, // wMaxPacketSizeL
        0x02, // wMaxPacketSizeH
        0x00, // bInterval
};

struct Device_t g_deviceCdc = { "CDC (Virtual COM Port)", _cdcDescriptorDevice, _cdcDescriptorConfig, NULL };


/*******************************************************************************
 * DEVICE KEYBOARD
 */
unsigned char _keyboardDescriptorDevice[] = {
    18,     // bLength
    1,      // bDescriptorType
    0x00,   // bcdUSB (low)
    0x02,   // bcdUSB (high)
    0x00,   // bDeviceClass (Defined in the interface descriptor)
    0x00,   // bDeviceSubClass
    0x00,   // bDeviceProtocol
    64,     // bMaxPacketSize0
    0x34,   // idVendor (low)
    0x12,   // idVendor (high)
    0xCD,   // idProduct (low)
    0xAB,   // idProduct (high)
    0x00,   // bcdDevice (low)
    0x42,   // bcdDevice (high)
    0x00,   // iManufacturer
    0x00,   // iProduct
    0x00,   // iSerialNumber
    1,      // bNumConfigurations
};

unsigned char _keyboardDescriptorConfig[] = {
    //  Descriptor Config
    0x09, // bLength
    0x02, // bDescriptorType
    0x22, // wTotalLengthL
    0x00, // wTotalLengthH
    0x01, // bNumInterfaces
    0x01, // bConfigurationValue
    0x00, // iConfiguration
    0x80, // bmAttributes
    0x64, // MaxPower
    //  Descriptor Interface
    0x09, // bLength
    0x04, // bDescriptorType
    0x00, // bInterfaceNumber
    0x00, // bAlternateSetting
    0x01, // bNumEndpoint
    0x03, // bInterfaceClass
    0x00, // bInterfaceSubClass
    0x01, // bInterfaceProtocol
    0x00, // iInterface
    //  Descriptor HID
    0x09, // bLength
    0x21, // bDescriptorType
    0x11, // bcdHIDL = 0x11,
    0x01, // bcdHIDH = 0x01,
    0x08, // bCountryCode
    0x01, // bNumDescriptors
    0x22, // bDescriptorTypeX
    0x17, // wDescriptorLengthL
    0x00, // wDescriptorLengthH
    //  Descriptor Endpoint
    0x07, // bLength
    0x05, // bDescriptorType
    0x81, // bEndpointAddress (IN)
    0x03, // bmAttributes
    0x04, // wMaxPacketSizeL
    0x00, // wMaxPacketSizeH
    0x01, // bInterval
};

unsigned char _keyboardDescriptorHidReport[] = {
	0x05, 0x01,		// Usage Page (Generic Desktop)
	0x09, 0x06,		// Usage (Keyboard)
	0xA1, 0x01,		// Collection (Application)
	0x95, 0x04,		// Report Count (4)
	0x75, 0x08,		// Report Size (8)
	0x15, 0x00,		// Logical Minimum (0)
	0x25, 0x65,		// Logical Maximum(101)
	0x05, 0x07,		// Usage Page (Key Codes)
	0x19, 0x00,		// Usage Minimum (0)
	0x29, 0x65,		// Usage Maximum (101)
	0x81, 0x00,		// Input (Data, Array)   ; Key arrays (4 bytes)
	0xC0,		    // End Collection
};

struct Device_t g_deviceKeyboard = { "Keyboard", _keyboardDescriptorDevice, _keyboardDescriptorConfig, _keyboardDescriptorHidReport };


