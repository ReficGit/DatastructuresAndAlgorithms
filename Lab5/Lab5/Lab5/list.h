#define DO_LIST_HEADER(Titem,MAX) \
	typedef struct { \
	int count; \
	Titem array[MAX]; \
} TList##Titem; \
	\
	void initialize_list_##Titem(TList##Titem *list); \
	int insert_item_##Titem(TList##Titem *list, Titem item); \
	int retrieve_ith_##Titem(const TList##Titem *list, int i, Titem *item); \
	int number_of_items_##Titem(const TList##Titem *list); \
	int list_empty_##Titem(const TList##Titem *list);
// END DO_LIST_HEADER

// List implementation template
#define DO_LIST_IMP(Titem,MAX) \
	void initialize_list_##Titem(TList##Titem *list) { \
	list->count = 0; \
} \
int list_empty_##Titem(const TList##Titem *list){ \
	return (!list->count); \
} \
int retrieve_ith_##Titem(const TList##Titem *list, int i, Titem *item) {\
	if (!list_empty_##Titem(list) && i <list->count) {\
	*item = list->array[i];\
	return 1;\
	} else \
	return 0;\
} \
	int number_of_items_##Titem(const TList##Titem *list){\
	return list->count;\
} \
	int insert_item_##Titem(TList##Titem *list, Titem item) { \
	int pos=0;\
	int i=0;\
	if (number_of_items_##Titem(list) < MAX ) {\
		while(compare_##Titem(list->array[pos], item) == -1 && pos < number_of_items_##Titem(list)) pos++;\
	}\
		if (number_of_items_##Titem(list) < MAX) {\
		for (i = number_of_items_##Titem(list) - 1 ; i >= pos ; i-- ){\
	    list->array[i+1] = list->array[i];\
		}\
		}\
		list->array[pos] = item;\
		list->count++;\
};
// END DO_LIST_IMP