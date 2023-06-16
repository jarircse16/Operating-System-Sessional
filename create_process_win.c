#include<stdio.h>
#include<windows.h>

int main(VOID)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si,sizeof(si));
    si.cb=sizeof(si);
    ZeroMemory(&pi,sizeof(pi));

    printf("%x",pi);

    if(!CreateProcess(NULL,"E:\\CISCO packet tracer\\Cisco Packet Tracer 7.2\\bin\\PacketTracer7.exe",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi))
    {
        fprintf(stderr,"Create Process Failed.");
        return -1;
    }
    WaitForSingleObject(pi.hProcess,INFINITE);
    printf("Process complete.");
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
