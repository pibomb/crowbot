#include <iostream>
#include <fstream>

#define directory "images"
#define name "hp_bar_spritesheet"
#define filename "hp_bar.png"

using namespace std;

int main()
{
    ifstream sfin(directory
                  "/"
                  filename, ios::ate|ios::binary);
    size_t filesize=sfin.tellg();
    sfin.close();
    ifstream fin(directory
                 "/"
                 filename, ios::binary);
    ofstream fout(directory
                  "/"
                  name
                  ".cpp", ios::binary);
    ofstream hfout(directory
                   "/"
                   name
                   ".h", ios::binary);
    unsigned char ch;
    int counter=0;
    hfout<<"#ifndef "<<name<<"_H_INCLUDED"<<endl;
    hfout<<"#define "<<name<<"_H_INCLUDED"<<endl;
    hfout<<"extern size_t __"<<name<<"_size;"<<endl;
    hfout<<"extern unsigned char __"<<name<<"_data["<<filesize+1<<"];"<<endl;
    hfout<<"#endif"<<endl;
    hfout.close();
    fout<<"#include <cstddef>"<<endl;
    fout<<"#include \""<<name<<".h\""<<endl;
    fout<<"size_t __"<<name<<"_size="<<filesize<<";"<<endl;
    fout<<"unsigned char __"<<name<<"_data[]={";
    while(fin.good())
    {
        ch=fin.get();
        if(counter)
        {
            fout<<",";
        }
        fout<<(int)ch;
        counter++;
        if(counter!=fin.tellg() && fin.good())
        {
            cout<<"Error at: "<<counter<<" "<<fin.tellg()<<endl;
        }
    }
    fout<<"};"<<endl;
    fin.close();
    fout.close();
    cout<<counter<<" bytes written to file."<<endl;

    return 0;
}
