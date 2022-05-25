#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>


using namespace std;

class Game
{
    private:
        char ch;
        string pass ="";
        int pass_count=3;


    public:

        Game()
        {
           
        }

        int get_password()
        {   
            cout<<"\n\n==============================WELCOME TO THE CONSOLE===========================\n\n";
            cout<<"\nYou Need To Enter the Password to play the game ! ";

            while(pass_count!=0)
            {   
                pass = "";

                cout<<"\n\nPassword : ";

                ch = _getch();

                while(ch != 13)
                {
                    pass.push_back(ch);
                    cout << '*';
                    ch = _getch();
                }

                if(pass == "HangMan")
                {
                    return 1;
                }
                else
                {   
                    pass_count--;
                    cout << "\nWrong Password!!\n";
                    cout<<pass_count<<" Chances Remaining !!";
                }
            
            }
            return 0;
        }

};



class FunnyNames : public Game    //??????
{
    private:

        char fname[20];
        char lname[20];
        char combined1[40], combined2[40];

    public:

        FunnyNames()
        {

        }

        FunnyNames operator+(FunnyNames a)// operator overloading
        {
            FunnyNames temp;      //object?

            strcpy(temp.combined1, fname);     //string functions
            strcat(temp.combined1, " ");
            strcat(temp.combined1, a.lname);

            strcpy(temp.combined2, a.fname);
            strcat(temp.combined2, " ");
            strcat(temp.combined2, lname);

            return temp;
        }


        void new_names()
        {
            cout<<"\nYour New Names Are : ";
            cout<<"\n"<<combined1;
            cout<<"\n"<<combined2;
        }

        void get_name()
        {
            cout<<"\nEnter Your First Name : ";
            cin>>fname;

            cout<<"Enter Your Last Name : ";
            cin>>lname;
        }


};


void begin_FunnyNames()
{
    cout<<"\n\nInstructions : \n1. This Game Required Only Two Players.";
    cout<<"\n2. Both Players Need to Enter their First Name and Last Name.";
    //cout<<"\n3. The words will be saved in a file and we can view it later.";
    //cout<<"\n4. ";

}



class HangMan : public Game
{
    private:
        int marks=0, len=0, player=1, z=0;
        char str[100]; //arr[50] = {'a','e','i','o','u'};

    public:

        HangMan(int p)
        {   
            player = p;
            cout<<"\nPlayer "<<p<<" : ";
            cout<<"\nEnter a Word (Only small characters): ";
            cin>>str;
            cout<<"\n\n\n\n\n\n\n";
            
            len = strlen(str);

            fstream file;
            
            file.open("Words.txt",ios_base::app);

            if(file.is_open())
            {  
                //fflush(stdin);
                file<<str; 
                file<<"\n";

                file.close();
            }
        }
        
        
        void setMarks(int m)
        {
            marks = marks + m;
        }

        ~HangMan()
        {
            cout<<"\n\nMarks of Player "<<player<<" Are : "<<marks;
        }

        int friend chance(HangMan *a);
};


int draw(int l)
{   
    
    switch(l)
    {   
        cout<<"\n===============================Current Position==================================\n ";

        case 0: cout<<"\n\n\t\t   6 more chances remaining ";
                //cout<<"\n\n\t\t\t      O";
                return 1; 
                break;

        case 1: cout<<"\n\n\t\t   5 more chances remaining ";
                cout<<"\n\n\t\t\t      O\n\n\n";
                return 2; 
                break;
        
        case 2: cout<<"\n\n\t\t   4 more chances remaining ";
                cout<<"\n\n\t\t\t      O\n\t\t\t    /\n\n\n";
                return 3;
                break;

        case 3: cout<<"\n\n\t\t   3 more chances remaining ";
                cout<<"\n\n\t\t\t      O\n\t\t\t    /   \\\n\n\n";     
                return 4;
                break;

        case 4: cout<<"\n\n\t\t   2 more chances remaining ";
                cout<<"\n\n\t\t\t      O\n\t\t\t    / | \\\n\t\t\t      |\n\t\t\t\n\n\n";
                return 5;
                break;
        
        case 5: cout<<"\n\n\t\t   1 more chances remaining ";
                cout<<"\n\n\t\t\t      O\n\t\t\t    / | \\\n\t\t\t      |\n\t\t\t     /   \n\t\t\t    /   \n\n\n";
                return 6;
                break;
        
        case 6: cout<<"\n\n\t\t     OOPS You are DEAD !!";
                cout<<"\n\n\t\t\t      O\n\t\t\t    / | \\\n\t\t\t      |\n\t\t\t     / \\\n\t\t\t    /   \\";   
                return 7;
                break;                

    }  
           
}

void begin_HangMan()
{
    cout<<"\n\t\t\t\tH     H     MM     MM\n\t\t\t\tH     H     M  M  M M\n\t\t\t\tHHHHHHH     M   M   M\n\t\t\t\tH     H     M       M\n\t\t\t\tH     H     M       M";
    cout<<"\n\nInstructions : \n1. This Game Required Minimum Two Players.";
    cout<<"\n2. One player has to enter a word and the other players needs to identify the that word using one letter at a time before he is hanged.";
    cout<<"\n3. The words will be saved in a file and we can view it later.";
    //cout<<"\n4. ";

}


int chance(HangMan *a)
{   
    int i=0, j=0, len=0, flag1=0, flag2, x=1, z=5, count=10;
    char c, letter, arr[40]={'a','e','i','o','u'};    

    len = strlen(a->str);
    z = strlen(arr);


    while(x!=7)
    {
        count=0;

        for(i=0; i<len; i++)
        {   
            flag1=0;
            
            for(j=0; j<z; j++)
            {   

                if(a->str[i]==arr[j])
                {
                    cout<<"\t"<<arr[j]<<"\t";
                    flag1=1;
                }
            }

            if(flag1==0)
            {
                cout<<"\t"<<"_"<<"\t";
                count++;
            }

        }    

        if(count==0)
        {
            cout<<"\n\nCONGRATULATIONS - you have found the RIGHT WORD\n";
            return 10;
        }

        cout<<"\n\nEnter a character : ";
        cin>>letter;

        arr[z] = letter;
        z++;

        flag2 = 0;        

        for(i=0;i<len;i++)
        {
            if(letter == a->str[i])
            {  
                cout<<"\nThis Letter is Present !\n";
                flag2 = 1;
            }
        }

        if(flag2!=1)
        {
            x = draw(x);
        }

    }

    return 0;
}


       
    
    


int main()
{   
  
    char c1,c2;
    int i=0, j=0, marks1=0, pass=0, marks2=0, choice;


    Game o;
    pass = o.get_password();

    if(pass == 1)
    {
        cout << "\nAccess granted! Lets PLAY!! \n";
    }
    else
    {   
        cout<<"\n================================OOPS! Too Many Attemps! ==================================================";
        //cout<<"\nBetter Luck Next Time!"
        return 0;
    }


    cout<<"\n\nWhich Game Do You Want To Play ? : \n1. Name Mismatch\n2. HangMan\n";
    cin>>choice;

    if(choice == 2)
    {
    
        HangMan *ptr[40];

        begin_HangMan();

        while(1)
        {
            cout<<"\n\n\nDo you want to Enter a new Word? (y/n) : ";
            cin>>c1;

            if (c1=='y')
            {   
                ptr[i] = new HangMan(i);

                
                
                marks1 = chance(ptr[i]);
                ptr[i]->setMarks(marks1);
               
                i++;
            }
            else
            {
                break;
            }

        }

        for(j=0;j<i;j++)
        {
            delete ptr[j];
        }    

        cout<<"\n\nThank You For Trying Out HangMan.";
        cout<<"\nHope You Enjoyed!\n\n";
    }
    else if(choice == 1)
    {   
        begin_FunnyNames();

        cout<<"\n\nPlayer 1 : \n";
        FunnyNames f1;
        f1.get_name();

        cout<<"Player 2 : \n";
        FunnyNames f2;
        f2.get_name();

        FunnyNames f3 = f1 + f2;

        f3.new_names();
        
    }


}   