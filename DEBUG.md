```
bq25798:
  id: bq25798_component_1
  i2c_id: bus_a
  adc_en: true
  adc_rate: ADC_RATE_CONTINUOUS
  adc_sample: ADC_SAMPLE_15BIT
  vsysmin: 12000 # FIXME test only
  # Disable unnecessary ADCs
  vac2_adc_dis: true
  dplus_adc_dis: true
  dminus_adc_dis: true
  # Disable Hi-Z mode
  en_hiz: false
  # Enable measurement of the battery current
  en_ibat: true
  # Disable setting the ILIM by external resistor
  en_extilim: false
  # Keep the Out-of-audio-band (OOA) mode enabled for silent operation
  dis_fwd_ooa: false
```

# Oživování

Setup: připojeno na +5V USB

## Krok 1 - statické hodnoty po zapnutí

| Setting | Value | Board 1 (old) | Board 3 (new) |
| ------- | ----- | ----- | ----- |
| AC1_PRESENT_STAT | VAC1 present (above present threshold) | ✔️| ✔️|
| ACRB1_STAT | ACFET1/RBFET1 Closed (Path Enabled) |✔️ | ✔️|
| ACRB2_STAT | ACFET2/RBFET2 Open (Path Disabled) | ✔️| ✔️|
| CELL | 4 cell in series | ✔️| ✔️|
| DIS_ACDRV |	OFF	 |✔️ | ✔️|
| EN_ACDRV1 |ON	 | ✔️|✔️ |
| EN_BACKUP |OFF	 |✔️ |✔️ |
| EN_OTG 	|OFF	 | ✔️| ✔️|
| PG_STAT |Power good	 |✔️ | ✔️|
| VAC1_ADC | about 5000 mV	 | ✔️| ✔️|
| VBUS_ADC | about 5000 mV	 | ✔️| ✔️|
| VBUS_PRESENT_STAT| 	VBUS present (above present threshold)	 |✔️ | ✔️|
| VBUS_STAT | Unknown adaptor (3A) | ✔️| |
| VSYSMIN | 12000 mV	 | ✔️| ✔️|
| VSYS_ADC | about 12000 mV	 | ✔️|✔️ |
| VSYS_STAT |	In VSYSMIN regulation (VBAT < VSYSMIN)	 | ✔️| ✔️|

Ověřeno že:
 - čip komunikuje
 - funguje měření napětí
 - je správně detekován RPROG
 - je správně detekována přítomnost ACFET1/RBFET1
 - funguje step-up konvertor pro nabíjení

## Krok 2 - ověření funkce ACFET1

Přepnout DIS_ACDRV na ON.

| Setting | Value | Board 1 (old) | Board 3 (new) |
| ------- | ----- | ----- | ----- |
| DIS_ACDRV | ON | ✔️| |
| EN_ACDRV1 | OFF (automaticky) | ✔️| |
| PG_STAT | Not in power good status | ✔️| |
| VBAT_PRESENT_STAT  | VBAT NOT present | ✔️| |
| VBUS_PRESENT_STAT | VBUS NOT present | ✔️| |

Přepnout DIS_ACDRV na OFF.

| Setting | Value | Board 1 (old) | Board 3 (new) |
| ------- | ----- | ----- | ----- |
| DIS_ACDRV | OFF |✔️ | |
| EN_ACDRV1 | ON (automaticky) |✔️ | |
| PG_STAT | Power good |✔️ | |
| VBAT_PRESENT_STAT  | VBAT NOT present |✔️ | |
| VBUS_PRESENT_STAT | VBUS present (above present threshold) | ✔️| |

Ověřeno, že:
FIXME

## Krok 3 - ověření funkčnosti baterie

Připojit **pouze** 4S baterii (nikoli +5V na vstupu), potom zresetovat ESP32 aby znovu inicializoval čip.

| Setting | Value | Board 1 (old) | Board 3 (new) |
| ------- | ----- | ----- | ----- |
| AC1_PRESENT_STAT | VAC1 NOT present	| ✔️
| ACRB1_STAT | ACFET1/RBFET1 Closed (Path Enabled) | ✔️
| ACRB2_STAT | ACFET2/RBFET2 Open (Path Disabled)	 | ✔️
| CHG_STAT | Not Charging	| ✔️
| DIS_ACDRV |	OFF	| ✔️
| EN_ACDRV1 | OFF	 | ✔️
| PG_STAT | Not in power good status | ✔️
| VBATOTG_LOW_STAT | VBAT is high enough to enable OTG operation | ✔️
| VBAT_ADC | about 16000 mV | ✔️
| VBAT_PRESENT_STAT |	VBAT present | ✔️
| VBUS_PRESENT_STAT |	VBUS NOT present | ✔️
| VBUS_STAT | No Input or BHOT or BCOLD in OTG mode | ✔️
| VSYS_ADC | about 16000 mV | ✔️
| VSYS_STAT| Not in VSYSMIN regulation (VBAT > VSYSMIN) | ✔️

Ověřeno, že:
FIXME
