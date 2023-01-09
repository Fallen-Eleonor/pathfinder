#include "../inc/pathfinder.h"

int main(int argc, char const *argv[]) {
    t_pathfinder_main data;
    int count_vertices = 0;
    data.file_text = mx_get_file_text(argc, argv);
    data.nodes = mx_get_nodes(data);
    data.names_vertices = mx_get_names_vertices(data.nodes, &count_vertices);
    mx_error_invalid_number(count_vertices, data.file_text, data);
    mx_error_duplicate_bridges(data.nodes, data);
    mx_pathfinder(data.nodes, data.names_vertices, count_vertices);
    mx_delete_pathfinder_data(data);
    return 0;
}

