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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "substrate_types.h"
#include "substrate_types_V12.h"
#include <stddef.h>
#include <stdint.h>

#define PD_SUDO_UNCHECKED_WEIGHT 1793
    typedef struct 
    {
        pd_Call_t call;
        pd_u64_t weight;
    } pd_sudo_unchecked_weight_V12_t;

#define PD_BUY_VTBC_V12 3080
    typedef struct
    {
        compactInt_t value;
        pd_LookupCryptoTokenType_V12_t crypto_type;
    } pd_buy_vtbc_V12_t;

#define PD_SELL_VTBC_V12 3082
    typedef struct
    {
        compactInt_t value;
        pd_LookupCryptoTokenType_V12_t crypto_type;
    } pd_sell_vtbc_V12_t;

#define PD_CANCEL_VTBC_ORDER_V12 3081
    typedef struct
    {
        pd_LookupTradeType_V12_t trade_type;
        pd_Bytes_t order_id;
        pd_LookupCryptoTokenType_V12_t crypto_type;
    } pd_cancel_vtbc_order_V12_t;

#define PD_WITHDRAW_INITIATE_V12 3084
    typedef struct
    {
        compactInt_t value;
        pd_LookupCryptoTokenType_V12_t crypto_type;
    } pd_withdraw_initiate_V12_t;

#define PD_CLAIM_DISTRIBUTION_V12 3092
    typedef struct
    {
        pd_LookupCryptoTokenType_V12_t crypto_type;
    } pd_claim_distribution_V12_t;

#define PD_INITIATE_CONVERT_VTBC_TO_VTBT_SUBSTRATE_V12 3085
    typedef struct
    {
        compactInt_t value;
    } pd_initiate_convert_vtbc_to_vtbt_substrate_V12_t;

#define PD_INITIATE_CONVERT_VTBT_TO_VTBC_SUBSTRATE_V12 3086
    typedef struct
    {
        compactInt_t value;
    } pd_initiate_convert_vtbt_to_vtbc_substrate_V12_t;

#define PD_INITIATE_TRANSFER_OF_VTBT_SUBSTRATE_V12 3087
    typedef struct
    {
        pd_LookupCryptoAddress_V12_t dest;
        compactInt_t value;
    } pd_initiate_transfer_of_vtbt_substrate_V12_t;

#define PD_SUDO_CALL_V12 0
    typedef struct {
        pd_Call_t call;
    } pd_sudo_call_V12_t;

#ifdef SUBSTRATE_PARSER_FULL

#endif

    typedef union
    {
        pd_buy_vtbc_V12_t buy_vtbc_V12;
        pd_sell_vtbc_V12_t sell_vtbc_V12;
        pd_sudo_call_V12_t sudo_call_V12;
        pd_sudo_unchecked_weight_V12_t sudo_unchecked_weight_V12;
        pd_withdraw_initiate_V12_t withdraw_initiate_V12;
        pd_claim_distribution_V12_t claim_distribution_V12;
        pd_initiate_convert_vtbc_to_vtbt_substrate_V12_t initiate_convert_vtbc_to_vtbt_substrate_V12;
        pd_initiate_convert_vtbt_to_vtbc_substrate_V12_t initiate_convert_vtbt_to_vtbc_substrate_V12;
        pd_initiate_transfer_of_vtbt_substrate_V12_t initiate_transfer_of_vtbt_substrate_V12;
        pd_cancel_vtbc_order_V12_t cancel_vtbc_order_V12;

#ifdef SUBSTRATE_PARSER_FULL
#endif
    } pd_MethodBasic_V12_t;

#define PD_SET_CODE_V12 3
    typedef struct
    {
        pd_Bytes_t code;
    } pd_set_code_V12_t;

#define PD_SET_KEY_V12 1794
    typedef struct
    {
        pd_LookupCryptoAddress_V12_t dest;
    } pd_set_key_V12_t;

#define PD_SET_VTB_DEX_FEE_COLLECTOR_ACCOUNT_V12 3072
    typedef struct
    {
        pd_LookupCryptoAddress_V12_t dest;
    } pd_set_vtb_dex_fee_collector_account_V12_t;

#define PD_SET_VTB_DEX_TRANSACTION_FEE_V12 3073
    typedef struct
    {
        compactInt_t value;
    } pd_set_vtb_dex_transaction_fee_V12_t;

#define PD_SET_CHECK_AND_RETURN_WITHDRAW_PENDING_AMOUNT 3074
    typedef struct
    {
        pd_LookupCryptoAddress_V12_t dest;
        pd_LookupId_V12_t id;
    } pd_check_and_return_withdraw_pending_amount_V12_t;

#define PD_SET_CHECK_AND_REMOVE_FROM_LIST 3075
    typedef struct
    {
        pd_LookupCryptoAddress_V12_t dest;
        pd_LookupId_V12_t id;
    } pd_check_and_remove_from_pending_list_V12_t;

#define PD_STOP_CRYPTO_FUNCTIONALITY_V12 3078
    typedef struct
    {
        compactInt_t value;
        pd_LookupCryptoTokenType_V12_t crypto_type;
    } pd_stop_crypto_functionality_V12_t;

#define PD_RESUME_CRYPTO_FUNCTIONALITY_V12 3079
    typedef struct
    {
        compactInt_t value;
        pd_LookupCryptoTokenType_V12_t crypto_type;
    } pd_resume_crypto_functionality_V12_t;

#ifdef SUBSTRATE_PARSER_FULL
#endif

    typedef union
    {
        pd_set_code_V12_t set_code_V12;
        pd_set_key_V12_t set_key_V12;
        pd_set_vtb_dex_transaction_fee_V12_t set_vtb_dex_transaction_fee_V12;
        pd_set_vtb_dex_fee_collector_account_V12_t set_vtb_dex_fee_collector_account_V12;
        pd_check_and_return_withdraw_pending_amount_V12_t check_and_return_withdraw_pending_amount_V12;
        pd_check_and_remove_from_pending_list_V12_t check_and_remove_from_pending_list_V12;
        pd_resume_crypto_functionality_V12_t resume_crypto_functionality_V12;
        pd_stop_crypto_functionality_V12_t stop_crypto_functionality_V12;

#ifdef SUBSTRATE_PARSER_FULL
#endif
    } pd_MethodNested_V12_t;

    typedef union
    {
        pd_MethodBasic_V12_t basic;
        pd_MethodNested_V12_t nested;
    } pd_Method_V12_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
