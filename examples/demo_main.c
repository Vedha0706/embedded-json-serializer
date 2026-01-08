#include <stdio.h>
#include "json_serializer.h"

int main(void)
{
	gateway_data_t gateway = {
		.gateway_id = "gateway_1234",
		.date = "1970-01-01",
		.device_type = "stromleser",
		.interval_minutes = 15,
		.total_readings = 1,
		.device_count = 1,
		.devices = {
			{
				.media = "water",
				.meter = "waterstarm",
				.device_id = "stromleser_50898527",
				.unit = "m3",
				.data_count = 1,
				.data = {
					{
						.timestamp = "1970-01-01 00:00",
						.meter_datetime = "1970-01-01 00:00",
						.total_m3 = 107.752f,
						.status = "OK"
					}
				}
			}
		}
	};
	char json_output[1024];
	
	int ret = serialize_to_json(&gateway, json_output, sizeof(json_output));
	if (ret != JS_OK) {
		printf("Serialization failed: %d\n", ret);
		return -1;
	}
	printf("%s\n", json_output);
	return 0;
}
