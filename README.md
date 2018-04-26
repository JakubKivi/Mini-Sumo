# Mini-Sumo
First really project by CałkaCompany+

Oznaczenia wyjść i wejść w kodzie:

| numer wyjścia | arduino | zmienna w kodzie  |                 opis            |
| ------------  |---------| ----------------  | ------------------------------  |
|       1       |  PWM/D3 |      `floorBR`    |    Czujnik podłoża prawy tylny  |
|       2       |    D4   |      `floorFR`    |   Czujnik podłoża prawy przedni |
|    3\5\21     |   GND   |         `-`       |           Uziemienie            |
|      4\6      |   VCC   |         `-`       |           Zasilanie             |
|       9       |  PWM/D5 |       `PWMA`      |         PWM dla silnika A       |
|      10       |  PWM/D6 |       `AIN2`      |         Wejście sterujące       |
|      11       |    D7   |       `AIN1`      |         Wejście sterujące       |
|      12       |    D8   |       `STBY`      |                                 |
|      13       |    D9   |       `BIN1`      |         Wejście sterujące       |
|      14       |    D10  |       `BIN2`      |         Wejście sterujące       |
|      15       | PWM/D11 |       `PWMB`      |         PWM dla silnika B       |
|      16       |    D12  |        `-`        |                                 |
|      17       |    D13  |     `sensorFL`    | Czujnik odległości lewy przedni |
|      23       |    A0   |     `sensorFR`    | Czujnik odległości prawy przedni|
|      24       |    A1   |     `sensorF`     |   Czujnik odległości przedni    |
|      25       |    A2   |     `sensorBL`    | Czujnik odległości prawy tylny  |
|      26       |    A3   |     `sensorB`     |   Czujnik odległości tylni      |
|      27       |    A4   |         `-`       |                                 |
|      28       |    A5   |         `-`       |                                 |
|      30       |  D0/RX  |     `sensorBR`    |  Czujnik odległości prawy tylni |
|      31       |  D1/TX  |     `floorBL`     |   Czujnik podłoża lewy tylny    |
|      32       |    D2   |     `floorFL`     |  Czujnik podłoża lewy przedni   |

