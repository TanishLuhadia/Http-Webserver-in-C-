#include<stdlib.h>
#include<iostream>
#include<tmwp>
#include<ctime>
using namespace std;
using namespace tmwp;
void dispatchTime(Request &request,Response &response)
{
time_t t=time(0);
string  now=(string)ctime(&t);
request.setKeyValue("time",now);
request.forward("time.tpl");
}
void getCityView(Request &request,Response &response)
{
string cityCodeString=request.get("cityCode");
int cityCode=atoi(cityCodeString.c_str());
cout<<"City code is ("<<cityCode<<")"<<endl;
if(cityCode==1) request.forward("Ujjain.html");
else if(cityCode==2) request.forward("Indore.html");
else if(cityCode==3) request.forward("Dewas.html");
else
{
request.setKeyValue("error","Invalid Choice");
request.setKeyValue("errorMessage","Invalid option selected");
request.forward("errorPage.tpl");
}
}
void saveEnquiry(Request &request,Response &response)
{
string n=request.get("nm nm");
string c=request.get("ct");
string a=request.get("ad");
string m=request.get("msg");
cout<<"Data received"<<endl;
cout<<"Name : "<<n<<endl;
cout<<"City  : "<<c<<endl;
cout<<"Address  : "<<a<<endl;
cout<<"Query : "<<m<<endl;
// some logic to save data somewhere (may be a file or some database)
request.forward("SaveNotification.html");
}
int main()
{
TMWebProjector server(8080);
server.onRequest("/now",dispatchTime);
server.onRequest("/getCity",getCityView);
server.onRequest("/addEnquiry",saveEnquiry);
server.start();
return 0;
}