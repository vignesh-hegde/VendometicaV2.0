#ifndef VENDOMETICA_H
#define VENDOMETICA_H
#include <stdint.h>

// defineing GPIO pins
#define HEATER_COIL             14       
#define WATER_IN_PUMP          13       
#define WATER_LEVEL_SENSOR_1    5        
#define WATER_LEVEL_SENSOR_2    8        
#define WATER_LEVEL_SENSOR_3    10        
#define WATER_LEVEL_SENSOR_4    11        
#define WATER_LEVEL_SENSOR_5    12        
#define TEMPERATURE_SENSOR      15      
#define CUP_DETECTOR            18          
#define POWDER_DISPENSER        20        
#define WATER_OUT_PUMP          28       

#define MAX_ALLOWED_HEATING_PERIOD_SEC  (10)

#define NullPtr 0
#define UInt8   uint8_t     
#define Int8    int8_t      
#define UInt16  uint16_t    
#define Int16   int16_t     
#define UInt32  uint32_t    
#define Int32   int32_t     
#define UInt64  uint64_t    
#define Int64   int64_t     
#define Float32 float       
#define Float64 double      
#endif

