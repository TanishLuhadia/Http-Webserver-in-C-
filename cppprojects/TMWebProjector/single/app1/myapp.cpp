#include<stdlib.h>
#include<iostream>
#include<tmwp>
#include<ctime>
using namespace std;
using namespace tmwp;

int main()
{
TMWebProjector server(8080);
server.start();
return 0;
}