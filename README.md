# Ledger VTB App

[![Build](https://github.com/blooo-io/LedgerHQ-app-vtb/actions/workflows/main.yml/badge.svg)](https://github.com/blooo-io/LedgerHQ-app-vtb/actions/workflows/main.yml)
[![CI](https://github.com/blooo-io/LedgerHQ-app-vtb/actions/workflows/ledger.yml/badge.svg)](https://github.com/blooo-io/LedgerHQ-app-vtb/actions/workflows/ledger.yml)
---

This project contains the VTB app (https://vtbcommunity.org/) for Ledger Nano S and X.

- Ledger Nano S/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**
# VTB  1.107.x

## vtbDex

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Buy Vtbc |    |  |  | `TokenType` crypto_type <br/> `u256` crypto_amount <br/> |
|Sell Vtbc |    |  |  | `TokenType` crypto_type <br/> `u256` crypto_amount <br/> |
|Cancel buy Vtbc order |    |  |  | `Vecu8` order_id <br/> |
|Cancel sell Vtbc order |    |  |  | `Vecu8` order_id <br/> |
|Claim distribution |    |  |  | `TokenType` crypto_type <br/> |
|Initiate convert Vtbc to Vtbt substrate |    |   |   | `u256` crypto_amount <br/> |
|Initiate convert Vtbt to Vtbc substrate |    |   |   | `u256` crypto_amount <br/> |
|Initiate transfer of Vtbt substrate |    |   |   | `AccountId` address <br/>`u256` crypto_amount <br/> |
|Withdraw initiate |    |  |  | `TokenType` crypto_type <br/> `u256` crypto_amount <br/> |

