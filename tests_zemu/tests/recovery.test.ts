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
import { APP_SEED, models } from './common'
import { newSubstrateApp } from '@zondax/ledger-substrate'

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

jest.setTimeout(60000)

beforeAll(async () => {
  await Zemu.checkAndPullImage()
})

describe('Recovery', function () {
  test.each(models)('main secret menu (%s)', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(), "VTB")

      const vtb_expected_address = '5Da9vz35EVcsHpHhW3kgQ1nfguER3RUrS37VMNXuch297M7k'
      const vtb_expected_pk = '42b21fdbd41f058c3b4de9bce93fdb968c394e0f07bca480ae25d4035d0af534'
      
      const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      expect(resp.address).toEqual(vtb_expected_address)
      expect(resp.pubKey).toEqual(vtb_expected_pk)
    } finally {
      await sim.close()
    }
  })
})
