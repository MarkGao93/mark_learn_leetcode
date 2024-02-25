// #include "aegis.h"
#include "common.h"
#include "array.h"
#include "dichotomy.h"
// #include "mainWindow.h"
// #include <QApplication>
// #include "lateralController.h"

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
    ret = dichotomy_main();
//    aegis_run(argc, argv);
    // aegis_run();


    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();

//    while(1)
//    {

//        usleep(1000000);
//    }
	return 0;
}

