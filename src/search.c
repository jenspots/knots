#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <knots/search.h>

const char* knots_search_shift_and(const char* text, const char* search_term) {
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

    // Iterate over the text and apply shift-and.
    uint64_t target = 1 << (st_length - 1);
    uint64_t vec = text[0] == search_term[0] ? 1 : 0;

    for (uint64_t i = 1; i < text_length; ++i) {
        const unsigned char c = text[i];

        vec <<= 1;
        vec += 1; // "shift" in a one.
        vec &= vectors[c];

        if (vec & target) {
            free(vectors);
            return text + i - st_length + 1;
        }
    }

    free(vectors);
    return NULL;
}

const char* knots_search_shift_or(const char* text, const char* search_term) {
    assert(text);
    assert(search_term);

    const uint64_t text_length = strlen(text);
    const uint64_t st_length = strlen(search_term);
    assert(st_length < 64);

    // Initialize the characteristic vectors.
    uint64_t *vectors = malloc(256 * sizeof(uint64_t));

    for (uint64_t i = 0; i < 256; ++i) {
        vectors[i] = UINT64_MAX;
    }

    for (uint64_t i = 0; i < st_length; ++i) {
        const unsigned char c = search_term[i];
        vectors[c] -= (1 << i);
    }

    // Iterate over the text and apply shift-and.
    uint64_t target = 1 << (st_length - 1);
    uint64_t vec = text[0] == search_term[0] ? ~1 : ~0;

    for (uint64_t i = 1; i < text_length; ++i) {
        const unsigned char c = text[i];

        vec <<= 1;
        vec |= vectors[c];

        if (!(vec & target)) {
            free(vectors);
            return text + i - st_length + 1;
        }
    }

    free(vectors);
    return NULL;
}
