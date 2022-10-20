/** ******************************************************************************
 *  (c) 2020 Zondax GmbH
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

import Zemu, { DEFAULT_START_OPTIONS } from '@zondax/zemu'
import { newSubstrateApp } from '@zondax/ledger-substrate'
import { txBuyVTB, txCancelBuyVtbcOrder, txCancelSellVtbcOrder, txClaimDistribution, txInitiateConvertVtbcToVtbtSubstrate, txInitiateConvertVtbtToVtbcSubstrate, txInitiateTransferOfVtbtSubstrate, txSellVTB, txWithdrawInitiate, txStopVTBdexFunctionality, txResumeVTBdexFunctionality, txSetCode, txSetKey } from './zemu_blobs'
import { APP_SEED, models } from './common'

// @ts-ignore
import ed25519 from 'ed25519-supercop'
// @ts-ignore
import { blake2bFinal, blake2bInit, blake2bUpdate } from 'blakejs'

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

jest.setTimeout(180000)

beforeAll(async () => {
  await Zemu.checkAndPullImage()
})

describe('Standard', function () {
  test.each(models)('can start and stop container', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
    } finally {
      await sim.close()
    }
  })

  // test.each(models)('main menu', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     await sim.navigateAndCompareSnapshots('.', `${m.prefix.toLowerCase()}-mainmenu`, [1, 0, 0, 3, -4])
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('get app version', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")
  //     const resp = await app.getVersion()

  //     console.log(resp)

  //     expect(resp.return_code).toEqual(0x9000)
  //     expect(resp.error_message).toEqual('No errors')
  //     expect(resp).toHaveProperty('test_mode')
  //     expect(resp).toHaveProperty('major')
  //     expect(resp).toHaveProperty('minor')
  //     expect(resp).toHaveProperty('patch')
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('get address', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")

  //     const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

  //     console.log(resp)

  //     expect(resp.return_code).toEqual(0x9000)
  //     expect(resp.error_message).toEqual('No errors')

  //     const expected_address = '5Da9vz35EVcsHpHhW3kgQ1nfguER3RUrS37VMNXuch297M7k'
  //     const expected_pk = '42b21fdbd41f058c3b4de9bce93fdb968c394e0f07bca480ae25d4035d0af534'

  //     expect(resp.address).toEqual(expected_address)
  //     expect(resp.pubKey).toEqual(expected_pk)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('show address', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")

  //     const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true)
  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  //     await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-show_address`)

  //     const resp = await respRequest

  //     console.log(resp)

  //     expect(resp.return_code).toEqual(0x9000)
  //     expect(resp.error_message).toEqual('No errors')

  //     const expected_address = '5Da9vz35EVcsHpHhW3kgQ1nfguER3RUrS37VMNXuch297M7k'
  //     const expected_pk = '42b21fdbd41f058c3b4de9bce93fdb968c394e0f07bca480ae25d4035d0af534'

  //     expect(resp.address).toEqual(expected_address)
  //     expect(resp.pubKey).toEqual(expected_pk)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('show address - reject', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")

  //     const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true)
  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  //     await sim.navigateAndCompareUntilText('.', `${m.prefix.toLowerCase()}-show_address_reject`, 'REJECT')

  //     const resp = await respRequest
  //     console.log(resp)

  //     expect(resp.return_code).toEqual(0x6986)
  //     expect(resp.error_message).toEqual('Transaction rejected')
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('sign basic buyVTB', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(txBuyVTB, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  //     await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_buy_vtb`)

  //     const signatureResponse = await signatureRequest

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('sign basic sellVTB', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(txSellVTB, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  //     await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_sell_vtb`)

  //     const signatureResponse = await signatureRequest

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('sign basic withdrawInitiate', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(txWithdrawInitiate, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  //     await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_withdraw_initiate`)

  //     const signatureResponse = await signatureRequest

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('sign basic claimDistribution', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(txClaimDistribution, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  //     await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_claim_distribution`)

  //     const signatureResponse = await signatureRequest

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('sign basic initiateConvertVtbcToVtbtSubstrate', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(txInitiateConvertVtbcToVtbtSubstrate, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  //     await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_initiate_convert_vtbc_to_vtbt_substrate`)

  //     const signatureResponse = await signatureRequest

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('sign basic initiateConvertVtbtToVtbcSubstrate', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(txInitiateConvertVtbtToVtbcSubstrate, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  //     await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_initiate_convert_vtbt_to_vtbc_substrate`)

  //     const signatureResponse = await signatureRequest

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('sign basic initiateTransferOfVtbtSubstrate', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(txInitiateTransferOfVtbtSubstrate, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  //     await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_initiate_transfer_of_vtbt_substrate`)

  //     const signatureResponse = await signatureRequest

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('sign basic cancelBuyVtbcOrder', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(txCancelBuyVtbcOrder, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  //     await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_cancel_buy_vtbc_order`)

  //     const signatureResponse = await signatureRequest

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('sign basic cancelSellVtbcOrder', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(txCancelSellVtbcOrder, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  //     await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_cancel_sell_vtbc_order`)

  //     const signatureResponse = await signatureRequest

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('sign basic stopVtbdexFunctionality', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(txStopVTBdexFunctionality, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  //     await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_stop_vtb_dex_functionality`)

  //     const signatureResponse = await signatureRequest

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('sign basic resumeVtbdexFunctionality', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(txResumeVTBdexFunctionality, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  //     await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_resume_vtb_dex_functionality`)

  //     const signatureResponse = await signatureRequest

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('sign basic setCode', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(), "VTB")
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(txSetCode, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  //     await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_set_code`)

  //     const signatureResponse = await signatureRequest

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })

  test.each(models)('sign basic setKey', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(), "VTB")
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlob = Buffer.from(txSetKey, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_set_key`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })
})
