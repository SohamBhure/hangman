#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>

using namespace std;

class Game
{
    private:
        string PASSWORD = "HangMan";
        char ch;
        string pass ="";
        int pass_count=3;



    public:

        //Game()
        //{}

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

                if(pass == PASSWORD)
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


class HangMan : public Game
{
    private:
        int marks=0, len=0, player=1, z=0;
        char ch; // str[100]; //arr[50] = {'a','e','i','o','u'};
        string str;

    public:
        HangMan(int p)
        {   
            player = p%2 + 1;
            cout<<"\nPlayer "<<player<<" : ";
            cout<<"\nEnter a Word (Only small characters): ";
            ch = _getch();

            while(ch != 13)
            {
                str.push_back(ch);
                cout << '*';
                ch = _getch();
            }
            cout<<"\n\n\n\n\n\n\n";
        }
        
        /*
        void setMarks(int m)
        {
            marks = marks + m;
        }

        ~HangMan()
        {
            cout<<"\n\nMarks of Player "<<player<<" Are : "<<marks;
        }
        */

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

    len = (a->str).size();
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
    int i=0, j=0, marks=0, pass=0, choice;

    Game o;
    pass = o.get_password();

    if(pass == 1)
    {
        cout << "\nAccess granted! Lets PLAY!! \n";
    }
    else
    {   
        cout<<"\n================================OOPS! Too Many Attemps! ==================================================";
        return 0;
    }

    
    HangMan *ptr[40];
    begin_HangMan();
    while(1)
    {
        cout<<"\n\n\nDo you want to Enter a new Word? (y/n) : ";
        cin>>c1;
        if (c1=='y' || c1=='Y')
        {   
            ptr[i] = new HangMan(i);
                    
            marks = chance(ptr[i]);
            //ptr[i]->setMarks(marks1);
           
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