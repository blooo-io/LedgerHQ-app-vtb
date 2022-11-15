/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define COIN_ADDR_TYPE 42 // change 0 to 42 for general
#define CLA 0x9c

#define HDPATH_LEN_DEFAULT 5
#define HDPATH_0_DEFAULT (0x80000000 | 0x2c)
#define HDPATH_1_DEFAULT (0x80000000 | 0x2b6) //change from 0x162 to 0x2b6
#define HDPATH_1_RECOVERY (0x80000000 | 0x2b6) //change from 0x1b2 to 0x2b6

#define HDPATH_2_DEFAULT (0x80000000u | 0u)
#define HDPATH_3_DEFAULT (0u)
#define HDPATH_4_DEFAULT (0u)

#define SK_LEN_25519 64u
#define SCALAR_LEN_ED25519 32u
#define SIG_PLUS_TYPE_LEN 65u

#define PK_LEN_25519 32u
#define MAX_SIGN_SIZE 256u
#define BLAKE2B_DIGEST_SIZE 32u

typedef enum {
    key_ed25519 = 0,

#if defined(SUPPORT_SR25519)
    key_sr25519 = 1
#endif

} key_kind_e;

// Coin Specific
#define PK_ADDRESS_TYPE COIN_ADDR_TYPE
#define SUPPORTED_TX_VERSION_CURRENT LEDGER_MAJOR_VERSION
#define SUPPORTED_TX_VERSION_PREVIOUS (LEDGER_MAJOR_VERSION - 1)
#define SUPPORTED_SPEC_VERSION (LEDGER_MINOR_VERSION + 0)
#define SUPPORTED_MINIMUM_SPEC_VERSION 107

#define COIN_AMOUNT_DECIMAL_PLACES 18 // change 10 to 18
#define MAINCOIN_GENESIS_HASH "286bc8414c7000ce1d6ee6a834e29a54c1784814b76243eb77ed0b2c5573c60f"
#define TESTCOIN_GENESIS_HASH "7483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa"
#define COIN_NAME "VTB"
#define COIN_TICKER "VTB "

#define COIN_SECRET_REQUIRED_CLICKS 10

#define MENU_MAIN_APP_LINE1 "VTB"
#define MENU_MAIN_APP_LINE2 "Ready"
#define MENU_MAIN_APP_LINE2_SECRET "VTB RECOVERY"
#define APPVERSION_LINE1 "VTB"
#define APPVERSION_LINE2 "v" APPVERSION

#ifdef __cplusplus
}
#endif
