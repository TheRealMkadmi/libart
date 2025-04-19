#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include "test_art.c"

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_art_init_and_destroy),
        cmocka_unit_test(test_art_insert),
        cmocka_unit_test(test_art_insert_verylong),
        cmocka_unit_test(test_art_insert_search),
        cmocka_unit_test(test_art_insert_delete),
        cmocka_unit_test(test_art_insert_random_delete),
        cmocka_unit_test(test_art_insert_iter),
        cmocka_unit_test(test_art_iter_prefix),
        cmocka_unit_test(test_art_long_prefix),
        cmocka_unit_test(test_art_insert_search_uuid),
        cmocka_unit_test(test_art_max_prefix_len_scan_prefix),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
