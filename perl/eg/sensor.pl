use Time::HiRes;
use lib "..";
use ev3;

my @color = ( "?", "BLACK", "BLUE", "GREEN", "YELLOW", "RED", "WHITE", "BROWN" );

sub _touch_pressed {
    my $sn = shift;
    return ( ev3::get_sensor_value( 0, $sn ))[ 1 ] != 0;
}

print "Waiting the EV3 brick online...\n";
ev3::ev3_init() > 0 || exit( 1 );

print "*** ( EV3 ) Hello! ***\n";
ev3::ev3_sensor_init();

print "Found sensors:\n";
for ( $i = 0; $i < $ev3::SENSOR_DESC__LIMIT_; $i++ ) {
    my $type_inx = ev3::ev3_sensor_desc_type_inx( $i );
    if ( $type_inx != $ev3::SENSOR_TYPE__NONE_) {
        my $type = ev3::ev3_sensor_type( $type_inx );
        print "  type = $type\n";
        my $port_name = ev3::ev3_port_name( ev3::ev3_sensor_desc_port( $i ), ev3::ev3_sensor_desc_extport( $i ));
        print "  port = $port_name\n";
        my ( $ok, $mode ) = ev3::get_sensor_mode( $i, 256 );
        if ( $ok ) {
            print "  mode = $mode\n";
        }
        my ( $ok, $n ) = ev3::get_sensor_num_values( $i );
        if ( $ok ) {
            for ( $ii = 0; $ii < $n; $ii++ ) {
                my ( $ok, $val ) = ev3::get_sensor_value( $ii, $i );
                if ( $ok ) {
                    print "  value$ii = $val\n";
                }
            }
        }
    }
}
my ( $ok, $sn_touch ) = ev3::ev3_search_sensor( $ev3::LEGO_EV3_TOUCH );
if ( $ok ) {
    print "TOUCH sensor is found, press BUTTON for EXIT...\n";
    my ( $ok, $sn_color ) = ev3::ev3_search_sensor( $ev3::EV3_UART_29 );
    if ( $ok ) {
        print "COLOR sensor is found, reading COLOR...\n";
        ev3::set_sensor_mode( $sn_color, "COL-COLOR" );
        while ( true ) {
            # Read color sensor value
            my ( $ok, $val ) = ev3::get_sensor_value( 0, $sn_color );
            if ( !$ok || ( $val < 0 ) || ( $val >= scalar @color )) {
                $val = 0;
            }
            print "\r($color[ $val ])";
            $| = 1;
            # Check touch pressed
            if ( _touch_pressed( $sn_touch )) {
                last;
            }
            Time::HiRes::sleep( 0.2 );
            print "\r        ";
            $| = 1;
            if ( _touch_pressed( $sn_touch )) {
                last;
            }
            Time::HiRes::sleep( 0.2 );
        }
    } else {
        print "COLOR sensor is NOT found\n";
        # Wait touch pressed
        while ( !_touch_pressed( $sn_touch )) {
            Time::HiRes::sleep( 0.2 );
        }
    }
} else {
    print "TOUCH sensor is NOT found\n";
}
ev3::ev3_uninit();
print "\n*** ( EV3 ) Bye! ***\n";
