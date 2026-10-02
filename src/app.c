#include "app.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct app {
    char *message;
};

app_status_t app_create(const char *message, app_t **out_app)
{
    app_t *instance;
    size_t message_length;

    if (out_app == NULL) {
        return APP_STATUS_INVALID_ARGUMENT;
    }
    *out_app = NULL;

    if (message == NULL) {
        return APP_STATUS_INVALID_ARGUMENT;
    }

    message_length = strlen(message);
    if (message_length == SIZE_MAX) {
        return APP_STATUS_OUT_OF_MEMORY;
    }

    instance = malloc(sizeof(*instance));
    if (instance == NULL) {
        return APP_STATUS_OUT_OF_MEMORY;
    }

    instance->message = malloc(message_length + 1U);
    if (instance->message == NULL) {
        free(instance);
        return APP_STATUS_OUT_OF_MEMORY;
    }

    memcpy(instance->message, message, message_length + 1U);
    *out_app = instance;
    return APP_STATUS_OK;
}

void app_destroy(app_t **app)
{
    if (app == NULL || *app == NULL) {
        return;
    }

    free((*app)->message);
    free(*app);
    *app = NULL;
}

const char *app_message(const app_t *app)
{
    if (app == NULL) {
        return NULL;
    }

    return app->message;
}

app_status_t app_print(const app_t *app, FILE *output)
{
    if (app == NULL || output == NULL) {
        return APP_STATUS_INVALID_ARGUMENT;
    }

    if (fprintf(output, "%s\n", app->message) < 0) {
        return APP_STATUS_IO_ERROR;
    }

    return APP_STATUS_OK;
}