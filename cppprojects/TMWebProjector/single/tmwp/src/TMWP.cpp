#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<tmwp>
#include<iostream>
using namespace tmwp;
void decode(char *j,int len)
{
for(int i=0;i<len;i++)
{
if(j[i]=='+') 
{
j[i]=' '; //Space: Replaced by '+'
}
else if(j[i]=='%' && j[i+1]=='2' && j[i+2]=='1')
{
 j[i]='!';     //Exclamation mark (!): %21
}
else if(j[i]=='%' && j[i+1]=='2' && j[i+2]=='2')
{
 j[i]='"';   //Double quotation mark ("): %22
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='2' && j[i+2]=='3')
{
 j[i]='#';   //Number sign (#): %23
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='2' && j[i+2]=='4')
{
 j[i]='$';   //Dollar sign ($): %24
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='2' && j[i+2]=='5')
{
 j[i]='%';   //Percent sign (%): %25
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='2' && j[i+2]=='6')
{
 j[i]='&';   //Ampersand (&): %26
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='2' && j[i+2]=='7')
{
 j[i]='\'';   //Single quotation mark ('): %27
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='2' && j[i+2]=='8')
{
 j[i]='(';   //Left parenthesis (() %28
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='2' && j[i+2]=='9')
{
 j[i]=')';   //Right parenthesis ()): %29
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='2' && j[i+2]=='B')
{
 j[i]='+';   //Plus sign (+): %2B
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='2' && j[i+2]=='A')
{
 j[i]='*';   //Asterisk (*): %2A
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='2' && j[i+2]=='C')
{
 j[i]=',';   //Comma (,): %2C
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='2' && j[i+2]=='F')
{
 j[i]='/';   //Forward slash (/): %2F
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='3' && j[i+2]=='A')
{
 j[i]=':';   //Colon (:): %3A
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='3' && j[i+2]=='B')
{
 j[i]=';';   //Semicolon (;): %3B
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='3' && j[i+2]=='C')
{
 j[i]='<';   //Less than sign (<): %3C
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='3' && j[i+2]=='D')
{
 j[i]='=';   //Equals sign (=): %3D
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='3' && j[i+2]=='E')
{
 j[i]='>';   //Greater than sign (>): %3E
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='3' && j[i+2]=='F')
{
 j[i]='?';   //Question mark (?): %3F
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
else if(j[i]=='%' && j[i+1]=='4' && j[i+2]=='0')
{
 j[i]='@';   //Commercial at (@): %40
for(int  f=i+1;f<len;f++) j[f]=j[f+2]; 
}
}
}

int hasEnding (string url)
{
int len=url.length();
if(url[len-4]=='.' && url[len-3]=='t' && url[len-2]=='p' && url[len-1]=='l')  return 1;
else return 0;
}

string Request::get(string name)
{
string val;
char *j;
int i,e,len,f;
for(i=0;i<this->dataCount;i++)
{
len=strlen(data[i]);
j=(char *)malloc(sizeof(char)*len);
for(e=0;data[i][e]!='\0' && data[i][e]!='=';e++) j[e]=data[i][e];
j[e]='\0';
if(data[i][e]!='=') continue; // back to next cycle of for loop
decode(j,len);
if(strcmp(j,name.c_str())==0) break;
}
if(i==this->dataCount)
{
val="";
}
else
{
e=e+1;
for(f=0;e<len;e++,f++) j[f]=data[i][e];
j[f]='\0';
decode(j,strlen(j));
val=string(j);
}
return val;
}
void Request::setKeyValue(string k,string v)
{
keyValues.insert(pair<string,string>(k,v));
}
string Request::getValue(string k)
{
map<string,string>::iterator iter;
iter=keyValues.find(k);
if(iter==keyValues.end()) return string("");
return iter->second;
}
void Request::forward(string forwardTo)
{
this->forwardTo=forwardTo;
}


Response::Response(int clientSocketDescriptor)
{
this->clientSocketDescriptor=clientSocketDescriptor;
this->isClosed=false;
this->headerCreated=false;
}
void Response::createHeader()
{
char header[51];
strcpy(header,"HTTP/1.1 200 OK\nContent-Type: text/html\n\n");
send(clientSocketDescriptor,header,strlen(header),0);
this->headerCreated=true;
}

void Response::write(const char *str)
{
if(str==NULL) return;
int len=strlen(str);
if(len==0) return;
if(!this->headerCreated) createHeader();
send(clientSocketDescriptor,str,len,0);
}
void Response::write(string str)
{
write(str.c_str());
}
// you need to overload more methods for primitive types
void Response::close()
{
if(this->isClosed) return;
closesocket(this->clientSocketDescriptor);
this->isClosed=true;
} 
int extensionEquals(const char *left,const char * right)
{
char a,b;
while(*left && *right)
{
a=*left;
b=*right;
if(a>=65 && a<=90) a+=32;
if(b>=65 && b<=90) b+=32;
if(a!=b) return 0;
left++;
right++;
}
return *left==*right;
}

char *getMIMEType(char *resource)
{
char *mimeType;
mimeType=NULL;
int len=strlen(resource);
if(len<4) return mimeType;
int lastIndexOfDot=len-1;
while(lastIndexOfDot>0 && resource[lastIndexOfDot]!='.') lastIndexOfDot--;
if(lastIndexOfDot==0) return mimeType;
if(extensionEquals(resource+lastIndexOfDot+1,"html"))
{
mimeType=(char *)malloc(sizeof(char)*10);
strcpy(mimeType,"text/html");
}
if(extensionEquals(resource+lastIndexOfDot+1,"css"))
{
mimeType=(char *)malloc(sizeof(char)*9);
strcpy(mimeType,"text/css");
}
if(extensionEquals(resource+lastIndexOfDot+1,"js"))
{
mimeType=(char *)malloc(sizeof(char)*16);
strcpy(mimeType,"text/javascript");
}
if(extensionEquals(resource+lastIndexOfDot+1,"jpg"))
{
mimeType=(char *)malloc(sizeof(char)*11);
strcpy(mimeType,"image/jpeg");
}
if(extensionEquals(resource+lastIndexOfDot+1,"jpeg"))
{
mimeType=(char *)malloc(sizeof(char)*11);
strcpy(mimeType,"image/jpeg");
}
if(extensionEquals(resource+lastIndexOfDot+1,"png"))
{
mimeType=(char *)malloc(sizeof(char)*10);
strcpy(mimeType,"image/png");
}
if(extensionEquals(resource+lastIndexOfDot+1,"ico"))
{
mimeType=(char *)malloc(sizeof(char)*13);
strcpy(mimeType,"image/x-icon");
}
return mimeType;
}
char isClientSideResource(char *resource)
{
int i;
for(i=0;resource[i]!='\0' && resource[i]!='.';i++);
if(resource[i]=='\0') return 'N';
return 'Y';
}
Request *parseRequest(char *bytes)
{
char method[11];
char resource[1001];
int i,j;
for(i=0;bytes[i]!=' ';i++) method[i]=bytes[i];
method[i]='\0';
i+=2;
char **data=NULL;
int dataCount=0;
if(strcmp(method,"GET")==0)
{
for(j=0;bytes[i]!=' ';j++,i++) 
{
if(bytes[i]=='?') break;
resource[j]=bytes[i];
}
resource[j]='\0';
if(bytes[i]=='?')
{
i++;
int si=i;
dataCount=0;
while(bytes[i]!=' ')
{
if(bytes[i]=='&') dataCount++;
i++;
}
dataCount++;
data=(char **)malloc(sizeof(char*)*dataCount);
int *pc=(int *)malloc(sizeof(int)*dataCount);
i=si;
int j=0;
while(bytes[i]!=' ')
{
if(bytes[i]=='&')
{
pc[j]=i;
j++;
}
i++;
}
pc[j]=i;
i=si;
j=0;
int howManyToPick;
while(j<dataCount)
{
howManyToPick=pc[j]-i;
data[j]=(char *)malloc(sizeof(char)*(howManyToPick+1));
strncpy(data[j],bytes+i,howManyToPick);
data[j][howManyToPick]='\0';
i=pc[j]+1;
j++;
}
}
}//method is of GET type
printf("Request arrived for %s\n",resource);
//Request *request=(Request *)malloc(sizeof(Request));
Request *request=new Request; //v v v v v important
request->dataCount=dataCount;
request->data=data;
request->method=(char *)malloc((sizeof(char)*strlen(method))+1);
strcpy(request->method,method);
if(resource[0]=='\0')
{
request->resource=NULL;
request->isClientSideTechnologyResource='Y';
request->mimeType=NULL;
request->isSpecial='N';
}
else
{
request->resource=(char *)malloc((sizeof(char)*strlen(resource))+1);
strcpy(request->resource,resource);
request->isClientSideTechnologyResource=isClientSideResource(resource);
request->mimeType=getMIMEType(resource);
if(hasEnding(resource)==1) request->isSpecial='Y';
else request->isSpecial='N';
}
return request;
}
TMWebProjector::TMWebProjector(int portNumber)
{
this->portNumber=portNumber;
}
TMWebProjector::~TMWebProjector()
{
}
void TMWebProjector::onRequest(string url,void(*ptrOnRequest)(Request &,Response &))
{
if(url.length()==0 || ptrOnRequest==NULL) return;
requestMappings.insert(pair<string,void(*)(Request &,Response&)>(url,ptrOnRequest));
}

void TMWebProjector::start()
{
FILE *f;
int rc,i,length;
char g;
int bytesExtracted;
char responseBuffer[1024];
char requestBuffer[8192];
struct sockaddr_in serverSocketInformation;
struct sockaddr_in clientSocketInformation;
int serverSocketDescriptor;
int clientSocketDescriptor;
int len;
int successCode;
WORD ver;
WSADATA wsadata;
ver=MAKEWORD(1,1);
WSAStartup(ver,&wsadata);
serverSocketDescriptor=socket(AF_INET,SOCK_STREAM,0);
if(serverSocketDescriptor<0)
{
printf("Unable to create socket\n");
return ;
}
serverSocketInformation.sin_family=AF_INET;
serverSocketInformation.sin_port=htons(this->portNumber);
serverSocketInformation.sin_addr.s_addr=htonl(INADDR_ANY);
successCode=bind(serverSocketDescriptor,(struct sockaddr *)&serverSocketInformation,sizeof(serverSocketInformation));
char message[101];
if(successCode<0)
{
sprintf(message,"Unable to bind socket to port %d",this->portNumber);
printf("%s\n",message);
WSACleanup();
return ;
}
listen(serverSocketDescriptor,10);
len=sizeof(clientSocketInformation);
while(1) // loop to accept connection
{
sprintf(message,"TMServer is ready to accept request on port %d",this->portNumber);
printf("%s\n",message);
clientSocketDescriptor=accept(serverSocketDescriptor,(struct sockaddr *)&clientSocketInformation,&len);
if(clientSocketDescriptor<0)
{
printf("Unable to accept client connection\n");
closesocket(serverSocketDescriptor);
WSACleanup();
return ;
}
bytesExtracted=recv(clientSocketDescriptor,requestBuffer,8192,0);
if(bytesExtracted<0)
{
// what to do is yet to be decided
}else
if(bytesExtracted==0)
{
// what to do is yet to be decided
}
else
{
requestBuffer[bytesExtracted]='\0';
Request *request=parseRequest(requestBuffer);
while(1) // infinte loop to enable forwarding feature
{
if(request->isClientSideTechnologyResource=='Y')
{
if(request->isSpecial=='N')
{
if(request->resource==NULL)
{
f=fopen("index.html","rb");
if(f!=NULL) printf("Sending index.html\n");
if(f==NULL)
{
f=fopen("index.htm","rb");
if(f!=NULL) printf("Sending index.htm\n");
}
if(f==NULL)
{
strcpy(responseBuffer,"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 163\nConnection:close\n\n<DOCKTYPE HTML><html lang='en'><head><meta charset='utf-8'><title>TMWeb Projector</title></head><body><h2 style='color:red'>Resource / not found</h2></body></html>");
send(clientSocketDescriptor,responseBuffer,strlen(responseBuffer),0);
printf("Sending 404 page\n");
closesocket(clientSocketDescriptor);
break ; // introduced because of forwarding feature
}
else
{
fseek(f,0,2);
length=ftell(f);
fseek(f,0,0);
sprintf(responseBuffer,"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\nConnection: close\n\n",length);
send(clientSocketDescriptor,responseBuffer,strlen(responseBuffer),0);
i=0;
while(i<length)
{
rc=length-i;
if(rc>1024) rc=1024;
fread(&responseBuffer,rc,1,f);
send(clientSocketDescriptor,responseBuffer,rc,0);
i+=rc;
}
fclose(f);
closesocket(clientSocketDescriptor);
break ; // introduced because of forwarding feature
}
}
else
{
f=fopen(request->resource,"rb");
if(f!=NULL) printf("Sending %s\n",request->resource);
if(f==NULL)
{
// something need to be done over here
printf("Sending 404 page\n");
char tmp[501];
sprintf(tmp,"<DOCKTYPE HTML><html lang='en'><head><meta charset='utf-8'><title>TMWeb Projector</title></head><body><h2 style='color:red'>Resource /%s not found</h2></body></html>",request->resource);
sprintf(responseBuffer,"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\nConnection:close\n\n",strlen(tmp));  // here
strcat(responseBuffer,tmp);
send(clientSocketDescriptor,responseBuffer,strlen(responseBuffer),0);
break ; // introduced because of forwarding feature
}
else
{
fseek(f,0,2);
length=ftell(f);
fseek(f,0,0);
sprintf(responseBuffer,"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\nConnection: close\n\n",length);
send(clientSocketDescriptor,responseBuffer,strlen(responseBuffer),0);
i=0;
while(i<length)
{
rc=length-i;
if(rc>1024) rc=1024;
fread(&responseBuffer,rc,1,f);
send(clientSocketDescriptor,responseBuffer,rc,0);
i+=rc;
}
fclose(f);
closesocket(clientSocketDescriptor);
break ; // introduced because of forwarding feature
}
}
} // isSpecial='N' if part 
else
{
// here starts
FILE *f,*tmpp;
char symbol;
int len;
int found=0;
char *imf;
char responseBuffer[5000];
char c;
f=fopen(request->resource,"rb");
tmpp=fopen("tmp.dat","wb");
if(f!=NULL) printf("Sending %s\n",request->resource);
if(f==NULL)
{
// something need to be done over here
printf("Sending 404 page\n");
char tmp[501];
sprintf(tmp,"<DOCKTYPE HTML><html lang='en'><head><meta charset='utf-8'><title>TMWeb Projector</title></head><body><h2 style='color:red'>Resource /%s not found</h2></body></html>",request->resource);
sprintf(responseBuffer,"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\nConnection:close\n\n",strlen(tmp));  // here
strcat(responseBuffer,tmp);
send(clientSocketDescriptor,responseBuffer,strlen(responseBuffer),0);
break ; // introduced because of forwarding feature
}
while(1)
{
found=0;
c=fgetc(f);
if(feof(f)) break;
if(c!='$') fputc(c,tmpp);
string cc;
if(c=='$') 
{
c=fgetc(f); 
if(c!='$') 
{
fputc('$',tmpp);
fputc(c,tmpp);
continue;
}
c=fgetc(f);
if(c!='$') 
{
fputc('$',tmpp);
fputc('$',tmpp);
fputc(c,tmpp);
continue;
}
c=fgetc(f);
if(c!='{') 
{
fputc('$',tmpp);
fputc('$',tmpp);
fputc('$',tmpp);
fputc(c,tmpp);
continue;
}
symbol=fgetc(f);
cc=cc+symbol;
while(symbol!='}')
{
symbol=fgetc(f);
if(symbol!='}')
{
cc=cc+symbol;
}
if(feof(f)) 
{
printf("Sending syntax error page\n");
char tmp[501];
sprintf(tmp,"<DOCKTYPE HTML><html lang='en'><head><meta charset='utf-8'><title>TMWeb Projector</title></head><body><h2 style='color:red'>Syntax error $$$ is not closed</h2></body></html>");
sprintf(responseBuffer,"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\nConnection:close\n\n",strlen(tmp));  // here
strcat(responseBuffer,tmp);
send(clientSocketDescriptor,responseBuffer,strlen(responseBuffer),0);
break;
}
} // inner while
string keyValue;
keyValue=request->getValue(cc);
fputs(keyValue.c_str(),tmpp);
cc.clear();
}     // if
} // while loop
fclose(f);
fclose(tmpp);

// here ends





f=fopen("tmp.dat","rb");
if(f!=NULL) printf("Sending tmp.dat\n");
if(f==NULL)
{
// something need to be done over here
printf("Sending 404 page\n");
char tmp[501];
sprintf(tmp,"<DOCKTYPE HTML><html lang='en'><head><meta charset='utf-8'><title>TMWeb Projector</title></head><body><h2 style='color:red'>Resource /%s not found</h2></body></html>","tmp.dat");
sprintf(responseBuffer,"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\nConnection:close\n\n",strlen(tmp));  // here
strcat(responseBuffer,tmp);
send(clientSocketDescriptor,responseBuffer,strlen(responseBuffer),0);
break ; // introduced because of forwarding feature
}
else
{
fseek(f,0,2);
length=ftell(f);
fseek(f,0,0);
sprintf(responseBuffer,"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\nConnection: close\n\n",length);
send(clientSocketDescriptor,responseBuffer,strlen(responseBuffer),0);
i=0;
while(i<length)
{
rc=length-i;
if(rc>1024) rc=1024;
fread(&responseBuffer,rc,1,f);
send(clientSocketDescriptor,responseBuffer,rc,0);
i+=rc;
}
fclose(f);
closesocket(clientSocketDescriptor);
break ; // introduced because of forwarding feature
}





request->isSpecial='N';
}
} //isClientSideTechnology parts ends here
else
{
// more changes required in context to server side resource
map<string,void(*)(Request &,Response&)>::iterator iter;
iter=requestMappings.find(string("/")+string(request->resource));
if(iter==requestMappings.end())
{
printf("Sending 404 page\n");
char tmp[501];
sprintf(tmp,"<DOCKTYPE HTML><html lang='en'><head><meta charset='utf-8'><title>TMWeb Projector</title></head><body><h2 style='color:red'>Resource /%s not found</h2></body></html>",request->resource);
sprintf(responseBuffer,"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\nConnection: close\n\n",strlen(tmp));
strcat(responseBuffer,tmp);
send(clientSocketDescriptor,responseBuffer,strlen(responseBuffer),0);
break ; // introduced because of forwarding feature
}
else
{
Response response(clientSocketDescriptor);
iter->second(*request,response);
if(request->forwardTo.length()>0)
{
free(request->resource);
request->resource=(char *)malloc((sizeof(char)*request->forwardTo.length())+1);
strcpy(request->resource,request->forwardTo.c_str());
cout<<"Request at server side for "<<request->resource<<endl;
request->isClientSideTechnologyResource=isClientSideResource(request->resource);
request->mimeType=getMIMEType(request->resource);
if(hasEnding(request->resource)==1) request->isSpecial='Y';
else request->isSpecial='N';
request->forwardTo=""; // **
continue;
}
if(request->data!=NULL)
{
for(int k=0;k<request->dataCount;k++) free(request->data[k]);
free(request->data);
}
break; // introduce because of forwarding feature
}
}
}
} // the infinite loop introduced because of forwarding featture ends
}// the infinite loop related to accept method ends here
closesocket(serverSocketDescriptor);
WSACleanup();
return ;
}