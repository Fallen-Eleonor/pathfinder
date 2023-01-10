#include "../inc/pathfinder.h"

void mx_init_path(t_part_path path[], int n) {
    for (int i = 0; i < n * n; i++) {
        path[i].name = NULL;
    }
}

int mx_get_index_last_element(t_part_path path[]) {
    int index = 0;
    while (path[index].name != NULL)
        index++;
    return index;
}

void mx_add_to_path(t_part_path path[], char *name_vertex, int distance) {
    int index = mx_get_index_last_element(path);
    path[index].name = name_vertex;
    path[index].length = distance;
}

void mx_delete_from_path(t_part_path path[]) {
    int index = mx_get_index_last_element(path) - 1;
    path[index].name = NULL;
    path[index].length = 0;
}

