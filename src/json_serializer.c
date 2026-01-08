#include "json_serializer.h"
#include <stdio.h>

#define WRITE(fmt, ...) do {
	int n = snprintf(ptr, remaining, fmt, __VA_ARGS__);
	if (n < 0 || (size_t)n >= remaining) return JS_ERR_BUFFER_SMALL;
	ptr += n;
	remaining -= n;
} while (0)

int serialize_to_json(const gateway_data_t *input,
					char *output,
					size_t output_size)
{
	if (!input || !output) return JS_ERR_NULL_PTR;
	char *ptr = output;
	size_t remaining = output_size;
	WRITE("[{");
	WRITE("\"gatewayId\":\"%s\",", input->gateway_id);
	WRITE("\"date\":\"%s\",", input->date);
	WRITE("\"deviceType\":\"%s\",", input->device_type);
	WRITE("\"interval_minutes\":%d,", input->interval_minutes);
	WRITE("\"total_readings\":%d,", input->total_readings);
	
	WRITE("\"values\":{\"device_count\":%d,\"readings\":[", input->device_count);
	
	
	for (int i = 0; i < input->device_count; i++) {
		device_reading_t *d = &input->devices[i];
		WRITE("{");
		WRITE("\"media\":\"%s\",", d->media);
		WRITE("\"meter\":\"%s\",", d->meter);
		WRITE("\"deviceId\":\"%s\",", d->device_id);
		WRITE("\"unit\":\"%s\",", d->unit);
		WRITE("\"data\":[");
		
		
		for (int j = 0; j < d->data_count; j++) {
			meter_data_t *m = &d->data[j];
			WRITE("{");
			WRITE("\"timestamp\":\"%s\",", m->timestamp);
			WRITE("\"meter_datetime\":\"%s\",", m->meter_datetime);
			WRITE("\"total_m3\":%.3f,", m->total_m3);
			WRITE("\"status\":\"%s\"", m->status);
			WRITE("}");
			if (j < d->data_count - 1) WRITE(",");
		}
		
		WRITE("]}");
		if (i < input->device_count - 1) WRITE(",");
	}
	WRITE("]}}]");
	return JS_OK;
}
