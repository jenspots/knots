#ifndef KNOTS_UTILS_H
#define KNOTS_UTILS_H

#include <stdint.h>

/**
 * Calculate the Levenshtein distance of two strings.
 */
uint64_t knots_levenshtein(const char*, const char*);

#endif