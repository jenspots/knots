#include <assert.h>
#include <string.h>
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

int main(int argc, char** argv) {
    ananas();
    barbados();
    return 0;
}
