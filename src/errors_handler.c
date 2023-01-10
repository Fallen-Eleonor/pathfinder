#include "../inc/pathfinder.h"

void mx_error_invalid_number(int counted, char *file_text, t_pathfinder_main data) {
    char *number = mx_strndup(file_text, (mx_get_char_index(file_text, '\n')));
    int file_count = mx_atoi(number);
    free(number);
    if (counted == file_count) {
        return;
    }
    mx_printstr("error: invalid number of islands\n");
    mx_delete_pathfinder_data(data);
    exit(-1);
}

void mx_error_sum_of_bridges_lengths(long int sum, t_pathfinder_main data, char *str_line) {
    if (sum <= __INT_MAX__) {
        return;
    }
    mx_printstr("error: sum of bridges lengths is too big\n");
    free(str_line);
    mx_delete_pathfinder_data(data);
    exit(-1);
}

void mx_error_duplicate_bridges(t_list *nodes, t_pathfinder_main data) {
    t_list *current_nodes = nodes;
    while (current_nodes != NULL) {
        t_list *temp_nodes = current_nodes->next;
        while (temp_nodes) {
            if (mx_is_same_node(current_nodes->data, temp_nodes->data)) {
                mx_printstr("error: duplicate bridges\n");
                mx_delete_pathfinder_data(data);
                exit(-1);
            }
            temp_nodes = temp_nodes->next;
        }
        current_nodes = current_nodes->next;
    }
}

