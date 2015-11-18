/* The application */
int main () {
     TOrderedList list; Titem item;
     int i;

     initialize_list(&list);
     printf("\n Enter items in any order\n");

     for (i = 0 ; i < 5 ; i++) {
        read_item(&item);
        if (!insert_item(&list, item))
            printf("\nList is full");
     }

     printf("\nList ouputted using for loop and retrieve_ith function:\n");
     for (i=0; i<number_of_items(&list); i++) {
		retrieve_ith(&list, i, &item);
		print_item(item);
     }

     return 0;
}