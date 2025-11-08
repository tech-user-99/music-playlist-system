#include<iostream>
using namespace std;

class song{
	public:
	string title,artist;
	song* next;
};

void addsong(song* &head,string title,string artist){
	song* newsong=new song{title,artist,NULL};
	if(!head){
		head=newsong;
        cout<<"song added as the first entry.\n\n";
        return;
	}
	
	song* temp=head;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=newsong;
	cout<<"song added successfully.\n\n";
}

void display(song* &head){
	if(!head){
		cout<<"NO RECORDED WAS FOUND"<<endl;
		return;
	}
	song* temp=head;
	int count=1;
	cout<<"\n--- song List ---\n\n";
	while(temp){
		cout<<count++<<". "<<temp->title<<" by "<<temp->artist<<endl;
		temp=temp->next;
	}
}

void search(song* &head,string title){
	song* temp=head;
	while(temp){
		if(temp->title==title){
			cout<<"Title: "<<temp->title<<endl;
			cout<<"Artist: "<<temp->artist<<endl;
			return;
		}
		temp=temp->next;
	}
	cout<<"song not found.\n\n";
}

void playnext(song* &current){
	if(!current){
		cout<<"NO RECORDED WAS FOUND"<<endl;
		return;
	}
	cout<<"Now playing: "<<current->title<<" by "<<current->artist<<endl;
	current=current->next;
}

void deletesong(song* &head,string title){
	if(!head){
        cout<<"No song to delete.\n\n";
        return;
    }
    if(head->title==title){
    	song* todelete=head;
		head=head->next;
		delete todelete;
    	cout<<"Song deleted.\n\n";
        return;
	}
	song* temp=head;
	while(temp->next && temp->next->title!=title){
		temp=temp->next;
	}
	if(temp->next){
    	song* todelete=temp->next;
		temp->next=temp->next->next;
		delete todelete;
    	cout<<"song deleted.\n\n";
        return;
	}
	else{
        cout<<"song not found.\n\n";
    }
}

int main(){
    song* head=NULL;
    song* current=NULL;
    int choice;
    string title, artist;

    do{
        cout<<"----------------------------\n";
        cout<<"1. Add song\n";
        cout<<"2. Display songs\n";
        cout<<"3. Search song\n";
        cout<<"4. Delete song\n";
        cout<<"5. Play next song\n";
        cout<<"6. Exit\n";
        cout<<"----------------------------\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:
                cout<<"\nEnter title: ";
                getline(cin, title);
                cout<<"Enter artist: ";
                getline(cin, artist);
                addsong(head, title, artist);
                if(!current)current=head;
                break;

            case 2:
                display(head);
                break;

            case 3:
                cout<<"\nEnter title to search: ";
                getline(cin, title);
                search(head, title);
                break;

            case 4:
                cout<<"\nEnter title to delete: ";
                getline(cin, title);
                deletesong(head, title);
                if(current && current->title==title){
                    current=head; 
                }
                break;

            case 5:
                playnext(current);
                if(!current){
                    cout<<"End of playlist. Resetting to beginning.\n";
                    current=head;
                }
                break;

            case 6:
                cout<<"\nGoodbye!\n";
                break;

            default:
                cout<<"\nInvalid choice. Please try again.\n\n";
        }
    }
	while(choice!=6);
    while(head){
        song* temp=head;
        head=head->next;
        delete temp;
    }
    
    return 0;
}
