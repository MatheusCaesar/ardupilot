#pragma once

#include <AP_Common/AP_Common.h>
#include "GCS_MAVLink.h"

#define AP_PARAM_VEHICLE_NAME periph

// Global parameter class.
//
class Parameters {
public:
    static const uint16_t k_format_version = 2;

    enum {
        // Layout version number, always key zero.
        //
        k_param_format_version = 0,
        k_param_gps,
        k_param_compass,
        k_param_can_node,
        k_param_can_baudrate0,
        k_param_baro,
        k_param_buzz_volume,
        k_param_led_brightness,
        k_param_airspeed,
        k_param_rangefinder,
        k_param_flash_bootloader,
        k_param_rangefinder_baud0,
        k_param_adsb_baudrate,
        k_param_hardpoint_id,
        k_param_hardpoint_rate,
        k_param_baro_enable,
        k_param_esc_number0,
        k_param_battery_lib,
        k_param_debug,
        k_param_serial_number,
        k_param_adsb_port,
        k_param_servo_channels,
        k_param_rangefinder_port0,
        k_param_gps_port,
        k_param_msp_port,
        k_param_notify,
        k_param_esc_pwm_type,
        k_param_logger,
        k_param_log_bitmask,
        k_param_can_baudrate1,
        k_param_can_baudrate2,
        k_param_can_protocol0,
        k_param_can_protocol1,
        k_param_can_protocol2,
        k_param_sysid_this_mav_old,
        k_param_serial_manager,
        k_param_gps_mb_only_can_port,
        k_param_scripting,
        k_param_esc_telem_port,
        k_param_can_fdmode,
        k_param_can_fdbaudrate0,
        k_param_can_fdbaudrate1,
        k_param_node_stats,
        k_param_rangefinder_max_rate,
        k_param_efi,
        k_param_efi_port,
        k_param_efi_baudrate,
        k_param_esc_telem_rate,
        k_param_can_slcan_cport,
        k_param_temperature_sensor,
        k_param_esc_command_timeout_ms,
        k_param_proximity,
        k_param_proximity_baud,
        k_param_proximity_port,
        k_param_proximity_max_rate,
        k_param_nmea,
        k_param_kdecan,
        k_param_pole_count0,
        k_param_esc_serial_port0,
        k_param_esc_number1,
        k_param_pole_count1,
        k_param_esc_serial_port1,
        k_param_networking_periph,
        k_param_rpm_sensor,
        k_param_g_rcin,
        k_param_sitl,
        k_param_ahrs,
        k_param_battery_balance,
        k_param_battery_hide_mask,
        k_param_can_mirror_ports,
        k_param_rtc,
        k_param_can_terminate0,
        k_param_can_terminate1,
        k_param_can_terminate2,
        k_param_serial_options,
        k_param_relay,
        k_param_temperature_msg_rate,
        k_param_rangefinder_baud1,
        k_param_rangefinder_port1,
        k_param_options,
        k_param_rpm_msg_rate,
        k_param_esc_rate,
        k_param_esc_extended_telem_rate,
        k_param_imu_sample_rate,
        k_param_imu,
        k_param_dac,
        k_param__gcs,
        k_param_battery_tag,
        k_param_servo_command_timeout_ms,
    };

    AP_Int16 format_version;
    AP_Int16 can_node;
    
    AP_Int32 can_baudrate[HAL_NUM_CAN_IFACES];
#if HAL_NUM_CAN_IFACES >= 2
    AP_Enum<AP_CAN::Protocol> can_protocol[HAL_NUM_CAN_IFACES];
#endif

#if AP_CAN_SLCAN_ENABLED
    AP_Int8 can_slcan_cport;
#endif

#if AP_PERIPH_BUZZER_WITHOUT_NOTIFY_ENABLED
    AP_Int8 buzz_volume;
#endif
#if AP_PERIPH_HAVE_LED_WITHOUT_NOTIFY
    AP_Int8 led_brightness;
#endif
#if AP_PERIPH_BARO_ENABLED
    AP_Int8 baro_enable;
#endif
#if !defined(HAL_NO_FLASH_SUPPORT) && !defined(HAL_NO_ROMFS_SUPPORT)
    AP_Int8 flash_bootloader;
#endif

#if AP_PERIPH_RANGEFINDER_ENABLED
    AP_Int32 rangefinder_baud[RANGEFINDER_MAX_INSTANCES];
    AP_Int8 rangefinder_port[RANGEFINDER_MAX_INSTANCES];
    AP_Int16 rangefinder_max_rate;
#endif

#if AP_PERIPH_PROXIMITY_ENABLED
    AP_Int32 proximity_baud;
    AP_Int8 proximity_port;
    AP_Int16 proximity_max_rate;
#endif


#if AP_PERIPH_ADSB_ENABLED
    AP_Int32 adsb_baudrate;
    AP_Int8 adsb_port;
#endif

#if AP_PERIPH_PWM_HARDPOINT_ENABLED
    AP_Int16 hardpoint_id;
    AP_Int8 hardpoint_rate;
#endif

#if AP_PERIPH_HOBBYWING_ESC_ENABLED || AP_PERIPH_ESC_APD_ENABLED
    #if defined ESC_NUMBERS
        #error "ESC_NUMBERS should not have been previously defined"
    #endif
    #if defined(APD_ESC_INSTANCES)
        #define ESC_NUMBERS APD_ESC_INSTANCES
    #else
        #define ESC_NUMBERS 2
    #endif // defined(APD_ESC_INSTANCES)
    AP_Int8 esc_number[ESC_NUMBERS];
    AP_Int8 esc_serial_port[ESC_NUMBERS];
#endif

#if defined(ESC_NUMBERS)
    AP_Int8 pole_count[ESC_NUMBERS];
#endif

#if AP_PERIPH_GPS_ENABLED
    AP_Int8 gps_port;
#if GPS_MOVING_BASELINE
    AP_Int8 gps_mb_only_can_port;
#endif
#endif

#if AP_PERIPH_MSP_ENABLED
    AP_Int8 msp_port;
#endif

#if AP_PERIPH_RC_OUT_ENABLED
    AP_Int16 esc_rate;
    AP_Int8 esc_pwm_type;
    AP_Int16 esc_command_timeout_ms;
#if HAL_WITH_ESC_TELEM && !HAL_GCS_ENABLED
    AP_Int8 esc_telem_port;
#endif
#if HAL_WITH_ESC_TELEM
    AP_Int32 esc_telem_rate;
#if AP_EXTENDED_ESC_TELEM_ENABLED
    AP_Int16 esc_extended_telem_rate;
#endif
#endif
    AP_Int16 servo_command_timeout_ms;
#endif

    AP_Int8 debug;

    AP_Int32 serial_number;

#if HAL_LOGGING_ENABLED
    AP_Int32        log_bitmask;
#endif

#if AP_PERIPH_BATTERY_ENABLED
    AP_Int32 battery_hide_mask;
#endif

#if AP_PERIPH_EFI_ENABLED
    AP_Int32 efi_baudrate;
    AP_Int8 efi_port;
#endif

#if AP_PERIPH_IMU_ENABLED
    AP_Int16 imu_sample_rate;
#endif

#if HAL_PERIPH_CAN_MIRROR
    AP_Int8 can_mirror_ports;
#endif // HAL_PERIPH_CAN_MIRROR

#if AP_PERIPH_DEVICE_TEMPERATURE_ENABLED
    AP_Int8 temperature_msg_rate;
#endif

#if AP_PERIPH_RPM_STREAM_ENABLED
    AP_Int16 rpm_msg_rate;
#endif

#if HAL_CANFD_SUPPORTED
    AP_Int8 can_fdmode;
    AP_Int8 can_fdbaudrate[HAL_NUM_CAN_IFACES];
#else
    static constexpr uint8_t can_fdmode = 0;
#endif

    AP_Int32 options;

    AP_Int8 can_terminate[HAL_NUM_CAN_IFACES];

    AP_Int8 node_stats;
    Parameters() {}
};

extern const AP_Param::Info var_info[];
