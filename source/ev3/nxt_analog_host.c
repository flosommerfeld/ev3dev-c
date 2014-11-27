
/*  nxt_analog_host.c was generated by yup.py (yupp) 0.7b7
    out of nxt_analog_host.yu-c at 2014-11-27 15:30
 *//**
 *  \file  nxt_analog_host.c (nxt_analog_host.yu-c)
 *  \brief  NXT Analog Host.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#define NXT_ANALOG_HOST_IMPLEMENT

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "modp_numtoa.h"
#include "ev3.h"
#include "ev3_port.h"
#include "nxt_analog_host.h"

#define HOST_PATH_LEN  25  /* "/sys/bus/legoev3/devices/" */

size_t get_nxt_analog_host_device_type( uint8_t port, uint8_t extport, char *buf, size_t sz )
{
	char s[ 64 ] = "/sys/bus/legoev3/devices" "/";

	strcpy( s + HOST_PATH_LEN, ev3_port_name( port, extport ));
	strcpy( s + strlen( s ), ":nxt-analog-host/device_type" );
	return ev3_read_char_array( s, buf, sz );
}

size_t get_nxt_analog_host_port_name( uint8_t port, uint8_t extport, char *buf, size_t sz )
{
	char s[ 64 ] = "/sys/bus/legoev3/devices" "/";

	strcpy( s + HOST_PATH_LEN, ev3_port_name( port, extport ));
	strcpy( s + strlen( s ), ":nxt-analog-host/port_name" );
	return ev3_read_char_array( s, buf, sz );
}

size_t set_nxt_analog_host_set_sensor( uint8_t port, uint8_t extport, char *value )
{
	char s[ 64 ] = "/sys/bus/legoev3/devices" "/";

	strcpy( s + HOST_PATH_LEN, ev3_port_name( port, extport ));
	strcpy( s + strlen( s ), ":nxt-analog-host/set_sensor" );
	return ev3_write_char_array( s, value );
}

