#ifndef PTRBOX_APP_H
#define PTRBOX_APP_H

#include <stdio.h>

typedef struct app app_t;

typedef enum {
    APP_STATUS_OK = 0,
    APP_STATUS_INVALID_ARGUMENT,
    APP_STATUS_OUT_OF_MEMORY,
    APP_STATUS_IO_ERROR
} app_status_t;

app_status_t app_create(const char *message, app_t **out_app);
void app_destroy(app_t **app);
const char *app_message(const app_t *app);
app_status_t app_print(const app_t *app, FILE *output);

#endif