#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct student{
    int id;
    char name[20];
};
int main()
{
    int a,b;
   // cin>>a;
    student s;
    while(1){
        cout<<"1.Write in record"<<endl;
        cout<<"2.Read in record"<<endl;
        cout<<"3.Delete something from record"<<endl;
        cout<<"4.exit"<<endl;
        //cout<<"press  for read"<<endl;
        cin>>a;
        bool chk = false;
        switch(a)
        {
         //   cin>>a;
            case 1:
            {
                cout<<"Enter student ID"<<endl;
                cin>>s.id;
                cout<<"Enter student Name"<<endl;
                cin>>s.name;
                ofstream sdata;
                sdata.open("student.txt",ios :: app);
                sdata << s.id;
                sdata << endl;
                sdata << s.name;
                sdata << endl;
                sdata.close();
                break;
            }
            case 2:
            {
                ifstream tdata;
                 tdata.open("student.txt");
                 tdata >> s.id;
                 tdata >> s.name;
                 while(!tdata.eof())
                 {
                      cout<<"Student Id is:"<<s.id<<endl;
                      cout<<"Student Name:"<<s.name<<endl;
                      tdata >> s.id;
                      tdata >> s.name;
                 }
                 tdata.close();
                break;
            }
            case 3:
            {
               cout<<"Enter id of Student whom you want to delete"<<endl;
                int id;
                cin>>id;
                ifstream is("student.txt");

                ofstream ofs;
                ofs.open("temp.txt", ofstream::out);

                char c;
                int line_no = 1;
                int tempid = 0;
                bool found = false;
                string ss = "";
                string ff = "";
                while (is.get(c))
                {

                    if(c >='0' && c <= '9'){
                        tempid *= 10;
                        tempid += c - '0';
                    }
                    if(line_no%2==0)
                        ss += c;
                    else{
                        ff += c;
                    }
                    if (c == '\n') {

                        if(line_no %2 == 0){
                            if(tempid != id){
                                ofs << ff ;
                                ofs << ss;
                            }
                            tempid = 0;
                            ss = "";
                            ff = "";
                        }

                        line_no++;
                    }


                }

                ofs.close();

                is.close();
                remove("student.txt");
                rename("temp.txt", "student.txt");
                break;
     }
   case 4:
            {
                chk = true;
                break;
            }
        }
        if(chk)
            break;
    }
  //  cout<<"Hello World";
    return 0;
    //return 0;
}
