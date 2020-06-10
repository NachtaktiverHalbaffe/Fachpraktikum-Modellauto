/*  GlobalDefinitions.h
 *	1.0, 2020-05-17
 *	
 *		Here are all global "#define"'s implemented
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Alexander Laichinger
 */

#ifndef GLOBALDEFINITIONS_H_
#define GLOBALDEFINITIONS_H_


/****************************   CLOCK   ****************************/
#ifndef F_CPU	
#define	F_CPU					  16000000UL
#endif 

/****************************   REMOTE  ****************************/

#define DRIVING_DIRECTION				0x00
#define STEERING_DIRECTION				0x01
#define LIGHT_STATUS					0x02
#define HORN_STATUS						0x03

#define LIGHT_OFF						0x00
#define LIGHT_AUTOMATIC					0x01
#define LIGHT_ON						0x02

#define MIN_FORWARD						 523
#define MIN_REVERSE					 	 500

#define MIN_LEFT						 500
#define MIN_RIGHT						 523

#define STEERING_SERVO_AHEAD			 512
#define SENSOR_SERVO_AHEAD				 512

/****************************   Servo   ****************************/
#define SENSOR_SERVO_PIN				 10
#define STEERING_SERVO_PIN				 9

/****************************   MOTOR   ****************************/
#define MOTOR_FORWARD_PIN				 5
#define MOTOR_REVERSE_PIN				 6
#define PWM_MAX_FORWARD					 510
#define PWM_MAX_REVERSE					 0


/****************************    HORN   ****************************/

#define HORN_OFF						0x00
#define HORN_ON							0x01



/****************************   SENSOR  ****************************/

#define FRONT_SONIC						0x00
#define REAR_SONIC						0x01
#define FRONT_SONIC_TRIGGER_PIN			0
#define FRONT_SONIC_ECHO_PIN			1
#define REAR_SONIC_TRIGGER_PIN			2
#define REAR_SONIC_ECHO_PIN				3




/****************************   Custom  ****************************/


#endif /* GLOBALDEFINITIONS_H_ */




