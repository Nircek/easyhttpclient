#include "wineasyhttpclient.hpp"
std::string GitHub::Nircek::wineasyhttpclient(std::string url){
    //TODO: GITHUB LINK
    //inspired by joske's program found in http://www.dreamincode.net/forums/topic/101532-download-file-from-url/

    HINTERNET hIurl, hInet;
    std::string ret;
    std::stringstream ss;
    try{
        goto l;
        err:
        ss<<'/'<<GetLastError();//https://support.microsoft.com/en-us/help/193625/info-wininet-error-codes-12001-through-12156
        return ss.str();
        l:
        if(InternetAttemptConnect(0)!=ERROR_SUCCESS)goto err;
        if((hInet = InternetOpen("downloader",INTERNET_OPEN_TYPE_DIRECT,NULL,NULL,0))==NULL)goto err;
        if((hIurl = InternetOpenUrl(hInet,url.c_str(),NULL,0,INTERNET_FLAG_NO_CACHE_WRITE,0))==NULL)goto err;
        const size_t BUF_SIZE=0x400;
        unsigned char buf[BUF_SIZE];
        unsigned long readed;
        do
        {
            if(!InternetReadFile(hIurl,&buf,BUF_SIZE,&readed))goto err;
            ret.append((const char*) buf, readed);
        }while (readed);
    }
    catch (...){
        InternetCloseHandle(hIurl);
        InternetCloseHandle(hInet);
        throw;
    }
    InternetCloseHandle(hIurl);
    InternetCloseHandle(hInet);
    return ret;
}
