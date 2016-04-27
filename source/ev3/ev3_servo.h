
/*  ev3_servo.h was generated by yup.py (yupp) 0.9b2
    out of ev3_servo.yu-h 
 *//**
 *  \file  ev3_servo.h (ev3_servo.yu-h)
 *  \brief  EV3 Servo Motors.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#ifndef EV3_SERVO_H
#define EV3_SERVO_H

#ifdef  EV3_SERVO_IMPLEMENT
#define EV3_SERVO_EXT
#define EV3_SERVO_EXT_INIT( dec, init ) \
	dec = init
#else
#define EV3_SERVO_EXT extern
#define EV3_SERVO_EXT_INIT( dec, init ) \
	extern dec
#endif

#ifndef COMMA
#define COMMA   ,
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  \defgroup ev3_servo Servo Motors
 *  \brief Access to EV3 Servo Motors.
 *  \see http://www.ev3dev.org/docs/drivers/servo-motor-class/
 *  \{
 */

#define SERVO_DIR  "/sys/class/servo-motor"  /**< Directory of servo motors. */

/**
 *  \brief Structure of a servo motor descriptor.
 */
typedef struct {
	INX_T type_inx;  /**< Servo motor type. */
	uint8_t port;  /**< Servo motor EV3 port. */
	uint8_t extport;  /**< Servo motor extended port. */
	uint8_t addr;  /**< Servo motor I2C address. */

} EV3_SERVO;

#define SERVO_DESC__LIMIT_  DESC_LIMIT  /**< Limit of servo motor descriptors. */

#define SERVO__NONE_  SERVO_DESC__LIMIT_  /**< Servo motor is not found. */

/**
 *  \brief Vector of servo motor descriptors (filled by \ref ev3_servo_init).
 */
EV3_SERVO_EXT EV3_SERVO ev3_servo[ SERVO_DESC__LIMIT_ ];

/**
 *  \brief Identifiers of servo motor types.
 */
enum {
	SERVO_TYPE__NONE_ = 0,  /* XXX: memset( 0 ) is used */

	SERVO_MOTOR,

	SERVO_TYPE__COUNT_,  /**< Count of servo motor types. */
	SERVO_TYPE__UNKNOWN_ = SERVO_TYPE__COUNT_
};

/**
 *  \brief Common identifiers of servo motor "command" attribute.
 */
enum {
	SERVO_COMMAND__NONE_ = 0,

	SERVO_RUN,
	SERVO_FLOAT,

	SERVO_COMMAND__COUNT_,  /**< Count of servo motor "command" attribute. */
	SERVO_COMMAND__UNKNOWN_ = SERVO_COMMAND__COUNT_
};

/**
 *  \brief Common identifiers of servo motor "polarity" attribute.
 */
enum {
	SERVO_POLARITY__NONE_ = 0,

	SERVO_NORMAL,
	SERVO_INVERSED,

	SERVO_POLARITY__COUNT_,  /**< Count of servo motor "polarity" attribute. */
	SERVO_POLARITY__UNKNOWN_ = SERVO_POLARITY__COUNT_
};

/**
 *  \brief Common identifiers of servo motor "state" attribute.
 */
enum {
	SERVO_STATE__NONE_ = 0,

	SERVO_RUNNING = 0x1L,

};

/**
 *  \brief Read "address" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_address( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Read "command" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_command( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Write "command" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_command( uint8_t sn, char *value );

/**
 *  \brief Write "command" attribute of several servo motors.
 *  \param sn Vector of sequence numbers ending with DESC_LIMIT.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t multi_set_servo_command( uint8_t *sn, char *value );

/**
 *  \brief Read "driver_name" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_driver_name( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Read "max_pulse_sp" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_max_pulse_sp( uint8_t sn, int *buf );

/**
 *  \brief Write "max_pulse_sp" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_max_pulse_sp( uint8_t sn, int value );

/**
 *  \brief Write "max_pulse_sp" attribute of several servo motors.
 *  \param sn Vector of sequence numbers ending with DESC_LIMIT.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t multi_set_servo_max_pulse_sp( uint8_t *sn, int value );

/**
 *  \brief Read "mid_pulse_sp" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_mid_pulse_sp( uint8_t sn, int *buf );

/**
 *  \brief Write "mid_pulse_sp" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_mid_pulse_sp( uint8_t sn, int value );

/**
 *  \brief Write "mid_pulse_sp" attribute of several servo motors.
 *  \param sn Vector of sequence numbers ending with DESC_LIMIT.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t multi_set_servo_mid_pulse_sp( uint8_t *sn, int value );

/**
 *  \brief Read "min_pulse_sp" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_min_pulse_sp( uint8_t sn, int *buf );

/**
 *  \brief Write "min_pulse_sp" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_min_pulse_sp( uint8_t sn, int value );

/**
 *  \brief Write "min_pulse_sp" attribute of several servo motors.
 *  \param sn Vector of sequence numbers ending with DESC_LIMIT.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t multi_set_servo_min_pulse_sp( uint8_t *sn, int value );

/**
 *  \brief Read "polarity" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_polarity( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Write "polarity" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_polarity( uint8_t sn, char *value );

/**
 *  \brief Write "polarity" attribute of several servo motors.
 *  \param sn Vector of sequence numbers ending with DESC_LIMIT.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t multi_set_servo_polarity( uint8_t *sn, char *value );

/**
 *  \brief Read "position_sp" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_position_sp( uint8_t sn, int *buf );

/**
 *  \brief Write "position_sp" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_position_sp( uint8_t sn, int value );

/**
 *  \brief Write "position_sp" attribute of several servo motors.
 *  \param sn Vector of sequence numbers ending with DESC_LIMIT.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t multi_set_servo_position_sp( uint8_t *sn, int value );

/**
 *  \brief Read "rate_sp" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_rate_sp( uint8_t sn, int *buf );

/**
 *  \brief Write "rate_sp" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_rate_sp( uint8_t sn, int value );

/**
 *  \brief Write "rate_sp" attribute of several servo motors.
 *  \param sn Vector of sequence numbers ending with DESC_LIMIT.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t multi_set_servo_rate_sp( uint8_t *sn, int value );

/**
 *  \brief Read "state" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_state( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get name of the specified servo motor type.
 *  \param type_inx Index of the servo motor type.
 *  \return Requested value.
 */
EV3_SERVO_EXT const char *ev3_servo_type( INX_T type_inx );

/**
 *  \brief Read "driver_name" attribute and get index of the servo motor type.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_SERVO_EXT INX_T get_servo_type_inx( uint8_t sn );

/**
 *  \brief Read the servo motor attributes that are required for filling the descriptor.
 *  \param sn Sequence number.
 *  \param desc Buffer for the descriptor.
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_desc( uint8_t sn, EV3_SERVO *desc );

/**
 *  \brief Get descriptor of the servo motor.
 *  \param sn Sequence number.
 *  \return Pointer to the servo motor descriptor.
 */
EV3_SERVO_EXT EV3_SERVO *ev3_servo_desc( uint8_t sn );

/**
 *  \brief Get type from the servo motor descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_SERVO_EXT INX_T ev3_servo_desc_type_inx( uint8_t sn );

/**
 *  \brief Get EV3 port from the servo motor descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_SERVO_EXT uint8_t ev3_servo_desc_port( uint8_t sn );

/**
 *  \brief Get extended port from the servo motor descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_SERVO_EXT uint8_t ev3_servo_desc_extport( uint8_t sn );

/**
 *  \brief Get I2C address from the servo motor descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_SERVO_EXT uint8_t ev3_servo_desc_addr( uint8_t sn );

/**
 *  \brief Assemble EV3 port name from the servo motor descriptor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \return Requested value.
 */
EV3_SERVO_EXT char *ev3_servo_port_name( uint8_t sn, char *buf );

/**
 *  \brief Search of a sequence number of the specified servo motor type.
 *  \param type_inx The servo motor type.
 *  \param[out] sn Buffer for the sequence number.
 *  \param from Search initial value.
 *  \return Flag - the servo motor is found.
 */
EV3_SERVO_EXT bool ev3_search_servo( INX_T type_inx, uint8_t *sn, uint8_t from );

/**
 *  \brief Search of a sequence number the servo motor by plug-in attributes.
 *  \param port EV3 port.
 *  \param extport Extended port.
 *  \param[out] sn Buffer for the sequence number.
 *  \param from Search initial value.
 *  \return Flag - the servo motor is found.
 */
EV3_SERVO_EXT bool ev3_search_servo_plugged_in( uint8_t port, uint8_t extport, uint8_t *sn, uint8_t from );

/**
 *  \brief Get name of the specified servo motor command.
 *  \param command_inx Index of the servo motor command.
 *  \return Requested value.
 */
EV3_SERVO_EXT const char *ev3_servo_command( INX_T command_inx );

/**
 *  \brief Read "command" attribute of the servo motor and get the index.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_SERVO_EXT INX_T get_servo_command_inx( uint8_t sn );

/**
 *  \brief Write "command" attribute of the servo motor by the index.
 *  \param sn Sequence number.
 *  \param command_inx Index of the servo motor command.
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_command_inx( uint8_t sn, INX_T command_inx );

/**
 *  \brief Write "command" attribute of several servo motors by the index.
 *  \param sn Vector of sequence numbers ending with DESC_LIMIT.
 *  \param command_inx Index of the servo motor command.
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t multi_set_servo_command_inx( uint8_t *sn, INX_T command_inx );

/**
 *  \brief Get name of the specified servo motor polarity.
 *  \param polarity_inx Index of the servo motor polarity.
 *  \return Requested value.
 */
EV3_SERVO_EXT const char *ev3_servo_polarity( INX_T polarity_inx );

/**
 *  \brief Read "polarity" attribute of the servo motor and get the index.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_SERVO_EXT INX_T get_servo_polarity_inx( uint8_t sn );

/**
 *  \brief Write "polarity" attribute of the servo motor by the index.
 *  \param sn Sequence number.
 *  \param polarity_inx Index of the servo motor polarity.
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_polarity_inx( uint8_t sn, INX_T polarity_inx );

/**
 *  \brief Write "polarity" attribute of several servo motors by the index.
 *  \param sn Vector of sequence numbers ending with DESC_LIMIT.
 *  \param polarity_inx Index of the servo motor polarity.
 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t multi_set_servo_polarity_inx( uint8_t *sn, INX_T polarity_inx );

/**
 *  \brief Read "state" attribute of the servo motor and get the flags.
 *  \param sn Sequence number.
 *  \param flags Buffer for the flags.
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_state_flags( uint8_t sn, FLAGS_T *flags );

/**
 *  \brief Detect connected servo motors.
 *  \return The number of found servo motors or -1 in case of an error.
 */
EV3_SERVO_EXT int ev3_servo_init( void );

/** \} */

#ifdef __cplusplus
}
#endif

#endif

