
/*  ev3_sensor.c was generated by yup.py (yupp) 0.7b7
    out of ev3_sensor.yu-c at 2014-11-27 15:29
 *//**
 *  \file  ev3_sensor.c (ev3_sensor.yu-c)
 *  \brief  EV3 Sensors.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#define EV3_SENSOR_IMPLEMENT

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "modp_numtoa.h"
#include "ev3.h"
#include "ev3_port.h"
#include "ev3_sensor.h"

#define PATH_PREF_LEN  25
#define _ID_SPOT  "///"

#define PATH_BIN_DATA  "/sys/class/msensor/sensor" _ID_SPOT "bin_data"
#define PATH_BIN_DATA_FORMAT  "/sys/class/msensor/sensor" _ID_SPOT "bin_data_format"
#define PATH_COMMAND  "/sys/class/msensor/sensor" _ID_SPOT "command"
#define PATH_COMMANDS  "/sys/class/msensor/sensor" _ID_SPOT "commands"
#define PATH_DP  "/sys/class/msensor/sensor" _ID_SPOT "dp"
#define PATH_FW_VERSION  "/sys/class/msensor/sensor" _ID_SPOT "fw_version"
#define PATH_ADDRESS  "/sys/class/msensor/sensor" _ID_SPOT "address"
#define PATH_MODE  "/sys/class/msensor/sensor" _ID_SPOT "mode"
#define PATH_MODES  "/sys/class/msensor/sensor" _ID_SPOT "modes"
#define PATH_NAME  "/sys/class/msensor/sensor" _ID_SPOT "name"
#define PATH_NUM_VALUES  "/sys/class/msensor/sensor" _ID_SPOT "num_values"
#define PATH_POLL_MS  "/sys/class/msensor/sensor" _ID_SPOT "poll_ms"
#define PATH_PORT_NAME  "/sys/class/msensor/sensor" _ID_SPOT "port_name"
#define PATH_UNITS  "/sys/class/msensor/sensor" _ID_SPOT "units"
#define PATH_VALUE0  "/sys/class/msensor/sensor" _ID_SPOT "value0"
#define PATH_VALUE1  "/sys/class/msensor/sensor" _ID_SPOT "value1"
#define PATH_VALUE2  "/sys/class/msensor/sensor" _ID_SPOT "value2"
#define PATH_VALUE3  "/sys/class/msensor/sensor" _ID_SPOT "value3"
#define PATH_VALUE4  "/sys/class/msensor/sensor" _ID_SPOT "value4"
#define PATH_VALUE5  "/sys/class/msensor/sensor" _ID_SPOT "value5"
#define PATH_VALUE6  "/sys/class/msensor/sensor" _ID_SPOT "value6"
#define PATH_VALUE7  "/sys/class/msensor/sensor" _ID_SPOT "value7"

#define PATH_VALUE  "/sys/class/msensor/sensor" _ID_SPOT "value"

size_t get_sensor_bin_data( uint8_t sn, byte *buf, size_t sz )
{
	char s[] = PATH_BIN_DATA;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_byte_array( s, buf, sz );
}

size_t set_sensor_bin_data( uint8_t sn, byte *value, size_t sz )
{
	char s[] = PATH_BIN_DATA;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_byte_array( s, value, sz );
}

size_t get_sensor_bin_data_format( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_BIN_DATA_FORMAT;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t set_sensor_command( uint8_t sn, char *value )
{
	char s[] = PATH_COMMAND;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_char_array( s, value );
}

size_t get_sensor_commands( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_COMMANDS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_sensor_dp( uint8_t sn, dword *buf )
{
	char s[] = PATH_DP;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_dword( s, buf );
}

size_t get_sensor_fw_version( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_FW_VERSION;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_sensor_address( uint8_t sn, byte *buf )
{
	char s[] = PATH_ADDRESS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_byte( s, buf );
}

size_t get_sensor_mode( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_MODE;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t set_sensor_mode( uint8_t sn, char *value )
{
	char s[] = PATH_MODE;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_char_array( s, value );
}

size_t get_sensor_modes( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_MODES;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_sensor_name( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_NAME;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_sensor_num_values( uint8_t sn, dword *buf )
{
	char s[] = PATH_NUM_VALUES;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_dword( s, buf );
}

size_t get_sensor_poll_ms( uint8_t sn, dword *buf )
{
	char s[] = PATH_POLL_MS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_dword( s, buf );
}

size_t set_sensor_poll_ms( uint8_t sn, dword value )
{
	char s[] = PATH_POLL_MS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_dword( s, value );
}

size_t get_sensor_port_name( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_PORT_NAME;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_sensor_units( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_UNITS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_sensor_value0( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE0;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value1( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE1;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value2( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE2;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value3( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE3;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value4( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE4;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value5( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE5;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value6( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE6;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value7( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE7;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value( uint8_t inx, uint8_t sn, int *buf )
{
	char s[] = PATH_VALUE "    ";

	if ( inx > 8 ) return ( 0 );

	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';
	modp_uitoa10( inx, s + PATH_PREF_LEN + 3 + 5 );

	return ev3_read_int( s, buf );
}

const char *ev3_sensor_type( uint8_t type_inx )
{
	switch ( type_inx ) {
	case EV3_ANALOG_XX:
		return "ev3-analog-XX";
	case NXT_ANALOG:
		return "nxt-analog";
	case HT_NXT_COLOR:
		return "ht-nxt-color";
	case HT_NXT_ANGLE:
		return "ht-nxt-angle";
	case HT_NXT_ACCEL:
		return "ht-nxt-accel";
	case HT_NXT_BAROMETRIC:
		return "ht-nxt-barometric";
	case HT_NXT_COLOR_V2:
		return "ht-nxt-color-v2";
	case HT_NXT_EOPD:
		return "ht-nxt-eopd";
	case HT_NXT_FORCE:
		return "ht-nxt-force";
	case HT_NXT_GYRO:
		return "ht-nxt-gyro";
	case HT_NXT_IR_LINK:
		return "ht-nxt-ir-link";
	case HT_NXT_IR_RECEIVER:
		return "ht-nxt-ir-receiver";
	case HT_NXT_PIR:
		return "ht-nxt-pir";
	case HT_NXT_COMPASS:
		return "ht-nxt-compass";
	case HT_NXT_MAG:
		return "ht-nxt-mag";
	case HT_NXT_IR_SEEKER_V2:
		return "ht-nxt-ir-seeker-v2";
	case HT_NXT_SMUX:
		return "ht-nxt-smux";
	case HT_SUPER_PRO:
		return "ht-super-pro";
	case EV3_UART_30:
		return "ev3-uart-30";
	case EV3_UART_32:
		return "ev3-uart-32";
	case EV3_UART_29:
		return "ev3-uart-29";
	case LEGO_EV3_TOUCH:
		return "lego-ev3-touch";
	case EV3_UART_33:
		return "ev3-uart-33";
	case WEDO_MOTION:
		return "wedo-motion";
	case WEDO_TILT:
		return "wedo-tilt";
	case LEGO_POWER_STORAGE:
		return "lego-power-storage";
	case LEGO_NXT_TOUCH:
		return "lego-nxt-touch";
	case LEGO_NXT_LIGHT:
		return "lego-nxt-light";
	case LEGO_NXT_SOUND:
		return "lego-nxt-sound";
	case LEGO_NXT_US:
		return "lego-nxt-us";
	case MI_XG1300L:
		return "mi-xg1300l";
	case MS_ABSOLUTE_IMU:
		return "ms-absolute-imu";
	case MS_ANGLE:
		return "ms-angle";
	case MS_LIGHT_ARRAY:
		return "ms-light-array";
	case MS_8CH_SERVO:
		return "ms-8ch-servo";
	case MS_NXT_TOUCH_MUX:
		return "ms-nxt-touch-mux";

	}
	return STR_unknown_;
}

uint8_t get_sensor_type_inx( uint8_t sn )
{
	char buf[ 64 ];
	char *t;

	if ( !get_sensor_name( sn, buf, sizeof( buf ))) return ( SENSOR_TYPE__NONE_ );

	/* If type name contains ':' it starts with port e.g. "outB:rcx-motor" */
	t = strrchr( buf, ':' );
	t = ( t ) ? t + 1 : buf;

	if ( strcmp( t, "ev3-analog-XX" ) == 0 ) return EV3_ANALOG_XX;
	if ( strcmp( t, "nxt-analog" ) == 0 ) return NXT_ANALOG;
	if ( strcmp( t, "ht-nxt-color" ) == 0 ) return HT_NXT_COLOR;
	if ( strcmp( t, "ht-nxt-angle" ) == 0 ) return HT_NXT_ANGLE;
	if ( strcmp( t, "ht-nxt-accel" ) == 0 ) return HT_NXT_ACCEL;
	if ( strcmp( t, "ht-nxt-barometric" ) == 0 ) return HT_NXT_BAROMETRIC;
	if ( strcmp( t, "ht-nxt-color-v2" ) == 0 ) return HT_NXT_COLOR_V2;
	if ( strcmp( t, "ht-nxt-eopd" ) == 0 ) return HT_NXT_EOPD;
	if ( strcmp( t, "ht-nxt-force" ) == 0 ) return HT_NXT_FORCE;
	if ( strcmp( t, "ht-nxt-gyro" ) == 0 ) return HT_NXT_GYRO;
	if ( strcmp( t, "ht-nxt-ir-link" ) == 0 ) return HT_NXT_IR_LINK;
	if ( strcmp( t, "ht-nxt-ir-receiver" ) == 0 ) return HT_NXT_IR_RECEIVER;
	if ( strcmp( t, "ht-nxt-pir" ) == 0 ) return HT_NXT_PIR;
	if ( strcmp( t, "ht-nxt-compass" ) == 0 ) return HT_NXT_COMPASS;
	if ( strcmp( t, "ht-nxt-mag" ) == 0 ) return HT_NXT_MAG;
	if ( strcmp( t, "ht-nxt-ir-seeker-v2" ) == 0 ) return HT_NXT_IR_SEEKER_V2;
	if ( strcmp( t, "ht-nxt-smux" ) == 0 ) return HT_NXT_SMUX;
	if ( strcmp( t, "ht-super-pro" ) == 0 ) return HT_SUPER_PRO;
	if ( strcmp( t, "ev3-uart-30" ) == 0 ) return EV3_UART_30;
	if ( strcmp( t, "ev3-uart-32" ) == 0 ) return EV3_UART_32;
	if ( strcmp( t, "ev3-uart-29" ) == 0 ) return EV3_UART_29;
	if ( strcmp( t, "lego-ev3-touch" ) == 0 ) return LEGO_EV3_TOUCH;
	if ( strcmp( t, "ev3-uart-33" ) == 0 ) return EV3_UART_33;
	if ( strcmp( t, "wedo-motion" ) == 0 ) return WEDO_MOTION;
	if ( strcmp( t, "wedo-tilt" ) == 0 ) return WEDO_TILT;
	if ( strcmp( t, "lego-power-storage" ) == 0 ) return LEGO_POWER_STORAGE;
	if ( strcmp( t, "lego-nxt-touch" ) == 0 ) return LEGO_NXT_TOUCH;
	if ( strcmp( t, "lego-nxt-light" ) == 0 ) return LEGO_NXT_LIGHT;
	if ( strcmp( t, "lego-nxt-sound" ) == 0 ) return LEGO_NXT_SOUND;
	if ( strcmp( t, "lego-nxt-us" ) == 0 ) return LEGO_NXT_US;
	if ( strcmp( t, "mi-xg1300l" ) == 0 ) return MI_XG1300L;
	if ( strcmp( t, "ms-absolute-imu" ) == 0 ) return MS_ABSOLUTE_IMU;
	if ( strcmp( t, "ms-angle" ) == 0 ) return MS_ANGLE;
	if ( strcmp( t, "ms-light-array" ) == 0 ) return MS_LIGHT_ARRAY;
	if ( strcmp( t, "ms-8ch-servo" ) == 0 ) return MS_8CH_SERVO;
	if ( strcmp( t, "ms-nxt-touch-mux" ) == 0 ) return MS_NXT_TOUCH_MUX;

	return ( SENSOR_TYPE__COUNT_ );
}

uint8_t get_sensor_port_inx( uint8_t sn, uint8_t *extport )
{
	char buf[ 32 ];

	if ( !get_sensor_port_name( sn, buf, sizeof( buf ))) return ( EV3_PORT__NONE_ );

	return ( ev3_port_inx( buf, extport ));
}

EV3_SENSOR *ev3_sensor_desc( uint8_t sn )
{
	if ( sn >= SENSOR_DESC__LIMIT_) sn = SENSOR_DESC__LIMIT_ - 1;
	return ( ev3_sensor + sn );
}

uint8_t ev3_sensor_desc_type_inx( uint8_t sn )
{
	return ( ev3_sensor_desc( sn )->type_inx );
}

uint8_t ev3_sensor_desc_port( uint8_t sn )
{
	return ( ev3_sensor_desc( sn )->port );
}

uint8_t ev3_sensor_desc_extport( uint8_t sn )
{
	return ( ev3_sensor_desc( sn )->extport );
}

uint8_t ev3_sensor_desc_addr( uint8_t sn )
{
	return ( ev3_sensor_desc( sn )->addr );
}

bool ev3_search_sensor( uint8_t type_inx, uint8_t *sn, uint8_t from )
{
	uint8_t _sn = from;

	while ( _sn < SENSOR_DESC__LIMIT_) {
		if ( ev3_sensor[ _sn ].type_inx == type_inx ) {
			*sn = _sn;
			return ( true );
		}
		++_sn;
	}
	*sn = SENSOR__NONE_;
	return ( false );
}

bool ev3_search_sensor_plugged_in( uint8_t port, uint8_t extport, uint8_t addr, uint8_t *sn, uint8_t from )
{
	uint8_t _sn = from;

	while ( _sn < SENSOR_DESC__LIMIT_) {
		if ( ev3_sensor[ _sn ].port == port ) {
			if ( addr ) {
				if ( ev3_sensor[ _sn ].addr == addr ) {
					*sn = _sn;
					return ( true );
				}
			}
			else
			if ( extport ) {
				if ( ev3_sensor[ _sn ].extport == extport ) {
						*sn = _sn;
						return ( true );
					}
			}
			else {
				*sn = _sn;
				return ( true );
			}
		}
		++_sn;
	}
	*sn = SENSOR__NONE_;
	return ( false );
}

int ev3_sensor_init( void )
{
	char list[ 256 ];
	char *p;
	uint32_t sn;
	int cnt = 0;

	memset( ev3_sensor, 0, sizeof( ev3_sensor ));

	if ( !ev3_listdir( "/sys/class/msensor", list, sizeof( list ))) return ( -1 );

	p = strtok( list, " " );
	while ( p ) {
		if (( ev3_string_suffix( "sensor", &p, &sn ) == 1 ) && ( sn < SENSOR_DESC__LIMIT_)) {
			get_sensor_address( sn, &ev3_sensor[ sn ].addr );
			ev3_sensor[ sn ].type_inx = get_sensor_type_inx( sn );
			ev3_sensor[ sn ].port = get_sensor_port_inx( sn, &ev3_sensor[ sn ].extport );
			++cnt;
		}
		p = strtok( NULL, " " );
	}
	return ( cnt );
}

