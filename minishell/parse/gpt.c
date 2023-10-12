#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 따옴표로 묶인 부분을 기준으로 분리하여 2차원 배열로 반환
char **splitByQuotes(const char *input) {
    char **tokens = NULL; // 토큰을 저장할 2차원 배열
    char *token = NULL;
    int in_quotes = 0; // 따옴표 내부인지 여부 (0: 아님, 1: 큰 따옴표, 2: 작은 따옴표)
    int token_count = 0; // 토큰의 개수

	while (*input)
	{
		if ((*input == '\'' || *input == '"') && in_quotes == 0)
			in_quotes = 1;
		else if (*input == '\'' || *input == '"' && in_quotes == 1)

	}
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
