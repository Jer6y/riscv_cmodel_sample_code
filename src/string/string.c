#include <string.h>
#include <stdarg.h>
#include <printf.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

 void *  memmove(void *str1, const void *str2, size_t n)
{
	if(str1 == NULL || str2 == NULL || n <=0)
		return str1;
	for(int i=0;i<n;i++)
	{
		((char*)str1)[i] = ((char*)str2)[i];
	}
	return str1;
}

 size_t  strnlen(const char* s, size_t maxlen)
{
	if(s == NULL)
		return 0;
	size_t lenth;
    	for(lenth=0;lenth < maxlen && s[lenth]!=0;lenth++) ;
   	return lenth;	
}

 size_t  strlen(const char * src)
{
    if(src == NULL)
	    return 0;
    size_t lenth;
    for(lenth=0;src[lenth]!=0;lenth++) ;
    return lenth;
}

 char*   strcpy_safe(char *dest, const char *src, size_t max_size)
{
	if(max_size <=0 )
		return dest;
	if(src == NULL || dest == NULL)
            return dest;
	int i;
	for(i=0;src[i]!=0 && i<max_size;i++)
	{
		dest[i]=src[i];
	}
	if(i>=max_size)
		dest[i-1] = 0;
	else
		dest[i] = 0;
	return dest;
}

 char *strcpy(char *dest, const char *src)
{
    if(src == NULL || dest == NULL)
	    return dest;
    int i;
    for(i=0;src[i]!=0;i++)
    {
        dest[i]=src[i];
    }
    dest[i] = 0;
    return dest;
}

 char*   strncpy_safe(char *dest, const char *src, size_t n, size_t max_size)
{
	if(max_size <=0 || n <=0) 
		return dest;
	if(src == NULL || dest == NULL)
		return dest;
	int i;
	for(i=0;src[i]!=0 && i<n && i<max_size;i++)
	{
		dest[i]=src[i];
	}
	if(i>=max_size)
		dest[i-1]=0;
	else
		dest[i]=0;
	return dest;
}

 char *strncpy(char *dest, const char *src, size_t n)
{
    if(n <=0 || dest == NULL || src == NULL)
	    return dest;
    int i;
    for(i=0;src[i]!=0&&i<n;i++)
    {
        dest[i]=src[i];
    }
    dest[i] = 0;
    return dest;
}

 int strcmp(const char* src,const char *des)
{
    if(src == NULL && des == NULL)
	    return 0;
    if((src == NULL) ^ (des == NULL))
    {
	    if(src == NULL)
		    return -des[0];
	    return src[0];
    }
    for(int i=0;!(src[i]==0&&des[i]==0);i++)
    {
        if(src[i]-des[i]!=0) 
        return src[i]-des[i];
    }
    return 0;
}

 char *strcat(char *dest, const char *src)
{
    if(src == NULL || dest == NULL)
	    return dest;
    char* p =dest;
    while(*p!=0) p++;
    for(int i=0;src[i]!=0;i++,p++)
    {
        *p = src[i];
    }
    *p=0;
    return dest;
}

 char *strchr(const char *str, int c)
{
    if(str == NULL)
	    return NULL;
    char* p = (char*)str;
    while(true)
    {
	if(*p==0)
		return NULL;
	else if(*p == c)
		return p;
    	p++;
    }
}

 char *strrchr(const char *str, int c)
{
    if(str == NULL)
	    return NULL;
    char* p = (char*)str;
    char* last=NULL;
    while(true)
    {
        if(*p==0)
	    break;
        else if(*p==c)
	    last = p;
	p++;
    }
    return last;
}

 int memcmp(const void *str1, const void *str2, size_t n)
{
    if((str1 ==NULL && str2 == NULL) || n<=0)
	    return 0;
    if((str1 == NULL) ^ (str2 == NULL))
    {
    	if(str1 == NULL)
		return -(((char*)str2)[0]);
	if(str2 == NULL)
		return ((char*)str1)[0];
    }
    char* s1 = (char*)str1;
    char* s2 = (char*)str2;
    for(int i=0;i<n;i++)
    {
        if(s1[i] - s2[i]!=0) return s1[i]-s2[i];
    }
    return 0;
}

 void *memcpy(void *des, const void *src, size_t n)
{
    if((des == NULL) || ((void*)src == NULL) || n<=0)
	    return des;
    char* des1=(char*)des;
    const char* src1=(const char*)src;
    for(size_t i =0;i<n;i++)
    {
        des1[i]=src1[i];
    }
    return des;
}

 void *memchr(const void *str, int c, size_t n)
{
    if(str == NULL || n <=0)
	    return NULL;
    char* p = (char*)str;
    int i;
    for(i=0;i<n;i++)
    {
        if(p[i]==c)
        {
            return (void*)(p+i);
        }
    }
    return 0;
}

 void *memset(const void *des, uint8_t c,size_t n)
{
    if((des == NULL) || n <=0)
	    return (void*)des;
    char* t = (char*)des;
    int i;
    for(i=0;i<n;i++)
        t[i]=c;
    return t;
}

