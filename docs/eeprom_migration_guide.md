# Athena EEPROM Migration Guide

If you have an existing application that writes data to the EEPROM, here are the steps you need to take for converting your program to use `AthenaEEPROM.h` instead of the built-in `EEPROM.h`.

## 1. Make sure the Program's EEPROM data addresses start at 0x0

AthenaEEPROM translates application code offsets automatically inside of the library. The standard EEPROM calls do not need to change their addresses. Address "0x0" will start at the `NETEEPROM_END` location automatically. 

If you've manually adjusted addresses to take account the bootloader code, undo those changes.

## 2. Replace EEPROM.h with AthenaEEPROM.h EVERYWHERE the header is Used

This update is important, because the AthenaEEPROM library automatically provides an offset to bypass the reserved bootloader area. Also, if both headers are included in your application, the linker will throw an error due to duplicate definitions of the `EEPROM` object.

Only changing the header is necessary, existing EEPROM API calls will work without modification.

# 3. Replace Any IP, MAC, and SUBSET EEPROM programming calls with the AthenaEEPROM API

Instead of manually writing these values to the EEPROM in your application, you will use a single call to the `EEPROM.writeNet` function that is provided with `AthenaEEPROM.h`:

```
    /** Write the full network settings to the EEPROM and set the network
     *  settings signature in order to have the bootloader detect them.
     *  @param mac pointer to byte array where the MAC address is stored.
     *  @param ip IPAddress object with the IP to set for the Arduino.
     *  @param gw IPAddress object with the IP of the Gateway. Needed even for local use.
     *  @param sn IPAddress object with the Subnet Mask. */
    void writeNet(byte* mac, IPAddress ip, IPAddress gw, IPAddress sn);
```

Example use:

```
byte  mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress  ip(192, 168, 1, 120);
IPAddress  gateway(192, 168, 1, 1);
IPAddress  subnet(255, 255, 255, 0);

/* Write the new settings values to EEPROM */
EEPROM.writeNet(mac, ip, gateway, subnet);
```

These values can be read from the bootloader EEPROM space using the following `AthenaEEPROM` API calls:

```
/** Read the MAC address from EEPROM.
 *  @return  Pointer to allocated memory with the MAC address. */
byte* readMAC(void);
/** Read IP.
 *  @return IPAddress object with the IP of the Arduino. */
IPAddress readIP(void);
/** Read Gateway
 *  @return IPAddress object with the IP of the Gateway. */
IPAddress readGW(void);
/** Read Subnet Mask
 *  @return IPAddress object with the Subnet Mask. */
IPAddress readSN(void);
```

