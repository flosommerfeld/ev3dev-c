
/*  ev3_input.h was generated by yup.py (yupp) 0.7b7
    out of ev3_input.yu-h at 2014-11-27 15:24
 *//**
 *  \file  ev3_input.h (ev3_input.yu-h)
 *  \brief  EV3 Input Ports.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#ifndef EV3_INPUT_H
#define EV3_INPUT_H

#ifdef  EV3_INPUT_IMPLEMENT
#define EV3_INPUT_EXT
#define EV3_INPUT_EXT_INIT( dec, init ) \
	dec = init
#else
#define EV3_INPUT_EXT extern
#define EV3_INPUT_EXT_INIT( dec, init ) \
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
 *  \addtogroup ev3_port
 *  \{
 */

#define INPUT_DIR  "/sys/bus/legoev3/devices"  /**< Directory of input ports. */
#define INPUT__BASE_  1  /**< Base index of EV3 input ports. */

/**
 *  \brief Identifiers of EV3 input ports.
 */
enum {
	INPUT_1 = INPUT__BASE_ + 0,
	INPUT_2 = INPUT__BASE_ + 1,
	INPUT_3 = INPUT__BASE_ + 2,
	INPUT_4 = INPUT__BASE_ + 3,

};

#define INPUT__COUNT_  4  /**< Count of EV3 input ports. */

/**
 *  \brief Identifiers of input port modes.
 */
enum {
	INPUT_AUTO,
	INPUT_EV3_ANALOG,
	INPUT_EV3_UART,
	INPUT_NXT_ANALOG,
	INPUT_NXT_COLOR,
	INPUT_NXT_I2C,
	INPUT_OTHER_UART,
	INPUT_RAW,

	INPUT_MODE__COUNT_  /**< Count of input port modes. */
};

/**
 *  \brief Get index of the EV3 input port from the port name.
 *  \param name Port name.
 *  \return EV3 input port index.
 */
EV3_INPUT_EXT uint8_t ev3_input_inx( const char *name );

/**
 *  \brief Get name of the specified EV3 input port.
 *  \param port Port index.
 *  \return Requested value.
 */
EV3_INPUT_EXT const char *ev3_input_name( uint8_t port );

/**
 *  \brief Get "mode" attribute of the input port.
 *  \param port Port index.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_INPUT_EXT size_t get_input_mode( uint8_t port, char *buf, size_t sz );

/**
 *  \brief Set "mode" attribute of the input port.
 *  \param port Port index.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_INPUT_EXT size_t set_input_mode( uint8_t port, char *value );

/**
 *  \brief Get "modes" attribute of the input port.
 *  \param port Port index.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_INPUT_EXT size_t get_input_modes( uint8_t port, char *buf, size_t sz );

/**
 *  \brief Get "pin1_mv" attribute of the input port.
 *  \param port Port index.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_INPUT_EXT size_t get_input_pin1_mv( uint8_t port, int *buf );

/**
 *  \brief Get "pin6_mv" attribute of the input port.
 *  \param port Port index.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_INPUT_EXT size_t get_input_pin6_mv( uint8_t port, int *buf );

/**
 *  \brief Get "state" attribute of the input port.
 *  \param port Port index.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_INPUT_EXT size_t get_input_state( uint8_t port, char *buf, size_t sz );

/**
 *  \brief Get name of the specified input mode.
 *  \param mode_inx The input mode.
 *  \return Requested value.
 */
EV3_INPUT_EXT const char *ev3_input_mode( uint8_t mode_inx );

/**
 *  \brief Get the mode index of the input port.
 *  \param port Port index.
 *  \return Index of the mode or INPUT_MODE__COUNT_ - error has occurred.
 */
EV3_INPUT_EXT uint8_t get_input_mode_inx( uint8_t port );

/**
 *  \brief Set the mode of the input by index.
 *  \param port Port index.
 *  \param mode_inx Index of the mode.
 *  \return Count of written bytes.
 */
EV3_INPUT_EXT size_t set_input_mode_inx( uint8_t port, uint8_t mode_inx );

/** \} */

#ifdef __cplusplus
}
#endif

#endif

