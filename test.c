#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/list.h>
struct birthday{
    int a;
    int b;
    int c;
    struct list_head list;
};
static LIST_HEAD(birthday_list);

int simple_init(void)
{

    struct birthday *people;
    int a = 1,b = 1,c = 2000,i = 0 ;
    for(i=0;i<5;i++)
    {
        people = kmalloc(sizeof(*people),GFP_KERNEL);
        people->a = a++;
        people->b = b++;
        people->c = c++;
        INIT_LIST_HEAD(&people->list);
        list_add_tail(&people->list,&birthday_list);
    }

    struct birthday *ptr;

  //  INIT_LIST_HEAD(&person->list);
	printk(KERN_INFO "结果如下：\n");
    list_for_each_entry(ptr,&birthday_list,list)
    {
        printk(KERN_INFO "%d.%d.%d\n",ptr->day,ptr->month,ptr->year);
    }


    return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
    struct birthday *ptr,*next;
    list_for_each_entry_safe(ptr,next,&birthday_list,list)
    {
        list_del(&ptr->list);
        kfree(ptr);
    }
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
