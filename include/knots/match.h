#ifndef KNOTS_MATCH_H
#define KNOTS_MATCH_H

#include <stdint.h>

/**
 * Searches a text for a match using the shift-and algorithm while allowing for
 * up to n mismatches.
 * @return Pointer to the start of the match in the text when found, otherwise
 * NULL is returned.
 */
const char* knots_match_shift_and(const char*, const char*, uint64_t);

#endif // KNOTS_MATCH_H
