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

#include "parser_common.h"
#include "substrate_methods_V12.h"
#include "substrate_types_V12.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readLookupCryptoTokenType_V12(parser_context_t* c,pd_LookupCryptoTokenType_V12_t* v);
parser_error_t _readLookupCryptoAmount_V12(parser_context_t* c,compactInt_t* v);
parser_error_t _readLookupOrder_V12(parser_context_t* c,pd_LookupCryptoOrder_V12_t* v);
parser_error_t _readLookupId_V12(parser_context_t* c, pd_LookupId_V12_t* v);
parser_error_t _readLookupAddress32_V12(parser_context_t *c, pd_LookupCryptoAddress_V12_t *v);
parser_error_t _readAccountId_V12(parser_context_t* c, pd_AccountId_V12_t* v);
parser_error_t _readAccountIndex_V12(parser_context_t* c, pd_AccountIndex_V12_t* v);
parser_error_t _readAccountVoteSplit_V12(parser_context_t* c, pd_AccountVoteSplit_V12_t* v);
parser_error_t _readAccountVoteStandard_V12(parser_context_t* c, pd_AccountVoteStandard_V12_t* v);
parser_error_t _readAccountVote_V12(parser_context_t* c, pd_AccountVote_V12_t* v);
parser_error_t _readAuthorityIdasRuntimeAppPublicSignature_V12(parser_context_t* c, pd_AuthorityIdasRuntimeAppPublicSignature_V12_t* v);
parser_error_t _readBoxCallOrHashOfT_V12(parser_context_t* c, pd_BoxCallOrHashOfT_V12_t* v);
parser_error_t _readBoxEquivocationProofHashBlockNumber_V12(parser_context_t* c, pd_BoxEquivocationProofHashBlockNumber_V12_t* v);
parser_error_t _readBoxEquivocationProofHeader_V12(parser_context_t* c, pd_BoxEquivocationProofHeader_V12_t* v);
parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V12(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V12_t* v);
parser_error_t _readBoxMultiLocation_V12(parser_context_t* c, pd_BoxMultiLocation_V12_t* v);
parser_error_t _readBoxPalletsOrigin_V12(parser_context_t* c, pd_BoxPalletsOrigin_V12_t* v);
parser_error_t _readBoxRawSolutionSolutionOfT_V12(parser_context_t* c, pd_BoxRawSolutionSolutionOfT_V12_t* v);
parser_error_t _readBoxVersionedMultiAssets_V12(parser_context_t* c, pd_BoxVersionedMultiAssets_V12_t* v);
parser_error_t _readBoxVersionedMultiLocation_V12(parser_context_t* c, pd_BoxVersionedMultiLocation_V12_t* v);
parser_error_t _readBoxVersionedXcmTasSysConfigCall_V12(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V12_t* v);
parser_error_t _readBoxVersionedXcmTuple_V12(parser_context_t* c, pd_BoxVersionedXcmTuple_V12_t* v);
parser_error_t _readCallHashOf_V12(parser_context_t* c, pd_CallHashOf_V12_t* v);
parser_error_t _readCompactAccountIndex_V12(parser_context_t* c, pd_CompactAccountIndex_V12_t* v);
parser_error_t _readCompactPerBill_V12(parser_context_t* c, pd_CompactPerBill_V12_t* v);
parser_error_t _readConfigOpBalanceOfT_V12(parser_context_t* c, pd_ConfigOpBalanceOfT_V12_t* v);
parser_error_t _readConfigOpPerbill_V12(parser_context_t* c, pd_ConfigOpPerbill_V12_t* v);
parser_error_t _readConfigOpPercent_V12(parser_context_t* c, pd_ConfigOpPercent_V12_t* v);
parser_error_t _readConfigOpu32_V12(parser_context_t* c, pd_ConfigOpu32_V12_t* v);
parser_error_t _readConviction_V12(parser_context_t* c, pd_Conviction_V12_t* v);
parser_error_t _readEcdsaPublic_V12(parser_context_t* c, pd_EcdsaPublic_V12_t* v);
parser_error_t _readEcdsaSignature_V12(parser_context_t* c, pd_EcdsaSignature_V12_t* v);
parser_error_t _readEd25519Public_V12(parser_context_t* c, pd_Ed25519Public_V12_t* v);
parser_error_t _readEd25519Signature_V12(parser_context_t* c, pd_Ed25519Signature_V12_t* v);
parser_error_t _readElectionScore_V12(parser_context_t* c, pd_ElectionScore_V12_t* v);
parser_error_t _readEraIndex_V12(parser_context_t* c, pd_EraIndex_V12_t* v);
parser_error_t _readEthereumAddress_V12(parser_context_t* c, pd_EthereumAddress_V12_t* v);
parser_error_t _readHeadData_V12(parser_context_t* c, pd_HeadData_V12_t* v);
parser_error_t _readHeartbeatBlockNumber_V12(parser_context_t* c, pd_HeartbeatBlockNumber_V12_t* v);
parser_error_t _readHrmpChannelId_V12(parser_context_t* c, pd_HrmpChannelId_V12_t* v);
parser_error_t _readIdentityFields_V12(parser_context_t* c, pd_IdentityFields_V12_t* v);
parser_error_t _readJudgementBalanceOfT_V12(parser_context_t* c, pd_JudgementBalanceOfT_V12_t* v);
parser_error_t _readKeyOwnerProof_V12(parser_context_t* c, pd_KeyOwnerProof_V12_t* v);
parser_error_t _readKeyValue_V12(parser_context_t* c, pd_KeyValue_V12_t* v);
parser_error_t _readKey_V12(parser_context_t* c, pd_Key_V12_t* v);
parser_error_t _readKeys_V12(parser_context_t* c, pd_Keys_V12_t* v);
parser_error_t _readLeasePeriodOfT_V12(parser_context_t* c, pd_LeasePeriodOfT_V12_t* v);
parser_error_t _readLookupasStaticLookupSource_V12(parser_context_t* c, pd_LookupasStaticLookupSource_V12_t* v);
parser_error_t _readMemberCount_V12(parser_context_t* c, pd_MemberCount_V12_t* v);
parser_error_t _readMultiSignature_V12(parser_context_t* c, pd_MultiSignature_V12_t* v);
parser_error_t _readMultiSigner_V12(parser_context_t* c, pd_MultiSigner_V12_t* v);
parser_error_t _readNextConfigDescriptor_V12(parser_context_t* c, pd_NextConfigDescriptor_V12_t* v);
parser_error_t _readOpaqueCall_V12(parser_context_t* c, pd_OpaqueCall_V12_t* v);
parser_error_t _readOptionAccountId_V12(parser_context_t* c, pd_OptionAccountId_V12_t* v);
parser_error_t _readOptionElectionScore_V12(parser_context_t* c, pd_OptionElectionScore_V12_t* v);
parser_error_t _readOptionMultiSignature_V12(parser_context_t* c, pd_OptionMultiSignature_V12_t* v);
parser_error_t _readOptionMultiSigner_V12(parser_context_t* c, pd_OptionMultiSigner_V12_t* v);
parser_error_t _readOptionProxyType_V12(parser_context_t* c, pd_OptionProxyType_V12_t* v);
parser_error_t _readOptionReferendumIndex_V12(parser_context_t* c, pd_OptionReferendumIndex_V12_t* v);
parser_error_t _readOptionStatementKind_V12(parser_context_t* c, pd_OptionStatementKind_V12_t* v);
parser_error_t _readOptionTimepoint_V12(parser_context_t* c, pd_OptionTimepoint_V12_t* v);
parser_error_t _readOptionTupleBalanceOfTBalanceOfTBlockNumber_V12(parser_context_t* c, pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V12_t* v);
parser_error_t _readOptionXcmVersion_V12(parser_context_t* c, pd_OptionXcmVersion_V12_t* v);
parser_error_t _readOptionschedulePeriodBlockNumber_V12(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V12_t* v);
parser_error_t _readOverweightIndex_V12(parser_context_t* c, pd_OverweightIndex_V12_t* v);
parser_error_t _readParaId_V12(parser_context_t* c, pd_ParaId_V12_t* v);
parser_error_t _readParachainsInherentDataHeader_V12(parser_context_t* c, pd_ParachainsInherentDataHeader_V12_t* v);
parser_error_t _readPerbill_V12(parser_context_t* c, pd_Perbill_V12_t* v);
parser_error_t _readPercent_V12(parser_context_t* c, pd_Percent_V12_t* v);
parser_error_t _readProxyType_V12(parser_context_t* c, pd_ProxyType_V12_t* v);
parser_error_t _readPvfCheckStatement_V12(parser_context_t* c, pd_PvfCheckStatement_V12_t* v);
parser_error_t _readReferendumIndex_V12(parser_context_t* c, pd_ReferendumIndex_V12_t* v);
parser_error_t _readRegistrarIndex_V12(parser_context_t* c, pd_RegistrarIndex_V12_t* v);
parser_error_t _readRenouncing_V12(parser_context_t* c, pd_Renouncing_V12_t* v);
parser_error_t _readRewardDestination_V12(parser_context_t* c, pd_RewardDestination_V12_t* v);
parser_error_t _readSessionIndex_V12(parser_context_t* c, pd_SessionIndex_V12_t* v);
parser_error_t _readSolutionOrSnapshotSize_V12(parser_context_t* c, pd_SolutionOrSnapshotSize_V12_t* v);
parser_error_t _readSr25519Public_V12(parser_context_t* c, pd_Sr25519Public_V12_t* v);
parser_error_t _readSr25519Signature_V12(parser_context_t* c, pd_Sr25519Signature_V12_t* v);
parser_error_t _readStatementKind_V12(parser_context_t* c, pd_StatementKind_V12_t* v);
parser_error_t _readSupportsAccountId_V12(parser_context_t* c, pd_SupportsAccountId_V12_t* v);
parser_error_t _readTimepoint_V12(parser_context_t* c, pd_Timepoint_V12_t* v);
parser_error_t _readTupleAccountIdData_V12(parser_context_t* c, pd_TupleAccountIdData_V12_t* v);
parser_error_t _readTupleBalanceOfTBalanceOfTBlockNumber_V12(parser_context_t* c, pd_TupleBalanceOfTBalanceOfTBlockNumber_V12_t* v);
parser_error_t _readValidationCodeHash_V12(parser_context_t* c, pd_ValidationCodeHash_V12_t* v);
parser_error_t _readValidationCode_V12(parser_context_t* c, pd_ValidationCode_V12_t* v);
parser_error_t _readValidatorPrefs_V12(parser_context_t* c, pd_ValidatorPrefs_V12_t* v);
parser_error_t _readValidatorSignature_V12(parser_context_t* c, pd_ValidatorSignature_V12_t* v);
parser_error_t _readVecAccountId_V12(parser_context_t* c, pd_VecAccountId_V12_t* v);
parser_error_t _readVecKeyValue_V12(parser_context_t* c, pd_VecKeyValue_V12_t* v);
parser_error_t _readVecKey_V12(parser_context_t* c, pd_VecKey_V12_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V12(parser_context_t* c, pd_VecLookupasStaticLookupSource_V12_t* v);
parser_error_t _readVecTupleAccountIdData_V12(parser_context_t* c, pd_VecTupleAccountIdData_V12_t* v);
parser_error_t _readVestingInfo_V12(parser_context_t* c, pd_VestingInfo_V12_t* v);
parser_error_t _readVote_V12(parser_context_t* c, pd_Vote_V12_t* v);
parser_error_t _readWeightLimit_V12(parser_context_t* c, pd_WeightLimit_V12_t* v);
parser_error_t _readWeight_V12(parser_context_t* c, pd_Weight_V12_t* v);
parser_error_t _readXcmVersion_V12(parser_context_t* c, pd_XcmVersion_V12_t* v);
parser_error_t _readschedulePeriodBlockNumber_V12(parser_context_t* c, pd_schedulePeriodBlockNumber_V12_t* v);
parser_error_t _readschedulePriority_V12(parser_context_t* c, pd_schedulePriority_V12_t* v);

// toString functions
parser_error_t _toStringLookupCryptoTokenType_V12(
    const pd_LookupCryptoTokenType_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupCryptoAmount_V12(
    const pd_CryptoAmount_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V12(
    const pd_AccountId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringId_V12(
    const pd_LookupId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V12(
    const pd_AccountIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V12(
    const pd_AccountVoteSplit_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V12(
    const pd_AccountVoteStandard_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V12(
    const pd_AccountVote_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorityIdasRuntimeAppPublicSignature_V12(
    const pd_AuthorityIdasRuntimeAppPublicSignature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxCallOrHashOfT_V12(
    const pd_BoxCallOrHashOfT_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHashBlockNumber_V12(
    const pd_BoxEquivocationProofHashBlockNumber_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHeader_V12(
    const pd_BoxEquivocationProofHeader_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V12(
    const pd_BoxIdentityInfoMaxAdditionalFields_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxMultiLocation_V12(
    const pd_BoxMultiLocation_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxPalletsOrigin_V12(
    const pd_BoxPalletsOrigin_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxRawSolutionSolutionOfT_V12(
    const pd_BoxRawSolutionSolutionOfT_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V12(
    const pd_BoxVersionedMultiAssets_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V12(
    const pd_BoxVersionedMultiLocation_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V12(
    const pd_BoxVersionedXcmTasSysConfigCall_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTuple_V12(
    const pd_BoxVersionedXcmTuple_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V12(
    const pd_CallHashOf_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V12(
    const pd_CompactAccountIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V12(
    const pd_CompactPerBill_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpBalanceOfT_V12(
    const pd_ConfigOpBalanceOfT_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPerbill_V12(
    const pd_ConfigOpPerbill_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPercent_V12(
    const pd_ConfigOpPercent_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpu32_V12(
    const pd_ConfigOpu32_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V12(
    const pd_Conviction_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaPublic_V12(
    const pd_EcdsaPublic_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V12(
    const pd_EcdsaSignature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Public_V12(
    const pd_Ed25519Public_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Signature_V12(
    const pd_Ed25519Signature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V12(
    const pd_ElectionScore_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V12(
    const pd_EraIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V12(
    const pd_EthereumAddress_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeadData_V12(
    const pd_HeadData_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeartbeatBlockNumber_V12(
    const pd_HeartbeatBlockNumber_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHrmpChannelId_V12(
    const pd_HrmpChannelId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V12(
    const pd_IdentityFields_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgementBalanceOfT_V12(
    const pd_JudgementBalanceOfT_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V12(
    const pd_KeyOwnerProof_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V12(
    const pd_KeyValue_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V12(
    const pd_Key_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V12(
    const pd_Keys_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeasePeriodOfT_V12(
    const pd_LeasePeriodOfT_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupAddress_V12(
    const pd_LookupCryptoAddress_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupOrder_V12(
    const pd_LookupCryptoOrder_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V12(
    const pd_LookupasStaticLookupSource_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V12(
    const pd_MemberCount_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V12(
    const pd_MultiSignature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner_V12(
    const pd_MultiSigner_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNextConfigDescriptor_V12(
    const pd_NextConfigDescriptor_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V12(
    const pd_OpaqueCall_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V12(
    const pd_OptionAccountId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionElectionScore_V12(
    const pd_OptionElectionScore_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature_V12(
    const pd_OptionMultiSignature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner_V12(
    const pd_OptionMultiSigner_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V12(
    const pd_OptionProxyType_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V12(
    const pd_OptionReferendumIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionStatementKind_V12(
    const pd_OptionStatementKind_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V12(
    const pd_OptionTimepoint_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTupleBalanceOfTBalanceOfTBlockNumber_V12(
    const pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionXcmVersion_V12(
    const pd_OptionXcmVersion_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionschedulePeriodBlockNumber_V12(
    const pd_OptionschedulePeriodBlockNumber_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V12(
    const pd_OverweightIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V12(
    const pd_ParaId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParachainsInherentDataHeader_V12(
    const pd_ParachainsInherentDataHeader_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V12(
    const pd_Perbill_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V12(
    const pd_Percent_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V12(
    const pd_ProxyType_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPvfCheckStatement_V12(
    const pd_PvfCheckStatement_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V12(
    const pd_ReferendumIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V12(
    const pd_RegistrarIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing_V12(
    const pd_Renouncing_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V12(
    const pd_RewardDestination_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSessionIndex_V12(
    const pd_SessionIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSolutionOrSnapshotSize_V12(
    const pd_SolutionOrSnapshotSize_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Public_V12(
    const pd_Sr25519Public_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Signature_V12(
    const pd_Sr25519Signature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStatementKind_V12(
    const pd_StatementKind_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSupportsAccountId_V12(
    const pd_SupportsAccountId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V12(
    const pd_Timepoint_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V12(
    const pd_TupleAccountIdData_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleBalanceOfTBalanceOfTBlockNumber_V12(
    const pd_TupleBalanceOfTBalanceOfTBlockNumber_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidationCodeHash_V12(
    const pd_ValidationCodeHash_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidationCode_V12(
    const pd_ValidationCode_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V12(
    const pd_ValidatorPrefs_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorSignature_V12(
    const pd_ValidatorSignature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V12(
    const pd_VecAccountId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V12(
    const pd_VecKeyValue_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V12(
    const pd_VecKey_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource_V12(
    const pd_VecLookupasStaticLookupSource_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V12(
    const pd_VecTupleAccountIdData_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V12(
    const pd_VestingInfo_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V12(
    const pd_Vote_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V12(
    const pd_WeightLimit_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V12(
    const pd_Weight_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmVersion_V12(
    const pd_XcmVersion_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePeriodBlockNumber_V12(
    const pd_schedulePeriodBlockNumber_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePriority_V12(
    const pd_schedulePriority_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
