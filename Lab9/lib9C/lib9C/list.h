// Interface of list
typedef struct node *Tpointer;

typedef struct node {
	void *item;
	Tpointer next;
} Tnode;

typedef struct complex_numbers{
	int x;
	int y;
}Tcomplex;

typedef Tpointer Tlist;

void initialize_list(Tlist *list);
void insert_to_list_end (Tlist *list, void *data);
extern void print_list(void *p);
extern void cleanup_list(void *p);