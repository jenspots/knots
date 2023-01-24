#ifndef KNOTS_SEARCH_H
#define KNOTS_SEARCH_H

/**
 * Searches a text for a literal string match using the Knuth-Morris-Pratt
 * algorithm.
 * @return Pointer to the start of the match in the text when found, otherwise
 * NULL is returned.
 */
const char* knots_search_kmp(const char* text, const char* search_term);


/**
 * Searches a text for a literal string match using the Boyer-Moore-Horspool
 * algorithm.
 * @return Pointer to the start of the match in the text when found, otherwise
 * NULL is returned.
 */
const char* knots_search_bmh(const char* text, const char* search_term);

/**
 * Searches a text for a literal string match using the shift-and algorithm.
 * @return Pointer to the start of the match in the text when found, otherwise
 * NULL is returned.
 */
const char* knots_search_shift_and(const char* text, const char* search_term);

/**
 * Searches a text for a literal string match using the shift-or algorithm.
 * @return Pointer to the start of the match in the text when found, otherwise
 * NULL is returned.
 */
const char* knots_search_shift_or(const char* text, const char* search_term);

#endif // KNOTS_SEARCH_H
