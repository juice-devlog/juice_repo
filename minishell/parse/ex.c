#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **splitByQuotes(const char *input) {
    char **tokens = NULL;
    int token_count = 0;
    int in_quotes = 0;
    const char *ptr = input;
    const char *token_start = ptr;

    while (*ptr) {
        if (*ptr == '"' || *ptr == '\'') {
            if (in_quotes == 0) {
                in_quotes = *ptr;
                token_start = ptr + 1;
            } else if (in_quotes == *ptr) {
                in_quotes = 0;
                int token_len = ptr - token_start;
                if (token_len > 0) {
                    char *token = (char *)malloc(token_len + 1);
                    strncpy(token, token_start, token_len);
                    token[token_len] = '\0';
                    tokens = (char **)realloc(tokens, (token_count + 1) * sizeof(char *));
                    tokens[token_count] = token;
                    token_count++;
                }
                ptr++;
                token_start = ptr;
            }
        } else if (*ptr == ' ' && in_quotes == 0) {
            int token_len = ptr - token_start;
            if (token_len > 0) {
                char *token = (char *)malloc(token_len + 1);
                strncpy(token, token_start, token_len);
                token[token_len] = '\0';
                tokens = (char **)realloc(tokens, (token_count + 1) * sizeof(char *));
                tokens[token_count] = token;
                token_count++;
            }
            token_start = ptr + 1;
        }
        ptr++;
    }

    int token_len = ptr - token_start;
    if (token_len > 0) {
        char *token = (char *)malloc(token_len + 1);
        strncpy(token, token_start, token_len);
        token[token_len] = '\0';
        tokens = (char **)realloc(tokens, (token_count + 1) * sizeof(char *));
        tokens[token_count] = token;
        token_count++;
    }

    tokens = (char **)realloc(tokens, (token_count + 1) * sizeof(char *));
    tokens[token_count] = NULL;

    return tokens;
}

int main() {
    const char *input = "\"hello world\" \"cat\" 'meow'\"good'for'you!\"";
    char **tokens = splitByQuotes(input);

    for (int i = 0; tokens[i] != NULL; i++) {
        printf("Token %d: %s\n", i, tokens[i]);
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}
