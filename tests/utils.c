#include <assert.h>
#include <knots/utils.h>

int main(int argc, char** argv) {
    assert(knots_levenshtein("lessen", "feesten") == 3);
    assert(knots_levenshtein("feesten", "lessen") == 3);
    assert(knots_levenshtein("sitting", "kitten") == 3);
    assert(knots_levenshtein("intention", "execution") == 5);
    assert(knots_levenshtein("ros", "horse") == 3);
}
