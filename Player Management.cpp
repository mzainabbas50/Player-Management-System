#include<iostream>
#include<fstream>  
#include<string>   
#include<stdlib.h> 
#include<conio.h>  

using namespace std;

class file
{
    private:
        int playerid;
        string playerName;
        int age;
        char add[30];
        long long phno;   
        string parentName;
        char game[30];
      
        string coachName;
        int dorm;
        int bed;



    public:

        
        void input(){

            cout<<"\nEnter player id no: ";
            cin>>playerid;
            cout<<"\nEnter player age: ";
            cin>>age;

      
            string strFname="", strLname="";
            cout<<"\nEnter the First Name of Player: ";
            cin>>strFname;
            cout<<"\nEnter the Last Name of Player: ";
            cin>>strLname;
            playerName = strFname +"_"+ strLname;


            cout<<"\nEnter player address(City): ";
            cin>>add;
            cout<<"\nEnter player phone no.: ";
            cin>>phno;

            
            cout<<"\nEnter the First Name of Player's Parent: ";
            cin>>strFname;
            cout<<"\nEnter the Last Name of Player's Parent: ";
            cin>>strLname;
            parentName = strFname +"_"+ strLname;



            cout<<"\nEnter game name 'Basketball', 'TableTennis', 'Cricket', 'Volleyball', 'Hockey', 'FOOTBALL', 'Badminton'\nGame Name: ";
            cin>>game;

            
            cout<<"\nEnter the First Name of Coach: ";
            cin>>strFname;
            cout<<"\nEnter the Last Name of Coach: ";
            cin>>strLname;
            coachName = strFname +"_"+ strLname;


         
            cout<<"\nEnter dorm no.: ";
            cin>>dorm;
            cout<<"\nEnter bed no.: ";
            cin>>bed;

        }

        void output(){
            cout<<"\nPlayer Details: \n";
            cout<<"playerid==>"<<playerid<<endl;
            cout<<"player name==>"<<playerName<<endl;
            cout<<"player add==>"<<add<<endl;
            cout<<"phone no==>"<<phno<<endl;
            cout<<"parent name==>"<<parentName<<endl;
            cout<<"game prefered==>"<<game<<endl;
            cout<<"coach alloted==>"<<coachName<<endl;
            cout<<"dorm no==>"<<dorm<<endl;
            cout<<"bed no==>"<<bed<<endl;

        }

      

        string retplayername(){
            return playerName;
        }


        int retplayerid(){
            return playerid;
        }

        int retage(){
            return age;
        }

        char* radd(){
            return add;
        }

        long long  rphno(){ 
            return phno;
        }

      

       string rparentn(){
            return parentName;
       }


        char* rgame(){
            return game;
        }


       

        string rcoachn(){
            return coachName;
        }


        int rdorm(){
            return dorm;
        }

        int rbed(){
            return bed;
        }

};



void writeInFile(file fobj){

    char arr[]= "     ";
    ofstream fout;
    fout.open("PlayersRecord.txt", ios::out | ios::app);

    fout<<"id";
    fout<<fobj.retplayerid();fout<<arr;
    fout<<fobj.retplayername();fout<<arr;
    fout<<fobj.retage();fout<<arr;
    fout<<fobj.radd();fout<<arr;
    fout<<fobj.rphno();fout<<arr;

    fout<<"pn";
    fout<<fobj.rparentn();fout<<arr;
    fout<<fobj.rgame();fout<<arr;

    fout<<"cn";
    fout<<fobj.rcoachn();fout<<arr;

    fout<<'D';   
    fout<<fobj.rdorm();fout<<arr;

    fout<<'B';  
    fout<<fobj.rbed();fout<<arr;
    fout<<'\n';


    fout.close();

}



void showAllRecords(){

    ifstream readFile;
    readFile.open("PlayersRecord.txt");
    char charsInLine[1024];
    int count=0;
    cout<<"Players records :\n\n";
    while(!readFile.eof()){
        readFile.getline(charsInLine,1024);
        cout<<charsInLine<<endl;
    }
    readFile.close();

}




void deleteInRecords(int choice){

    string deleteString;
    string strFname="", strLname="";
    if(choice == 1){  
        cout<<"Enter the Player's Id whose record needs to be deleted\n";
        cin>>deleteString;
        deleteString = "id"+deleteString;
        cout<<"deleteString: "<<deleteString<<endl;
    }
    else{              
        cout<<"Enter the First Name of Player: ";
        cin>>strFname;
        cout<<"\nEnter the Last Name of Player: ";
        cin>>strLname;
        deleteString = strFname+"_"+strLname;
        cout<<"deleteString: "<<deleteString<<endl;
    }


    ifstream readFile;
    ofstream writeFile("sample.txt");

    char charsInLine[1024];

    readFile.open("PlayersRecord.txt");
  
    int count=0;
    bool found = false; 
   
    while(!readFile.eof()){

        readFile.getline(charsInLine,1024);
        string strLine(charsInLine); 
        cout<<count<<": "<<charsInLine<<endl;

        size_t found = strLine.find(deleteString);

        if(found != string::npos){

            found = true; 
            break;
        }

       
        else{
            writeFile<<charsInLine;
            writeFile<<"\n";
         
        }
        count++;

    }

    readFile.close();  
    writeFile.close(); 

    remove("PlayersRecord.txt");    
    rename("sample.txt", "PlayersRecord.txt");  

   
    if(found == false){
       cout<<"No records available...!\n";
    }
}




void countPlayers(){
    ifstream readFile;
    char charsInLine[1024];
    int countPlayer=0;

    readFile.open("PlayersRecord.txt");  
    while(!readFile.eof()){

        readFile.getline(charsInLine,1024);
        string strLine(charsInLine); 

        
        size_t found = strLine.find("id"); 

        
        if(found!= string::npos){
            countPlayer++;
            cout<<charsInLine<<endl;  
        }
        else{
            break; 
        }
    }

    cout<<"Number of Players available in our Records: "<<countPlayer<<endl;
    readFile.close(); 

}





void countPlayersInGame(){

    ifstream readFile;
    readFile.open("PlayersRecord.txt");
    char charsInLine[1024];
    int count=0;  

   
    string games[7]={"Basketball","TableTennis","Cricket","Volleyball","Hockey", "Taekwondo", "Badminton"};
    string gameName="";


    for(int i=0; i<7 ; i++){    

        gameName = games[i]; 
      
        int countGame = 0;

        ifstream readFile;
        readFile.open("PlayersRecord.txt");

        while(!readFile.eof()){

            readFile.getline(charsInLine, 1024);
            string strLine(charsInLine);  


            size_t found = strLine.find(gameName); 
            if(found!= string::npos){
                countGame++;
               

            }

        }

        readFile.close();

        cout<<"No. of Players enrolled in "<<gameName<<": "<<countGame<<endl;
        countGame = 0; 
   }

}





void searchInRecords(int choice){
   
    string searchString="";
    string strFname="", strLname="";

    switch(choice){

        case 1: 
                cout<<"Enter the First Name of Player: ";
                cin>>strFname;
                cout<<"Enter the Last Name of Player: ";
                cin>>strLname;
                searchString = strFname+"_"+strLname;  
                cout<<"Search String: "<<searchString<<endl;
                break;

        case 2: cout<<"Enter the Player Id: ";
                cin>>searchString;
                searchString = "id"+searchString;
                cout<<"Search String: "<<searchString<<endl;
                break;

        case 3: cout<<"Enter the Dorm No.: ";
                cin>>searchString;
                searchString = "D"+searchString;
                cout<<"Search String: "<<searchString<<endl;
                break;

        case 4: cout<<"Enter the Bed No.: ";
                cin>>searchString;
                searchString = "B"+searchString;
                cout<<"Search String: "<<searchString<<endl;
                break;

        case 5:
                cout<<"\nEnter the First Name of Player's Parent: ";
                cin>>strFname;
                cout<<"\nEnter the Last Name of Player's Parent: ";
                cin>>strLname;
                searchString = "pn"+strFname+"_"+strLname; 
                cout<<"Search String: "<<searchString<<endl;
                break;

        case 6: cout<<"Enter Player's Games Basketball, TableTennis, Cricket, Volleyball, Hockey, Taekwondo , Badminton : ";
                cin>>searchString;
                break;

        case 7: cout<<"Wrong Input..! Enter your choice again...\n";
                break;

    }


    ifstream readFile;
    readFile.open("PlayersRecord.txt");
    char charsInLine[1024]; int count=0;  
    searchString = searchString+" ";

    while(!readFile.eof()){
      
        readFile.getline(charsInLine, 1024);
     

        string strLine(charsInLine);  

        size_t found = strLine.find(searchString); 

        if(found!= string::npos){
            count++;
            cout<<"Records "<<count<<" : "<<charsInLine<<endl;  
        }
    }

    readFile.close();
    if( count == 0 )
        cout<<"NO records found...!\n";
    else{
        cout<<"No. of Records found for "<<searchString<<": "<<count<<endl;
    }
}





void clearCompleteDatabase(){
    int x;
    cout<<"Do you want to delete the complete database of Players...?\n Press 1 to confirm: ";
    cin>>x;

    if(x==1){
        remove("PlayersRecord.txt"); 
        ofstream writeFile("PlayersRecord.txt");  
        writeFile.close(); 
    }
}





int main(){

    file fileobj;   

    while(1){
        int choice;
        cout<<"\n\n############### MENU ###############";
        cout<<"\n1: Add a new Player Record";
        cout<<"\n2: Show all Players Record";
        cout<<"\n3: Delete Player by its Player Id from Record";
        cout<<"\n4: Delete Player by its Player Name from Record";
        cout<<"\n5: Search Player using Player Name";
        cout<<"\n6: Search Player using Player Id";
        cout<<"\n7: Search Player using Dorm No.";
        cout<<"\n8: Search Player using Bed No.";
        cout<<"\n9: Search Players using Parents Name";
        cout<<"\n10: Search Players in a specific Game";
        cout<<"\n11: Count the No. of Player in all Games";
        cout<<"\n12: Count the Total no. of Player's Record";
        cout<<"\n13: Clear the complete database of Player's Record";
        cout<<"\n14: Exit from Program";

        cout<<"\n\nEnter your choice...!\n";
        cin>>choice;
        system("cls");

        switch(choice){

            case 1: fileobj.input();  
                    writeInFile(fileobj); 
                    break;
            case 2: showAllRecords();
                    break;
            case 3: deleteInRecords(1);
                    break;
            case 4: deleteInRecords(2);
                    break;
            case 5: searchInRecords(1);
                    break;
            case 6: searchInRecords(2);
                    break;
            case 7: searchInRecords(3);
                    break;
            case 8: searchInRecords(4);
                    break;
            case 9: searchInRecords(5);
                    break;
            case 10: searchInRecords(6);
                    break;
            case 11: countPlayersInGame();
                    break;
            case 12: countPlayers();
                    break;
            case 13: clearCompleteDatabase();
                    break;
            case 14: cout<<"Exiting from program...\n";
                     exit(0); 
            default: cout<<"Wrong Choice..! enter your choice again...\n";
                     break;

        }
   }
}