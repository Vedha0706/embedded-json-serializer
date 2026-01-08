#ifndef JSON_SERIALIZER_H
#define JSON_SERIALIZER_H

#include <stddef.h>

#define JS_OK 0
#define JS_ERR_NULL_PTR -1
#define JS_ERR_BUFFER_SMALL -2

#define MAX_DEVICES 4
#define MAX_DATA_POINTS 4
/* Data structures */

typedef struct {
	const char *timestamp;
	const char *meter_datetime;
	float total_m3;
	const char *status;
} meter_data_t;

typedef struct {
	const char *media;
	const char *meter;
	const char *device_id;
	const char *unit;
	int data_count;
	meter_data_t data[MAX_DATA_POINTS];
} device_reading_t;

typedef struct {
	const char *gateway_id;
	const char *date;
	const char *device_type;
	int interval_minutes;
	int total_readings;
	int device_count;
	device_reading_t devices[MAX_DEVICES];
} gateway_data_t;

/* API */
int serialize_to_json(const gateway_data_t *input,
						char *output,
						size_t output_size);
#endif
