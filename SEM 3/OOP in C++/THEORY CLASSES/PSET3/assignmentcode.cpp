
/* THE FOLLOWING PROGRAMME DEMONSTRATES A PLAYLIST MANAGEMENT SOFTWARE.
USERS ARE ABLE TO FILL IN DETAILS OF THE SONGS , ADD OR REMOVE SONGS AS PER THEIR CHOICE AND MODIFY THE TITLE AS AND WHEN NEEDED. 
PURPOSE OF THE PROGRAMME IS NOT TO SIMULATE A REAL-WORLD USER-INTERACTION, RATHER TO EXPLORE THE FOLLOWING CONCEPTS AND THEIR USAGE: 
1. ACCESS SPECIFIERS
2. CONSTRUCTOR TYPES
3. DEEP COPY AND SHALLOW COPY
4. DYNAMIC MEMORY ALLOCATION FOR ATTRIBUTES AND CLASSES */

#include <iostream>
#include <cstring>
#include<vector>
using namespace std;

class song {
    private: //by default private attributes 
    char* artist;
    char* album; 
    public:
    
    char* title;


    // DEFAULT CONSTRUCTOR ASKS USER FOR INFORMATION ABOUT THE SONG
        song()
    {
        cout << "Enter the title of the song: ";
        title = new char[50]; // allocate buffer for title
        cin.getline(title, 50);
        artist = new char[50];
        cout << "Enter the artist of the song: ";
        cin.getline(artist, 50);
        album = new char[50];
        cout << "Enter the album of the song: ";
        cin.getline(album, 50);
    }
    song(const char* title, const char* artist, const  char* album) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title); //using strcpy to avoid leaks

        artist = new char[strlen(artist) + 1];
        strcpy(this->artist, artist);
    }


    //Deep Copy Constructor (default overriden)
    song(const song &other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);

        artist = new char[strlen(other.artist) + 1];
        strcpy(artist, other.artist);

        album = new char[strlen(other.album)+1]; 
        strcpy(album,other.album);
    }
    
    void modify()
    {
        cout << "Enter the new title of the song: ";
        title = new char[50]; // allocate buffer for title
        cin.getline(title, 50);
        artist = new char[50];
        cout << "Enter the new artist of the song: ";
        cin.getline(artist, 50);
        album = new char[50];
        cout << "Enter the new album of the song: ";
        cin.getline(album, 50);
        cout<<"The song details now are: \nTitle:"<<title<<"\nArtist: "<<artist<<"\nAlbum: "<<album; 
    }
    /*Shallow Copy Simulation is like this but by default C++ uses shallow copy
    void shallowcopy(const Book &other) {
        title = other.title;
        author = other.author;
    }
    */

    // Destructor
    ~song() {
        delete[] title;
        delete[] artist;
        delete[] album; 
    }

    // Display function
    void display() const {
        cout << "Title: " << title << ", artist: " << artist << endl;
    }
};
//Function to add the song in a vector called playlist: 
    void playlist_expand(vector<song> playlist, const song &other)
    {
        playlist.push_back(other);
    }
//function to remove song in a vector called playlist
    void remove_song(vector<song> playlist)
    {
        cout << "Enter the title of the song to remove: ";
        char searchtitle[50];
        cin.getline(searchtitle, 50);

        for(int i =0;i<playlist.size();i++)
        {
            if(playlist[i].title == searchtitle)
            {
                playlist.erase(playlist.begin() + i); 
            }
        }
    }


int main() {
    /*
    song song1("The Alchemist", "Paulo Coelho");
    song song2 = song1; // CHANGED TO DEEP COPY (will get modified )
    song song3("Temp", "Temp Author");

    cout << "Before modification:" << endl;
    song1.display();
    song2.display();
    song3.display();

    // Modify original
    strcpy(song1.author, "Changed Author");

    cout << "\nAfter modification of book1:" << endl;
    song1.display();
    song2.display(); //changed as it is shallow copy
  
    return 0;
    */
    vector<song> playlist;
    int choice;
    do {
        cout << "WELCOME TO A CHEAPER VERSION OF SPOTIFY. NO ADS I PROMISE. HERE ARE THE ACTIONS: \n";
        cout << "1. Add Song to the playlist"<<endl;
        cout << "2. Remove a Song to the playlist"<<endl;
        cout << "3. Modify a Song from the playlist"<<endl;
        cout << "4. Display Playlist"<<endl;
        cout << "5. Demonstrate Deep Copy"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) 
        {
            song s;
            playlist_expand(playlist, s); 
            cout << "Song added to playlist.\n";
        } 
        else if (choice == 2) {
            if (playlist.size() == 0) {
                cout << "Playlist is empty.\n";
                continue;
            }
            else
                remove_song(playlist);
                
        } else if (choice == 3) {
            if (playlist.empty()) {
                cout << "Playlist is empty.\n";
                continue;
            }
            int idx;
            cout << "Enter song index to modify (starting from 1): ";
            cin >> idx;
            cin.ignore();
            if (idx < 1 || idx > playlist.size()) {
                cout << "Invalid index.\n";
            } else {
                playlist[idx - 1].modify();
            }
        } else if (choice == 4) {
            if (playlist.empty()) {
                cout << "Playlist is empty.\n";
            } else {
                cout << "\n--- Playlist ---\n";
                for (size_t i = 0; i < playlist.size(); ++i) {
                    cout << i + 1 << ". ";
                    playlist[i].display();
                }
            }
        } else if (choice == 5) {
            if (playlist.size() < 1) {
                cout << "Add at least one song first.\n";
            } else {
                cout << "Demonstrating deep copy:\n";
                song copySong = playlist[0]; // invokes deep copy constructor
                cout << "Original song: ";
                playlist[0].display();
                cout << "Copied song: ";
                copySong.display();
                cout << "Now modifying original song...\n";
                playlist[0].modify();
                cout << "\nOriginal song after modification: ";
                playlist[0].display();
                cout << "Copied song remains: ";
                copySong.display();
            }
        }
    } while (choice != 0);
    cout << "Exiting Playlist Manager.\n";
}