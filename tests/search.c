#include <assert.h>
#include <string.h>
#include <knots/match.h>
#include <knots/search.h>

void ananas() {
    const char* text = "ananas";
    const char* search_term = "ana";
    const char* match = NULL;

    match = knots_search_shift_or(text, search_term);
    assert(match);
    assert(strncmp(search_term, match, strlen(search_term)) == 0);

    match = knots_search_shift_and(text, search_term);
    assert(match);
    assert(strncmp(search_term, match, strlen(search_term)) == 0);

    match = knots_match_shift_and(text, "ama", 1);
    assert(match == text);
    match = knots_match_shift_and(text, "bna", 1);
    assert(match == text);
    match = knots_match_shift_and(text, "nas", 0);
    assert(match == text + 3);
    match = knots_match_shift_and(text, "______", 6);
    assert(match == text);
    match = knots_match_shift_and(text, "__a___", 5);
    assert(match == text);
}

void barbados() {
    const char* text = "barbaarse_barbecue_in_barbados";
    const char* search_term = "barbados";
    const char* match = NULL;

    match = knots_search_shift_and(text, search_term);
    assert(match);
    assert(strncmp(search_term, match, strlen(search_term)) == 0);

    match = knots_search_shift_or(text, search_term);
    assert(match);
    assert(strncmp(search_term, match, strlen(search_term)) == 0);
}

void dank() {
    const char* text = "een_dansfeest";
    const char* search_term = "dank";
    const char* match = NULL;

    match = knots_match_shift_and(text, search_term, 1);
    assert(match == text + 4);
}

int main(int argc, char** argv) {
    ananas();
    barbados();
    dank();
    return 0;
}
