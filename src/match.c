#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <knots/match.h>

const char* knots_match_shift_and(
    const char* text,
    const char* search_term,
    uint64_t mismatches
) {
    assert(text);
    assert(search_term);

    const uint64_t text_length = strlen(text);
    const uint64_t st_length = strlen(search_term);
    assert(st_length < 64);

    // Initialize the characteristic vectors.
    uint64_t *vectors = calloc(256, sizeof(uint64_t));

    for (uint64_t i = 0; i < st_length; ++i) {
        const unsigned char c = search_term[i];
        vectors[c] |= (1 << i);
    }

    // Initialize the bitvector table.
    uint64_t target = 1 << (st_length - 1);
    uint64_t * table = calloc(mismatches + 1, sizeof(uint64_t));

    if (text[0] == search_term[0]) {
        table[0] = 1;
    }

    for (uint64_t i = 1; i < mismatches + 1; ++i) {
        table[i] = 1;
    }

    // Iterate over the text and apply shift-and.
    const char* result = NULL;
    uint64_t result_mismatches = UINT64_MAX;

    for (uint64_t char_index = 1; char_index < text_length; ++char_index) {
        const unsigned char c = text[char_index];

        for (uint64_t i = mismatches + 1; i > 0; --i) {
            uint64_t index = i - 1;
            uint64_t prev = index ? table[index - 1] : 0;

            uint64_t vec = table[index];
            vec <<= 1;
            vec += 1; // "shift" in a one.
            vec &= vectors[c];
            vec |= prev << 1;
            vec |= index > 0 ? 1 : 0;
            table[index] = vec;

            if (vec & target && index < result_mismatches) {
                result = text + char_index - st_length + 1;
                result_mismatches = index;

                if (index == 0) {
                    free(table);
                    free(vectors);
                    return result;
                }
            }
        }
    }

    free(table);
    free(vectors);
    return result;
}
