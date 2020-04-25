EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L nixie_control_board-rescue:STM32F103C8T6-keyboard MCU1
U 1 1 59A32309
P 2550 1850
F 0 "MCU1" H 2300 750 60  0000 C CNN
F 1 "STM32F103C8T6" H 2600 2900 60  0000 C CNN
F 2 "keyboard:STM32F103C8T6" H 2450 1900 60  0001 C CNN
F 3 "" H 2450 1900 60  0000 C CNN
	1    2550 1850
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:DS3231-keyboard U1
U 1 1 59A32661
P 2800 3600
F 0 "U1" H 2550 3150 60  0000 C CNN
F 1 "DS3231" H 2800 4050 60  0000 C CNN
F 2 "SMD_Packages:SOIC16" H 2850 3750 60  0001 C CNN
F 3 "" H 2850 3750 60  0000 C CNN
	1    2800 3600
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:Battery-device BT1
U 1 1 59A3268C
P 3550 3650
F 0 "BT1" H 3650 3700 50  0000 L CNN
F 1 "Battery" H 3650 3600 50  0000 L CNN
F 2 "keyboard:Coin_battery" V 3550 3690 50  0001 C CNN
F 3 "" V 3550 3690 50  0000 C CNN
	1    3550 3650
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR01
U 1 1 59A327A3
P 3550 4200
F 0 "#PWR01" H 3550 3950 50  0001 C CNN
F 1 "GND" H 3550 4050 50  0000 C CNN
F 2 "" H 3550 4200 50  0000 C CNN
F 3 "" H 3550 4200 50  0000 C CNN
	1    3550 4200
	1    0    0    -1  
$EndComp
Text GLabel 3500 3250 2    60   Input ~ 0
SCL
Text GLabel 3250 3350 2    60   Input ~ 0
SDA
Text GLabel 2150 3450 0    60   Input ~ 0
SQW
$Comp
L nixie_control_board-rescue:C_Small-device C1
U 1 1 59A33289
P 1600 3500
F 0 "C1" H 1610 3570 50  0000 L CNN
F 1 "1uF" V 1450 3400 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1600 3500 50  0001 C CNN
F 3 "" H 1600 3500 50  0000 C CNN
	1    1600 3500
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:C_Small-device C2
U 1 1 59A332E7
P 10350 3450
F 0 "C2" H 10360 3520 50  0000 L CNN
F 1 "0.1uF" V 10500 3350 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 10350 3450 50  0001 C CNN
F 3 "" H 10350 3450 50  0000 C CNN
	1    10350 3450
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR07
U 1 1 59A33D06
P 10300 3650
F 0 "#PWR07" H 10300 3400 50  0001 C CNN
F 1 "GND" H 10300 3500 50  0000 C CNN
F 2 "" H 10300 3650 50  0000 C CNN
F 3 "" H 10300 3650 50  0000 C CNN
	1    10300 3650
	0    -1   -1   0   
$EndComp
Text GLabel 10500 3750 2    60   Input ~ 0
SCL
Text GLabel 10800 3850 2    60   Input ~ 0
SDA
$Comp
L nixie_control_board-rescue:R_Pack04-device RP1
U 1 1 59A343F6
P 9900 2150
F 0 "RP1" H 9900 2600 50  0000 C CNN
F 1 "R_PACK4" H 9900 2100 50  0000 C CNN
F 2 "Resistors_SMD:R_Array_Convex_4x0402" H 9900 2150 50  0001 C CNN
F 3 "" H 9900 2150 50  0000 C CNN
	1    9900 2150
	-1   0    0    1   
$EndComp
Text GLabel 10100 2350 3    60   Input ~ 0
SDA
Text GLabel 9800 2350 3    60   Input ~ 0
SCL
$Comp
L nixie_control_board-rescue:GND-power #PWR09
U 1 1 59A36607
P 8350 5750
F 0 "#PWR09" H 8350 5500 50  0001 C CNN
F 1 "GND" H 8350 5600 50  0000 C CNN
F 2 "" H 8350 5750 50  0000 C CNN
F 3 "" H 8350 5750 50  0000 C CNN
	1    8350 5750
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:Conn_01x02-conn P1
U 1 1 59A36B46
P 6350 4750
F 0 "P1" H 6350 4900 50  0000 C CNN
F 1 "CONN_01X02" V 6450 4750 50  0000 C CNN
F 2 "keyboard:Power_connectors_5mm" H 6350 4750 50  0001 C CNN
F 3 "" H 6350 4750 50  0000 C CNN
	1    6350 4750
	-1   0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR010
U 1 1 59A37047
P 7450 5450
F 0 "#PWR010" H 7450 5200 50  0001 C CNN
F 1 "GND" H 7450 5300 50  0000 C CNN
F 2 "" H 7450 5450 50  0000 C CNN
F 3 "" H 7450 5450 50  0000 C CNN
	1    7450 5450
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:CP1_Small-device C3
U 1 1 59A37156
P 7450 4950
F 0 "C3" H 7460 5020 50  0000 L CNN
F 1 "10uF, 25V" V 7600 4750 50  0000 L CNN
F 2 "Capacitor_SMD:C_1210_3225Metric" H 7450 4950 50  0001 C CNN
F 3 "" H 7450 4950 50  0000 C CNN
	1    7450 4950
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:C_Small-device C4
U 1 1 59A371EF
P 7750 4950
F 0 "C4" H 7760 5020 50  0000 L CNN
F 1 "100nF" V 7900 4850 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7750 4950 50  0001 C CNN
F 3 "" H 7750 4950 50  0000 C CNN
	1    7750 4950
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:C_Small-device C5
U 1 1 59A37253
P 7900 5700
F 0 "C5" H 7910 5770 50  0000 L CNN
F 1 "100nF" H 7650 5600 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7900 5700 50  0001 C CNN
F 3 "" H 7900 5700 50  0000 C CNN
	1    7900 5700
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR011
U 1 1 59A372A2
P 7900 5850
F 0 "#PWR011" H 7900 5600 50  0001 C CNN
F 1 "GND" H 7900 5700 50  0000 C CNN
F 2 "" H 7900 5850 50  0000 C CNN
F 3 "" H 7900 5850 50  0000 C CNN
	1    7900 5850
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:Q_NMOS_DGS-device Q1
U 1 1 59A3835A
P 9100 5150
F 0 "Q1" H 9400 5200 50  0000 R CNN
F 1 "IRF644" H 9150 5300 50  0000 R CNN
F 2 "keyboard:TO-220" H 9300 5250 50  0001 C CNN
F 3 "" H 9100 5150 50  0000 C CNN
	1    9100 5150
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:R_Small-device R1
U 1 1 59A39755
P 9200 5600
F 0 "R1" H 9230 5620 50  0000 L CNN
F 1 "R050" H 9230 5560 50  0000 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric" H 9200 5600 50  0001 C CNN
F 3 "" H 9200 5600 50  0000 C CNN
	1    9200 5600
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:INDUCTOR-pspice L1
U 1 1 59A39DCD
P 8900 4400
F 0 "L1" H 8900 4500 50  0000 C CNN
F 1 "100uH/1.8A" H 8900 4350 50  0000 C CNN
F 2 "keyboard:CD127" H 8900 4400 50  0001 C CNN
F 3 "" H 8900 4400 50  0000 C CNN
	1    8900 4400
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:D_Small-device D1
U 1 1 59A39F64
P 9350 4750
F 0 "D1" H 9300 4830 50  0000 L CNN
F 1 "MUR160" H 9200 4670 50  0000 L CNN
F 2 "Diodes_THT:Diode_DO-41_SOD81_Horizontal_RM10" V 9350 4750 50  0001 C CNN
F 3 "" V 9350 4750 50  0000 C CNN
	1    9350 4750
	-1   0    0    1   
$EndComp
$Comp
L nixie_control_board-rescue:CP1_Small-device C6
U 1 1 59A39FC1
P 9600 4900
F 0 "C6" H 9610 4970 50  0000 L CNN
F 1 "4.7uF/250V" V 9750 4550 50  0000 L CNN
F 2 "Capacitors_THT:C_Radial_D8_L13_P3.8" H 9600 4900 50  0001 C CNN
F 3 "" H 9600 4900 50  0000 C CNN
	1    9600 4900
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR012
U 1 1 59A3A0F1
P 9600 5000
F 0 "#PWR012" H 9600 4750 50  0001 C CNN
F 1 "GND" H 9600 4850 50  0000 C CNN
F 2 "" H 9600 5000 50  0000 C CNN
F 3 "" H 9600 5000 50  0000 C CNN
	1    9600 5000
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:R_Small-device R2
U 1 1 59A3A738
P 9900 5250
F 0 "R2" V 10000 5300 50  0000 L CNN
F 1 "1M5,220V" V 10100 5150 50  0000 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric" H 9900 5250 50  0001 C CNN
F 3 "" H 9900 5250 50  0000 C CNN
	1    9900 5250
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:R_Small-device R3
U 1 1 59A3A7DF
P 9900 6050
F 0 "R3" H 9930 6070 50  0000 L CNN
F 1 "10K" H 9930 6010 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 9900 6050 50  0001 C CNN
F 3 "" H 9900 6050 50  0000 C CNN
	1    9900 6050
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:POT-device RV1
U 1 1 59A3A83B
P 9900 5650
F 0 "RV1" H 9750 5650 50  0000 C CNN
F 1 "5K" H 9750 5750 50  0000 C CNN
F 2 "Potentiometer_SMD:Potentiometer_Trimmer-EVM3E" H 9900 5650 50  0001 C CNN
F 3 "" H 9900 5650 50  0000 C CNN
	1    9900 5650
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR013
U 1 1 59A3AA79
P 9900 6200
F 0 "#PWR013" H 9900 5950 50  0001 C CNN
F 1 "GND" H 9900 6050 50  0000 C CNN
F 2 "" H 9900 6200 50  0000 C CNN
F 3 "" H 9900 6200 50  0000 C CNN
	1    9900 6200
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:C_Small-device C7
U 1 1 59A3AE68
P 10300 4950
F 0 "C7" H 10310 5020 50  0000 L CNN
F 1 "100nF, 250V" V 10450 4600 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 10300 4950 50  0001 C CNN
F 3 "" H 10300 4950 50  0000 C CNN
	1    10300 4950
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR014
U 1 1 59A3AF27
P 10300 5150
F 0 "#PWR014" H 10300 4900 50  0001 C CNN
F 1 "GND" H 10300 5000 50  0000 C CNN
F 2 "" H 10300 5150 50  0000 C CNN
F 3 "" H 10300 5150 50  0000 C CNN
	1    10300 5150
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:Conn_01x02-conn P2
U 1 1 59A3B055
P 10900 4850
F 0 "P2" H 10900 5000 50  0000 C CNN
F 1 "CONN_01X02" V 11000 4850 50  0000 C CNN
F 2 "keyboard:Power_connectors_5mm" H 10900 4850 50  0001 C CNN
F 3 "" H 10900 4850 50  0000 C CNN
	1    10900 4850
	1    0    0    1   
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR015
U 1 1 59A3B16F
P 10700 5050
F 0 "#PWR015" H 10700 4800 50  0001 C CNN
F 1 "GND" H 10700 4900 50  0000 C CNN
F 2 "" H 10700 5050 50  0000 C CNN
F 3 "" H 10700 5050 50  0000 C CNN
	1    10700 5050
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:MAX1771-keyboard U3
U 1 1 59A379DA
P 8400 5250
F 0 "U3" H 8150 4850 60  0000 C CNN
F 1 "MAX1771" H 8750 4850 60  0000 C CNN
F 2 "keyboard_extended:sop-8" H 8400 5750 60  0001 C CNN
F 3 "" H 8400 5750 60  0000 C CNN
	1    8400 5250
	1    0    0    -1  
$EndComp
Text GLabel 3150 2200 2    60   Input ~ 0
SCL
Text GLabel 3400 2300 2    60   Input ~ 0
SDA
$Comp
L nixie_control_board-rescue:GND-power #PWR017
U 1 1 59A43332
P 3300 2700
F 0 "#PWR017" H 3300 2450 50  0001 C CNN
F 1 "GND" H 3300 2550 50  0000 C CNN
F 2 "" H 3300 2700 50  0000 C CNN
F 3 "" H 3300 2700 50  0000 C CNN
	1    3300 2700
	0    -1   -1   0   
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR018
U 1 1 59A43391
P 1950 900
F 0 "#PWR018" H 1950 650 50  0001 C CNN
F 1 "GND" H 1950 750 50  0000 C CNN
F 2 "" H 1950 900 50  0000 C CNN
F 3 "" H 1950 900 50  0000 C CNN
	1    1950 900 
	0    1    1    0   
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR019
U 1 1 59A43658
P 1800 1000
F 0 "#PWR019" H 1800 750 50  0001 C CNN
F 1 "GND" H 1800 850 50  0000 C CNN
F 2 "" H 1800 1000 50  0000 C CNN
F 3 "" H 1800 1000 50  0000 C CNN
	1    1800 1000
	0    1    1    0   
$EndComp
$Comp
L nixie_control_board-rescue:CP1-device C9
U 1 1 59A43C15
P 6200 3550
F 0 "C9" H 6225 3650 50  0000 L CNN
F 1 "10uF" H 6225 3450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6200 3550 50  0001 C CNN
F 3 "" H 6200 3550 50  0000 C CNN
	1    6200 3550
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR021
U 1 1 59A43C16
P 6200 3700
F 0 "#PWR021" H 6200 3450 50  0001 C CNN
F 1 "GND" H 6200 3550 50  0000 C CNN
F 2 "" H 6200 3700 50  0000 C CNN
F 3 "" H 6200 3700 50  0000 C CNN
	1    6200 3700
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:C-device C8
U 1 1 59A43C17
P 5050 3550
F 0 "C8" H 5075 3650 50  0000 L CNN
F 1 "10uF" H 5075 3450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5088 3400 50  0001 C CNN
F 3 "" H 5050 3550 50  0000 C CNN
	1    5050 3550
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR022
U 1 1 59A43C18
P 5050 3700
F 0 "#PWR022" H 5050 3450 50  0001 C CNN
F 1 "GND" H 5050 3550 50  0000 C CNN
F 2 "" H 5050 3700 50  0000 C CNN
F 3 "" H 5050 3700 50  0000 C CNN
	1    5050 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3450 3250 3450
Wire Wire Line
	3250 3550 3250 3650
Connection ~ 3250 3650
Connection ~ 3250 3750
Connection ~ 3250 3850
Wire Wire Line
	2350 4200 3250 4200
Connection ~ 3250 3950
Wire Wire Line
	2350 3650 2350 3750
Connection ~ 2350 3950
Connection ~ 2350 3850
Connection ~ 2350 3750
Connection ~ 3250 4200
Wire Wire Line
	3250 3250 3500 3250
Wire Wire Line
	2150 3450 2350 3450
Connection ~ 9250 2950
Wire Wire Line
	10800 3850 10300 3850
Wire Wire Line
	10300 3750 10500 3750
Connection ~ 9900 1950
Wire Wire Line
	8350 5750 8450 5750
Wire Wire Line
	8900 5350 9200 5350
Wire Wire Line
	9200 5750 9200 5700
Connection ~ 8450 5750
Wire Wire Line
	9200 5350 9200 5500
Wire Wire Line
	9900 5350 9900 5450
Wire Wire Line
	8900 5450 9900 5450
Wire Wire Line
	8400 4750 8400 4800
Wire Wire Line
	9200 4400 9200 4750
Connection ~ 9200 4750
Wire Wire Line
	9600 4800 9600 4750
Wire Wire Line
	9900 4750 9900 5150
Wire Wire Line
	10300 4750 10300 4850
Connection ~ 10300 4750
Wire Wire Line
	3150 2300 3400 2300
Wire Wire Line
	1800 1000 1950 1000
Wire Wire Line
	5050 3400 5050 3300
Wire Wire Line
	5950 3300 6200 3300
Wire Wire Line
	6200 3400 6200 3300
Connection ~ 6200 3300
$Comp
L nixie_control_board-rescue:GND-power #PWR024
U 1 1 59A4705C
P 5500 3600
F 0 "#PWR024" H 5500 3350 50  0001 C CNN
F 1 "GND" H 5500 3450 50  0000 C CNN
F 2 "" H 5500 3600 50  0000 C CNN
F 3 "" H 5500 3600 50  0000 C CNN
	1    5500 3600
	1    0    0    -1  
$EndComp
Text GLabel 1950 1900 0    60   Input ~ 0
SCK
Wire Wire Line
	3150 2700 3300 2700
$Comp
L nixie_control_board-rescue:GND-power #PWR029
U 1 1 59A50233
P 6400 1800
F 0 "#PWR029" H 6400 1550 50  0001 C CNN
F 1 "GND" H 6400 1650 50  0000 C CNN
F 2 "" H 6400 1800 50  0000 C CNN
F 3 "" H 6400 1800 50  0000 C CNN
	1    6400 1800
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR030
U 1 1 59A502A4
P 6400 2500
F 0 "#PWR030" H 6400 2250 50  0001 C CNN
F 1 "GND" H 6400 2350 50  0000 C CNN
F 2 "" H 6400 2500 50  0000 C CNN
F 3 "" H 6400 2500 50  0000 C CNN
	1    6400 2500
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR031
U 1 1 59A50403
P 6400 1050
F 0 "#PWR031" H 6400 800 50  0001 C CNN
F 1 "GND" H 6400 900 50  0000 C CNN
F 2 "" H 6400 1050 50  0000 C CNN
F 3 "" H 6400 1050 50  0000 C CNN
	1    6400 1050
	1    0    0    -1  
$EndComp
Text GLabel 3150 900  2    60   Input ~ 0
SHIFT_SER_OUT
Text GLabel 3150 1000 2    60   Input ~ 0
SHIFT_SERIAL_CLOCK
Text GLabel 3150 1100 2    60   Input ~ 0
SHIFT_LATCH_CLOCK
Text GLabel 1950 1700 0    60   Input ~ 0
MOSI
Text GLabel 6000 1050 0    60   Input ~ 0
BUTTON_1
Text GLabel 6000 1800 0    60   Input ~ 0
BUTTON_2
Text GLabel 6000 2500 0    60   Input ~ 0
BUTTON_3
Text GLabel 1950 2400 0    60   Input ~ 0
BUTTON_3
Text GLabel 1950 2500 0    60   Input ~ 0
BUTTON_2
Text GLabel 1950 2600 0    60   Input ~ 0
BUTTON_1
Text GLabel 7650 3300 2    60   Input ~ 0
SHIFT_SER_OUT
Text GLabel 7650 3400 2    60   Input ~ 0
SHIFT_SERIAL_CLOCK
Text GLabel 7650 3500 2    60   Input ~ 0
SHIFT_LATCH_CLOCK
$Comp
L nixie_control_board-rescue:AT24C02-keyboard U2
U 1 1 59A5FC41
P 9900 3700
F 0 "U2" H 9750 3450 60  0000 C CNN
F 1 "AT24C02" H 9900 3950 60  0000 C CNN
F 2 "kicad-libraries:SOIC8" H 9900 3300 60  0001 C CNN
F 3 "" H 9900 3650 60  0000 C CNN
	1    9900 3700
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR036
U 1 1 59A60D39
P 9500 3850
F 0 "#PWR036" H 9500 3600 50  0001 C CNN
F 1 "GND" H 9500 3700 50  0000 C CNN
F 2 "" H 9500 3850 50  0000 C CNN
F 3 "" H 9500 3850 50  0000 C CNN
	1    9500 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 3350 9250 3750
Wire Wire Line
	9250 3750 9500 3750
Wire Wire Line
	9500 3650 9350 3650
Wire Wire Line
	9350 3650 9350 3350
Wire Wire Line
	9450 3350 9450 3550
Wire Wire Line
	9450 3550 9500 3550
Text GLabel 3150 1200 2    60   Input ~ 0
SHIFT_OUT_ENABLE
Text GLabel 3150 1300 2    60   Input ~ 0
SHIFT_CLEAR
Text GLabel 7650 3700 2    60   Input ~ 0
SHIFT_CLEAR
Text GLabel 7650 3600 2    60   Input ~ 0
SHIFT_OUT_ENABLE
Text GLabel 1950 1400 0    60   Input ~ 0
SCL2
Text GLabel 1950 1300 0    60   Input ~ 0
SDA2
Wire Wire Line
	3550 4200 3550 3850
Wire Wire Line
	7450 4400 7450 4750
Connection ~ 7450 4750
Wire Wire Line
	7900 5850 7900 5800
Wire Wire Line
	10300 5050 10300 5150
Wire Wire Line
	9900 5800 9900 5850
Wire Wire Line
	10050 5650 10050 5850
Wire Wire Line
	10050 5850 9900 5850
Connection ~ 9900 5850
Connection ~ 9900 5450
Wire Wire Line
	9150 4400 9200 4400
Wire Wire Line
	9250 4750 9200 4750
$Comp
L nixie_control_board-rescue:GND-power #PWR037
U 1 1 5B4D0AB3
P 8550 4800
F 0 "#PWR037" H 8550 4550 50  0001 C CNN
F 1 "GND" H 8550 4650 50  0000 C CNN
F 2 "" H 8550 4800 50  0000 C CNN
F 3 "" H 8550 4800 50  0000 C CNN
	1    8550 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 4800 8550 4750
Wire Wire Line
	8550 4550 8550 4400
Wire Wire Line
	7450 4400 8550 4400
Connection ~ 8550 4400
Wire Wire Line
	9450 4750 9600 4750
Connection ~ 9900 4750
Connection ~ 9600 4750
Wire Wire Line
	9900 6200 9900 6150
$Comp
L nixie_control_board-rescue:CP1_Small-device C10
U 1 1 5B4D3355
P 8550 4650
F 0 "C10" H 8350 4750 50  0000 L CNN
F 1 "100uF, 25V" V 8700 4350 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-7343-15_Kemet-W" H 8550 4650 50  0001 C CNN
F 3 "" H 8550 4650 50  0000 C CNN
	1    8550 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 4850 7750 4750
Connection ~ 7750 4750
Wire Wire Line
	7900 5600 7900 5450
Connection ~ 7450 5250
Wire Wire Line
	3250 3650 3250 3750
Wire Wire Line
	3250 3750 3250 3850
Wire Wire Line
	3250 3850 3250 3950
Wire Wire Line
	3250 3950 3250 4200
Wire Wire Line
	2350 3950 2350 4200
Wire Wire Line
	2350 3850 2350 3950
Wire Wire Line
	2350 3750 2350 3850
Wire Wire Line
	3250 4200 3550 4200
Wire Wire Line
	8450 5750 9200 5750
Wire Wire Line
	9200 4750 9200 4950
Wire Wire Line
	10300 4750 10700 4750
Wire Wire Line
	6200 3300 6300 3300
Wire Wire Line
	7450 4750 7450 4850
Wire Wire Line
	7450 4750 7750 4750
Wire Wire Line
	9900 5850 9900 5950
Wire Wire Line
	9900 5450 9900 5500
Wire Wire Line
	8550 4400 8650 4400
Wire Wire Line
	9900 4750 10150 4750
Wire Wire Line
	9600 4750 9900 4750
Wire Wire Line
	7750 4750 8400 4750
Wire Wire Line
	7450 5250 7750 5250
Wire Wire Line
	7450 5250 7450 5450
Wire Wire Line
	9800 1950 9900 1950
Wire Wire Line
	9900 1950 10000 1950
Wire Wire Line
	10000 1950 10100 1950
Connection ~ 10000 1950
$Comp
L nixie_control_board-rescue:R_Pack04-device RP2
U 1 1 5B56EA65
P 9250 3150
F 0 "RP2" H 9250 3600 50  0000 C CNN
F 1 "R_PACK4" H 9250 3100 50  0000 C CNN
F 2 "Resistors_SMD:R_Array_Convex_4x0402" H 9250 3150 50  0001 C CNN
F 3 "" H 9250 3150 50  0000 C CNN
	1    9250 3150
	-1   0    0    1   
$EndComp
Wire Wire Line
	9150 2950 9250 2950
Wire Wire Line
	9250 2950 9350 2950
Wire Wire Line
	9350 2950 9450 2950
Connection ~ 9350 2950
$Comp
L nixie_control_board-rescue:SW_DIP_x01-switches SW4
U 1 1 5B587F79
P 6950 4750
F 0 "SW4" H 6950 4483 50  0000 C CNN
F 1 "SW_DIP_x01" H 6950 4574 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6950 4750 50  0001 C CNN
F 3 "" H 6950 4750 50  0001 C CNN
	1    6950 4750
	1    0    0    1   
$EndComp
Connection ~ 8350 5750
Connection ~ 9200 5350
Wire Wire Line
	10700 4850 10700 5050
$Comp
L nixie_control_board-rescue:SSD1306-OLED-ssd1306-oled U7
U 1 1 5B58EAB4
P 2650 6300
F 0 "U7" H 2700 7647 60  0000 C CNN
F 1 "SSD1306-OLED" H 2700 7541 60  0000 C CNN
F 2 "ssd1306oled:SSD1306-096-INCH-OLED" H 3650 5500 60  0001 C CNN
F 3 "" H 3650 5500 60  0001 C CNN
	1    2650 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 3350 1600 3350
Wire Wire Line
	1600 3350 1600 3400
Connection ~ 1600 3350
Wire Wire Line
	1600 3350 2350 3350
Wire Wire Line
	1600 3600 1600 4200
Wire Wire Line
	1600 4200 2350 4200
Connection ~ 2350 4200
Wire Wire Line
	10300 3550 10350 3550
Wire Wire Line
	10350 3550 10800 3550
Connection ~ 10350 3550
$Comp
L nixie_control_board-rescue:GND-power #PWR0101
U 1 1 5B59F085
P 10350 3200
F 0 "#PWR0101" H 10350 2950 50  0001 C CNN
F 1 "GND" H 10350 3050 50  0000 C CNN
F 2 "" H 10350 3200 50  0000 C CNN
F 3 "" H 10350 3200 50  0000 C CNN
	1    10350 3200
	-1   0    0    1   
$EndComp
Wire Wire Line
	10350 3200 10350 3350
Connection ~ 3550 4200
$Comp
L nixie_control_board-rescue:C-device C15
U 1 1 5B5C99B0
P 1800 5750
F 0 "C15" H 1825 5850 50  0000 L CNN
F 1 "2.2uF" H 1825 5650 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1838 5600 50  0001 C CNN
F 3 "" H 1800 5750 50  0000 C CNN
	1    1800 5750
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:C-device C16
U 1 1 5B5C9BF7
P 1800 6150
F 0 "C16" H 1825 6250 50  0000 L CNN
F 1 "2.2uF" H 1825 6050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1838 6000 50  0001 C CNN
F 3 "" H 1800 6150 50  0000 C CNN
	1    1800 6150
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:C-device C13
U 1 1 5B5C9C6F
P 1450 5650
F 0 "C13" H 1475 5750 50  0000 L CNN
F 1 "2.2uF" H 1475 5550 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1488 5500 50  0001 C CNN
F 3 "" H 1450 5650 50  0000 C CNN
	1    1450 5650
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:C-device C12
U 1 1 5B5C9CED
P 1250 5500
F 0 "C12" H 1275 5600 50  0000 L CNN
F 1 "10uF" H 1275 5400 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1288 5350 50  0001 C CNN
F 3 "" H 1250 5500 50  0000 C CNN
	1    1250 5500
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:C-device C11
U 1 1 5B5C9D5F
P 1050 5350
F 0 "C11" H 1075 5450 50  0000 L CNN
F 1 "2.2uF" H 1075 5250 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1088 5200 50  0001 C CNN
F 3 "" H 1050 5350 50  0000 C CNN
	1    1050 5350
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:C-device C14
U 1 1 5B5C9DD7
P 1650 6650
F 0 "C14" H 1675 6750 50  0000 L CNN
F 1 "2.2uF/16V" H 1675 6550 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1688 6500 50  0001 C CNN
F 3 "" H 1650 6650 50  0000 C CNN
	1    1650 6650
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:R-device R6
U 1 1 5B5CA047
P 1400 6550
F 0 "R6" V 1480 6550 50  0000 C CNN
F 1 "390K" V 1400 6550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1330 6550 50  0001 C CNN
F 3 "" H 1400 6550 50  0000 C CNN
	1    1400 6550
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0102
U 1 1 5B5CA5FD
P 1450 5900
F 0 "#PWR0102" H 1450 5650 50  0001 C CNN
F 1 "GND" H 1450 5750 50  0000 C CNN
F 2 "" H 1450 5900 50  0000 C CNN
F 3 "" H 1450 5900 50  0000 C CNN
	1    1450 5900
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0103
U 1 1 5B5CA6FD
P 1250 5900
F 0 "#PWR0103" H 1250 5650 50  0001 C CNN
F 1 "GND" H 1250 5750 50  0000 C CNN
F 2 "" H 1250 5900 50  0000 C CNN
F 3 "" H 1250 5900 50  0000 C CNN
	1    1250 5900
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0104
U 1 1 5B5CA766
P 1050 5900
F 0 "#PWR0104" H 1050 5650 50  0001 C CNN
F 1 "GND" H 1050 5750 50  0000 C CNN
F 2 "" H 1050 5900 50  0000 C CNN
F 3 "" H 1050 5900 50  0000 C CNN
	1    1050 5900
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0105
U 1 1 5B5CA7CF
P 1650 7000
F 0 "#PWR0105" H 1650 6750 50  0001 C CNN
F 1 "GND" H 1650 6850 50  0000 C CNN
F 2 "" H 1650 7000 50  0000 C CNN
F 3 "" H 1650 7000 50  0000 C CNN
	1    1650 7000
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0106
U 1 1 5B5CA838
P 1400 7000
F 0 "#PWR0106" H 1400 6750 50  0001 C CNN
F 1 "GND" H 1400 6850 50  0000 C CNN
F 2 "" H 1400 7000 50  0000 C CNN
F 3 "" H 1400 7000 50  0000 C CNN
	1    1400 7000
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0107
U 1 1 5B5CA8A1
P 1950 7000
F 0 "#PWR0107" H 1950 6750 50  0001 C CNN
F 1 "GND" H 1950 6850 50  0000 C CNN
F 2 "" H 1950 7000 50  0000 C CNN
F 3 "" H 1950 7000 50  0000 C CNN
	1    1950 7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 6700 1950 6800
Wire Wire Line
	1950 6800 1950 6900
Connection ~ 1950 6800
Wire Wire Line
	1950 6900 1950 7000
Connection ~ 1950 6900
Connection ~ 1950 7000
Wire Wire Line
	1650 6500 1950 6500
Wire Wire Line
	1650 6800 1650 7000
Wire Wire Line
	1400 7000 1400 6700
Wire Wire Line
	1400 6400 1950 6400
Wire Wire Line
	1800 6000 1950 6000
Wire Wire Line
	1800 6300 1950 6300
Wire Wire Line
	1800 5900 1950 5900
Wire Wire Line
	1800 5600 1950 5600
Wire Wire Line
	1450 5900 1450 5800
Wire Wire Line
	1450 5500 1450 5450
Wire Wire Line
	1450 5450 1950 5450
Wire Wire Line
	1250 5900 1250 5650
Wire Wire Line
	1250 5350 1950 5350
Wire Wire Line
	1050 5900 1050 5500
Wire Wire Line
	1050 5200 1450 5200
$Comp
L nixie_control_board-rescue:GND-power #PWR0108
U 1 1 5B60A6D6
P 3450 7000
F 0 "#PWR0108" H 3450 6750 50  0001 C CNN
F 1 "GND" H 3450 6850 50  0000 C CNN
F 2 "" H 3450 7000 50  0000 C CNN
F 3 "" H 3450 7000 50  0000 C CNN
	1    3450 7000
	0    -1   -1   0   
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0109
U 1 1 5B60A888
P 3450 6900
F 0 "#PWR0109" H 3450 6650 50  0001 C CNN
F 1 "GND" H 3450 6750 50  0000 C CNN
F 2 "" H 3450 6900 50  0000 C CNN
F 3 "" H 3450 6900 50  0000 C CNN
	1    3450 6900
	0    -1   -1   0   
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0110
U 1 1 5B60A8F1
P 3450 6800
F 0 "#PWR0110" H 3450 6550 50  0001 C CNN
F 1 "GND" H 3450 6650 50  0000 C CNN
F 2 "" H 3450 6800 50  0000 C CNN
F 3 "" H 3450 6800 50  0000 C CNN
	1    3450 6800
	0    -1   -1   0   
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0111
U 1 1 5B60A95A
P 3450 6700
F 0 "#PWR0111" H 3450 6450 50  0001 C CNN
F 1 "GND" H 3450 6550 50  0000 C CNN
F 2 "" H 3450 6700 50  0000 C CNN
F 3 "" H 3450 6700 50  0000 C CNN
	1    3450 6700
	0    -1   -1   0   
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0112
U 1 1 5B60A9C3
P 3450 6600
F 0 "#PWR0112" H 3450 6350 50  0001 C CNN
F 1 "GND" H 3450 6450 50  0000 C CNN
F 2 "" H 3450 6600 50  0000 C CNN
F 3 "" H 3450 6600 50  0000 C CNN
	1    3450 6600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3450 6500 3450 6400
Wire Wire Line
	3450 6400 3650 6400
Connection ~ 3450 6400
Wire Wire Line
	3450 6300 3650 6300
$Comp
L nixie_control_board-rescue:GND-power #PWR0113
U 1 1 5B617497
P 3450 6000
F 0 "#PWR0113" H 3450 5750 50  0001 C CNN
F 1 "GND" H 3450 5850 50  0000 C CNN
F 2 "" H 3450 6000 50  0000 C CNN
F 3 "" H 3450 6000 50  0000 C CNN
	1    3450 6000
	0    -1   -1   0   
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0114
U 1 1 5B617500
P 3450 5900
F 0 "#PWR0114" H 3450 5650 50  0001 C CNN
F 1 "GND" H 3450 5750 50  0000 C CNN
F 2 "" H 3450 5900 50  0000 C CNN
F 3 "" H 3450 5900 50  0000 C CNN
	1    3450 5900
	0    -1   -1   0   
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0115
U 1 1 5B617569
P 3450 5800
F 0 "#PWR0115" H 3450 5550 50  0001 C CNN
F 1 "GND" H 3450 5650 50  0000 C CNN
F 2 "" H 3450 5800 50  0000 C CNN
F 3 "" H 3450 5800 50  0000 C CNN
	1    3450 5800
	0    -1   -1   0   
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0116
U 1 1 5B6175D2
P 3450 5200
F 0 "#PWR0116" H 3450 4950 50  0001 C CNN
F 1 "GND" H 3450 5050 50  0000 C CNN
F 2 "" H 3450 5200 50  0000 C CNN
F 3 "" H 3450 5200 50  0000 C CNN
	1    3450 5200
	0    -1   -1   0   
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0117
U 1 1 5B61763B
P 3450 5400
F 0 "#PWR0117" H 3450 5150 50  0001 C CNN
F 1 "GND" H 3450 5250 50  0000 C CNN
F 2 "" H 3450 5400 50  0000 C CNN
F 3 "" H 3450 5400 50  0000 C CNN
	1    3450 5400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1450 5050 1450 5200
Connection ~ 1450 5200
Wire Wire Line
	1450 5200 1950 5200
Wire Wire Line
	1450 5200 1450 5450
Connection ~ 1450 5450
$Comp
L nixie_control_board-rescue:GND-power #PWR0126
U 1 1 5B626905
P 3450 5600
F 0 "#PWR0126" H 3450 5350 50  0001 C CNN
F 1 "GND" H 3450 5450 50  0000 C CNN
F 2 "" H 3450 5600 50  0000 C CNN
F 3 "" H 3450 5600 50  0000 C CNN
	1    3450 5600
	0    -1   -1   0   
$EndComp
Text GLabel 3450 5700 2    50   Input ~ 0
DISP_RESET
Text GLabel 3150 2100 2    50   Input ~ 0
DISP_RESET
$Sheet
S 4650 5150 850  950 
U 5B626F78
F0 "buck_converter" 50
F1 "buck_converter.sch" 50
$EndSheet
Wire Wire Line
	6600 4400 6600 4750
Wire Wire Line
	6600 4750 6650 4750
Wire Wire Line
	6550 4750 6600 4750
Connection ~ 6600 4750
Wire Wire Line
	7250 4750 7450 4750
Wire Wire Line
	7450 5050 7450 5250
Wire Wire Line
	7750 5050 7750 5250
Connection ~ 7750 5250
Wire Wire Line
	7750 5250 7900 5250
Wire Wire Line
	6550 5250 7450 5250
Text GLabel 3650 6400 2    60   Input ~ 0
SDA
Text GLabel 3650 6300 2    60   Input ~ 0
SCL
Wire Wire Line
	6550 4850 6550 5250
$Comp
L nixie_control_board-rescue:Conn_01x07-conn J1
U 1 1 5B58DE01
P 7450 3400
F 0 "J1" H 7370 2875 50  0000 C CNN
F 1 "Conn_01x07" H 7370 2966 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07_Pitch2.54mm" H 7450 3400 50  0001 C CNN
F 3 "~" H 7450 3400 50  0001 C CNN
	1    7450 3400
	-1   0    0    1   
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0122
U 1 1 5B597B29
P 7650 3200
F 0 "#PWR0122" H 7650 2950 50  0001 C CNN
F 1 "GND" H 7650 3050 50  0000 C CNN
F 2 "" H 7650 3200 50  0000 C CNN
F 3 "" H 7650 3200 50  0000 C CNN
	1    7650 3200
	0    -1   -1   0   
$EndComp
$Comp
L nixie_control_board-rescue:+5V-power #PWR0118
U 1 1 5C5AA42E
P 10800 3550
F 0 "#PWR0118" H 10800 3400 50  0001 C CNN
F 1 "+5V-power" H 10815 3723 50  0000 C CNN
F 2 "" H 10800 3550 50  0001 C CNN
F 3 "" H 10800 3550 50  0001 C CNN
	1    10800 3550
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:+5V-power #PWR0120
U 1 1 5C5AA57D
P 9250 2950
F 0 "#PWR0120" H 9250 2800 50  0001 C CNN
F 1 "+5V-power" H 9265 3123 50  0000 C CNN
F 2 "" H 9250 2950 50  0001 C CNN
F 3 "" H 9250 2950 50  0001 C CNN
	1    9250 2950
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:+5V-power #PWR0121
U 1 1 5C5AA6C5
P 9900 1950
F 0 "#PWR0121" H 9900 1800 50  0001 C CNN
F 1 "+5V-power" H 9915 2123 50  0000 C CNN
F 2 "" H 9900 1950 50  0001 C CNN
F 3 "" H 9900 1950 50  0001 C CNN
	1    9900 1950
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:+5V-power #PWR0124
U 1 1 5C5AA8B2
P 1450 3350
F 0 "#PWR0124" H 1450 3200 50  0001 C CNN
F 1 "+5V-power" V 1465 3477 50  0000 L CNN
F 2 "" H 1450 3350 50  0001 C CNN
F 3 "" H 1450 3350 50  0001 C CNN
	1    1450 3350
	0    -1   -1   0   
$EndComp
$Comp
L nixie_control_board-rescue:+3.3V-power #PWR0125
U 1 1 5C5AAADD
P 1450 5050
F 0 "#PWR0125" H 1450 4900 50  0001 C CNN
F 1 "+3.3V-power" H 1465 5223 50  0000 C CNN
F 2 "" H 1450 5050 50  0001 C CNN
F 3 "" H 1450 5050 50  0001 C CNN
	1    1450 5050
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:+12V-power #PWR0128
U 1 1 5C5AAC99
P 7450 4400
F 0 "#PWR0128" H 7450 4250 50  0001 C CNN
F 1 "+12V-power" H 7465 4573 50  0000 C CNN
F 2 "" H 7450 4400 50  0001 C CNN
F 3 "" H 7450 4400 50  0001 C CNN
	1    7450 4400
	1    0    0    -1  
$EndComp
Connection ~ 7450 4400
$Comp
L nixie_control_board-rescue:+5V-power #PWR0134
U 1 1 5C5AAEC0
P 3600 2600
F 0 "#PWR0134" H 3600 2450 50  0001 C CNN
F 1 "+5V-power" V 3615 2728 50  0000 L CNN
F 2 "" H 3600 2600 50  0001 C CNN
F 3 "" H 3600 2600 50  0001 C CNN
	1    3600 2600
	0    1    1    0   
$EndComp
$Comp
L nixie_control_board-rescue:+3.3V-power #PWR0135
U 1 1 5C5AAFBC
P 3600 2800
F 0 "#PWR0135" H 3600 2650 50  0001 C CNN
F 1 "+3.3V-power" V 3615 2928 50  0000 L CNN
F 2 "" H 3600 2800 50  0001 C CNN
F 3 "" H 3600 2800 50  0001 C CNN
	1    3600 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	3150 2600 3600 2600
Wire Wire Line
	3150 2800 3600 2800
$Comp
L nixie_control_board-rescue:+5V-power #PWR0136
U 1 1 5C5B53DB
P 4900 3300
F 0 "#PWR0136" H 4900 3150 50  0001 C CNN
F 1 "+5V-power" V 4915 3427 50  0000 L CNN
F 2 "" H 4900 3300 50  0001 C CNN
F 3 "" H 4900 3300 50  0001 C CNN
	1    4900 3300
	0    -1   -1   0   
$EndComp
$Comp
L nixie_control_board-rescue:+3.3V-power #PWR0137
U 1 1 5C5B54E5
P 6300 3300
F 0 "#PWR0137" H 6300 3150 50  0001 C CNN
F 1 "+3.3V-power" V 6315 3428 50  0000 L CNN
F 2 "" H 6300 3300 50  0001 C CNN
F 3 "" H 6300 3300 50  0001 C CNN
	1    6300 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	4900 3300 5050 3300
$Comp
L nixie_control_board-rescue:+5V-power #PWR0141
U 1 1 5C5BADB1
P 7900 3100
F 0 "#PWR0141" H 7900 2950 50  0001 C CNN
F 1 "+5V-power" V 7915 3228 50  0000 L CNN
F 2 "" H 7900 3100 50  0001 C CNN
F 3 "" H 7900 3100 50  0001 C CNN
	1    7900 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	7900 3100 7650 3100
$Comp
L nixie_control_board-rescue:+3.3V-power #PWR0142
U 1 1 5C5C046E
P 3700 5300
F 0 "#PWR0142" H 3700 5150 50  0001 C CNN
F 1 "+3.3V-power" V 3715 5428 50  0000 L CNN
F 2 "" H 3700 5300 50  0001 C CNN
F 3 "" H 3700 5300 50  0001 C CNN
	1    3700 5300
	0    1    1    0   
$EndComp
Wire Wire Line
	3700 5300 3450 5300
Wire Wire Line
	5850 3150 5950 3150
Wire Wire Line
	5950 3150 5950 3300
$Comp
L nixie_control_board-rescue:+12P-power #PWR0132
U 1 1 5C5CCF02
P 6600 4400
F 0 "#PWR0132" H 6600 4250 50  0001 C CNN
F 1 "+12P-power" H 6615 4573 50  0000 C CNN
F 2 "" H 6600 4400 50  0001 C CNN
F 3 "" H 6600 4400 50  0001 C CNN
	1    6600 4400
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:Conn_01x02-conn P4
U 1 1 5C5BD612
P 6250 850
F 0 "P4" H 6250 1000 50  0000 C CNN
F 1 "CONN_01X02" V 6350 850 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6250 850 50  0001 C CNN
F 3 "" H 6250 850 50  0000 C CNN
	1    6250 850 
	0    1    -1   0   
$EndComp
$Comp
L nixie_control_board-rescue:Conn_01x02-conn P6
U 1 1 5C5D31C1
P 6250 1600
F 0 "P6" H 6250 1750 50  0000 C CNN
F 1 "CONN_01X02" V 6350 1600 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6250 1600 50  0001 C CNN
F 3 "" H 6250 1600 50  0000 C CNN
	1    6250 1600
	0    1    -1   0   
$EndComp
$Comp
L nixie_control_board-rescue:Conn_01x02-conn P7
U 1 1 5C5D325F
P 6250 2300
F 0 "P7" H 6250 2450 50  0000 C CNN
F 1 "CONN_01X02" V 6350 2300 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6250 2300 50  0001 C CNN
F 3 "" H 6250 2300 50  0000 C CNN
	1    6250 2300
	0    1    -1   0   
$EndComp
Wire Wire Line
	6150 2500 6000 2500
Wire Wire Line
	6250 2500 6400 2500
Wire Wire Line
	6400 1800 6250 1800
Wire Wire Line
	6150 1800 6000 1800
Wire Wire Line
	6000 1050 6150 1050
Wire Wire Line
	6250 1050 6400 1050
$Comp
L nixie_control_board-rescue:C_Small-device C17
U 1 1 5E9DCF70
P 10150 5250
F 0 "C17" H 10160 5320 50  0000 L CNN
F 1 "100nF, 250V" V 10300 4900 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 10150 5250 50  0001 C CNN
F 3 "" H 10150 5250 50  0000 C CNN
	1    10150 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 5450 10150 5450
Wire Wire Line
	10150 5450 10150 5350
Wire Wire Line
	10150 5150 10150 4750
Connection ~ 10150 4750
Wire Wire Line
	10150 4750 10300 4750
Connection ~ 5050 3300
Connection ~ 5950 3300
$Comp
L nixie_control_board-rescue:AMS1117-keyboard P3
U 1 1 59A43C11
P 5500 3350
F 0 "P3" H 5250 3200 60  0000 C CNN
F 1 "AMS1117" H 5500 3800 60  0000 C CNN
F 2 "keyboard:SOT-223" H 5500 3350 60  0001 C CNN
F 3 "" H 5500 3350 60  0001 C CNN
	1    5500 3350
	1    0    0    -1  
$EndComp
$EndSCHEMATC
