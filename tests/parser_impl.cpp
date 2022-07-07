/*******************************************************************************
*   (c) 2019 Zondax GmbH
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

#include "gmock/gmock.h"

#include <iostream>
#include <hexutils.h>
#include <parser_txdef.h>
#include <parser.h>
#include "parser_impl.h"

// Test that we can parse SCALE-encoded unsigned integers correctly (uint8_t, uint16_t, uint32_t, uint64_t}
TEST(SCALE, UIntX) {
    parser_context_t ctx;
    parser_error_t err;
    uint8_t buffer[100];
    auto bufferLen = parseHexString(
            buffer,
            sizeof(buffer),
            "45"
            "1234"
            "12345678"
            "1234567812345678"
    );

    parser_init(&ctx, buffer, bufferLen);

    uint8_t v8 = 0;
    err = _readUInt8(&ctx, &v8);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(v8, 69);

    uint16_t v16 = 0;
    err = _readUInt16(&ctx, &v16);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(v16, 13330);

    uint32_t v32 = 0;
    err = _readUInt32(&ctx, &v32);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(v32, 2018915346);

    uint64_t v64 = 0;
    err = _readUInt64(&ctx, &v64);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(v64, 8671175386481439762);
}


// Confirm bad transactions are rejected with an error message
TEST(SCALE, BadTXMethod) {
    parser_context_t ctx;
    parser_error_t err;

    uint8_t buffer[100];
    auto bufferLen = parseHexString(buffer, sizeof(buffer), "0102030405060708091011");

    parser_init(&ctx, buffer, bufferLen);

    parser_tx_t tx;

    err = _readTx(&ctx, &tx);
    EXPECT_EQ(err, parser_unexpected_callIndex) << parser_getErrorDescription(err);;
}

// // Confirm bad transactions are rejected with an error message
// TEST(SCALE, BadTX) {
//     parser_context_t ctx;
//     parser_error_t err;

//     uint8_t buffer[100];
//     auto bufferLen = parseHexString(buffer, sizeof(buffer), "04080601000064a7b3b6e00d00000000000000000000000000000000000000000000");

//     parser_init(&ctx, buffer, bufferLen);

//     parser_tx_t tx;

//     err = _readTx(&ctx, &tx);
//     EXPECT_EQ(err, parser_unexpected_buffer_end) << parser_getErrorDescription(err);;
// }
