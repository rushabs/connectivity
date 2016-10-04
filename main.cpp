#include <iostream>
#include<pthread.h>
#include<iomanip>

using namespace std;

void *function(void *str)
{
    char *msg;
    msg=(char*) str;
    cout<<"MESSAGE IS:\n"<<msg<<endl;


}

void *function2(void *num)
{
    int *ans;

    ans=(int*) num;

    cout<<"NUMBER IS:\n"<<dec<<ans<<endl;

}

int main()
{
    pthread_t t1,t2;
    const char *str1="THREAD A\n";
    int num1=12;
    //const char *str2="THREAD B\n";

    int r1,r2;
    r1=pthread_create(&t1,NULL,function,(void*) str1);
    r2=pthread_create(&t1,NULL,function2,(void*) num1);

    if(r1)
    {
        cout<<"ERROR IN A"<<endl;

    }
    else
        if(r2)
    {
        cout<<"ERROR IN B"<<endl;
    }
      pthread_join(t1,NULL);
      pthread_join(t2,NULL);
    return 0;
}
