#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to check if a character is a whitespace
int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

// Tokenize the input line
char **tokenize_line(const char *line) {
    char **tokens = NULL;
    int token_count = 0;
    int in_double_quote = 0, in_single_quote = 0, in_parentheses = 0;
    int start = 0, end = 0;
    int length = strlen(line);

    while (end <= length) {
        char c = line[end];

        // Toggle flags based on quotes or parentheses
        if (c == '"' && !in_single_quote && !in_parentheses) {
            in_double_quote = !in_double_quote;
        } else if (c == '\'' && !in_double_quote && !in_parentheses) {
            in_single_quote = !in_single_quote;
        } else if (c == '(' && !in_double_quote && !in_single_quote) {
            in_parentheses++;
        } else if (c == ')' && !in_double_quote && !in_single_quote) {
            in_parentheses--;
        }

        // If we encounter a whitespace or end of line and not within quotes or parentheses
        if ((is_whitespace(c) || c == '\0') && !in_double_quote && !in_single_quote && !in_parentheses) {
            if (start != end) { // there is a word to add
                char *token = strndup(line + start, end - start);
                tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
                tokens[token_count++] = token;
            }
            start = end + 1;
        }

        end++;
    }

    // Null-terminate the tokens array
    tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
    tokens[token_count] = NULL;

    return tokens;
}

// Free tokens
void free_tokens(char **tokens) {
    if (!tokens) return;
    for (int i = 0; tokens[i]; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

// Example usage
int main() {
    char line[] = "echo \"hello world\" >outdir | <indir grep \"(word\" >outdir";
    char **tokens = tokenize_line(line);

    for (int i = 0; tokens[i]; i++) {
        printf("token[%d] = %s\n", i, tokens[i]);
    }

    free_tokens(tokens);
    return 0;
}
