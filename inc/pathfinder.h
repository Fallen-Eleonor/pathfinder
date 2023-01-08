#ifndef PATHFINDER
#define PATHFINDER

#include "libmx.h"

typedef struct s_pathfinder_main {
    char *file_text;
    t_list **nodes;
    t_list **names_vertices;
} t_pathfinder_main;

typedef struct s_graph_node {
    int edge_length;
    char *first_vertex;
    char *second_vertex;
} t_graph_node;

typedef struct s_graph_vertex {
    char *name_vertex;
} t_graph_vertex;

typedef struct s_part_path {
    char *name;
    int length;
} t_part_path;

// File
char *mx_get_file_text(int argc, char const *argv[]);

// Nodes(Part path)
t_list *mx_get_nodes(t_pathfinder_main data);
t_list *mx_get_names_vertices(t_list *nodes, int *count);
bool mx_is_same_node(t_graph_node *node_first, t_graph_node *node_second);

// Matrix
int **mx_create_adjacency_matrix(t_list *nodes, t_list *names_vertices, int n);
int **mx_matrix_rebild(int **graph, t_list *nodes, t_list *names_vertices, int n);
void mx_print_matrix(int **graph, int n);

// Path
void mx_pathfinder(t_list *nodes, t_list *names_vertices, int count_vertices);
void mx_find_pathway(t_list *names_vertices, int **graph, int n, int print_count);
int mx_get_index_last_element(t_part_path path[]);
void mx_init_path(t_part_path path[], int n);
void mx_add_to_path(t_part_path path[], char *name_vertex, int distance);
void mx_delete_from_path(t_part_path path[]);
void mx_print_path(t_part_path path[], char *last_element_name, int total_distance);

// Errors
int mx_error_line(char *file_text); 
void mx_error_invalid_number(int counted, char *file_text, t_pathfinder_main data);
void mx_error_sum_of_bridges_lengths(long int sum, t_pathfinder_main data, char *str_line);
void mx_error_duplicate_bridges(t_list *nodes, t_pathfinder_main data);

// Memory clear
void mx_delete_list(t_list *list);
void mx_delete_list_nodes(t_list *list);
void mx_delete_node(t_graph_node *node);
void mx_delete_matrix(int **graph, int n);
void mx_delete_pathfinder_data(t_pathfinder_main data);
#endif



// ddunaj || Antiplagiat mark

