// #include "aegis.h"
#include "common.h"
#include "array.h"
#include "dichotomy.h"
#include "hash_table.h"
#include "data_string.h"
#include "linked_list.h"


// static void sighand(int sig)
// {
//   static unsigned int last;
//   cout<<"main.cpp - sighand"<<endl;

//   switch (sig) {
//   case SIGINT:
//     printf("oops! stop!!!\n");
//     _exit(0);
//      break;
//   case SIGALRM:
//     break;
//   }
// }

int main(int argc, char *argv[])
{
    cout<<"main.cpp - main"<<endl;

//    signal(SIGINT, sighand);

    printf("start to run the pangu...\n");
    cout<<endl;

	int ret = array_main();
    // ret = dichotomy_main();
    // ret = hash_table_main();
    // ret = data_string_main();
    ret = linked_list_main();




//    while(1)
//    {

//        usleep(1000000);
//    }
	return 0;
}

