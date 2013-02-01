#include <common.h>

widget_list *list;


int stk_init()
{
    list = NULL;
}


int stk_widget_insert(void *widget)
{
    widget_list *new_widget = (widget_list *)malloc(sizeof(widget_list));
    new_widget->this = widget;
    new_widget->prev = NULL;
    new_widget->next = list;

    if(list != NULL)
        list->prev = new_widget;

    list = new_widget;
}


int stk_widget_delete(void *widget)
{

}


int stk_widget_search(void *widget)
{
    widget_list *node = list;
    if(node ==  NULL)
        printf("Empty list\n");
    else
        while(node)
        {
            if (node->this == widget)
            {
                printf("Widget %p found!\n", widget);
                return FOUND;
            }
            else
                node = node->next;
        }
        
        printf("Widget %p not found :(\n", widget);
        return NOT_FOUND;
}


void stk_widget_print()
{
    // widget_list *node = list;
    // if(node ==  NULL)
    //     printf("Empty list\n");
    // else
    //     while(1)
    //     {
    //         node = list;
    //         while(node)
    //         {
    //             printf("%p\n", node->this);
    //             node = node->next;
    //         }
    //     }
}


void stk_run()
{
    XEvent    event;
    widget_list *node = list;
    stk_widget *wnode = NULL;

    if(node ==  NULL)
        printf("Empty list\n");
    else
        while(1)
        {
            node = list;
            while(node)
            {
                printf("%p\n", node->this);
                wnode = (stk_widget*)node;
                //if (XCheckWindowEvent(wnode->dsp, wnode->win, wnode->mask, &event))
                  printf("Event happened to %p\n", wnode);
                node = node->next;
            }
        }
}
