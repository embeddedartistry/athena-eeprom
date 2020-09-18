/*
 * AthenaEEPROM_defs.h - Athena Bootloader helper library
 * Copyright (c) 2012 Stylianos Tsampas.  All right reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef AthenaEEPROM_defs_h
#define AthenaEEPROM_defs_h

/* EEPROM partitioning */
#define NETEEPROM_START 0
#define NETEEPROM_MAJVER NETEEPROM_START
#define NETEEPROM_MINVER (NETEEPROM_START + 1)
#define NETEEPROM_IMG_STAT (NETEEPROM_START + 2)
#define NETEEPROM_SIG_1 (NETEEPROM_START + 3)
#define NETEEPROM_SIG_2 (NETEEPROM_START + 4)
#define NETEEPROM_DATA (NETEEPROM_START + 5) // used by bootloader
#define NETEEPROM_GW (NETEEPROM_START + 5)
#define NETEEPROM_SN (NETEEPROM_START + 9)
#define NETEEPROM_MAC (NETEEPROM_START + 13)
#define NETEEPROM_IP (NETEEPROM_START + 19)
#define NETEEPROM_SIG_3 (NETEEPROM_START + 23)
#define NETEEPROM_PORT (NETEEPROM_START + 24)
#define NETEEPROM_SIG_4 (NETEEPROM_START + 26)
#define NETEEPROM_PASS (NETEEPROM_START + 27)
#define NETEEPROM_TFTP_MODE_RESERVED (NETEEPROM_START + 63)
#define NETEEPROM_BOOT_DELAY_RESERVED (NETEEPROM_START + 64)
#define NETEEPROM_ATHENA_VER_MAJOR (NETEEPROM_START + 65)
#define NETEEPROM_ATHENA_VER_MINOR (NETEEPROM_START + 66)
#define NETEEPROM_ATHENA_VER_PATCH (NETEEPROM_START + 67)
// This is set using the Arduino pin number (e.g., 53)
#define NETEEPROM_ETHERNET_CS_PIN (NETEEPROM_START + 68)
// This is set using the Arduino pin number (e.g., 53)
#define NETEEPROM_ETHERNET_RESET_PIN (NETEEPROM_START + 69)
#define NETEEPROM_END (NETEEPROM_START + 70)
#define NETEEPROM_OFFSET NETEEPROM_END

#define EEPROM_SETTINGS_SIZE 18
#define REGISTER_BLOCK_SIZE 28

/* Athena EEPROM values */
#define ATHENA_EEPROM_FORMAT_MAJVER 1
#define ATHENA_EEPROM_FORMAT_MINVER 3

#define NETEEPROM_IMG_BAD_VALUE (0xFF)
#define NETEEPROM_IMG_OK_VALUE (0xEE)
#define NETEEPROM_ENTER_UPDATE_MODE_VALUE (0xDD)

#define NETEEPROM_SIG_1_VALUE (0x55)
#define NETEEPROM_SIG_2_VALUE (0xAA)
#define NETEEPROM_SIG_3_VALUE (0xBB)
#define NETEEPROM_SIG_4_VALUE (0xCC)

#define DEFAULT_MAC_ADDR 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
#define DEFAULT_IP_ADDR 192, 168, 1, 128
#define DEFAULT_SUB_MASK 255, 255, 255, 0
#define DEFAULT_GW_ADDR 192, 168, 1, 1

#endif
