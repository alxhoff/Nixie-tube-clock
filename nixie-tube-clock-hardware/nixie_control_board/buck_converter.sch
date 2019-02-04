EESchema Schematic File Version 4
LIBS:nixie_control_board-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L nixie_control_board-rescue:INDUCTOR-pspice L2
U 1 1 5B627F6B
P 6100 3750
F 0 "L2" H 6100 3965 50  0000 C CNN
F 1 "10uH" H 6100 3874 50  0000 C CNN
F 2 "Inductors:Inductor_Wurth_HCI-7030" H 6100 3750 50  0001 C CNN
F 3 "" H 6100 3750 50  0001 C CNN
	1    6100 3750
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:C_Small-device C21
U 1 1 5B628078
P 5350 3450
F 0 "C21" V 5121 3450 50  0000 C CNN
F 1 "10nF" V 5212 3450 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 5350 3450 50  0001 C CNN
F 3 "" H 5350 3450 50  0001 C CNN
	1    5350 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	5050 3450 5250 3450
Wire Wire Line
	5450 3450 5550 3450
Wire Wire Line
	5550 3450 5550 3750
$Comp
L nixie_control_board-rescue:CP_Small-device C19
U 1 1 5B628664
P 3900 4100
F 0 "C19" H 3988 4146 50  0000 L CNN
F 1 "10uF/25V" H 3988 4055 50  0000 L CNN
F 2 "Capacitors_SMD:C_1210" H 3900 4100 50  0001 C CNN
F 3 "" H 3900 4100 50  0001 C CNN
	1    3900 4100
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:R_Small-device R9
U 1 1 5B628827
P 4300 3900
F 0 "R9" V 4200 3900 50  0000 C CNN
F 1 "100k" V 4400 3900 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 4300 3900 50  0001 C CNN
F 3 "" H 4300 3900 50  0001 C CNN
	1    4300 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	4400 3900 4550 3900
Wire Wire Line
	4200 3900 3900 3900
$Comp
L nixie_control_board-rescue:GND-power #PWR0127
U 1 1 5B628956
P 3900 4200
F 0 "#PWR0127" H 3900 3950 50  0001 C CNN
F 1 "GND" H 3905 4027 50  0000 C CNN
F 2 "" H 3900 4200 50  0001 C CNN
F 3 "" H 3900 4200 50  0001 C CNN
	1    3900 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 3750 3900 3750
Wire Wire Line
	3900 3750 3900 3900
Connection ~ 3900 3900
$Comp
L nixie_control_board-rescue:+12V-power #PWR0128
U 1 1 5B628ADE
P 3900 3450
F 0 "#PWR0128" H 3900 3300 50  0001 C CNN
F 1 "+12V" H 3915 3623 50  0000 C CNN
F 2 "" H 3900 3450 50  0001 C CNN
F 3 "" H 3900 3450 50  0001 C CNN
	1    3900 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 3450 3900 3750
Connection ~ 3900 3750
Wire Wire Line
	3900 4000 3900 3900
$Comp
L nixie_control_board-rescue:GND-power #PWR0129
U 1 1 5B628C97
P 5050 4350
F 0 "#PWR0129" H 5050 4100 50  0001 C CNN
F 1 "GND" H 5055 4177 50  0000 C CNN
F 2 "" H 5050 4350 50  0001 C CNN
F 3 "" H 5050 4350 50  0001 C CNN
	1    5050 4350
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:GND-power #PWR0130
U 1 1 5B628CF0
P 4450 4350
F 0 "#PWR0130" H 4450 4100 50  0001 C CNN
F 1 "GND" H 4455 4177 50  0000 C CNN
F 2 "" H 4450 4350 50  0001 C CNN
F 3 "" H 4450 4350 50  0001 C CNN
	1    4450 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 4150 4450 4050
Wire Wire Line
	4450 4050 4550 4050
$Comp
L nixie_control_board-rescue:C_Small-device C22
U 1 1 5B628F27
P 5550 4350
F 0 "C22" H 5458 4304 50  0000 R CNN
F 1 "3.9nF" H 5458 4395 50  0000 R CNN
F 2 "Capacitors_SMD:C_0603" H 5550 4350 50  0001 C CNN
F 3 "" H 5550 4350 50  0001 C CNN
	1    5550 4350
	-1   0    0    1   
$EndComp
$Comp
L nixie_control_board-rescue:R_Small-device R10
U 1 1 5B628F57
P 5550 4600
F 0 "R10" H 5491 4554 50  0000 R CNN
F 1 "6.8K" H 5491 4645 50  0000 R CNN
F 2 "Resistors_SMD:R_0603" H 5550 4600 50  0001 C CNN
F 3 "" H 5550 4600 50  0001 C CNN
	1    5550 4600
	-1   0    0    1   
$EndComp
Wire Wire Line
	5550 4500 5550 4450
$Comp
L nixie_control_board-rescue:GND-power #PWR0131
U 1 1 5B62948D
P 5550 4700
F 0 "#PWR0131" H 5550 4450 50  0001 C CNN
F 1 "GND" H 5555 4527 50  0000 C CNN
F 2 "" H 5550 4700 50  0001 C CNN
F 3 "" H 5550 4700 50  0001 C CNN
	1    5550 4700
	1    0    0    -1  
$EndComp
$Comp
L nixie_control_board-rescue:R_Small-device R11
U 1 1 5B6294AE
P 6000 4350
F 0 "R11" H 5941 4304 50  0000 R CNN
F 1 "10k" H 5941 4395 50  0000 R CNN
F 2 "Resistors_SMD:R_0603" H 6000 4350 50  0001 C CNN
F 3 "" H 6000 4350 50  0001 C CNN
	1    6000 4350
	-1   0    0    1   
$EndComp
$Comp
L nixie_control_board-rescue:C_Small-device C23
U 1 1 5B629559
P 6550 4350
F 0 "C23" H 6458 4304 50  0000 R CNN
F 1 "22uF/6.3V" H 6458 4395 50  0000 R CNN
F 2 "Capacitors_SMD:C_1206" H 6550 4350 50  0001 C CNN
F 3 "" H 6550 4350 50  0001 C CNN
	1    6550 4350
	-1   0    0    1   
$EndComp
Wire Wire Line
	6000 4250 6000 3900
Wire Wire Line
	6000 3900 6100 3900
Wire Wire Line
	6400 3900 6550 3900
Wire Wire Line
	6550 4500 6550 4450
Wire Wire Line
	6350 3750 6550 3750
$Comp
L keyboard:MP2307 U8
U 1 1 5B62B290
P 5050 3900
F 0 "U8" H 5300 3600 50  0000 C CNN
F 1 "MP2307" H 4800 4200 50  0000 C CNN
F 2 "kicad-libraries:SOIC8" H 5050 4400 50  0001 C CNN
F 3 "" H 5050 4400 50  0001 C CNN
	1    5050 3900
	1    0    0    -1  
$EndComp
Connection ~ 5550 3750
$Comp
L nixie_control_board-rescue:C_Small-device C20
U 1 1 5B62B8CA
P 4450 4250
F 0 "C20" H 4358 4204 50  0000 R CNN
F 1 "0.1uF" H 4358 4295 50  0000 R CNN
F 2 "Capacitors_SMD:C_0603" H 4450 4250 50  0001 C CNN
F 3 "" H 4450 4250 50  0001 C CNN
	1    4450 4250
	-1   0    0    1   
$EndComp
Wire Wire Line
	5550 3750 5850 3750
$Comp
L nixie_control_board-rescue:POT-device RV2
U 1 1 5B62B9A1
P 6250 3900
F 0 "RV2" V 6350 4000 50  0000 C CNN
F 1 "100K(26.1K)" V 6450 3950 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Trimmer-EVM3E" H 6250 3900 50  0001 C CNN
F 3 "" H 6250 3900 50  0001 C CNN
	1    6250 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	5550 3900 6000 3900
Connection ~ 6000 3900
Wire Wire Line
	5550 4050 5550 4250
Wire Wire Line
	6550 3900 6550 4050
Connection ~ 6550 3900
Connection ~ 6550 3750
Wire Wire Line
	6550 3750 6800 3750
$Comp
L nixie_control_board-rescue:+3.3V-power #PWR0132
U 1 1 5B62DCE7
P 6800 3750
F 0 "#PWR0132" H 6800 3600 50  0001 C CNN
F 1 "+3.3V" V 6815 3878 50  0000 L CNN
F 2 "" H 6800 3750 50  0001 C CNN
F 3 "" H 6800 3750 50  0001 C CNN
	1    6800 3750
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 4450 6000 4500
Wire Wire Line
	6000 4500 6550 4500
$Comp
L nixie_control_board-rescue:GND-power #PWR0133
U 1 1 5B62E461
P 6550 4500
F 0 "#PWR0133" H 6550 4250 50  0001 C CNN
F 1 "GND" H 6555 4327 50  0000 C CNN
F 2 "" H 6550 4500 50  0001 C CNN
F 3 "" H 6550 4500 50  0001 C CNN
	1    6550 4500
	1    0    0    -1  
$EndComp
Connection ~ 6550 4500
Wire Wire Line
	6550 3750 6550 3900
Wire Wire Line
	6250 4050 6550 4050
Connection ~ 6550 4050
Wire Wire Line
	6550 4050 6550 4250
$EndSCHEMATC
