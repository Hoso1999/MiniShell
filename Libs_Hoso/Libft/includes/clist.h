#ifndef CLIST_H
#define CLIST_H

# include <stdlib.h>
# include <unistd.h>
# include "cstring.h"
	
typedef struct list list_t;

typedef struct node node_t;

typedef struct element	element_t;

struct	element
{
	int		value;
	bool	isKeep;
	int		index;
};

struct node
{
	element_t	data;
	node_t		*next;
	node_t		*previous;
	void		(*insert_before)(node_t *self, node_t *node);
	void		(*insert_after)(node_t *self, node_t *node);
	void		(*swap)(node_t *self, node_t *node);
	void		(*reverse)(node_t *self);
	void		(*disconnect)(node_t *node);
};;


struct		list
{
	node_t		*begin;
	node_t		*end;
	int			size;
	void		(*push_back)(list_t *lst, element_t	data);
	void		(*push_front)(list_t *lst, element_t data);
	void		(*pop_front)(list_t *lst);
	void		(*pop_back)(list_t *lst);
	node_t		*(*advance)(node_t *it, int dist);
	node_t		*(*erase)(list_t *lst, node_t *it);
	node_t		*(*erase_between)(list_t *lst, node_t *start, node_t *end);
	
};

node_t				*ft_list_erase_between(list_t *self, node_t *start, node_t *end);

void				ft_node_disconnect(node_t *node);

node_t				*ft_list_erase(list_t *self, node_t *it);

node_t				*ft_list_iterator_advance(node_t *it, int dist);

void				ft_list_destructor(list_t *self);

int					ft_list_size(list_t *self);

void				ft_list_push_back(list_t *lst, element_t data);

void				ft_list_pop_front(list_t *lst);

void				ft_list_pop_back(list_t *lst);

void				ft_list_push_front(list_t *lst, element_t data);

void				node_insert_before(node_t *self, node_t *node);

void				node_insert_after(node_t *self, node_t *node);

void				node_reverse(node_t *self);

void				node_swap(node_t *self, node_t *node);

node_t				*ft_node_default_constructor();

node_t				*ft_node_copy_constructor(node_t *node);

node_t				*ft_node_constructor(element_t data);

void				ft_node_destructor(node_t *self);

list_t				ft_list_default_constructor();

list_t				ft_list_copy_constructor(const list_t *list);

list_t				ft_list_array_constructor(element_t *arr, int size);


//list_t				ft_list_initalizer_string_constructor(char **arr, int size);

//list_t				ft_list_initalizer_char_constructor(char *arr, int size);

void				ft_swap(void *a, void *b, size_t size);

#endif

