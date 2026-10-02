#include "app.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    const char *message;
    app_t *app = NULL;
    app_status_t status;

    if (argc > 2) {
        (void)fprintf(stderr, "Uso: %s [mensagem]\n", argv[0]);
        return EXIT_FAILURE;
    }

    message = argc == 2 ? argv[1] : "PtrBox pronto.";
    status = app_create(message, &app);
    if (status != APP_STATUS_OK) {
        (void)fprintf(stderr, "Nao foi possivel inicializar a aplicacao.\n");
        return EXIT_FAILURE;
    }

    status = app_print(app, stdout);
    app_destroy(&app);
    if (status != APP_STATUS_OK) {
        (void)fprintf(stderr, "Nao foi possivel escrever a mensagem.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}