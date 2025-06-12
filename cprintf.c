#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	if (argc < 2) {
		printf("Usage: %s <format> <values>", argv[0]);
	}
	
	char *format = argv[1];
    int arg_index = 2;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            i++;

            if (arg_index >= argc) {
                fprintf(stderr, "Error: Insufficient arguments.\n");
                return 1;
            }

            switch (format[i]) {
                case 'd': {
                    int val = atoi(argv[arg_index++]);
                    printf("%d", val);
                    break;
                }
                case 's': {
                    printf("%s", argv[arg_index++]);
                    break;
                }
                case '%': {
                    printf("%%");
                    break;
                }
                default:
                    fprintf(stderr, "Unknown format: %%%c\n", format[i]);
                    return 1;
            }
        } else if (format[i] == '\\' && format[i + 1] != '\0') {
            i++;
            switch (format[i]) {
                case 'n': putchar('\n'); break;
                case 't': putchar('\t'); break;
                case '\\': putchar('\\'); break;
                case 'r': putchar('\r'); break;
                case 'a': putchar('\a'); break;
                case 'b': putchar('\b'); break;
                default:
                    putchar('\\');
                    putchar(format[i]);
                    break;
            }
        } else {
            putchar(format[i]);
        }
    }
}