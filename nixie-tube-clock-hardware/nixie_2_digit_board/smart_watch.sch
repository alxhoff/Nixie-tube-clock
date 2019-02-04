EESchema Schematic File Version 4
LIBS:nixie_2_digit_board-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
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
P 3800 2300
F 0 "Y1" V 3754 2431 50  0000 L CNN
F 1 "Crystal" V 3845 2431 50  0000 L CNN
F 2 "Crystals:Crystal_SMD_3215-2pin_3.2x1.5mm" H 3800 2300 50  0001 C CNN
F 3 "" H 3800 2300 50  0001 C CNN
	1    3800 2300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR029
U 1 1 5B589993
P 4350 2600
F 0 "#PWR029" H 4350 2350 50  0001 C CNN
F 1 "GND" H 4355 2427 50  0000 C CNN
F 2 "" H 4350 2600 50  0001 C CNN
F 3 "" H 4350 2600 50  0001 C CNN
	1    4350 2600
	1    0    0    -1  
$EndComp
Text GLabel 5450 2500 2    50   Input ~ 0
SCL
Text GLabel 5450 2600 2    50   Input ~ 0
SDA
$Comp
L stm8:STM8S103F3 U22
U 1 1 5B58BB3D
P 8300 2050
F 0 "U22" H 8225 2867 50  0000 C CNN
F 1 "STM8S103F3" H 8225 2776 50  0000 C CNN
F 2 "kicad-libraries:TSSOP20" H 8300 2950 50  0001 C CNN
F 3 "" H 8300 2950 50  0001 C CNN
	1    8300 2050
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C18
U 1 1 5B58BD21
P 9900 2600
F 0 "C18" V 9671 2600 50  0000 C CNN
F 1 "1uF" V 9762 2600 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 9900 2600 50  0001 C CNN
F 3 "" H 9900 2600 50  0001 C CNN
	1    9900 2600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR048
U 1 1 5B58BDA3
P 9700 3100
F 0 "#PWR048" H 9700 2850 50  0001 C CNN
F 1 "GND" V 9705 2972 50  0000 R CNN
F 2 "" H 9700 3100 50  0001 C CNN
F 3 "" H 9700 3100 50  0001 C CNN
	1    9700 3100
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C9
U 1 1 5B5B77EF
P 2500 5200
F 0 "C9" H 2592 5246 50  0000 L CNN
F 1 "1uF" H 2592 5155 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2500 5200 50  0001 C CNN
F 3 "" H 2500 5200 50  0001 C CNN
	1    2500 5200
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C10
U 1 1 5B5B7863
P 3400 5200
F 0 "C10" H 3492 5246 50  0000 L CNN
F 1 "1uF" H 3492 5155 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3400 5200 50  0001 C CNN
F 3 "" H 3400 5200 50  0001 C CNN
	1    3400 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR024
U 1 1 5B5B78FD
P 2950 5300
F 0 "#PWR024" H 2950 5050 50  0001 C CNN
F 1 "GND" H 2955 5127 50  0000 C CNN
F 2 "" H 2950 5300 50  0001 C CNN
F 3 "" H 2950 5300 50  0001 C CNN
	1    2950 5300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR023
U 1 1 5B5B791D
P 2500 5300
F 0 "#PWR023" H 2500 5050 50  0001 C CNN
F 1 "GND" H 2505 5127 50  0000 C CNN
F 2 "" H 2500 5300 50  0001 C CNN
F 3 "" H 2500 5300 50  0001 C CNN
	1    2500 5300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR027
U 1 1 5B5B793D
P 3400 5300
F 0 "#PWR027" H 3400 5050 50  0001 C CNN
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
L tinkerforge:3V3 #PWR028
U 1 1 5B5B7A35
P 3600 5000
F 0 "#PWR028" H 3600 5100 40  0001 C CNN
F 1 "3V3" V 3609 5118 40  0000 L CNN
F 2 "" H 3600 5000 60  0000 C CNN
F 3 "" H 3600 5000 60  0000 C CNN
	1    3600 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	3600 5000 3400 5000
$Comp
L device:R_Small R9
U 1 1 5B5B7B9D
P 3400 4800
F 0 "R9" H 3459 4846 50  0000 L CNN
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
L power:GND #PWR026
U 1 1 5B5B7E49
P 3400 4400
F 0 "#PWR026" H 3400 4150 50  0001 C CNN
F 1 "GND" H 3405 4227 50  0000 C CNN
F 2 "" H 3400 4400 50  0001 C CNN
F 3 "" H 3400 4400 50  0001 C CNN
	1    3400 4400
	-1   0    0    1   
$EndComp
Text Label 6850 1550 2    50   ~ 0
SWIM
Text Label 4800 5400 0    50   ~ 0
SWIM
$Comp
L conn:USB_A J4
U 1 1 5B5B80BF
P 1300 6450
F 0 "J4" H 1355 6917 50  0000 C CNN
F 1 "USB_A" H 1355 6826 50  0000 C CNN
F 2 "keyboard:USB_Micro-B" H 1450 6400 50  0001 C CNN
F 3 "" H 1450 6400 50  0001 C CNN
	1    1300 6450
	1    0    0    -1  
$EndComp
$Comp
L ssd1306-oled:SSD1306-OLED U21
U 1 1 5B5B93D4
P 8150 5250
F 0 "U21" H 8200 6597 60  0000 C CNN
F 1 "SSD1306-OLED" H 8200 6491 60  0000 C CNN
F 2 "ssd1306oled:SSD1306-096-INCH-OLED" H 9150 4450 60  0001 C CNN
F 3 "" H 9150 4450 60  0001 C CNN
	1    8150 5250
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C15
U 1 1 5B5B95F8
P 7350 4700
F 0 "C15" H 7442 4746 50  0000 L CNN
F 1 "1uF" H 7442 4655 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7350 4700 50  0001 C CNN
F 3 "" H 7350 4700 50  0001 C CNN
	1    7350 4700
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C16
U 1 1 5B5B9725
P 7350 5100
F 0 "C16" H 7442 5146 50  0000 L CNN
F 1 "1uF" H 7442 5055 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7350 5100 50  0001 C CNN
F 3 "" H 7350 5100 50  0001 C CNN
	1    7350 5100
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C13
U 1 1 5B5B9761
P 7000 4700
F 0 "C13" H 7092 4746 50  0000 L CNN
F 1 "1uF" H 7092 4655 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7000 4700 50  0001 C CNN
F 3 "" H 7000 4700 50  0001 C CNN
	1    7000 4700
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C12
U 1 1 5B5B97BB
P 6700 4700
F 0 "C12" H 6792 4746 50  0000 L CNN
F 1 "1uF" H 6792 4655 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6700 4700 50  0001 C CNN
F 3 "" H 6700 4700 50  0001 C CNN
	1    6700 4700
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C11
U 1 1 5B5B97F3
P 6400 4700
F 0 "C11" H 6492 4746 50  0000 L CNN
F 1 "1uF" H 6492 4655 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6400 4700 50  0001 C CNN
F 3 "" H 6400 4700 50  0001 C CNN
	1    6400 4700
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C14
U 1 1 5B5B982B
P 7200 5550
F 0 "C14" H 7292 5596 50  0000 L CNN
F 1 "1uF" H 7292 5505 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7200 5550 50  0001 C CNN
F 3 "" H 7200 5550 50  0001 C CNN
	1    7200 5550
	1    0    0    -1  
$EndComp
$Comp
L device:R_Small R10
U 1 1 5B5B98FB
P 6850 5450
F 0 "R10" H 6909 5496 50  0000 L CNN
F 1 "1M" H 6909 5405 50  0000 L CNN
F 2 "Resistors_SMD:R_0603" H 6850 5450 50  0001 C CNN
F 3 "" H 6850 5450 50  0001 C CNN
	1    6850 5450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR035
U 1 1 5B5B99CD
P 7300 6050
F 0 "#PWR035" H 7300 5800 50  0001 C CNN
F 1 "GND" H 7305 5877 50  0000 C CNN
F 2 "" H 7300 6050 50  0001 C CNN
F 3 "" H 7300 6050 50  0001 C CNN
	1    7300 6050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR047
U 1 1 5B5B9A05
P 8950 5950
F 0 "#PWR047" H 8950 5700 50  0001 C CNN
F 1 "GND" V 8955 5822 50  0000 R CNN
F 2 "" H 8950 5950 50  0001 C CNN
F 3 "" H 8950 5950 50  0001 C CNN
	1    8950 5950
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR046
U 1 1 5B5B9AF5
P 8950 5850
F 0 "#PWR046" H 8950 5600 50  0001 C CNN
F 1 "GND" V 8955 5722 50  0000 R CNN
F 2 "" H 8950 5850 50  0001 C CNN
F 3 "" H 8950 5850 50  0001 C CNN
	1    8950 5850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR045
U 1 1 5B5B9B26
P 8950 5750
F 0 "#PWR045" H 8950 5500 50  0001 C CNN
F 1 "GND" V 8955 5622 50  0000 R CNN
F 2 "" H 8950 5750 50  0001 C CNN
F 3 "" H 8950 5750 50  0001 C CNN
	1    8950 5750
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR044
U 1 1 5B5B9B57
P 8950 5650
F 0 "#PWR044" H 8950 5400 50  0001 C CNN
F 1 "GND" V 8955 5522 50  0000 R CNN
F 2 "" H 8950 5650 50  0001 C CNN
F 3 "" H 8950 5650 50  0001 C CNN
	1    8950 5650
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR043
U 1 1 5B5B9B88
P 8950 5550
F 0 "#PWR043" H 8950 5300 50  0001 C CNN
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
L power:GND #PWR042
U 1 1 5B5B9D41
P 8950 4950
F 0 "#PWR042" H 8950 4700 50  0001 C CNN
F 1 "GND" V 8955 4822 50  0000 R CNN
F 2 "" H 8950 4950 50  0001 C CNN
F 3 "" H 8950 4950 50  0001 C CNN
	1    8950 4950
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR041
U 1 1 5B5B9DB5
P 8950 4850
F 0 "#PWR041" H 8950 4600 50  0001 C CNN
F 1 "GND" V 8955 4722 50  0000 R CNN
F 2 "" H 8950 4850 50  0001 C CNN
F 3 "" H 8950 4850 50  0001 C CNN
	1    8950 4850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR040
U 1 1 5B5B9DE6
P 8950 4750
F 0 "#PWR040" H 8950 4500 50  0001 C CNN
F 1 "GND" V 8955 4622 50  0000 R CNN
F 2 "" H 8950 4750 50  0001 C CNN
F 3 "" H 8950 4750 50  0001 C CNN
	1    8950 4750
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR039
U 1 1 5B5B9E17
P 8950 4550
F 0 "#PWR039" H 8950 4300 50  0001 C CNN
F 1 "GND" V 8955 4422 50  0000 R CNN
F 2 "" H 8950 4550 50  0001 C CNN
F 3 "" H 8950 4550 50  0001 C CNN
	1    8950 4550
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR038
U 1 1 5B5B9E48
P 8950 4350
F 0 "#PWR038" H 8950 4100 50  0001 C CNN
F 1 "GND" V 8955 4222 50  0000 R CNN
F 2 "" H 8950 4350 50  0001 C CNN
F 3 "" H 8950 4350 50  0001 C CNN
	1    8950 4350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR037
U 1 1 5B5B9E79
P 8950 4250
F 0 "#PWR037" H 8950 4000 50  0001 C CNN
F 1 "GND" V 8955 4122 50  0000 R CNN
F 2 "" H 8950 4250 50  0001 C CNN
F 3 "" H 8950 4250 50  0001 C CNN
	1    8950 4250
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR036
U 1 1 5B5B9EAA
P 8950 4150
F 0 "#PWR036" H 8950 3900 50  0001 C CNN
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
L power:GND #PWR034
U 1 1 5B5BC00C
P 7000 4900
F 0 "#PWR034" H 7000 4650 50  0001 C CNN
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
L power:GND #PWR051
U 1 1 5B5BEA2C
P 10000 2600
F 0 "#PWR051" H 10000 2350 50  0001 C CNN
F 1 "GND" V 10005 2472 50  0000 R CNN
F 2 "" H 10000 2600 50  0001 C CNN
F 3 "" H 10000 2600 50  0001 C CNN
	1    10000 2600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9800 2600 9600 2600
$Comp
L tinkerforge:3V3 #PWR033
U 1 1 5B5BF451
P 7000 3950
F 0 "#PWR033" H 7000 4050 40  0001 C CNN
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
L power:GND #PWR016
U 1 1 5B5C0E10
P 1300 6850
F 0 "#PWR016" H 1300 6600 50  0001 C CNN
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
L keyboard:DS1337 U20
U 1 1 5B5C37B7
P 4900 2450
F 0 "U20" H 4900 2825 50  0000 C CNN
F 1 "DS1337" H 4900 2734 50  0000 C CNN
F 2 "kicad-libraries:SO-8" H 4750 2550 50  0001 C CNN
F 3 "" H 4750 2550 50  0001 C CNN
	1    4900 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 2150 4200 2150
Wire Wire Line
	4200 2150 4200 2300
Wire Wire Line
	4200 2300 4350 2300
$Comp
L tinkerforge:3V3 #PWR032
U 1 1 5B5C641B
P 5450 2300
F 0 "#PWR032" H 5450 2400 40  0001 C CNN
F 1 "3V3" V 5459 2418 40  0000 L CNN
F 2 "" H 5450 2300 60  0000 C CNN
F 3 "" H 5450 2300 60  0000 C CNN
	1    5450 2300
	0    1    1    0   
$EndComp
$Comp
L tinkerforge:3V3 #PWR031
U 1 1 5B5C64D8
P 4800 5500
F 0 "#PWR031" H 4800 5600 40  0001 C CNN
F 1 "3V3" V 4809 5618 40  0000 L CNN
F 2 "" H 4800 5500 60  0000 C CNN
F 3 "" H 4800 5500 60  0000 C CNN
	1    4800 5500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR030
U 1 1 5B5C662B
P 4800 5300
F 0 "#PWR030" H 4800 5050 50  0001 C CNN
F 1 "GND" V 4805 5172 50  0000 R CNN
F 2 "" H 4800 5300 50  0001 C CNN
F 3 "" H 4800 5300 50  0001 C CNN
	1    4800 5300
	0    -1   -1   0   
$EndComp
Text GLabel 9600 1950 2    50   Input ~ 0
SCL
Text GLabel 9600 2050 2    50   Input ~ 0
SDA
$Comp
L device:C_Small C17
U 1 1 5B5C6A55
P 9700 3000
F 0 "C17" V 9471 3000 50  0000 C CNN
F 1 "0.1uF" V 9562 3000 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 9700 3000 50  0001 C CNN
F 3 "" H 9700 3000 50  0001 C CNN
	1    9700 3000
	-1   0    0    1   
$EndComp
$Comp
L tinkerforge:3V3 #PWR049
U 1 1 5B5C6BA2
P 9900 2800
F 0 "#PWR049" H 9900 2900 40  0001 C CNN
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
L power:GND #PWR050
U 1 1 5B5C961C
P 9950 2700
F 0 "#PWR050" H 9950 2450 50  0001 C CNN
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
L switches:SW_Push SW2
U 1 1 5B5CF6D3
P 2250 2450
F 0 "SW2" H 2250 2735 50  0000 C CNN
F 1 "SW_Push" H 2250 2644 50  0000 C CNN
F 2 "keyboard:4_4_1.5_button" H 2250 2650 50  0001 C CNN
F 3 "" H 2250 2650 50  0001 C CNN
	1    2250 2450
	1    0    0    -1  
$EndComp
Text GLabel 9600 2300 2    50   Input ~ 0
TEST_BTN1
Text GLabel 1950 2450 3    50   Input ~ 0
TEST_BTN1
$Comp
L power:GND #PWR021
U 1 1 5B5CF964
P 2450 2450
F 0 "#PWR021" H 2450 2200 50  0001 C CNN
F 1 "GND" V 2455 2322 50  0000 R CNN
F 2 "" H 2450 2450 50  0001 C CNN
F 3 "" H 2450 2450 50  0001 C CNN
	1    2450 2450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1850 2450 2050 2450
Connection ~ 2500 5000
$Comp
L keyboard:AMS1117 P2
U 1 1 5B5B773D
P 2950 5050
F 0 "P2" H 2950 5587 60  0000 C CNN
F 1 "AMS1117" H 2950 5481 60  0000 C CNN
F 2 "kicad-libraries:SOT-223" H 2950 5050 60  0001 C CNN
F 3 "" H 2950 5050 60  0001 C CNN
	1    2950 5050
	1    0    0    -1  
$EndComp
$Comp
L switches:SW_Push SW3
U 1 1 5B5D9026
P 2250 3150
F 0 "SW3" H 2250 3435 50  0000 C CNN
F 1 "SW_Push" H 2250 3344 50  0000 C CNN
F 2 "keyboard:4_4_1.5_button" H 2250 3350 50  0001 C CNN
F 3 "" H 2250 3350 50  0001 C CNN
	1    2250 3150
	1    0    0    -1  
$EndComp
Text GLabel 1950 3150 3    50   Input ~ 0
RESET
$Comp
L power:GND #PWR022
U 1 1 5B5D902D
P 2450 3150
F 0 "#PWR022" H 2450 2900 50  0001 C CNN
F 1 "GND" V 2455 3022 50  0000 R CNN
F 2 "" H 2450 3150 50  0001 C CNN
F 3 "" H 2450 3150 50  0001 C CNN
	1    2450 3150
	0    -1   -1   0   
$EndComp
Text GLabel 9600 2200 2    50   Input ~ 0
RESET
Text GLabel 5450 2400 2    50   Input ~ 0
INTB
Text GLabel 4350 2500 0    50   Input ~ 0
INTA
Text GLabel 6850 2250 0    50   Input ~ 0
INTA
Text GLabel 6850 2350 0    50   Input ~ 0
INTB
Text GLabel 4800 5200 2    50   Input ~ 0
RESET
Wire Wire Line
	4000 2400 4000 2450
Wire Wire Line
	4000 2450 3800 2450
Wire Wire Line
	4000 2400 4350 2400
$Comp
L conn:Conn_01x02 J5
U 1 1 5B5DE476
P 3000 6300
F 0 "J5" H 2920 5975 50  0000 C CNN
F 1 "Conn_01x02" H 2920 6066 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 3000 6300 50  0001 C CNN
F 3 "~" H 3000 6300 50  0001 C CNN
	1    3000 6300
	-1   0    0    1   
$EndComp
Text Label 3450 6200 0    50   ~ 0
BAT+
Text Label 3450 6300 0    50   ~ 0
BAT-
$Comp
L power:GND #PWR025
U 1 1 5B5DE829
P 3300 6300
F 0 "#PWR025" H 3300 6050 50  0001 C CNN
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
Text GLabel 9600 2400 2    50   Input ~ 0
TEST_BTN2
$Comp
L switches:SW_Push SW1
U 1 1 5B5C69CD
P 2250 1850
F 0 "SW1" H 2250 2135 50  0000 C CNN
F 1 "SW_Push" H 2250 2044 50  0000 C CNN
F 2 "keyboard:4_4_1.5_button" H 2250 2050 50  0001 C CNN
F 3 "" H 2250 2050 50  0001 C CNN
	1    2250 1850
	1    0    0    -1  
$EndComp
Text GLabel 1950 1850 3    50   Input ~ 0
TEST_BTN2
$Comp
L power:GND #PWR020
U 1 1 5B5C69D4
P 2450 1850
F 0 "#PWR020" H 2450 1600 50  0001 C CNN
F 1 "GND" V 2455 1722 50  0000 R CNN
F 2 "" H 2450 1850 50  0001 C CNN
F 3 "" H 2450 1850 50  0001 C CNN
	1    2450 1850
	0    -1   -1   0   
$EndComp
Text Label 1600 6250 0    50   ~ 0
BAT+
Wire Wire Line
	1450 1850 2050 1850
Wire Wire Line
	1450 1950 1850 1950
Wire Wire Line
	1850 1950 1850 2450
Wire Wire Line
	1450 2050 1800 2050
Wire Wire Line
	1800 2050 1800 3150
Wire Wire Line
	1800 3150 2050 3150
$Comp
L device:R_Pack04 RN8
U 1 1 5B5D6563
P 1250 1950
F 0 "RN8" V 1575 1950 50  0000 C CNN
F 1 "R_Pack04" V 1484 1950 50  0000 C CNN
F 2 "Resistors_SMD:R_Array_Concave_4x0402" V 1525 1950 50  0001 C CNN
F 3 "" H 1250 1950 50  0001 C CNN
	1    1250 1950
	0    1    -1   0   
$EndComp
$Comp
L tinkerforge:3V3 #PWR0154
U 1 1 5B5D6663
P 1050 2050
F 0 "#PWR0154" H 1050 2150 40  0001 C CNN
F 1 "3V3" V 1059 2168 40  0000 L CNN
F 2 "" H 1050 2050 60  0000 C CNN
F 3 "" H 1050 2050 60  0000 C CNN
	1    1050 2050
	0    -1   -1   0   
$EndComp
$Comp
L tinkerforge:3V3 #PWR0155
U 1 1 5B5D66A0
P 1050 1950
F 0 "#PWR0155" H 1050 2050 40  0001 C CNN
F 1 "3V3" V 1059 2068 40  0000 L CNN
F 2 "" H 1050 1950 60  0000 C CNN
F 3 "" H 1050 1950 60  0000 C CNN
	1    1050 1950
	0    -1   -1   0   
$EndComp
$Comp
L tinkerforge:3V3 #PWR0156
U 1 1 5B5D66DD
P 1050 1850
F 0 "#PWR0156" H 1050 1950 40  0001 C CNN
F 1 "3V3" V 1059 1968 40  0000 L CNN
F 2 "" H 1050 1850 60  0000 C CNN
F 3 "" H 1050 1850 60  0000 C CNN
	1    1050 1850
	0    -1   -1   0   
$EndComp
$Comp
L tinkerforge:3V3 #PWR0157
U 1 1 5B5D6734
P 1050 2150
F 0 "#PWR0157" H 1050 2250 40  0001 C CNN
F 1 "3V3" V 1059 2268 40  0000 L CNN
F 2 "" H 1050 2150 60  0000 C CNN
F 3 "" H 1050 2150 60  0000 C CNN
	1    1050 2150
	0    -1   -1   0   
$EndComp
Text GLabel 4800 5800 2    50   Input ~ 0
SCL
Text GLabel 4800 5900 2    50   Input ~ 0
SDA
$Comp
L power:GND #PWR0158
U 1 1 5B5CE74D
P 4800 5600
F 0 "#PWR0158" H 4800 5350 50  0001 C CNN
F 1 "GND" V 4805 5472 50  0000 R CNN
F 2 "" H 4800 5600 50  0001 C CNN
F 3 "" H 4800 5600 50  0001 C CNN
	1    4800 5600
	0    -1   -1   0   
$EndComp
$Comp
L tinkerforge:3V3 #PWR0159
U 1 1 5B5CE78C
P 4800 5700
F 0 "#PWR0159" H 4800 5800 40  0001 C CNN
F 1 "3V3" V 4809 5818 40  0000 L CNN
F 2 "" H 4800 5700 60  0000 C CNN
F 3 "" H 4800 5700 60  0000 C CNN
	1    4800 5700
	0    1    1    0   
$EndComp
$Comp
L conn:Conn_01x08 J6
U 1 1 5B5CEDF8
P 4600 5600
F 0 "J6" H 4520 4975 50  0000 C CNN
F 1 "Conn_01x08" H 4520 5066 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 4600 5600 50  0001 C CNN
F 3 "~" H 4600 5600 50  0001 C CNN
	1    4600 5600
	-1   0    0    1   
$EndComp
$EndSCHEMATC
