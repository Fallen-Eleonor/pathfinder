#include "../inc/pathfinder.h"

void mx_pathfinder(t_list *nodes, t_list *names_vertices, int count_vertices) {
    int **graph = mx_create_adjacency_matrix(nodes, names_vertices, count_vertices);
    t_list *names_verticesdup = mx_listdup(names_vertices);
    t_list *temp = names_verticesdup;
    int counter = count_vertices;
    while (counter != 1) {
        mx_find_pathway(names_vertices, graph, count_vertices, counter - 1);
        mx_swap_list(names_vertices, temp->data, temp->next->data);
        temp = temp->next;
        graph = mx_matrix_rebild(graph, nodes, names_vertices, count_vertices);
        counter--;
    }
    mx_delete_list(names_verticesdup);
    mx_delete_matrix(graph, count_vertices);
}

void mx_print_path(t_part_path path[], char *last_element, int total_distance) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(path[0].name);
    mx_printstr(" -> ");
    mx_printstr(last_element);
    mx_printchar('\n');
    mx_printstr("Route: ");
    for (int i = 0; path[i].name != NULL; i++) {
        mx_printstr(path[i].name);
        if (path[i + 1].name != NULL)
            mx_printstr(" -> ");
    }
    mx_printchar('\n');
    mx_printstr("Distance: ");
    if (path[2].name != NULL) {
        for (int i = 1; path[i].name != NULL; i++) {
            mx_printint(path[i].length);
            if (path[i + 1].name != NULL)
                mx_printstr(" + ");
        }
        mx_printstr(" = ");
    }
    mx_printint(total_distance);
    mx_printchar('\n');
    mx_printstr("========================================\n");
}


