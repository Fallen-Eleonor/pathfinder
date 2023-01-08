#include "../inc/pathfinder.h"

void mx_delete_list(t_list *list) {
    while (list != NULL) {
        mx_pop_back(&list);
    }
}

void mx_delete_list_nodes(t_list *list) {
    while (list != NULL) {
        mx_delete_node(mx_get_last_list_element(list)->data);
        mx_pop_back(&list);
    }
}

void mx_delete_node(t_graph_node *node) {
    free(node->first_vertex);
    free(node->second_vertex);
    free(node);
}

void mx_delete_pathfinder_data(t_pathfinder_main data) {
    free(data.file_text);
    if (data.nodes != NULL)
        mx_delete_list_nodes(data.nodes);
    if (data.names_vertices != NULL)
        mx_delete_list(data.names_vertices);
}

