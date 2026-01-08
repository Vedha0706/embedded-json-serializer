# Embedded JSON Serializer
## Overview
This project implements an embedded-friendly JSON serialization library for
smart-meter gateway data. The focus is on deterministic memory usage, clean API
design, and portability.
## Platform & Language
- Language: C (C99)
- Platform: Platform-agnostic (portable to STM32, ESP32, Arduino)
## Design Decisions
- No dynamic memory allocation
- No external JSON libraries
- Caller-provided output buffer
- Explicit error handling
## Public API
```c
int serialize_to_json(const gateway_data_t *input,
 char *output,
 size_t output_size);
