#include <iostream>
#include <string>
using namespace std;

void logMsg(const string &msg,int level=1)
{
    const string tag[]={" ","INFO","WARN","ERROR"};
    cout<<"["<<tag[level]<<"]"<<msg<<endl;
}

double interest(double principal,double year,double rate=7.5)
{
    return principal*rate*year/100.0;

}

int main(){
    logMsg("System Started");
    logMsg("Low Memory",2);
    cout<<"Interest="<<interest(10000,2)<<endl;
    cout<<"Interest="<<interest(10000,2,9.0)<<endl;

    return 0;
}