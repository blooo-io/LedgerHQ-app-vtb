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
    case 2560:  // Preimage:Note preimage
    case 2561:  // Preimage:Unnote preimage
    case 2562:  // Preimage:Request preimage
    case 2563:  // Preimage:Unrequest preimage
    case 768:   // Timestamp:Set
    case 1024:  // Indices:Claim
    case 1025:  // Indices:Transfer
    case 1026:  // Indices:Free
    case 1027:  // Indices:Force transfer
    case 1028:  // Indices:Freeze
    case 1284:  // Balances:Transfer all
    case 1285:  // Balances:Force unreserve
    case 1792:  // Staking:Bond
    case 1793:  // Staking:Bond extra
    case 1794:  // Staking:Unbond
    case 1795:  // Staking:Withdraw Unbonded
    case 1796:  // Staking:Validate
    case 1797:  // Staking:Nominate
    case 1798:  // Staking:Chill
    case 1799:  // Staking:Set payee
    case 1800:  // Staking:Set controller
    case 1801:  // Staking:Set validator count
    case 1802:  // Staking:Increase validator count
    case 1804:  // Staking:Force no eras
    case 1805:  // Staking:Force new era
    case 1806:  // Staking:Set invulnerables
    case 1807:  // Staking:Force unstake
    case 1808:  // Staking:Force new era always
    case 1809:  // Staking:Cancel deferred slash
    case 1810:  // Staking:Payout stakers
    case 1811:  // Staking:Rebond
    case 1812:  // Staking:Set history depth
    case 1813:  // Staking:Reap stash
    case 1814:  // Staking:Kick
    case 1816:  // Staking:Chill other
    case 1817:  // Staking:Force apply min commission
    case 2304:  // Session:Set keys
    case 2305:  // Session:Purge keys
    case 2818:  // Grandpa:Note stalled
    case 3584:  // Democracy:Propose
    case 3585:  // Democracy:Second
    case 3586:  // Democracy:Vote
    case 3587:  // Democracy:Emergency cancel
    case 3588:  // Democracy:External propose
    case 3589:  // Democracy:External propose majority
    case 3590:  // Democracy:External propose default
    case 3591:  // Democracy:Fast track
    case 3592:  // Democracy:Veto external
    case 3593:  // Democracy:Cancel referendum
    case 3594:  // Democracy:Cancel queued
    case 3595:  // Democracy:Delegate
    case 3596:  // Democracy:Undelegate
    case 3597:  // Democracy:Clear public proposals
    case 3598:  // Democracy:Note preimage
    case 3599:  // Democracy:Note preimage operational
    case 3600:  // Democracy:Note imminent preimage
    case 3601:  // Democracy:Note imminent preimage operational
    case 3602:  // Democracy:Reap preimage
    case 3603:  // Democracy:Unlock
    case 3604:  // Democracy:Remove vote
    case 3605:  // Democracy:Remove other vote
    case 3606:  // Democracy:Enact proposal
    case 3608:  // Democracy:Cancel proposal
    case 3840:  // Council:Set members
    case 3841:  // Council:Execute
    case 3842:  // Council:Propose
    case 3843:  // Council:Vote
    case 3844:  // Council:Close
    case 3845:  // Council:Disapprove proposal
    case 4096:  // TechnicalCommittee:Set members
    case 4097:  // TechnicalCommittee:Execute
    case 4098:  // TechnicalCommittee:Propose
    case 4099:  // TechnicalCommittee:Vote
    case 4100:  // TechnicalCommittee:Close
    case 4101:  // TechnicalCommittee:Disapprove proposal
    case 4352:  // PhragmenElection:Vote
    case 4353:  // PhragmenElection:Remove voter
    case 4354:  // PhragmenElection:Submit candidacy
    case 4356:  // PhragmenElection:Remove member
    case 4357:  // PhragmenElection:Clean defunct voters
    case 4608:  // TechnicalMembership:Add member
    case 4609:  // TechnicalMembership:Remove member
    case 4610:  // TechnicalMembership:Swap member
    case 4611:  // TechnicalMembership:Reset members
    case 4612:  // TechnicalMembership:Change key
    case 4613:  // TechnicalMembership:Set prime
    case 4614:  // TechnicalMembership:Clear prime
    case 4864:  // Treasury:Propose spend
    case 4865:  // Treasury:Reject proposal
    case 4866:  // Treasury:Approve proposal
    case 4867:  // Treasury:Remove approval
    case 6144:  // Claims:Claim
    case 6146:  // Claims:Claim attest
    case 6147:  // Claims:Attest
    case 6148:  // Claims:Move claim
    case 6400:  // Vesting:Vest
    case 6401:  // Vesting:Vest other
    case 6402:  // Vesting:Vested transfer
    case 6403:  // Vesting:Force vested transfer
    case 6404:  // Vesting:Merge schedules
    case 6656:  // Utility:Batch
    case 6658:  // Utility:Batch all
    case 6660:  // Utility:Force batch
    case 7168:  // Identity:Add registrar
    case 7171:  // Identity:Clear identity
    case 7172:  // Identity:Request judgement
    case 7173:  // Identity:Cancel request
    case 7174:  // Identity:Set fee
    case 7175:  // Identity:Set account id
    case 7178:  // Identity:Kill identity
    case 7181:  // Identity:Remove sub
    case 7182:  // Identity:Quit sub
    case 7425:  // Proxy:Add proxy
    case 7426:  // Proxy:Remove proxy
    case 7427:  // Proxy:Remove proxies
    case 7428:  // Proxy:Anonymous
    case 7429:  // Proxy:Kill anonymous
    case 7433:  // Proxy:Proxy announced
    case 8704:  // Bounties:Propose bounty
    case 8705:  // Bounties:Approve bounty
    case 8706:  // Bounties:Propose curator
    case 8707:  // Bounties:Unassign curator
    case 8708:  // Bounties:Accept curator
    case 8709:  // Bounties:Award bounty
    case 8710:  // Bounties:Claim bounty
    case 8711:  // Bounties:Close bounty
    case 8712:  // Bounties:Extend bounty expiry
    case 9728:  // ChildBounties:Add child bounty
    case 9729:  // ChildBounties:Propose curator
    case 9730:  // ChildBounties:Accept curator
    case 9731:  // ChildBounties:Unassign curator
    case 9732:  // ChildBounties:Award child bounty
    case 9733:  // ChildBounties:Claim child bounty
    case 9734:  // ChildBounties:Close child bounty
    case 8960:  // Tips:Report awesome
    case 8961:  // Tips:Retract tip
    case 8962:  // Tips:Tip new
    case 8963:  // Tips:Tip
    case 8964:  // Tips:Close tip
    case 8965:  // Tips:Slash tip
    case 9220:  // ElectionProviderMultiPhase:Governance fallback
    case 9472:  // BagsList:Rebag
    case 9473:  // BagsList:Put in front of
    case 13056: // Configuration:Set validation upgrade cooldown
    case 13057: // Configuration:Set validation upgrade delay
    case 13058: // Configuration:Set code retention period
    case 13059: // Configuration:Set max code size
    case 13060: // Configuration:Set max pov size
    case 13061: // Configuration:Set max head data size
    case 13062: // Configuration:Set parathread cores
    case 13063: // Configuration:Set parathread retries
    case 13064: // Configuration:Set group rotation frequency
    case 13065: // Configuration:Set chain availability period
    case 13066: // Configuration:Set thread availability period
    case 13067: // Configuration:Set scheduling lookahead
    case 13068: // Configuration:Set max validators per core
    case 13069: // Configuration:Set max validators
    case 13071: // Configuration:Set dispute post conclusion acceptance period
    case 13072: // Configuration:Set dispute max spam slots
    case 13073: // Configuration:Set dispute conclusion by time out period
    case 13074: // Configuration:Set no show slots
    case 13075: // Configuration:Set n delay tranches
    case 13076: // Configuration:Set zeroth delay tranche width
    case 13077: // Configuration:Set needed approvals
    case 13078: // Configuration:Set relay vrf modulo samples
    case 13079: // Configuration:Set max upward queue count
    case 13080: // Configuration:Set max upward queue size
    case 13081: // Configuration:Set max downward message size
    case 13082: // Configuration:Set ump service total weight
    case 13083: // Configuration:Set max upward message size
    case 13084: // Configuration:Set max upward message num per candidate
    case 13085: // Configuration:Set hrmp open request ttl
    case 13086: // Configuration:Set hrmp sender deposit
    case 13087: // Configuration:Set hrmp recipient deposit
    case 13088: // Configuration:Set hrmp channel max capacity
    case 13089: // Configuration:Set hrmp channel max total size
    case 13090: // Configuration:Set hrmp max parachain inbound channels
    case 13091: // Configuration:Set hrmp max parathread inbound channels
    case 13092: // Configuration:Set hrmp channel max message size
    case 13093: // Configuration:Set hrmp max parachain outbound channels
    case 13094: // Configuration:Set hrmp max parathread outbound channels
    case 13095: // Configuration:Set hrmp max message num per candidate
    case 13096: // Configuration:Set ump max individual weight
    case 13097: // Configuration:Set pvf checking enabled
    case 13098: // Configuration:Set pvf voting ttl
    case 13099: // Configuration:Set minimum validation upgrade delay
    case 13100: // Configuration:Set bypass consistency check
    case 14592: // Initializer:Force approve
    case 15364: // Hrmp:Force process hrmp open
    case 15365: // Hrmp:Force process hrmp close
    case 15872: // ParasDisputes:Force unfreeze
    case 17925: // Registrar:Reserve
    case 18432: // Auctions:New auction
    case 18433: // Auctions:Bid
    case 18434: // Auctions:Cancel auction
    case 18688: // Crowdloan:Create
    case 18689: // Crowdloan:Contribute
    case 18690: // Crowdloan:Withdraw
    case 18691: // Crowdloan:Refund
    case 18692: // Crowdloan:Dissolve
    case 18693: // Crowdloan:Edit
    case 18694: // Crowdloan:Add memo
    case 18695: // Crowdloan:Poke
    case 18696: // Crowdloan:Contribute all
        return false;
    default:
        return true;
    }
}
