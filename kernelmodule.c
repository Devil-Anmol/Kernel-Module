//Author: AG

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>
#include<linux/init.h>
#include<linux/cred.h>
#include<linux/sched.h>
// char buff[1024];
struct task_struct *tasklist;
const struct cred* c;
static char *input;

module_param(input,charp,0660);

static int __init INIT(void){
    printk("init");
    for_each_process(tasklist){
        if(!strcmp(input,tasklist->comm)){
            c = current_cred();
            pr_info("Process: %s\t PID:[%d]\t GroupId:[%d]\tUserId[%d]\n",tasklist->comm, tasklist->pid,c->gid,c->uid);
            break;
        }
        else{
            pr_info("Process not found\n");
        }
    }
    return 0;
}

static void __exit EXIT(void)
{
    printk("exit");
}

MODULE_LICENSE("GPL");
module_init(INIT);
module_exit(EXIT);
