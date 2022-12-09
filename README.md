# Ledger VTB App

[![Build](https://github.com/blooo-io/LedgerHQ-app-vtb/actions/workflows/main.yml/badge.svg)](https://github.com/blooo-io/LedgerHQ-app-vtb/actions/workflows/main.yml)
[![CI](https://github.com/blooo-io/LedgerHQ-app-vtb/actions/workflows/ledger.yml/badge.svg)](https://github.com/blooo-io/LedgerHQ-app-vtb/actions/workflows/ledger.yml)
---

This project contains the VTB app (https://vtbcommunity.org/) for Ledger Nano S, SP and X.

- Ledger Nano S/SP/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**
# VTB  1.107.x (Mainnet) & VTB v1.143.x (Testnet)

## vtbDex

| Name        | Arguments |
| :---------- |:--------|
|Buy Vtbc | `TokenType` PalletVtbdexCryptosTypesTokenType <br/> `u256` crypto_amount <br/> |
|Sell Vtbc | `TokenType` PalletVtbdexCryptosTypesTokenType <br/> `u256` crypto_amount <br/> |
|Cancel Vtbc order | `tradeType` PalletVtbdexTradeTypesTradeType <br/> `Vecu8` order_id <br/> `tokenType` PalletVtbdexCryptosTypesTokenType <br/> |
|Claim distribution | `TokenType` PalletVtbdexCryptosTypesTokenType <br/> |
|Initiate convert Vtbc to Vtbt substrate | `u256` crypto_amount <br/> |
|Initiate convert Vtbt to Vtbc substrate | `u256` crypto_amount <br/> |
|Initiate transfer of Vtbt substrate | `AccountId` address <br/>`u256` crypto_amount <br/> |
|Set VTBDex fee collector account | `AccountId` accountAddress <br/> |
|Set VTBDex transaction fee | `u256` fee <br/> |
|Stop VTBDex functionality | none |
|Resume VTBDex functionality | none |
|Check and return withdraw pending amount | `AccountId` user <br/> `Bytes` id <br/> |
|Check and remove from pending list | `AccountId` user <br/> `Bytes` id <br/> |

## Sudo

| Name        | Arguments |
| :---------- |:--------|
|Set key | `LookupSource` new <br/> |
|Call | `Call` method <br/> |
|Unchecked Weight | `Call` method <br/> `u64` weight <br/> |

## System

| Name        | Arguments |
| :---------- |:--------|
|Set code | `Bytes` code <br/> |