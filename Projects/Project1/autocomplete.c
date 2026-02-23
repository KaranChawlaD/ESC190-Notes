#include "autocomplete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_terms(const void *a, const void *b) {
    term *termA = (term *)a;
    term *termB = (term *)b;

    return strcmp(termA->term, termB->term);
}

int compare_weights(const void *a, const void *b) {
    term *termA = (term *)a;
    term *termB = (term *)b;

    if (termA->weight < termB->weight) return 1;
    if (termA->weight > termB->weight) return -1;
    return 0;
}

void read_in_terms(term **terms, int *pnterms, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) return;
    char cur_line[300];

    fgets(cur_line, 300-1, fp);
    *pnterms = atoi(cur_line);

    *terms = (term *)malloc(sizeof(term) * *pnterms);
    for (int i = 0; i < *pnterms; i++) {
        fgets(cur_line, 300-1, fp);

        cur_line[strcspn(cur_line, "\n")] = '\0';
        char *tab_location = strchr(cur_line, '\t');

        (*terms)[i].weight = atof(cur_line);
        strcpy((*terms)[i].term, tab_location+1);
    }
    fclose(fp);

    qsort(*terms, *pnterms, sizeof(term), compare_terms);
}

int lowest_match(term *terms, int nterms, char *substr) {
    int res = -1;
    int low = 0;
    int high = nterms-1;
    int mid;
    int cmp;
    size_t length = strlen(substr);


    while (low <= high) {
        mid = low + (high-low)/2;
        cmp = strncmp(substr, terms[mid].term, length);

        if (cmp == 0) {
            res = mid;
            high = mid - 1;
        }
        else if (cmp < 0) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return res;
}

int highest_match(term *terms, int nterms, char *substr) {
    int res = -1;
    int low = 0;
    int high = nterms-1;
    int mid;
    int cmp;
    size_t length = strlen(substr);

    while (low <= high) {
        mid = low + (high-low)/2;
        cmp = strncmp(substr, terms[mid].term, length);

        if (cmp == 0) {
            res = mid;
            low = mid + 1;
        }
        else if (cmp < 0) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return res;
}

void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr) {
    int high = highest_match(terms, nterms, substr);
    int low = lowest_match(terms, nterms, substr);
    if (high == -1 || low == -1) {
        *n_answer = 0;
        *answer = NULL;
        return;
    }
    else {
        *n_answer = high - low + 1;
    }

    *answer = (term *)malloc(sizeof(term) * (*n_answer));

    for (int i = 0; i < *n_answer; i++) {
        (*answer)[i] = terms[i + low];
    }

    qsort(*answer, *n_answer, sizeof(term), compare_weights);
}
