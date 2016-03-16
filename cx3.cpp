#include <iostream>  
#include <string>  
using namespace std;  
struct Word  
{    string Str;  
     int Count;   
};  
void CalcCount(Word *words,string &newWord,int size) 
{    int m=0;  
     for(;m<size;m++)  
     {   if(words[m].Str==newWord)  
	 
	 {       words[m].Count++;  
             return;  
         }  
         else if(words[m].Str=="")  
             break;  
     }  
    words[m].Str=newWord;  
    words[m].Count =1;  
} 
int main()  
{
     Word *words;  
     string content;  
     cout<<"输入一串英文:";  
     getline(cin, content);   
     int wCount = 1;  
     for(unsigned int m=0; m<content.length();m++)    
     {  
         if(content[m]==' ')  
             wCount++;  
     }  
     words=new Word[wCount];  
     string::size_type offset=content.find(' '); 
     while(offset!=string::npos)  
     {  
        string wStr=content.substr(0,offset);   
        if (wStr.length()<4)              
        {
            wCount--;
            content.erase(0,offset+1);
            offset=content.find(' ');
            continue;
        }
         content.erase(0,offset+1);            
         CalcCount(words,wStr,wCount);  
         offset=content.find(' ');   
	 }
    if (content.length()>= 4)
    {
        CalcCount(words, content, wCount);                            
    }
    else wCount--;

    for (int n=0; n<wCount; n++)
    {
        if (words[n].Str=="")
        {
            wCount--;
        }
    }
     for(m=0;m<wCount-1;m++)  
     {  
         cout << words[m].Str << "频率:" << words[m].Count << "次" << endl;  
     }  
    
     delete [] words;  
     return 0;  
} 

