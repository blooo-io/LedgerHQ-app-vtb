# VTB  1.107.x

## vtbDex

| Name        | Arguments |
| :---------- |:--------|
|Buy Vtbc | `TokenType` crypto_type <br/> `u256` crypto_amount <br/> |
|Sell Vtbc | `TokenType` crypto_type <br/> `u256` crypto_amount <br/> |
|Cancel buy Vtbc order | `Vecu8` order_id <br/> |
|Cancel sell Vtbc order | `Vecu8` order_id <br/> |
|Claim distribution | `TokenType` crypto_type <br/> |
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

## System

| Name        | Arguments |
| :---------- |:--------|
|Set code | `Bytes` code <br/> |