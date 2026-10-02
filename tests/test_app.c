#include "app.h"

#include <assert.h>
#include <stddef.h>
#include <string.h>

static void test_create_owns_message_copy(void)
{
    const char message[] = "teste modular";
    app_t *app = NULL;

    assert(app_create(message, &app) == APP_STATUS_OK);
    assert(app != NULL);
    assert(app_message(app) != message);
    assert(app_message(app) != NULL);
    assert(strcmp(app_message(app), message) == 0);

    app_destroy(&app);
    assert(app == NULL);
}

static void test_invalid_arguments(void)
{
    app_t *app = NULL;

    assert(app_create(NULL, &app) == APP_STATUS_INVALID_ARGUMENT);
    assert(app == NULL);
    assert(app_create("mensagem", NULL) == APP_STATUS_INVALID_ARGUMENT);
    assert(app_message(NULL) == NULL);
    assert(app_print(NULL, stdout) == APP_STATUS_INVALID_ARGUMENT);
    assert(app_print(NULL, NULL) == APP_STATUS_INVALID_ARGUMENT);
}

static void test_destroy_is_null_safe(void)
{
    app_t *app = NULL;

    app_destroy(NULL);
    app_destroy(&app);
    assert(app == NULL);
}

int main(void)
{
    test_create_owns_message_copy();
    test_invalid_arguments();
    test_destroy_is_null_safe();
    return 0;
}