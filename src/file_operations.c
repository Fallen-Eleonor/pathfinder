#include "../inc/pathfinder.h"

static int file_len(const char *file) {
    short fl = open(file, O_RDONLY);
    short fil = 0;
    int len = 0;
    char buf;
    fil = read(fl, &buf, 1);
    while (fil > 0) {
        fil = read(fl, &buf, 1);
        len++;
    }
    close(fl);
    return len;
}

int mx_error_line(char *file_text) {
    for (int i = 0; file_text[i] != '\0'; i++) {
        if (file_text[0] == '\n') {
            mx_printstr("error: line 1 is not valid\n");
            free(file_text);
            exit(-1);
        }
        if (file_text[i] == '\n') {
            break;
        }
        if (!mx_isdigit(file_text[i])) {
            mx_printstr("error: line 1 is not valid\n");
            free(file_text);
            exit(-1);
        }
    }
    return file_text;
}

char *mx_get_file_text(int argc, char const *argv[]) {
    if (argc == 1) {
        mx_printstr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
    int fl = open(argv[1], O_RDONLY);
    int fil = 0;
    int size = 0;
    if (fl == -1) {
        close(fl);
        mx_printstr("error: file ");
        mx_printstr(argv[1]);
        mx_printstr(" does not exist\n");
        exit(-1);
    }
    size = file_len(argv[1]);
    if (size == 0) {
        mx_printstr("error: file ");
        mx_printstr(argv[1]);
        mx_printstr(" is empty\n");
        exit(-1);
    }
    char *file_text = mx_strnew(size);
    fil = read(fl, file_text, size);
    close(fl);
    mx_error_line(file_text);
    return file_text;
}

