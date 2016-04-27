/*
 * common.h
 *
 *  Created on: 19 avr. 2016
 *      Author: guill
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "stm32f30x.h"
#include "event.h"

#include "Drivers/D_IO.h"
#include "Drivers/D_I2C.h"
#include "Drivers/D_Timer.h"
#include "Drivers/D_UART.h"

#include "Application/A_I2C.h"
#include "Application/A_capteur_ultrason.h"
#include "Application/A_servo_moteur.h"

/** Definition Esclave / maitre */
#define ESCLAVE				//	Carte actionneur configuree en esclave
//#define MAITRE			//	Carte actionneur configuree en maitre (sans raspberry)


/**
 * Statut de la derniere operation executee
 */
typedef enum{

	E_STATUS_PENDING = 0,
	E_STATUS_OK = 1,
	E_STATUS_ERROR = 2
}E_status;

/*
 * Definition d'un point
 */
typedef struct{
	uint16_t x;
	uint16_t y;
	uint8_t theta;
}S_point;


// Timer 100 us
extern uint8_t timer_100us;

// Timer 1 ms
extern uint8_t timer_1ms;

// Timer 10 ms
extern uint8_t timer_10ms;

// Timer 100 ms
extern uint8_t timer_100ms;

// Timer 1s
extern uint16_t timer_1s;

// Flag nouvelle reception I2C
extern uint8_t nb_data_i2c;

// Flag timeout I2C
extern uint8_t timeout_i2c;

// Executer ultrason
extern uint8_t exec_ultrason;

#endif /* COMMON_H_ */
