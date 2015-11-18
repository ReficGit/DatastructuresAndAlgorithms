/* ADT item  */
typedef char Titem;
int read_item(Titem *item);
void print_item(Titem item);
int compare(Titem item1, Titem item2);

typedef char Titem;

// Interface of list
typedef struct node *Tpointer;

typedef struct node {
	Titem item;
	Tpointer next;
} Tnode;

typedef Tpointer Tlist;

void initialize_list(TOrderedList *list);
int insert_item(TOrderedList *list, Titem item);
int retrieve_ith(const TOrderedList *list, int i, Titem *item);
int number_of_items(const TOrderedList *list);
int list_empty(const TOrderedList *list);
