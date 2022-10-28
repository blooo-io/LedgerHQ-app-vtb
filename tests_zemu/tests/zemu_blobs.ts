/** ******************************************************************************
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
 ******************************************************************************* */

export const txBuyVTB =
  '0c0801000064a7b3b6e00d000000000000000000000000000000000000000000000000350000006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa9b38f3c703557e9ff6e5742d3e15db44f9273ed59cd1c430e7ad5e4cfe038814'

export const txSellVTB =
  '0c0a01000064a7b3b6e00d000000000000000000000000000000000000000000000000d50300006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaab1a63725a3f29999c59f04d3ef51c75947a3a78ddda3e67337dc0ffc572398f5'

export const txWithdrawInitiate =
  '0c0c01000064a7b3b6e00d000000000000000000000000000000000000000000000000450100006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa5a5f5db21bb13df05f79d2140f24b969b1dad27426108731ef8e15a3b3811746'

export const txClaimDistribution =
  '0c1401150200006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa9d6fef9da1ab19e4a459bded815115e62e211978511b27d818253a4bc65c2807'

export const txInitiateConvertVtbcToVtbtSubstrate =
  '0c0d000064a7b3b6e00d000000000000000000000000000000000000000000000000050200006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaaeaa17e4f6232b103e4b3f43656dae65e071393e29b6f998c2cec1b21e11fc4b6'

export const txInitiateConvertVtbtToVtbcSubstrate =
  '0c0e000064a7b3b6e00d000000000000000000000000000000000000000000000000950200006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa808da7b54bf89c320eb773014d9809203f32d539a5f7bf691218fb4b8fe833ca'

export const txInitiateTransferOfVtbtSubstrate =
  '0c0f1c7fecbb0966efece5576c7a67aff075c3062badef7e25c53ccb159233094c3c000064a7b3b6e00d000000000000000000000000000000000000000000000000050300006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa82d148259cafa0055c4d45b1561b36d959bac95c7be76241813bf6dde5f73716'

export const txCancelSellVtbcOrder =
  '0c0b1c35458697464580f5031c006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa90d60fdf5a637a4bec8e0a445b0bda63f79e105b7329368378227f374b18b5a5' //0x6def043abb6dcab1715aaceb352629a5e53a0cdda0c8aeca71a1a068f43bae59

export const txCancelBuyVtbcOrder =
  '0c09806def043abb6dcab1715aaceb352629a5e53a0cdda0c8aeca71a1a068f43bae59450218006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa1b621331a19de243e681085fe55b0f92769021affff17b9b873799504378af79'

export const txStopVTBdexFunctionality =
  '07000c04350000006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa9b38f3c703557e9ff6e5742d3e15db44f9273ed59cd1c430e7ad5e4cfe038814'

export const txResumeVTBdexFunctionality =
  '07000c05350000006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa9b38f3c703557e9ff6e5742d3e15db44f9273ed59cd1c430e7ad5e4cfe038814'

export const txSetCode =
  '070000031012312312f5031c006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa90d60fdf5a637a4bec8e0a445b0bda63f79e105b7329368378227f374b18b5a5'

export const txSetKey =
  '070200e64ede8a1e71aa47a61ab106a7961ec18d752621b78868762f516a7856e81045f5031c006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa90d60fdf5a637a4bec8e0a445b0bda63f79e105b7329368378227f374b18b5a5'

export const txSetVtbDexFeeCollectorAccount =
  '07000c00e64ede8a1e71aa47a61ab106a7961ec18d752621b78868762f516a7856e81045f5031c006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa90d60fdf5a637a4bec8e0a445b0bda63f79e105b7329368378227f374b18b5a5'

export const txSetVtbDexTransactionFee =
  '07000c015cbcea4900000000000000000000000000000000000000000000000000000000f5031c006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa90d60fdf5a637a4bec8e0a445b0bda63f79e105b7329368378227f374b18b5a5'

export const txSetCheckAndReturnWithdrawPendingAmount =
  '07000c02eebd58aa6294be72a4f6b8d1e84b75de3464038074e8cc6dc7078fdc40ee3b42203058323133313233f5031c006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa90d60fdf5a637a4bec8e0a445b0bda63f79e105b7329368378227f374b18b5a5'

export const txSetCheckAndRemoveFromPendingList =
  '07000c03eebd58aa6294be72a4f6b8d1e84b75de3464038074e8cc6dc7078fdc40ee3b421012301230f5031c006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa90d60fdf5a637a4bec8e0a445b0bda63f79e105b7329368378227f374b18b5a5'

  export const txResumeCryptoFunctionality =
  '07000c0700f5031c006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa90d60fdf5a637a4bec8e0a445b0bda63f79e105b7329368378227f374b18b5a5'

  export const txStopCryptoFunctionality =
  '07000c0600f5031c006b000000010000007483b89572fb2bd687c7b9a93b242d0b237f9aba463aba07ec24503931038aaa90d60fdf5a637a4bec8e0a445b0bda63f79e105b7329368378227f374b18b5a5'
