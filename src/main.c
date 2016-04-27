//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include "common.h"


/** Variables globales */
// Buffer de reception I2C
uint8_t buffer_i2c_rx[255];

// Buffer de transmission I2C
uint8_t buffer_i2c_tx[255];

// index buffer_rx
uint8_t index_buffer_rx;

// index buffer_tx
uint8_t index_buffer_tx;

// Flag nouvelle reception I2C
uint8_t nb_data_i2c;

// Flag timeout I2C
uint8_t timeout_i2c;

// statut de la dernière opération
E_status status_operation;

// executer capteur ultrason
uint8_t exec_ultrason = 0;

// Timer 100 us
uint8_t timer_100us;

// Timer 1 ms
uint8_t timer_1ms;

// Timer 10 ms
uint8_t timer_10ms;

// Timer 100 ms
uint8_t timer_100ms;

// Timer 1s
uint16_t timer_1s;

/******************/



#ifdef MAITRE
/* Liste des points */
S_point liste_points[] = {{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0},
							{.x = 0, .y = 0, .theta = 0}
};

uint16_t index_point = 0;

#endif



/**
 * Fonction principale carte actionneur
 */
int main()
{
	/** Variables */
	E_SERVO_POSITION pos = SERVO_0deg;		// position initial du servomoteur

	/** Initialisation des peripheriques */
	// Initialiser les I/O
	F_init_IO();

	// Initialiser l'UART de debug
	F_init_UART_debug();

	// Initialiser les Timers
	F_Init_Timer();

	// Initialiser les capteurs ultrasons
	F_init_capteur_ultrasons();

	// Initialiser l'I2C
	#ifdef ESCLAVE
				// Initialiser l'I2C en mode esclave
	#endif
	#ifdef MAITRE
				// Initialiser l'I2C en mode maitre
	#endif

	/****************/

	// Eteindre les LEDs
	LED_GREEN_OFF();
	LED_RED_OFF();
	LED_ORANGE_OFF();

	// Attendre le demarrage du match
	while(1);

	// Demarrer le timer

#ifdef MAITRE
	// envoyer le premier point

#endif

	while(1)
	{
		// Si temps de realiser la Funny Action
		if(timer_1s >= 90)
		{
			// Ouvrir parasol
			LED_GREEN_ON();
		}

		// Toutes les 500ms, executer une mesure ultrason
		if(exec_ultrason == 1)
		{
			F_generer_trig(TRIG_AVANT);
			F_generer_trig(TRIG_ARRIERE);

			exec_ultrason = 0;	// Remise a 0 du flag
		}

#ifdef MAITRE
		// Si obstacle present
		if()
		{
			// Envoyer un signal : faire stopper le robot
		}

		// Si robot au point desire
		// Realiser une nouvelle action
		if(status_operation == E_STATUS_OK)
		{
			index_point ++;
			// Si il faut baisser le bras
			if()
			{
				// Activer l'electro-aimant
				while(); 	// Attendre bras en bas
			}
			// Si il faut lever le bras
			if()
			{
				while(); 	// Attendre bras en haut
			}

			// Si il faut laisser tomber les poissons
			if()
			{

			}
		}
#endif
	}

	 return 0;
}

// ----------------------------------------------------------------------------
