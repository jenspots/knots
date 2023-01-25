#include <assert.h>
#include <knots/utils.h>
#include <stdlib.h>
#include <string.h>

uint64_t knots_compare(const char* a, const char* b, uint64_t n) {
    for (uint64_t i = 0; i < n; ++i) {
        if (a[i] != b[i] || a[i] == '\0') {
            return i;
        }
    }

    return 0;
}

uint64_t knots_levenshtein(const char* a, const char* b) {
    assert(a);
    assert(b);

    uint64_t length_a = strlen(a);
    uint64_t length_b = strlen(b);

    uint64_t* table = calloc((length_a + 1) * 2, sizeof(uint64_t));
    uint64_t* current = table;
    uint64_t* previous = table + length_a + 1;

    for (uint64_t i = 0; i < length_a + 1; ++i) {
        previous[i] = i;
    }

    for (uint64_t index_b = 0; index_b < length_b; ++index_b) {
        current[0] = index_b + 1;

        for (uint64_t index_a = 0; index_a < length_a; ++index_a) {
            uint_fast8_t cost = a[index_a] == b[index_b] ? 0 : 1;

            uint64_t north_west = previous[index_a] + cost;
            uint64_t west = previous[index_a + 1] + 1;
            uint64_t north = current[index_a] + 1;

            if (north_west < west) {
                if (north < north_west) {
                    current[index_a + 1] = north;
                } else {
                    current[index_a + 1] = north_west;
                }
            } else {
                if (north < west) {
                    current[index_a + 1] = north;
                } else {
                    current[index_a + 1] = west;
                }
            }
        }

        uint64_t* tmp = current;
        current = previous;
        previous = tmp;
    }

    return previous[length_a];
}
