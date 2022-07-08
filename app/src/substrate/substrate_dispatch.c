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
#include "substrate_dispatch.h"
#include "parser_impl.h"

#include "zxmacros.h"
#include <stdint.h>

parser_error_t _readMethod(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_t* method)
{
    return _readMethod_V12(c, moduleIdx, callIdx, &method->V12);
}

uint8_t _getMethod_NumItems(uint8_t moduleIdx, uint8_t callIdx)
{
    return _getMethod_NumItems_V12(moduleIdx, callIdx);
}

const char* _getMethod_ModuleName(uint8_t moduleIdx)
{
    return _getMethod_ModuleName_V12(moduleIdx);
}

const char* _getMethod_Name(uint8_t moduleIdx, uint8_t callIdx)
{
    return _getMethod_Name_V12(moduleIdx, callIdx);
}

const char* _getMethod_ItemName(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    return _getMethod_ItemName_V12(moduleIdx, callIdx, itemIdx);
}

parser_error_t _getMethod_ItemValue(pd_Method_t* m, uint8_t moduleIdx, uint8_t callIdx,
    uint8_t itemIdx, char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    return _getMethod_ItemValue_V12(&m->V12, moduleIdx, callIdx, itemIdx, outValue,outValueLen, pageIdx, pageCount);
}

bool _getMethod_ItemIsExpert(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    return _getMethod_ItemIsExpert_V12(moduleIdx, callIdx, itemIdx);
}

bool _getMethod_IsNestingSupported(uint8_t moduleIdx, uint8_t callIdx)
{
    return _getMethod_IsNestingSupported_V12(moduleIdx, callIdx);
}
