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

#include "substrate_dispatch_V12.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_buy_vtbc_V12(
    parser_context_t* c, pd_buy_vtbc_V12_t* m)
{
    CHECK_ERROR(_readUInt8(c, &m->crypto_type.value))
    CHECK_ERROR(_readLookupCryptoTokenType_V12(c, &m->crypto_type))
    CHECK_ERROR(_readLookupCryptoAmount_V12(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cancel_buy_vtbc_order_V12(
    parser_context_t* c, pd_cancel_buy_vtbc_order_V12_t* m)
{
    c->offset += 1;
    CHECK_ERROR(_readLookupOrder_V12(c, &m->order_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cancel_sell_vtbc_order_V12(
    parser_context_t* c, pd_cancel_sell_vtbc_order_V12_t* m)
{
    c->offset += 1;
    CHECK_ERROR(_readLookupOrder_V12(c, &m->order_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sell_vtbc_V12(
    parser_context_t* c, pd_sell_vtbc_V12_t* m)
{
    CHECK_ERROR(_readUInt8(c, &m->crypto_type.value))
    CHECK_ERROR(_readLookupCryptoTokenType_V12(c, &m->crypto_type))
    CHECK_ERROR(_readLookupCryptoAmount_V12(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_withdraw_initiate_V12(
    parser_context_t* c, pd_withdraw_initiate_V12_t* m)
{
    CHECK_ERROR(_readUInt8(c, &m->crypto_type.value))
    CHECK_ERROR(_readLookupCryptoTokenType_V12(c, &m->crypto_type))
    CHECK_ERROR(_readLookupCryptoAmount_V12(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claim_distribution_V12(
    parser_context_t* c, pd_claim_distribution_V12_t* m)
{
    CHECK_ERROR(_readUInt8(c, &m->crypto_type.value))
    CHECK_ERROR(_readLookupCryptoTokenType_V12(c, &m->crypto_type))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_initiate_convert_vtbc_to_vtbt_substrate_V12(
    parser_context_t* c, pd_initiate_convert_vtbc_to_vtbt_substrate_V12_t* m)
{
    CHECK_ERROR(_readLookupCryptoAmount_V12(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_initiate_convert_vtbt_to_vtbc_substrate_V12(
    parser_context_t* c, pd_initiate_convert_vtbt_to_vtbc_substrate_V12_t* m)
{
    CHECK_ERROR(_readLookupCryptoAmount_V12(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_initiate_transfer_of_vtbt_substrate_V12(
    parser_context_t* c, pd_initiate_transfer_of_vtbt_substrate_V12_t* m)
{
    CHECK_ERROR(_readLookupAddress32_V12(c, &m->dest))
    CHECK_ERROR(_readLookupCryptoAmount_V12(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_check_and_remove_from_pending_list_V12(
    parser_context_t* c, pd_check_and_remove_from_pending_list_V12_t* m)
{
    CHECK_ERROR(_readLookupAddress32_V12(c, &m->dest))
    c->offset += 1;
    CHECK_ERROR(_readLookupId_V12(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_check_and_return_withdraw_pending_amount_V12(
    parser_context_t* c, pd_check_and_return_withdraw_pending_amount_V12_t* m)
{
    CHECK_ERROR(_readLookupAddress32_V12(c, &m->dest))
    c->offset += 1;
    CHECK_ERROR(_readLookupId_V12(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_set_vtb_dex_transaction_fee_V12(
    parser_context_t* c, pd_set_vtb_dex_transaction_fee_V12_t* m)
{
    CHECK_ERROR(_readLookupCryptoAmount_V12(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_set_vtb_dex_fee_collector_account_V12(
    parser_context_t* c, pd_set_vtb_dex_fee_collector_account_V12_t* m)
{
    CHECK_ERROR(_readLookupAddress32_V12(c, &m->dest))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_set_key_V12(
    parser_context_t* c, pd_set_key_V12_t* m)
{
    c->offset += 1;
    CHECK_ERROR(_readLookupAddress32_V12(c, &m->dest))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_set_code_V12(
    parser_context_t* c, pd_set_code_V12_t* m)
{
    c->offset += 1;
    CHECK_ERROR(_readLookupId_V12(c, &m->set_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_resume_crypto_functionality_V12(
    parser_context_t* c, pd_resume_crypto_functionality_V12_t* m)
{
    CHECK_ERROR(_readUInt8(c, &m->crypto_type.value))
    CHECK_ERROR(_readLookupCryptoTokenType_V12(c, &m->crypto_type))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stop_crypto_functionality_V12(
    parser_context_t* c, pd_stop_crypto_functionality_V12_t* m)
{
    CHECK_ERROR(_readUInt8(c, &m->crypto_type.value))
    CHECK_ERROR(_readLookupCryptoTokenType_V12(c, &m->crypto_type))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_unchecked_weight_V12(
    parser_context_t* c, pd_sudo_unchecked_weight_V12_t* m)
{
    CHECK_ERROR(_readUncheckedWeight_V12(c, &m->weight))
    c->offset = 2;
    // c->sizeModifier = 8;  
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_call_V12(
    parser_context_t* c, pd_sudo_call_V12_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

parser_error_t _readMethod_V12(
    parser_context_t *c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V12_t *method)
{

    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;
    switch (callPrivIdx)
    {
    case 3092: /* module 12 call 20 */
        CHECK_ERROR(_readMethod_claim_distribution_V12(c, &method->basic.claim_distribution_V12))
        break;
    case 3087: /* module 12 call 15 */
        CHECK_ERROR(_readMethod_initiate_transfer_of_vtbt_substrate_V12(c, &method->basic.initiate_transfer_of_vtbt_substrate_V12))
        break;
    case 3086: /* module 12 call 14 */
        CHECK_ERROR(_readMethod_initiate_convert_vtbt_to_vtbc_substrate_V12(c, &method->basic.initiate_convert_vtbt_to_vtbc_substrate_V12))
        break;
    case 3085: /* module 12 call 13 */
        CHECK_ERROR(_readMethod_initiate_convert_vtbc_to_vtbt_substrate_V12(c, &method->basic.initiate_convert_vtbc_to_vtbt_substrate_V12))
        break;
    case 3084: /* module 12 call 12 */
        CHECK_ERROR(_readMethod_withdraw_initiate_V12(c, &method->basic.withdraw_initiate_V12))
        break;
    case 3083: /* module 12 call 11 */
        CHECK_ERROR(_readMethod_cancel_sell_vtbc_order_V12(c, &method->basic.cancel_sell_vtbc_order_V12))
        break;
    case 3082: /* module 12 call 10 */
        CHECK_ERROR(_readMethod_sell_vtbc_V12(c, &method->basic.sell_vtbc_V12))
        break;
    case 3081: /* module 12 call 9 */
        CHECK_ERROR(_readMethod_cancel_buy_vtbc_order_V12(c, &method->basic.cancel_buy_vtbc_order_V12))
        break;
    case 3080: /* module 12 call 8 */
        CHECK_ERROR(_readMethod_buy_vtbc_V12(c, &method->basic.buy_vtbc_V12))
        break;
    case 3079: /* module 12 call 7 */
        CHECK_ERROR(_readMethod_resume_crypto_functionality_V12(c, &method->basic.resume_crypto_functionality_V12))
        break;
    case 3078: /* module 12 call 6 */
        CHECK_ERROR(_readMethod_stop_crypto_functionality_V12(c, &method->basic.stop_crypto_functionality_V12))
        break;
    case 3077: /* module 12 call 5 */
               // resumeVTBdexFunc
        break;
    case 3076: /* module 12 call 4 */
               // stopVTBdexFunc
        break;
    case 3075: /* module 12 call 3 */
        CHECK_ERROR(_readMethod_check_and_remove_from_pending_list_V12(c, &method->basic.check_and_remove_from_pending_list_V12))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_check_and_return_withdraw_pending_amount_V12(c, &method->basic.check_and_return_withdraw_pending_amount_V12))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_set_vtb_dex_transaction_fee_V12(c, &method->basic.set_vtb_dex_transaction_fee_V12))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_set_vtb_dex_fee_collector_account_V12(c, &method->basic.set_vtb_dex_fee_collector_account_V12))
        break;
    case 1794: /* module 7 call 2 */
        CHECK_ERROR(_readMethod_set_key_V12(c, &method->basic.set_key_V12))
        break;
    case 1793: /* module 7 call 1 */
        CHECK_ERROR(_readMethod_sudo_unchecked_weight_V12(c, &method->basic.sudo_unchecked_weight_V12))
        break;
    case 1792: /* module 7 call 0 */
        CHECK_ERROR(_readMethod_sudo_call_V12(c, &method->basic.sudo_call_V12))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_set_code_V12(c, &method->basic.set_code_V12))
        break;
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V12(uint8_t moduleIdx)
{
    switch (moduleIdx)
    {
    case 0:
        return STR_MO_SYSTEM;
    case 7:
        return STR_MO_SUDO;
    case 8:
    case 12:
        return STR_MO_VTBDEX;
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V12(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx)
    {
    case 3092: /* module 12 call 20 */
        return STR_ME_CLAIM_DISTRIBUTION;
    case 3087: /* module 12 call 15 */
        return STR_ME_INITIATE_TRANSFER_OF_VTBT_SUBSTRATE;
    case 3086: /* module 12 call 14 */
        return STR_ME_INITIATE_CONVERT_VTBT_TO_VTBC_SUBSTRATE;
    case 3085: /* module 12 call 13 */
        return STR_ME_INITIATE_CONVERT_VTBC_TO_VTBT_SUBSTRATE;
    case 3084: /* module 12 call 12 */
        return STR_ME_WITHDRAW_INITIATE;
    case 3083: /* module 12 call 11 */
        return STR_ME_CANCEL_SELL_VTBC_ORDER;
    case 3082: /* module 12 call 10 */
        return STR_ME_SELL_VTBC;
    case 3081: /* module 12 call 9 */
        return STR_ME_CANCEL_BUY_VTBC_ORDER;
    case 3080: /* module 12 call 8 */
        return STR_ME_BUY_VTBC;
    case 3079: /* module 12 call 7 */
        return STR_ME_RESUME_CRYPTO_FUNCTIONALITY;
    case 3078: /* module 12 call 6 */
        return STR_ME_STOP_CRYPTO_FUNCTIONALITY;
    case 3077: /* module 12 call 5 */
        return STR_ME_RESUME_VTB_DEX_FUNCTIONALITY;
    case 3076: /* module 12 call 4 */
        return STR_ME_STOP_VTB_DEX_FUNCTIONALITY;
    case 3075: /* module 12 call 3 */
        return STR_ME_CHECK_AND_REMOVE_FROM_PENDING_LIST;
    case 3074: /* module 12  call 2 */
        return STR_ME_CHECK_AND_RETURN_WITHDRAW_PENDING_AMOUNT;
    case 3073: /* module 12 call 1 */
        return STR_ME_SET_VTB_DEX_TRANSACTION_FEE;
    case 3072: /* module 12 call 0 */
        return STR_ME_SET_VTB_DEX_FEE_COLLECTOR_ACCOUNT;
    case 1794: /* module 7 call 2 */
        return STR_ME_SET_KEY;
    case 1793: /* module 7 call 1 */
        return STR_ME_SUDO_UNCHECKED_WEIGHT;
    case 1792: /* module 7 call 0 */
        return STR_ME_SUDO_CALL;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V12(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx)
    {
    case 3092: /* module 12 call 20 */
        return 1;
    case 3087: /* module 12 call 15 */
        return 2;
    case 3086: /* module 12 call 14 */
        return 1;
    case 3085: /* module 12 call 13 */
        return 1;
    case 3084: /* module 12 call 12 */
        return 2;
    case 3083: /* module 12 call 11 */
        return 1;
    case 3082: /* module 12 call 10 */
        return 2;
    case 3081: /* module 12 call 9 */
        return 1;
    case 3080: /* module 12 call 8 */
        return 2;
    case 3079: /* module 12 call 7 */
        return 1;
    case 3078: /* module 12 call 6 */
        return 1;
    case 3075: /* module 12 call 3 */
        return 2;
    case 3074: /* module 12 call 2 */
        return 2;
    case 3073: /* module 12 call 1 */
        return 1;
    case 3072: /* module 12 call 0 */
        return 1;
    case 1794: /* module 7 call 2 */
        return 1;
    case 1793: /* module 7 call 1 */
        return 2;
    case 1792: /* module 7 call 0 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V12(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx)
    {
    case 3092: /* module 12 call 20 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_crypto_type;
        default:
            return NULL;
        }
    case 3087: /* module 12 call 15 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_crypto_amount;
        default:
            return NULL;
        }
    case 3086: /* module 12 call 14 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_crypto_amount;
        default:
            return NULL;
        }
    case 3085: /* module 12 call 13 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_crypto_amount;
        default:
            return NULL;
        }
    case 3084: /* module 12 call 12 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_crypto_type;
        case 1:
            return STR_IT_crypto_amount;
        default:
            return NULL;
        }
    case 3083: /* module 12 call 11 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_order_id;
        default:
            return NULL;
        }
    case 3082: /* module 12 call 10 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_crypto_type;
        case 1:
            return STR_IT_crypto_amount;
        default:
            return NULL;
        }
    case 3081: /* module 12 call 9 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_order_id;
        default:
            return NULL;
        }
    case 3080: /* module 12 call 8 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_crypto_type;
        case 1:
            return STR_IT_crypto_amount;
        default:
            return NULL;
        }
    case 3079: /* module 12 call 7 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_crypto_type;
        default:
            return NULL;
        }
    case 3078: /* module 12 call 6 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_crypto_type;
        default:
            return NULL;
        }
    case 3075: /* module 12 call 3 */
         switch (itemIdx)
        {
        case 0:
            return STR_IT_account;
        case 1:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 3074: /* module 12 call 2 */
         switch (itemIdx)
        {
        case 0:
            return STR_IT_recipient;
        case 1:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 3073: /* module 12 call 1 */
         switch (itemIdx)
        {
        case 0:
            return STR_IT_fee_amount;
        default:
            return NULL;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 1794: /* module 7 call 2 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 1793: /* module 7 call 1 */
        switch(itemIdx) 
        {
        case 0:
            return STR_IT_weight;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx)
        {
         case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V12(
    pd_Method_V12_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx)
    {
    case 3092: /* module 12 call 20 */
        switch (itemIdx)
        {
        case 0: /* claim_distribution - network */;
            return _toStringLookupCryptoTokenType_V12(
                &m->basic.claim_distribution_V12.crypto_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3087: /* module 12 call 15 */
        switch (itemIdx)
        {
        case 0: /* initiate_transfer_of_vtbt_substrate - dest */;
            return _toStringLookupasStaticLookupAddress_V12(
                &m->basic.initiate_transfer_of_vtbt_substrate_V12.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* initiate_transfer_of_vtbt_substrate - amount */;
            return _toStringCompactAmount(
                &m->basic.initiate_transfer_of_vtbt_substrate_V12.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3086: /* module 12 call 14 */
        switch (itemIdx)
        {
        case 0: /* initiate_convert_vtbt_to_vtbc_substrate - amount */;
            return _toStringCompactAmount(
                &m->basic.initiate_convert_vtbt_to_vtbc_substrate_V12.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3085: /* module 12 call 13 */
        switch (itemIdx)
        {
        case 0: /* initiate_convert_vtbc_to_vtbt_substrate - amount */;
            return _toStringCompactAmount(
                &m->basic.initiate_convert_vtbc_to_vtbt_substrate_V12.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3084: /* module 12 call 12 */
        switch (itemIdx)
        {
        case 0: /* withdraw_initiate - network */;
            return _toStringLookupCryptoTokenType_V12(
                &m->basic.withdraw_initiate_V12.crypto_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* withdraw_initiate - amount */;
            return _toStringCompactAmount(
                &m->basic.withdraw_initiate_V12.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3083: /* module 12 call 11 */
        switch (itemIdx)
        {
        case 0: /* cancel_sell_vtbc_V11 - order_id */;
            return _toStringLookupasStaticLookupOrder_V12(
                &m->basic.cancel_sell_vtbc_order_V12.order_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3082: /* module 12 call 10 */
        switch (itemIdx)
        {
        case 0: /* sell_vtbc_V12 - network */;
            return _toStringLookupCryptoTokenType_V12(
                &m->basic.sell_vtbc_V12.crypto_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sell_vtbc_V12 - amount */;
            return _toStringCompactAmount(
                &m->basic.sell_vtbc_V12.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3081: /* module 12 call 9 */
        switch (itemIdx)
        {
        case 0: /* cancel_sell_vtbc_V11 - order_id */;
            return _toStringLookupasStaticLookupOrder_V12(
                &m->basic.cancel_buy_vtbc_order_V12.order_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3080: /* module 12 call 8 */
        switch (itemIdx)
        {
        case 0: /* buy_vtbc_V12 - network */;
            return _toStringLookupCryptoTokenType_V12(
                &m->basic.buy_vtbc_V12.crypto_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* buy_vtbc_V12 - amount */;
            return _toStringCompactAmount(
                &m->basic.buy_vtbc_V12.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3079: /* module 12 call 7 */
        switch (itemIdx)
        {
        case 0: /* resume_crypto_functionality - network */;
            return _toStringLookupCryptoTokenType_V12(
                &m->basic.resume_crypto_functionality_V12.crypto_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3078: /* module 12 call 6 */
        switch (itemIdx)
        {
        case 0: /* stop_crypto_functionality - network */;
            return _toStringLookupCryptoTokenType_V12(
                &m->basic.stop_crypto_functionality_V12.crypto_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3075: /* module 12 call 3 */
         switch (itemIdx)
        {
        case 0: /* check_and_remove_from_pending_list - dest */;
            return _toStringLookupasStaticLookupAddress_V12(
                &m->basic.check_and_remove_from_pending_list_V12.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* check_and_remove_from_pending_list - id */
            return _toStringId_V12(
                &m->basic.check_and_remove_from_pending_list_V12.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3074: /* module 12 call 2 */
         switch (itemIdx)
        {
        case 0: /* check_and_return_withdraw_pending_amount - dest */;
            return _toStringLookupasStaticLookupAddress_V12(
                &m->basic.check_and_return_withdraw_pending_amount_V12.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* check_and_return_withdraw_pending_amount - id */
            return _toStringId_V12(
                &m->basic.check_and_return_withdraw_pending_amount_V12.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx)
        {
        case 0: /* set_vbt_dex_transaction_fee - fee amount */
            return _toStringCompactAmount(
                &m->basic.set_vtb_dex_transaction_fee_V12.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        } 
    case 3072: /* module 12 call 0 */
        switch (itemIdx)
        {
        case 0: /* set_vtb_dex_collector_fee_account - dest */
            return _toStringLookupasStaticLookupAddress_V12(
                &m->basic.set_vtb_dex_fee_collector_account_V12.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        } 
    case 1794: /* module 7 call 2 */
        switch (itemIdx)
        {
        case 0: /* set_key - dest */
            return _toStringLookupasStaticLookupAddress_V12(
                &m->basic.set_key_V12.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        } 
    case 1793: /* module 7 call 1 */
        switch (itemIdx)
        {
        case 0: /* sudo_unchecked_weight - weight */;
            return _toStringUncheckedWeight_V12(
                &m->basic.sudo_unchecked_weight_V12.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_unchecked_weight  - call */;
            return _toStringCall(
                &m->basic.sudo_unchecked_weight_V12.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) 
        {
        case 0: /* Sudo - call */;
            return _toStringCall(
                &m->basic.sudo_call_V12.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx)
       {
        case 0: /* set_code - id */
            return _toStringId_V12(
                &m->basic.set_code_V12.set_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
       } 
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V12(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    return false;
}

bool _getMethod_IsNestingSupported_V12(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx)
    {
    case 1792: // Sudo:sudo call
        return false;
    default:
        return true;
    }
}
