EESchema Schematic File Version 4
LIBS:smart_watch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L device:Crystal Y1
U 1 1 5B58981F
P 3900 3450
F 0 "Y1" V 3854 3581 50  0000 L CNN
F 1 "Crystal" V 3945 3581 50  0000 L CNN
F 2 "Crystals:Crystal_SMD_3215-2pin_3.2x1.5mm" H 3900 3450 50  0001 C CNN
F 3 "" H 3900 3450 50  0001 C CNN
	1    3900 3450
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5B589993
P 4450 3750
F 0 "#PWR0101" H 4450 3500 50  0001 C CNN
F 1 "GND" H 4455 3577 50  0000 C CNN
F 2 "" H 4450 3750 50  0001 C CNN
F 3 "" H 4450 3750 50  0001 C CNN
	1    4450 3750
	1    0    0    -1  
$EndComp
Text GLabel 5550 3650 2    50   Input ~ 0
SCL
Text GLabel 5550 3750 2    50   Input ~ 0
SDA
$Comp
L stm8:STM8S103F3 U3
U 1 1 5B58BB3D
P 8300 2050
F 0 "U3" H 8225 2867 50  0000 C CNN
F 1 "STM8S103F3" H 8225 2776 50  0000 C CNN
F 2 "kicad-libraries:TSSOP20" H 8300 2950 50  0001 C CNN
F 3 "" H 8300 2950 50  0001 C CNN
	1    8300 2050
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C10
U 1 1 5B58BD21
P 9900 2600
F 0 "C10" V 9671 2600 50  0000 C CNN
F 1 "1uF" V 9762 2600 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 9900 2600 50  0001 C CNN
F 3 "" H 9900 2600 50  0001 C CNN
	1    9900 2600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5B58BDA3
P 9700 3100
F 0 "#PWR0102" H 9700 2850 50  0001 C CNN
F 1 "GND" V 9705 2972 50  0000 R CNN
F 2 "" H 9700 3100 50  0001 C CNN
F 3 "" H 9700 3100 50  0001 C CNN
	1    9700 3100
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C1
U 1 1 5B5B77EF
P 2500 5200
F 0 "C1" H 2592 5246 50  0000 L CNN
F 1 "1uF" H 2592 5155 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2500 5200 50  0001 C CNN
F 3 "" H 2500 5200 50  0001 C CNN
	1    2500 5200
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C2
U 1 1 5B5B7863
P 3400 5200
F 0 "C2" H 3492 5246 50  0000 L CNN
F 1 "1uF" H 3492 5155 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3400 5200 50  0001 C CNN
F 3 "" H 3400 5200 50  0001 C CNN
	1    3400 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5B5B78FD
P 2950 5300
F 0 "#PWR0103" H 2950 5050 50  0001 C CNN
F 1 "GND" H 2955 5127 50  0000 C CNN
F 2 "" H 2950 5300 50  0001 C CNN
F 3 "" H 2950 5300 50  0001 C CNN
	1    2950 5300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5B5B791D
P 2500 5300
F 0 "#PWR0104" H 2500 5050 50  0001 C CNN
F 1 "GND" H 2505 5127 50  0000 C CNN
F 2 "" H 2500 5300 50  0001 C CNN
F 3 "" H 2500 5300 50  0001 C CNN
	1    2500 5300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5B5B793D
P 3400 5300
F 0 "#PWR0105" H 3400 5050 50  0001 C CNN
F 1 "GND" H 3405 5127 50  0000 C CNN
F 2 "" H 3400 5300 50  0001 C CNN
F 3 "" H 3400 5300 50  0001 C CNN
	1    3400 5300
	1    0    0    -1  
$EndComp
Text Label 2150 5000 2    50   ~ 0
BAT+
Wire Wire Line
	2150 5000 2500 5000
$Comp
L tinkerforge:3V3 #PWR0106
U 1 1 5B5B7A35
P 3600 5000
F 0 "#PWR0106" H 3600 5100 40  0001 C CNN
F 1 "3V3" V 3609 5118 40  0000 L CNN
F 2 "" H 3600 5000 60  0000 C CNN
F 3 "" H 3600 5000 60  0000 C CNN
	1    3600 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	3600 5000 3400 5000
$Comp
L device:R_Small R3
U 1 1 5B5B7B9D
P 3400 4800
F 0 "R3" H 3459 4846 50  0000 L CNN
F 1 "1K" H 3459 4755 50  0000 L CNN
F 2 "Resistors_SMD:R_0603" H 3400 4800 50  0001 C CNN
F 3 "" H 3400 4800 50  0001 C CNN
	1    3400 4800
	1    0    0    -1  
$EndComp
$Comp
L device:LED D1
U 1 1 5B5B7CEA
P 3400 4550
F 0 "D1" V 3345 4628 50  0000 L CNN
F 1 "LED" V 3436 4628 50  0000 L CNN
F 2 "LEDs:LED_0603" H 3400 4550 50  0001 C CNN
F 3 "" H 3400 4550 50  0001 C CNN
	1    3400 4550
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5B5B7E49
P 3400 4400
F 0 "#PWR0107" H 3400 4150 50  0001 C CNN
F 1 "GND" H 3405 4227 50  0000 C CNN
F 2 "" H 3400 4400 50  0001 C CNN
F 3 "" H 3400 4400 50  0001 C CNN
	1    3400 4400
	-1   0    0    1   
$EndComp
$Comp
L conn:Conn_01x04 J2
U 1 1 5B5B7F51
P 4650 5000
F 0 "J2" H 4570 4575 50  0000 C CNN
F 1 "Conn_01x04" H 4570 4666 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x02_Pitch2.54mm" H 4650 5000 50  0001 C CNN
F 3 "~" H 4650 5000 50  0001 C CNN
	1    4650 5000
	-1   0    0    1   
$EndComp
Text Label 6850 1550 2    50   ~ 0
SWIM
Text Label 4850 5000 0    50   ~ 0
SWIM
$Comp
L conn:USB_A J1
U 1 1 5B5B80BF
P 1300 6450
F 0 "J1" H 1355 6917 50  0000 C CNN
F 1 "USB_A" H 1355 6826 50  0000 C CNN
F 2 "kicad-libraries:USB-A-SMT-8231" H 1450 6400 50  0001 C CNN
F 3 "" H 1450 6400 50  0001 C CNN
	1    1300 6450
	1    0    0    -1  
$EndComp
$Comp
L ssd1306-oled:SSD1306-OLED U2
U 1 1 5B5B93D4
P 8150 5250
F 0 "U2" H 8200 6597 60  0000 C CNN
F 1 "SSD1306-OLED" H 8200 6491 60  0000 C CNN
F 2 "ssd1306oled:SSD1306-096-INCH-OLED" H 9150 4450 60  0001 C CNN
F 3 "" H 9150 4450 60  0001 C CNN
	1    8150 5250
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C7
U 1 1 5B5B95F8
P 7350 4700
F 0 "C7" H 7442 4746 50  0000 L CNN
F 1 "1uF" H 7442 4655 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7350 4700 50  0001 C CNN
F 3 "" H 7350 4700 50  0001 C CNN
	1    7350 4700
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C8
U 1 1 5B5B9725
P 7350 5100
F 0 "C8" H 7442 5146 50  0000 L CNN
F 1 "1uF" H 7442 5055 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7350 5100 50  0001 C CNN
F 3 "" H 7350 5100 50  0001 C CNN
	1    7350 5100
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C5
U 1 1 5B5B9761
P 7000 4700
F 0 "C5" H 7092 4746 50  0000 L CNN
F 1 "1uF" H 7092 4655 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7000 4700 50  0001 C CNN
F 3 "" H 7000 4700 50  0001 C CNN
	1    7000 4700
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C4
U 1 1 5B5B97BB
P 6700 4700
F 0 "C4" H 6792 4746 50  0000 L CNN
F 1 "1uF" H 6792 4655 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6700 4700 50  0001 C CNN
F 3 "" H 6700 4700 50  0001 C CNN
	1    6700 4700
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C3
U 1 1 5B5B97F3
P 6400 4700
F 0 "C3" H 6492 4746 50  0000 L CNN
F 1 "1uF" H 6492 4655 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6400 4700 50  0001 C CNN
F 3 "" H 6400 4700 50  0001 C CNN
	1    6400 4700
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C6
U 1 1 5B5B982B
P 7200 5550
F 0 "C6" H 7292 5596 50  0000 L CNN
F 1 "1uF" H 7292 5505 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7200 5550 50  0001 C CNN
F 3 "" H 7200 5550 50  0001 C CNN
	1    7200 5550
	1    0    0    -1  
$EndComp
$Comp
L device:R_Small R4
U 1 1 5B5B98FB
P 6850 5450
F 0 "R4" H 6909 5496 50  0000 L CNN
F 1 "1M" H 6909 5405 50  0000 L CNN
F 2 "Resistors_SMD:R_0603" H 6850 5450 50  0001 C CNN
F 3 "" H 6850 5450 50  0001 C CNN
	1    6850 5450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5B5B99CD
P 7300 6050
F 0 "#PWR0108" H 7300 5800 50  0001 C CNN
F 1 "GND" H 7305 5877 50  0000 C CNN
F 2 "" H 7300 6050 50  0001 C CNN
F 3 "" H 7300 6050 50  0001 C CNN
	1    7300 6050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5B5B9A05
P 8950 5950
F 0 "#PWR0109" H 8950 5700 50  0001 C CNN
F 1 "GND" V 8955 5822 50  0000 R CNN
F 2 "" H 8950 5950 50  0001 C CNN
F 3 "" H 8950 5950 50  0001 C CNN
	1    8950 5950
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5B5B9AF5
P 8950 5850
F 0 "#PWR0110" H 8950 5600 50  0001 C CNN
F 1 "GND" V 8955 5722 50  0000 R CNN
F 2 "" H 8950 5850 50  0001 C CNN
F 3 "" H 8950 5850 50  0001 C CNN
	1    8950 5850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5B5B9B26
P 8950 5750
F 0 "#PWR0111" H 8950 5500 50  0001 C CNN
F 1 "GND" V 8955 5622 50  0000 R CNN
F 2 "" H 8950 5750 50  0001 C CNN
F 3 "" H 8950 5750 50  0001 C CNN
	1    8950 5750
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5B5B9B57
P 8950 5650
F 0 "#PWR0112" H 8950 5400 50  0001 C CNN
F 1 "GND" V 8955 5522 50  0000 R CNN
F 2 "" H 8950 5650 50  0001 C CNN
F 3 "" H 8950 5650 50  0001 C CNN
	1    8950 5650
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5B5B9B88
P 8950 5550
F 0 "#PWR0113" H 8950 5300 50  0001 C CNN
F 1 "GND" V 8955 5422 50  0000 R CNN
F 2 "" H 8950 5550 50  0001 C CNN
F 3 "" H 8950 5550 50  0001 C CNN
	1    8950 5550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8950 5450 8950 5350
Wire Wire Line
	8950 5350 9100 5350
Connection ~ 8950 5350
Wire Wire Line
	8950 5250 9100 5250
$Comp
L power:GND #PWR0114
U 1 1 5B5B9D41
P 8950 4950
F 0 "#PWR0114" H 8950 4700 50  0001 C CNN
F 1 "GND" V 8955 4822 50  0000 R CNN
F 2 "" H 8950 4950 50  0001 C CNN
F 3 "" H 8950 4950 50  0001 C CNN
	1    8950 4950
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 5B5B9DB5
P 8950 4850
F 0 "#PWR0115" H 8950 4600 50  0001 C CNN
F 1 "GND" V 8955 4722 50  0000 R CNN
F 2 "" H 8950 4850 50  0001 C CNN
F 3 "" H 8950 4850 50  0001 C CNN
	1    8950 4850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5B5B9DE6
P 8950 4750
F 0 "#PWR0116" H 8950 4500 50  0001 C CNN
F 1 "GND" V 8955 4622 50  0000 R CNN
F 2 "" H 8950 4750 50  0001 C CNN
F 3 "" H 8950 4750 50  0001 C CNN
	1    8950 4750
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 5B5B9E17
P 8950 4550
F 0 "#PWR0117" H 8950 4300 50  0001 C CNN
F 1 "GND" V 8955 4422 50  0000 R CNN
F 2 "" H 8950 4550 50  0001 C CNN
F 3 "" H 8950 4550 50  0001 C CNN
	1    8950 4550
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0118
U 1 1 5B5B9E48
P 8950 4350
F 0 "#PWR0118" H 8950 4100 50  0001 C CNN
F 1 "GND" V 8955 4222 50  0000 R CNN
F 2 "" H 8950 4350 50  0001 C CNN
F 3 "" H 8950 4350 50  0001 C CNN
	1    8950 4350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 5B5B9E79
P 8950 4250
F 0 "#PWR0119" H 8950 4000 50  0001 C CNN
F 1 "GND" V 8955 4122 50  0000 R CNN
F 2 "" H 8950 4250 50  0001 C CNN
F 3 "" H 8950 4250 50  0001 C CNN
	1    8950 4250
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 5B5B9EAA
P 8950 4150
F 0 "#PWR0120" H 8950 3900 50  0001 C CNN
F 1 "GND" V 8955 4022 50  0000 R CNN
F 2 "" H 8950 4150 50  0001 C CNN
F 3 "" H 8950 4150 50  0001 C CNN
	1    8950 4150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7450 4550 7350 4550
Wire Wire Line
	7350 4550 7350 4600
Wire Wire Line
	7350 4800 7350 4850
Wire Wire Line
	7350 4850 7450 4850
Wire Wire Line
	7450 4950 7350 4950
Wire Wire Line
	7350 4950 7350 5000
Wire Wire Line
	7350 5200 7350 5250
Wire Wire Line
	7350 5250 7450 5250
Wire Wire Line
	7450 5450 7200 5450
Wire Wire Line
	7450 5650 7300 5650
Wire Wire Line
	7300 5650 7300 5750
Wire Wire Line
	7450 5750 7300 5750
Connection ~ 7300 5750
Wire Wire Line
	7300 5750 7300 5850
Wire Wire Line
	7450 5850 7300 5850
Connection ~ 7300 5850
Wire Wire Line
	7300 5850 7300 5950
Wire Wire Line
	7450 5950 7300 5950
Connection ~ 7300 5950
Wire Wire Line
	7300 5950 7300 6050
Wire Wire Line
	7200 5650 7200 5950
Wire Wire Line
	7200 5950 7300 5950
Wire Wire Line
	6850 5550 6850 5950
Wire Wire Line
	6850 5950 7200 5950
Connection ~ 7200 5950
Wire Wire Line
	7450 5350 6850 5350
Text GLabel 9100 5250 2    50   Input ~ 0
SCL
Text GLabel 9100 5350 2    50   Input ~ 0
SDA
$Comp
L power:GND #PWR0121
U 1 1 5B5BC00C
P 7000 4900
F 0 "#PWR0121" H 7000 4650 50  0001 C CNN
F 1 "GND" H 7005 4727 50  0000 C CNN
F 2 "" H 7000 4900 50  0001 C CNN
F 3 "" H 7000 4900 50  0001 C CNN
	1    7000 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 4900 7000 4850
Wire Wire Line
	7000 4850 6700 4850
Wire Wire Line
	6700 4850 6700 4800
Connection ~ 7000 4850
Wire Wire Line
	7000 4850 7000 4800
Wire Wire Line
	6700 4850 6400 4850
Wire Wire Line
	6400 4850 6400 4800
Connection ~ 6700 4850
Wire Wire Line
	7450 4300 6700 4300
Wire Wire Line
	6700 4300 6700 4600
Wire Wire Line
	7450 4400 7000 4400
Wire Wire Line
	7000 4400 7000 4600
Wire Wire Line
	7450 4150 7000 4150
Wire Wire Line
	6400 4150 6400 4600
$Comp
L power:GND #PWR0122
U 1 1 5B5BEA2C
P 10000 2600
F 0 "#PWR0122" H 10000 2350 50  0001 C CNN
F 1 "GND" V 10005 2472 50  0000 R CNN
F 2 "" H 10000 2600 50  0001 C CNN
F 3 "" H 10000 2600 50  0001 C CNN
	1    10000 2600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9800 2600 9600 2600
$Comp
L tinkerforge:3V3 #PWR0123
U 1 1 5B5BF451
P 7000 3950
F 0 "#PWR0123" H 7000 4050 40  0001 C CNN
F 1 "3V3" H 7009 4106 40  0000 C CNN
F 2 "" H 7000 3950 60  0000 C CNN
F 3 "" H 7000 3950 60  0000 C CNN
	1    7000 3950
	1    0    0    -1  
$EndComp
Connection ~ 7000 4400
Wire Wire Line
	7000 3950 7000 4150
Connection ~ 7000 4150
Wire Wire Line
	7000 4150 6400 4150
Wire Wire Line
	7000 4150 7000 4400
$Comp
L power:GND #PWR0124
U 1 1 5B5C0E10
P 1300 6850
F 0 "#PWR0124" H 1300 6600 50  0001 C CNN
F 1 "GND" H 1305 6677 50  0000 C CNN
F 2 "" H 1300 6850 50  0001 C CNN
F 3 "" H 1300 6850 50  0001 C CNN
	1    1300 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 6850 1300 6850
Connection ~ 1300 6850
$Comp
L keyboard:DS1337 U1
U 1 1 5B5C37B7
P 5000 3600
F 0 "U1" H 5000 3975 50  0000 C CNN
F 1 "DS1337" H 5000 3884 50  0000 C CNN
F 2 "kicad-libraries:SO-8" H 4850 3700 50  0001 C CNN
F 3 "" H 4850 3700 50  0001 C CNN
	1    5000 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 3300 4300 3300
Wire Wire Line
	4300 3300 4300 3450
Wire Wire Line
	4300 3450 4450 3450
$Comp
L tinkerforge:3V3 #PWR0125
U 1 1 5B5C641B
P 5550 3450
F 0 "#PWR0125" H 5550 3550 40  0001 C CNN
F 1 "3V3" V 5559 3568 40  0000 L CNN
F 2 "" H 5550 3450 60  0000 C CNN
F 3 "" H 5550 3450 60  0000 C CNN
	1    5550 3450
	0    1    1    0   
$EndComp
$Comp
L tinkerforge:3V3 #PWR0126
U 1 1 5B5C64D8
P 4850 5100
F 0 "#PWR0126" H 4850 5200 40  0001 C CNN
F 1 "3V3" V 4859 5218 40  0000 L CNN
F 2 "" H 4850 5100 60  0000 C CNN
F 3 "" H 4850 5100 60  0000 C CNN
	1    4850 5100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0127
U 1 1 5B5C662B
P 4850 4900
F 0 "#PWR0127" H 4850 4650 50  0001 C CNN
F 1 "GND" V 4855 4772 50  0000 R CNN
F 2 "" H 4850 4900 50  0001 C CNN
F 3 "" H 4850 4900 50  0001 C CNN
	1    4850 4900
	0    -1   -1   0   
$EndComp
Text GLabel 9600 1950 2    50   Input ~ 0
SCL
Text GLabel 9600 2050 2    50   Input ~ 0
SDA
$Comp
L device:C_Small C9
U 1 1 5B5C6A55
P 9700 3000
F 0 "C9" V 9471 3000 50  0000 C CNN
F 1 "0.1uF" V 9562 3000 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 9700 3000 50  0001 C CNN
F 3 "" H 9700 3000 50  0001 C CNN
	1    9700 3000
	-1   0    0    1   
$EndComp
$Comp
L tinkerforge:3V3 #PWR0128
U 1 1 5B5C6BA2
P 9900 2800
F 0 "#PWR0128" H 9900 2900 40  0001 C CNN
F 1 "3V3" V 9909 2918 40  0000 L CNN
F 2 "" H 9900 2800 60  0000 C CNN
F 3 "" H 9900 2800 60  0000 C CNN
	1    9900 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	9600 2700 9950 2700
Wire Wire Line
	9600 2800 9700 2800
Wire Wire Line
	9700 2900 9700 2800
Connection ~ 9700 2800
Wire Wire Line
	9700 2800 9900 2800
$Comp
L power:GND #PWR0129
U 1 1 5B5C961C
P 9950 2700
F 0 "#PWR0129" H 9950 2450 50  0001 C CNN
F 1 "GND" V 9955 2572 50  0000 R CNN
F 2 "" H 9950 2700 50  0001 C CNN
F 3 "" H 9950 2700 50  0001 C CNN
	1    9950 2700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3400 4900 3400 5000
Connection ~ 3400 5000
Wire Wire Line
	2500 5100 2500 5000
Wire Wire Line
	3400 5100 3400 5000
$Comp
L switches:SW_Push SW1
U 1 1 5B5CF6D3
P 3300 1800
F 0 "SW1" H 3300 2085 50  0000 C CNN
F 1 "SW_Push" H 3300 1994 50  0000 C CNN
F 2 "keyboard:4_4_1.5_button" H 3300 2000 50  0001 C CNN
F 3 "" H 3300 2000 50  0001 C CNN
	1    3300 1800
	1    0    0    -1  
$EndComp
Text GLabel 9600 2300 2    50   Input ~ 0
TEST_BTN
Text GLabel 3000 1800 3    50   Input ~ 0
TEST_BTN
$Comp
L power:GND #PWR0130
U 1 1 5B5CF964
P 3500 1800
F 0 "#PWR0130" H 3500 1550 50  0001 C CNN
F 1 "GND" V 3505 1672 50  0000 R CNN
F 2 "" H 3500 1800 50  0001 C CNN
F 3 "" H 3500 1800 50  0001 C CNN
	1    3500 1800
	0    -1   -1   0   
$EndComp
$Comp
L device:R_Small R1
U 1 1 5B5CF9AE
P 2800 1800
F 0 "R1" V 2604 1800 50  0000 C CNN
F 1 "1K" V 2695 1800 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2800 1800 50  0001 C CNN
F 3 "" H 2800 1800 50  0001 C CNN
	1    2800 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	2900 1800 3100 1800
Wire Wire Line
	2700 1800 2600 1800
Connection ~ 2500 5000
$Comp
L keyboard:AMS1117 P1
U 1 1 5B5B773D
P 2950 5050
F 0 "P1" H 2950 5587 60  0000 C CNN
F 1 "AMS1117" H 2950 5481 60  0000 C CNN
F 2 "kicad-libraries:SOT-223" H 2950 5050 60  0001 C CNN
F 3 "" H 2950 5050 60  0001 C CNN
	1    2950 5050
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:3V3 #PWR0131
U 1 1 5B5D8DFD
P 2600 1800
F 0 "#PWR0131" H 2600 1900 40  0001 C CNN
F 1 "3V3" V 2609 1918 40  0000 L CNN
F 2 "" H 2600 1800 60  0000 C CNN
F 3 "" H 2600 1800 60  0000 C CNN
	1    2600 1800
	0    -1   -1   0   
$EndComp
$Comp
L switches:SW_Push SW2
U 1 1 5B5D9026
P 3300 2500
F 0 "SW2" H 3300 2785 50  0000 C CNN
F 1 "SW_Push" H 3300 2694 50  0000 C CNN
F 2 "keyboard:4_4_1.5_button" H 3300 2700 50  0001 C CNN
F 3 "" H 3300 2700 50  0001 C CNN
	1    3300 2500
	1    0    0    -1  
$EndComp
Text GLabel 3000 2500 3    50   Input ~ 0
RESET
$Comp
L power:GND #PWR0132
U 1 1 5B5D902D
P 3500 2500
F 0 "#PWR0132" H 3500 2250 50  0001 C CNN
F 1 "GND" V 3505 2372 50  0000 R CNN
F 2 "" H 3500 2500 50  0001 C CNN
F 3 "" H 3500 2500 50  0001 C CNN
	1    3500 2500
	0    -1   -1   0   
$EndComp
$Comp
L device:R_Small R2
U 1 1 5B5D9033
P 2800 2500
F 0 "R2" V 2604 2500 50  0000 C CNN
F 1 "1K" V 2695 2500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2800 2500 50  0001 C CNN
F 3 "" H 2800 2500 50  0001 C CNN
	1    2800 2500
	0    1    1    0   
$EndComp
Wire Wire Line
	2900 2500 3100 2500
Wire Wire Line
	2700 2500 2600 2500
$Comp
L tinkerforge:3V3 #PWR0133
U 1 1 5B5D903B
P 2600 2500
F 0 "#PWR0133" H 2600 2600 40  0001 C CNN
F 1 "3V3" V 2609 2618 40  0000 L CNN
F 2 "" H 2600 2500 60  0000 C CNN
F 3 "" H 2600 2500 60  0000 C CNN
	1    2600 2500
	0    -1   -1   0   
$EndComp
Text GLabel 9600 2200 2    50   Input ~ 0
RESET
Text GLabel 5550 3550 2    50   Input ~ 0
INTB
Text GLabel 4450 3650 0    50   Input ~ 0
INTA
Text GLabel 6850 2250 0    50   Input ~ 0
INTA
Text GLabel 6850 2350 0    50   Input ~ 0
INTB
Text GLabel 4850 4800 2    50   Input ~ 0
RESET
Wire Wire Line
	4100 3550 4100 3600
Wire Wire Line
	4100 3600 3900 3600
Wire Wire Line
	4100 3550 4450 3550
$Comp
L conn:Conn_01x02 J3
U 1 1 5B5DE476
P 3000 6300
F 0 "J3" H 2920 5975 50  0000 C CNN
F 1 "Conn_01x02" H 2920 6066 50  0000 C CNN
F 2 "" H 3000 6300 50  0001 C CNN
F 3 "~" H 3000 6300 50  0001 C CNN
	1    3000 6300
	-1   0    0    1   
$EndComp
Text Label 3450 6200 0    50   ~ 0
BAT+
Text Label 3450 6300 0    50   ~ 0
BAT-
$Comp
L power:GND #PWR0134
U 1 1 5B5DE829
P 3300 6300
F 0 "#PWR0134" H 3300 6050 50  0001 C CNN
F 1 "GND" H 3305 6127 50  0000 C CNN
F 2 "" H 3300 6300 50  0001 C CNN
F 3 "" H 3300 6300 50  0001 C CNN
	1    3300 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 6300 3300 6300
Wire Wire Line
	3300 6300 3450 6300
Connection ~ 3300 6300
Wire Wire Line
	3450 6200 3200 6200
$EndSCHEMATC